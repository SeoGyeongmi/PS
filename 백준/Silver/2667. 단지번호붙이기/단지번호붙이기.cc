#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
} Point;
int size;
int map[25][25];
int danji_count[400]={0}; // 존재할 수 있는 단지의 수 (넉넉히 잡음)
int danji_no=0; // 단지번호는 1부터 시작한다.
int visited[25][25]={0};
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};

int cmp(const void* a, const void* b){
    int x = *(int*)a;
    int y = *(int*)b;

    if(x<y) return -1;
    else if(x>y) return 1;
    else return 0;
}
void dfs(int curY, int curX){
    visited[curY][curX]=1; // visited함수는 map이 1일 때만 같이 조건 확인 함.
    danji_count[danji_no] += 1;

    for(int i=0; i<4; i++){
        int nextY = curY + dy[i];
        int nextX = curX + dx[i];

        if(nextY<0 || nextX<0 || nextY>=size || nextX>=size) continue;
        if(map[nextY][nextX]==1 && visited[nextY][nextX]==0){
            dfs(nextY, nextX);
        }
    }
}
int main(){
    int defineStart=0;
    int startX, startY;
    scanf("%d", &size);
    for(int y=0; y<size; y++){
        for(int x=0; x<size; x++){
            scanf("%1d", &map[y][x]);
            if(!defineStart && map[y][x]==1){
                startX = x;
                startY = y;
                defineStart=1;
            }
        }
    }
    if(!defineStart){ // 만약 집이 하나도 없으면 0 출력 후 프로그램 종료
        printf("0\n");
        return 0;
    }
    int isChecking=1;
    while(isChecking){
        dfs(startY, startX);
        danji_no++;

        isChecking=0; // 만약 밑의 for문 돌고 1이 된다면 아직 검사가 필요하다는 의미
        for(int i=0; i<25; i++){
            for(int j=0; j<25; j++){
                if(map[i][j]==1 && visited[i][j]==0){
                    startY = i;
                    startX = j;
                    isChecking=1;
                }
            }
        }
    }

    printf("%d\n", danji_no);
    qsort(danji_count, danji_no, sizeof(int), cmp);
    for(int i=0; i<danji_no; i++)
        printf("%d\n", danji_count[i]);
    return 0;
}