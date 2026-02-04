#include <stdio.h>

#define MAX 101

int adj[MAX][MAX];
int dist[MAX];
int q[MAX];
int n;


int bfs(int start, int target) {
    int front = 0, rear = 0;

    // 거리 초기화
    for (int i = 1; i <= n; i++)
        dist[i] = -1;

    dist[start] = 0;
    q[rear++] = start;

    while (front < rear) {
        int cur = q[front++];

        if (cur == target)
            return dist[cur];

        for (int next = 1; next <= n; next++) {
            if (adj[cur][next] && dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q[rear++] = next;
            }
        }
    }

    return -1;  // 연결되지 않은 경우
}

int main(void) {
    int a, b, m;

    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);

    // 초기화
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        // 양방향으로 처리
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    printf("%d\n", bfs(a, b));

    return 0;
}