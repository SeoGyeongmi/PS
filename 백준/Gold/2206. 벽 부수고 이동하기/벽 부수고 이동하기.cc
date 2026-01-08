#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


typedef struct {
    int y;
    int x;
    int isbroken; // 0: 안 부숨, 1: 부숨
} Point;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int N, M;
int mat[1001][1001];
int visited[1001][1001][2]; // [y][x][부숨여부]

void bfs() {
    queue<Point> q;
    
    // 시작점 (1, 1), 안 부순 상태(0), 거리 1
    q.push({1, 1, 0});
    visited[1][1][0] = 1;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        // 목적지 도착했다면
        if (cur.y == N && cur.x == M) {
            // visited 배열 자체가 '거리'를 담고 있으므로 바로 출력
            printf("%d\n", visited[cur.y][cur.x][cur.isbroken]);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;

            // 다음 칸이 빈 땅
            // 내 현재 상태(cur.isbroken) 그대로 이동 가능
            if (mat[ny][nx] == 0) {
                if (visited[ny][nx][cur.isbroken] == 0) {
                    visited[ny][nx][cur.isbroken] = visited[cur.y][cur.x][cur.isbroken] + 1;
                    q.push({ny, nx, cur.isbroken});
                }
            }
            
            // 다음 칸이 벽 일 때
            else if (mat[ny][nx] == 1) {
                if (cur.isbroken == 0) { // 아직 벽을 부술 수 있다면
                    if (visited[ny][nx][1] == 0) {
                        visited[ny][nx][1] = visited[cur.y][cur.x][0] + 1;
                        q.push({ny, nx, 1}); // 상태를 1로 바꿔서 큐에 넣음
                    }
                }
            }
        }
    }
    // 탐색 종료까지 목적지에 도달하지 못했다면, -1 출력
    printf("-1\n");
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &mat[i][j]); 
        }
    }

    bfs();
    return 0;
}