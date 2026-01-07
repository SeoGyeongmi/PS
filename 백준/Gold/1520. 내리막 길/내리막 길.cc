#include <stdio.h>

typedef struct 
{
    int x;
    int y;
} Point;

int dp[501][501];
int height[501][501];
int N,M; // 가로, 세로 길이
int count=0; // 경로의 개수
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};
int dfs(int cur_y, int cur_x){
    if((cur_y == M-1) && (cur_x == N-1)){
        // printf("도착!\n");
        count++;
        return 1;
    }

    if(dp[cur_y][cur_x] != -1)  
        return dp[cur_y][cur_x]; // 검사한 적이 있는 경로라면 그 경로의 경우의 수를 return
    dp[cur_y][cur_x] = 0; // 검사한 적이 없다면, 0부터 시작

    for(int i=0; i<4; i++){
        int next_y = cur_y + dy[i];
        int next_x = cur_x + dx[i];

        if(next_y<0 || next_x<0 || next_y>=M || next_x>=N) continue;
        if(height[next_y][next_x] < height[cur_y][cur_x]){
            dp[cur_y][cur_x] += dfs(next_y, next_x);
        }
    }
    return dp[cur_y][cur_x];
}
int main() {
    scanf("%d %d", &M, &N);
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &height[i][j]);
            dp[i][j] = -1; // 검사하기 전 표시
        }
    }

    printf("%d\n", dfs(0,0));


    return 0;
}