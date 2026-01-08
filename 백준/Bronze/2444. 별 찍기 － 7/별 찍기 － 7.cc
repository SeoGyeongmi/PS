#include <stdio.h>

int main() {

    int size;
    int blank, star;
    scanf("%d", &size);

    blank = size-1;
    star = 1;
    for(int i=0; i<2*size-1; i++){
        if(i<size){
            // 공백 출력 반복문 ' 출력이 무한 반복되는 이유?
            for(int j=blank; j>0; j--) printf(" ");
            // 별 출력 반복문
            for(int j=0; j<star; j++) printf("*");

            printf("\n");
            //공백, 별 값 조절
            if(i==size-1) continue;
            blank--;
            star += 2;
        }
        else{
            if(i==size) {
                blank++;
                star-=2;
            }
            for(int j=0; j<blank; j++) printf(" ");
            for(int j=star; j>0; j--) printf("*");
             printf("\n");
            //공백, 별 값 조절
            blank++;
            star-=2;
        }
        
    }
    return 0;
}
/*

*/