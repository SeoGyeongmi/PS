#include <stdio.h>

char stars[6561][6561]; // 3^8 만큼의 크기

void changeStar(int y, int x, int size) {
    if(size == 1){
        stars[y][x] = '*';
        return;
    }

    int next_size = size / 3; // recursive call에 넘겨 줄 next_size이다.
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1&& j==1) { // 중간이면 공백을 별로 바꾸지 않고 continue;
                continue;
            }

            changeStar(y+i*(size/3), x+j*(size/3), next_size);
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            stars[i][j] = ' ';

    changeStar(0,0,N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%c", stars[i][j]);
        printf("\n");
    }

    return 0;
}