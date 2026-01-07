#include <stdio.h>
#include <string.h>
int N,M; // N: 세로길이, M: 가로길이
int numOfcabage;
int map[51][51]={0};
int visited[51][51]={0};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,-1,1};
void dfs(int curY, int curX){
    visited[curY][curX]=1;

    for(int i=0; i<4; i++){
        int nextY = curY + dy[i];
        int nextX = curX + dx[i];

        if(nextY<0||nextX<0||nextX>=M||nextY>=N) continue;
        if(map[nextY][nextX]==1 && visited[nextY][nextX]==0)
            dfs(nextY, nextX);
    }
}
int main() {
    int testcase;    
    int isfirst=0;
    int startY, startX;
    int numOfLarva=0;
    scanf("%d", &testcase);
    for(int k=0; k<testcase; k++){
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        numOfLarva=0;
        scanf("%d %d %d", &M, &N, &numOfcabage);
        for(int i=0; i<numOfcabage; i++){
            int x,y;
            scanf("%d %d", &x, &y);
            map[y][x]=1;
            
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j]==1 && visited[i][j]==0){
                    dfs(i, j);
                    numOfLarva++;
                }
            }
        }
        printf("%d\n", numOfLarva);
    }
    return 0;
}