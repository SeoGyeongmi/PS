/*
BFS

queue에 위치 정보를 넣음
visitied 변수로 시간을 측정함

순간이동은 0초 소요, 걷기는(현재위치+1 or 현재위치-1) 1초 소요
*/
#include <stdio.h>

int visited[100001];
int dq[200005];

void bfs(int N, int K){
    for(int i=0;i<=100000;i++) visited[i] = -1;

    int front = 100000, rear = 100000;
    visited[N] = 0;
    dq[rear++] = N;

    while(front < rear){
        int cur = dq[front++];

        if(cur == K) return;

        int teleport = cur * 2;
        int wfront = cur + 1;
        int wback  = cur - 1;

        if(teleport >= 0 && teleport <= 100000){
            int nt = visited[cur];
            if(visited[teleport] == -1 || visited[teleport] > nt){
                visited[teleport] = nt;
                dq[--front] = teleport;
            }
        }

        if(wfront >= 0 && wfront <= 100000){
            int nt = visited[cur] + 1;
            if(visited[wfront] == -1 || visited[wfront] > nt){
                visited[wfront] = nt;
                dq[rear++] = wfront;
            }
        }

        if(wback >= 0 && wback <= 100000){
            int nt = visited[cur] + 1;
            if(visited[wback] == -1 || visited[wback] > nt){
                visited[wback] = nt;
                dq[rear++] = wback;
            }
        }
    }
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    bfs(N, K);

    printf("%d\n", visited[K]);
    return 0;
}
