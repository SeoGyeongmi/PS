#include <stdio.h>

int main() {
    /*
    SIZE입력받기
    초기 공백 개수는 size-1
    초기 별 개수는 1
    size 만큼 반복하기
        공백개수--
        별 개수++
        줄바꿈 출력
    */
    int size;
    int i,j;
    scanf("%d", &size);

    int star=1;
    int blank=size-1;
    for(i=0; i<size; i++){
        for(j=0; j<blank; j++){
            printf(" ");
        }
        for(j=0; j<star; j++){
            printf("*");
        }
        printf("\n");
        blank--;
        star++;
    }
    return 0;
}