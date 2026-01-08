#include <stdio.h>
#include <string.h>
// 비가 아예 안 오거나, 가장 낮은 건물의 높이보다 적게 올 수 있다(안전영역의 최솟값은 1)
int maxSafeZone=1; 
int curSafeZone=0;
int maxHeight=1; // max높이를 계산하여 불필요한 계산을 줄이려한다. 가능한 최소 높이는 1.
int size;
int height[101][101];
int visited[101][101];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};
// BFS용 함수
typedef struct 
{
    int y;
    int x;
} Point;
Point queue[10001];
int front=0, rear=0;

// 안전 구역을 세어주는 DFS(BFS)함수
// void dfs(int curY, int curX, int curHeight){
//     visited[curY][curX]=1;

//     for(int i=0; i<4; i++){
//         int nextY = curY + dy[i];
//         int nextX = curX + dx[i];
//         if(nextY<0||nextX<0||nextY>=size||nextX>=size) continue;
//         if(visited[nextY][nextX]==0 && height[nextY][nextX]>curHeight){
//             dfs(nextY, nextX, curHeight);
//         }
//     }
// }
void bfs(int curHeight){
    while(front<rear){
        Point cur = queue[front++];

        for(int i=0; i<4; i++){
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            if(nextY<0||nextX<0||nextY>=size||nextX>=size) continue;
            if(visited[nextY][nextX]==0 && height[nextY][nextX]>curHeight){
                visited[nextY][nextX]=1;
                queue[rear].y=nextY;
                queue[rear].x=nextX;
                rear++;
            }
        }
    }
}
int main(){
    scanf("%d", &size);

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            scanf("%d", &height[i][j]);
            // 입력받은 수들 중의 최대 높이가 maxHeight에 저장됨
            if(height[i][j]>maxHeight){ 
                maxHeight = height[i][j];
            }
        }
    }

    for(int curHeight=0; curHeight<=maxHeight; curHeight++){ // 모든 높이에 대해 안전 구역의 개수를 검사(높이는 1이상 maxHeight이하)
        memset(visited,0,sizeof(visited));
        curSafeZone=0;
        front=0;
        rear=0;
        for(int y=0; y<size; y++){ // 모든 좌표
            for(int x=0; x<size; x++){
                if(visited[y][x]==0 && height[y][x]>curHeight){
                    // bfs사용하며 추가된 로직들
                    visited[y][x]=1;
                    queue[rear].y = y;
                    queue[rear].x = x;
                    rear++;
                    bfs(curHeight);
                    // dfs(y,x, curHeight); 
                    curSafeZone += 1;
                }
            }
        }
        if(curSafeZone>maxSafeZone){
            maxSafeZone = curSafeZone;
        }
    }

    printf("%d\n", maxSafeZone);
    return 0;
}