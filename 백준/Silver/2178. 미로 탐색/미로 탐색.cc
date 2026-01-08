#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int x;
    int y;
} Point;
int N,M;
int maze[101][101];
/*
여기서 visited는 단순히 탐색의 유무 뿐만 아니라, 현재 어느 길이까지 검사했는지의 수치를 의미한다.
단 visited가 0이면 똑같이 아직 탐색 전. 0이 아니라면, 해당 탐색의 깊이를 의미한다.
*/
int visited[101][101]; 
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
Point queue[10001];
void bfs_maze(int startY, int startX){
    int front=0;
    int rear=0;
    visited[startY][startX]=1;
    queue[rear].y=startY;
    queue[rear].x=startX;
    rear++;

    while(front<rear){
        Point cur = queue[front++]; // queue의 맨 앞 노드를 꺼냄. 현재 검사하려는 노드이다.

        for(int i=0; i<4; i++){ // 상하좌우 검색하면서 1인 곳이 있으면(길이 있으면) queue에 넣는다.
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            // 범위 밖으로 나갔는지 검사
            if(nx < 1 || nx > M || ny < 1 || ny > N) continue;

            if(maze[ny][nx] == 1 && visited[ny][nx]==0){
                visited[ny][nx] = visited[cur.y][cur.x]+1;
                queue[rear].y = ny;
                queue[rear].x = nx;
                rear++;
            }
        }
    }
}
int main() {
    int Y,X;
    int size;
    scanf("%d %d", &N, &M);
    size = N*M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            scanf("%1d", &maze[i][j]);

    bfs_maze(1,1);
    printf("%d\n", visited[N][M]);
    return 0;
}