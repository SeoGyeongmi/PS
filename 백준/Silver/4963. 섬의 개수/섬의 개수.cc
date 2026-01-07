#include <stdio.h>
#include <string.h>
int dy[8] = {1,-1,0,0,1,-1,1,-1};
int dx[8] = {0,0,-1,1,1,1,-1,-1};
int W,H;
int map[51][51];
int visited[51][51];
int theNumofLands;
void dfs(int curY, int curX){
    visited[curY][curX]=1;

    for(int i=0; i<8; i++){
        int nextY = curY + dy[i];
        int nextX = curX + dx[i];
        if(nextY<0||nextX<0||nextY>=H||nextX>=W) continue;
        if(visited[nextY][nextX]==0 && map[nextY][nextX]==1){
            dfs(nextY, nextX);
        }
    }
}
int main(){

    while(1){
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        theNumofLands=0;
        scanf("%d %d", &W, &H);
        if(W==0 && H==0){
            break;
        }
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                scanf("%d", &map[i][j]);
            }
        }

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(map[i][j]==1 && visited[i][j]==0){
                    theNumofLands+=1;
                    dfs(i,j);
                }
                
            }
        }
        printf("%d\n", theNumofLands);
    }
    return 0;
}