#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
typedef struct { int x,y; } Point;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int area[100][100]={0};
int M,N,K;
int visited[100][100];
int ac=0;
int size[10000]={0};
int cmp(const void *a, const void *b){
    int x = *(int*)a;
    int y = *(int*)b;

    if(x>y) return 1;
    if(x<y) return -1;
    return 0;
}
void bfs(int startY, int startX){
    visited[startY][startX]=1; 
    Point q[10000];
    int front=0, rear=0;
    q[rear].y = startY;
    q[rear].x = startX;
    rear++;
    
    while(front<rear){
        Point cur = q[front++];
        size[ac]++; // 큐에 들어간 영역의 크기를 +1 
        for(int i=0; i<4; i++){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny<0 || nx<0 || ny>=M || nx>=N) continue;
            if(area[ny][nx]==0 && visited[ny][nx]==0){
                // 영역이 있고, 탐색되지 않은 곳이라면
                visited[ny][nx]=1;
                q[rear].y = ny;
                q[rear].x = nx;
                rear++;
            }
        }
    }
}
int main(){
    scanf("%d %d %d", &M, &N, &K);

    int x1,y1,x2,y2;
    for(int k=0; k<K; k++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int i=y1; i<y2; i++){
            for(int j=x1; j<x2; j++){
                area[i][j]=1;
            }
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(area[i][j]==0 && visited[i][j]==0){
                bfs(i,j);
                ac+=1;
            }
        }
    }
    qsort(size,ac,sizeof(int), cmp);
    printf("%d\n", ac);
    for(int i=0; i<ac; i++){
        printf("%d ", size[i]);
    }
    printf("\n");
    return 0;
}