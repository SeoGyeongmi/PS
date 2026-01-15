#include <stdio.h>
#include <stdlib.h>

int main() {
    char num1[4]={0};
    char num2[4]={0};
    int max=0;
    // scanf시 char로 받기
    // scanf(%s %s) -> scanf로 받으면 공백에 따라서 구분되기 때문에 두 번 받아줘야 함
    scanf("%s %s", num1, num2);
    // 확인용
    //printf("before : %s %s\n", num1, num2);
    // 세자리 수로 길이가 고정되어있으므로, 첫번째와 세번째를 서로 바꾸면 됨. 
    char temp;

    temp = num1[0];
    num1[0] = num1[2];
    num1[2] = temp;

    temp = num2[0];
    num2[0] = num2[2];
    num2[2] = temp;

    if(atoi(num1) > atoi(num2)) max = atoi(num1);
    else max = atoi(num2);

    printf("%d", max);
    // 바꾼 후의 세자리 수를 integer로 바꾼 수 그 크기를 비교한다.
    // 더 큰 수를 출력한다.
    return 0;
}
/*
// scanf시 char로 받기
// scanf(%s %s) -> scanf로 받으면 공백에 따라서 구분되기 때문에 두 번 받아줘야 함
// 세자리 수로 길이가 고정되어있으므로, 첫번째와 세번째를 서로 바꾸면 됨. 
// 바꾼 후의 세자리 수를 integer로 바꾼 수 그 크기를 비교한다.
// 더 큰 수를 출력한다.
*/