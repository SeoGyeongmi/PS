#include <stdio.h>
#include <string.h>

typedef struct {
    int y, x;
} Point;

int map[8][8];
// visited 배열은 사실 필요 없습니다. map 값만 1로 바꿨다 0으로 되돌리면 되니까요.
int saveArea_max = 0;
int N, M; // N: 세로, M: 가로

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void spreadVirus() {
    int cpmap[8][8];
    Point queue[64];
    int front = 0, rear = 0;

    // 맵 복사
    memcpy(cpmap, map, sizeof(map));

    // 바이러스(2) 찾아서 큐에 넣기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cpmap[i][j] == 2) {
                queue[rear].y = i;
                queue[rear].x = j;
                rear++;
            }
        }
    }

    // BFS 탐색
    while (front < rear) {
        Point cur = queue[front++];

        for (int i = 0; i < 4; i++) {
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M) continue;
            
            if (cpmap[nextY][nextX] == 0) {
                cpmap[nextY][nextX] = 2; // [수정2] == 가 아니라 =
                queue[rear].y = nextY;
                queue[rear].x = nextX;
                rear++;
            }
        }
    }

    // 안전 영역 세기
    int safeArea = 0;
    for (int i = 0; i < N; i++) {     // [수정4] i < N (세로)
        for (int j = 0; j < M; j++) { // [수정3] j++ 로 수정, j < M (가로)
            if (cpmap[i][j] == 0) {
                safeArea++;
            }
        }
    }

    if (safeArea > saveArea_max)
        saveArea_max = safeArea;
}

// [수정1] 벽 세우기 로직 전체 변경
// DFS지만 인접한 곳이 아니라 '전체 맵'에서 빈칸을 찾습니다.
void generateWall(int count) {
    if (count == 3) {
        spreadVirus();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 빈 칸이면 벽을 세워본다
            if (map[i][j] == 0) {
                map[i][j] = 1;         // 벽 세우기
                generateWall(count + 1); // 다음 벽 세우러 가기
                map[i][j] = 0;         // (백트래킹) 벽 허물기
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M); // [수정4] N, M 순서 맞춤

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 벽 0개인 상태에서 시작
    generateWall(0);

    printf("%d\n", saveArea_max);
    return 0;
}