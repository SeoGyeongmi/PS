#include <stdio.h>
#include <limits.h>

#define INF 1000000000 // 십억

int N, M; 
int start_node, end_node;


int map[1005][1005];
int dist[1005];
int visited[1005];
void dijkstra() {
    
    dist[start_node] = 0;
    for (int i = 0; i < N; i++) {
        
        // 방문하지 않은 도시 중 가장 비용이 적은 도시(min_idx) 찾기
        int min_val = INF;
        int min_idx = -1;

        for (int j = 1; j <= N; j++) {
            if (!visited[j] && dist[j] < min_val) {
                min_val = dist[j];
                min_idx = j;
            }
        }

        // 더 이상 갈 수 있는 도시가 없거나, 목적지가 확정되었다면 break
        if (min_idx == -1) break;
        visited[min_idx] = 1;

        // min_idx를 거쳐서 가는 게 더 빠른지, 주변 도시 검사
        for (int j = 1; j <= N; j++) {
            // 가는 길이 있고, 아직 확정 안 된 곳이라면
            if (!visited[j] && map[min_idx][j] != INF) {
                if (dist[min_idx] + map[min_idx][j] < dist[j]) {
                    dist[j] = dist[min_idx] + map[min_idx][j];
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;   
        visited[i] = 0; 
        for (int j = 1; j <= N; j++) {
            if (i == j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        
        // 같은 출발-도착이라도 비용이 다른 버스가 여러 대일 수 O
        // 그 중 가장 싼 비용만 저장해야 함
        if (map[u][v] > w) {
            map[u][v] = w;
        }
    }

    scanf("%d %d", &start_node, &end_node);
    dijkstra();
    printf("%d\n", dist[end_node]);

    return 0;
}