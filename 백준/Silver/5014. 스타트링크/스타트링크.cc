#include <stdio.h>

int queue[1000001];
int visited[1000001];
int F, start, fin, up, down;
void bfs(){
    if(start == fin) {
        printf("0\n");
        return;
    }
    int front=0, rear=0;
    queue[rear++] = start;
    visited[start]=0;
    
    while(front < rear) {
        int cur = queue[front++];
        int d[2] = {cur+up, cur-down}; // 현재 층에서 갈 수 있는 층 수

        for(int i=0; i<2; i++){
            int next = d[i];
            if(next == cur || next > F || next < 1) continue;
            if(visited[next]!=0) continue;

            if(next == fin){ // 원하는 목표층에 도달했다면
                printf("%d\n", visited[cur]+1);
                return;
            }
            visited[next] = visited[cur]+1;
            queue[rear++] = next;
        }
    }
    printf("use the stairs\n");
}
int main(){
    scanf("%d %d %d %d %d", &F, &start, &fin, &up, &down);

    bfs();
    return 0;
}