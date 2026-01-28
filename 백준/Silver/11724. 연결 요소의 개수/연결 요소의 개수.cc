#include <stdio.h>
int graph[1001][1001]={0};
int visited[1001]={0};
void dfs(int cur, int N){
    visited[cur]=1;
    
    for(int i=1; i<=N; i++)
        if(visited[i]==0 && graph[cur][i]==1)
            dfs(i,N);
}
int main() {
    int count=0;
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a][b]=1;
        graph[b][a]=1;
    }

    for(int i=1; i<=V; i++){
        if(visited[i]==0){
            count++;
            dfs(i, V);
        }
    }

    printf("%d\n", count);
    return 0;
}