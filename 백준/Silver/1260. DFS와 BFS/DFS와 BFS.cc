#include <stdio.h>
int graph[1001][1001]={0};
int visited[1001]={0};
int queue[1001];
void dfs(int cur, int N){
    visited[cur]=1;
    printf("%d ", cur);

    for(int next=1; next<=N; next++){
        if(visited[next]==0 && graph[cur][next]==1)
            dfs(next,N);
    }
}
void bfs(int start, int N){
    int front=0;
    int rear=0;

    visited[start] = 1;
    queue[rear++] = start;

    while(front<rear){
        // 맨 앞 노드 꺼내기
        int cur = queue[front++];
        printf("%d ", cur);

        for(int next=1; next<=N; next++){
            if(graph[cur][next]==1 && visited[next]==0){
                visited[next]=1;
                queue[rear++]=next;
            }
        }
    }
}
int main() {
    int nodes,conns,firstNode; // 정점의 개수, 간선의 개수, 탐색을 시작할 정점의 번호

    scanf("%d %d %d", &nodes, &conns, &firstNode);
    for(int i=0; i<conns; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a][b]=1;
        graph[b][a]=1; // biconnected(양방향) 간선이므로
    }
    dfs(firstNode, nodes);
    printf("\n");

    for(int i=0; i<=nodes; i++)
        visited[i]=0;
    bfs(firstNode, nodes);
    return 0;
}