#include <stdio.h>
#include <string.h>
int size;
int map[101][101];
int visited[101][101]={0};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void color(int curY, int curX, int colorNum){
    visited[curY][curX]=1;

    for(int i=0; i<4; i++){
        int nextY = curY + dy[i];
        int nextX = curX + dx[i];

        if(nextY<0||nextX<0||nextY>=size||nextX>=size) continue;
        if(map[nextY][nextX]==colorNum && visited[nextY][nextX]==0){ // 인접한 곳이 같은 색상인데, 방문을 안 했을 경우
            color(nextY, nextX, colorNum);
        }
    }
}
int main(){
    int count=0;
    scanf("%d", &size);

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            char temp;
            scanf(" %c", &temp);
            if(temp=='R') map[i][j]=1;
            else if(temp=='G') map[i][j]=2;
            else if(temp=='B') map[i][j]=3;
        }
    }
    // for(int i=0; i<size; i++){ // 디버깅
    //     for(int j=0; j<size; j++){
    //         printf("%d", map[i][j]);
    //     }
    //     printf("\n");
    // }

    // "적록색맹 아닌" 사람이 보는 구역의 수 계산&출력
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(visited[i][j]==0){
                count++;
                color(i,j,map[i][j]);
            }
        }
    }


    printf("%d ", count);

    // "적록색맹인" 사람이 보는 구역의 수 계산&출력
    count=0; // count 초기화
    memset(visited, 0, sizeof(visited)); // (다른 조건으로) 다시 새롭게 탐색해야 하므로 visited 초기화(0으로 다 초기화)
    for(int i=0; i<size; i++){ // G 구역을 R구역으로 바꿔주는 반복문
        for(int j=0; j<size; j++){
            if(map[i][j]==2){
                map[i][j]=1;
            }
        }
    }

    for(int i=0; i<size; i++){ // 인위적으로 조작한 맵을 위와 같이 탐색 후 출력
        for(int j=0; j<size; j++){
            if(visited[i][j]==0){
                count++;
                color(i,j,map[i][j]);
            }
        }
    }
    printf("%d\n", count);

    return 0;
}