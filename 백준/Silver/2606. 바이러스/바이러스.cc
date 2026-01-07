#include <stdio.h>

int graph[101][101];
int visited[101]={0};
int N; // 컴퓨터의 수
int count=-1; // 바이러스에 걸리게 되는 컴퓨터 수 표시
void dfs(int preNode){
    visited[preNode]=1;
    count++;

    for(int i=1; i<=N; i++){
        if(graph[preNode][i]==1 && visited[i]==0){
            dfs(i);
        }
    }
}
int main(){
    int links;

    scanf("%d", &N);
    scanf("%d", &links);

    for(int i=0; i<links; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(1); // 1번 컴퓨터부터 시작

    printf("%d\n", count);
    return 0;
}