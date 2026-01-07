#include <stdio.h>
// 입력: 수빈이가 있는 위치, 동생이 있는 위치 (5 7)
// 출력: 수빈이가 동생을 찾는 가장 빠른 시간
int visited[100001]={0}; // 만 번(만 초 안에는 찾는다고 일단 생각함)
int queue[100001];
/*
수빈이가 현재 있는 점에서 갈 수 있는 세 위치를 큐에 저장한다.
각각의 위치에 대해서는 몇 초만에 그 위치에 도달했는지를 저장하는데, 
그 시간(초)는 그 위치에 가기 전의 위치의 시간에 +1을 하면 된다.(visited)변수 활용 
*/
int bfs(int start, int finish){
    int front=0, rear=0;
    visited[start]=0; // 그 위치에 도달한 시간(단위 : 초)
    queue[rear++] = start;

    while(front < rear){
        int cur = queue[front++];
        int next_pos[3] = {cur+1, cur-1, cur*2};

        for(int i=0; i<3; i++){
            int next = next_pos[i]; // 앞, 뒤, 순간이동 위치를 각각 반복하여 계산한다.
            if(next < 0 || next > 100000) continue;
            if(visited[next] != 0) continue;    
            if(next == finish) // 만약 현재 검사하는 위치에서의 다음이동이 finish라면, 현재 위치까지의 시간+1을 return한다.
                return visited[cur]+1;
            // 찾는 위치가 아니라면..
            visited[next] = visited[cur]+1;
            queue[rear++] = next;
        }
        
    }
    return -1;
}
int main() {
    int start, finish;
    scanf("%d %d", &start, &finish);

    if(start==finish)
        printf("0\n");
    else
        printf("%d\n", bfs(start, finish));
    return 0;
}