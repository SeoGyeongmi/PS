#include <stdio.h>
#include <algorithm>
using namespace std;

int R, C;
int map[21][21];
int visited[26];
int ans = 0;   

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int count) {
    // 1. 현재까지의 기록(count)과 최대값(ans) 비교해서 갱신
    if (count > ans) ans = count;

    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];

        if (ny<0||nx<0||ny>=R||nx>=C) continue;
        
        int next_alpha = map[ny][nx];
        
        if (visited[next_alpha] == 0) {
            visited[next_alpha] = 1;     
            dfs(ny, nx, count + 1);      
            visited[next_alpha] = 0;  
        }
    }
}

int main() {
    char t;
    scanf("%d %d", &R, &C);
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf(" %c", &t); // 공백 앞에 안 넣어주면 개행 문자까지 바꿔서 넣음
            map[i][j] = t -'A';
        }
    }
    
    
    visited[map[0][0]] = 1;
    dfs(0,0,1); 

    printf("%d", ans);
    return 0;
}