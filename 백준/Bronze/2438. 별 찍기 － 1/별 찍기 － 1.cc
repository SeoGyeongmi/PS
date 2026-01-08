#include <stdio.h>

int main() {
    /*
    크기를 입력받는다.
    크기만큼 반복
        i 만큼 별을 한 줄에 다 찍는다.
        줄바꿈
    */
    int size;
    scanf("%d", &size);

    for(int i=1; i<=size; i++){
        for(int j=1; j<=i; j++) printf("*");
        printf("\n");
    }
    return 0;
}