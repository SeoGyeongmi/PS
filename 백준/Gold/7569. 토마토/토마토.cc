/*
main 함수에서 scan받으면서 1인 곳을 다 queue에 넣어놓고, bfs함수에서는 queue에서 pop하면서 시작하는 게 좋을지?
아니면 그냥 main에선 scan만 받고 bfs에서 1인 곳을 다 찾으면서 큐에 넣고 바로 큐에서 써내서
탐색해나가는 것이 좋을지
*/
#include <stdio.h>
typedef struct 
{
    int x;
    int y;
    int z;
} Point;
int X, Y, Z;
int tomato[101][101][101];
// visited 변수(방문 확인) 사용하지 않고 그냥 tomato자체를 1로 바꿔도 ㄱㅊ?
Point queue[1000001];
int dz[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dx[6] = {0,0,0,0,1,-1};
int time=0; // 토마토가 다 익는 데에 걸리는 시간 
int nonRipe=0;
int front=0, rear=0;
void bfs(){
    // 하나씩 pop할 때 마다 count++ 하기
    // 현재 검사하는 칸의 값이 -1이면 큐에 넣지X 
    // 큐에 넣는 토마토들은 다 익는 거임
    // + 큐에 싱싱한 토마토들 넣으면, nonRipe-- 하기
    while(front<rear){
        Point cur = queue[front++];

        for(int i=0; i<6; i++){
            int nextZ = cur.z + dz[i];
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            if(nextZ<0||nextY<0||nextX<0||nextZ>=Z||nextY>=Y||nextX>=X) continue;
            if(tomato[nextZ][nextY][nextX]==0){
                nonRipe--;
                tomato[nextZ][nextY][nextX]=tomato[cur.z][cur.y][cur.x]+1;
                time = tomato[nextZ][nextY][nextX];
                queue[rear].z = nextZ;
                queue[rear].y = nextY;
                queue[rear].x = nextX;
                rear++;
            }
        }
        

    }
}
int main(){
    scanf("%d %d %d", &X, &Y, &Z);

    for(int i=0; i<Z; i++){
        for(int j=0; j<Y; j++){
            for(int k=0; k<X; k++){
                scanf("%d", &tomato[i][j][k]);
                if(tomato[i][j][k]==1){
                    queue[rear].z = i;
                    queue[rear].y = j;
                    queue[rear].x = k;
                    rear++;
                }
                else if(tomato[i][j][k]==0){
                    nonRipe+=1;
                }
            }
        }
    }

    // 처음부터 안 익은 게 하나도 없다면 0 출력
    if (nonRipe == 0) {
        printf("0\n");
        return 0;
    }

    bfs();
    if(nonRipe>0){
        printf("-1\n");
        return 0;
    }
    // for(int i=0; i<Z; i++){
    //     for(int j=0; j<Y; j++){
    //         for(int k=0; k<X; k++){
    //             scanf("%d", &tomato[i][j][k]);
    //             if(tomato[i][j][k]==0){
    //                 printf("-1\n");
    //                 return 0;
    //             }
    //         }
    //     }
    // }
    /*
    tomato는 1부터 시작하기 때문에,
    처음에 이미 익어있던 tomato 주변 토마토들이 익을 때의 시간은 2이다(근데 여기서부터 1로 시작해야 함)
    따라서 1씩 시간이 밀려서 더해졌으므로, 마지막에 시간 출력할 때 -1 해주면 딱 맞음
    */
    printf("%d\n", time-1);
    
    return 0;
}