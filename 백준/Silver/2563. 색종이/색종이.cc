#include <stdio.h>

int main() {
    int pixel[100][100]={0};
    int num;
    int total=0;
    scanf("%d", &num);

    while(num--){ // 입력한 색종이의 개수만큼 반복하고 끝남
        int x,y;
        scanf("%d %d", &x, &y);

        for(int j=x; j<(x+10); j++)
            for(int i=y; i<(y+10); i++)
                pixel[j][i]=1;
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            total += pixel[i][j];
            // printf("%d", pixel[i][j]);
        }
        //printf("\n");
    }

    printf("%d\n", total);



    return 0;
}