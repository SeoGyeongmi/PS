#include <iostream>
#include <queue>
#include <cstring> 

using namespace std;

int N;
int mat[101][101];   
int result[101][101]; 
int visited[101];    
// 특정 시작점(start)에서 갈 수 있는 모든 곳을 찾는 BFS
void bfs(int start) {
    memset(visited, 0, sizeof(visited));
    
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next = 0; next < N; next++) {
            
            if (mat[cur][next] == 1 && visited[next] == 0) {
                visited[next] = 1;
                q.push(next);  
            }
        }
    }

    for (int i = 0; i < N; i++) {
        result[start][i] = visited[i];
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        bfs(i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}