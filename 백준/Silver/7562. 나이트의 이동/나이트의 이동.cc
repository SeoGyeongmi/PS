#include <stdio.h>
#include <string.h>
typedef struct 
{
    int x;
    int y;
} Point;

int N;
Point queue[90001];
int visited[301][301];
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int dx[8]={1,2,2,1,-1,-2,-2,-1};
void bfs(int size, int startY, int startX, int finishY, int finishX){
    if(startY==finishY && startX==finishX){
        printf("0\n");
        return;
    }
    int front=0, rear=0;
    visited[startY][startX]=0;
    queue[rear].y = startY;
    queue[rear].x = startX;
    rear++;

    while(front<rear){
        Point cur = queue[front++]; // 현재 큐에서 탐색하려는 좌표 하나를 pop함
        for(int i=0; i<8; i++){ // 이동 가능 경로 만큼 반복.
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            // 현재 검사하려는 좌표가 범위를 벗어났다면 다음 검사 좌표로 넘어가기
            if(ny < 0 || ny >= size || nx < 0 || nx >= size) continue;
            if(visited[ny][nx]!=0) continue;
            //printf("check about - (%d, %d)\n", nx, ny);
            if(ny == finishY && nx == finishX){
                printf("%d\n", visited[cur.y][cur.x]+1);
                return;
            }
            else{
                visited[ny][nx] = visited[cur.y][cur.x]+1;
                queue[rear].y = ny;
                queue[rear].x = nx;
                rear++;
            }
        }
    } // 탐색 종료 조건이 무엇일지 고민해보기
    /*
    미로 찾기와는 다르게, 0,1로 탐색 가능의 유무가 나뉘어져 있는 것이 아닌,
    !범위 내로!는 모두 갈 수 있다.
    */
}
int main() {
    
    int size;
    int startY, startX;
    int finishY, finishX;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &size);
        scanf("%d %d", &startY, &startX); // 현재 있는 칸
        scanf("%d %d", &finishY, &finishX); // 이동하려고 하는 칸

        // 초기화
        memset(visited, 0, sizeof(visited));

        bfs(size, startY, startX, finishY, finishX); 
    }
    return 0;
}