#include <stdio.h>
#include <string.h>
int main() {
    // int i;
    char str[100] = {0};
    int flag=0;
    scanf("%s", str);
    int size = strlen(str);
    int checkCount=strlen(str)/2;
    for(int i=0; i<checkCount; i++){
        // printf("size : %d\n", size);
        // printf("검사할 문자 : %c <-> %c\n", str[i], str[size-i-1]);
        if(str[i] != str[size-i-1]) {
            flag=1;
            break;
        }
    }
    if(flag){
        printf("0");
    }
    else printf("1");
    return 0;
}
/*
1. 문자열 입력받기
2. i , size-i-1 / index끼리 검사
3. 만약에 i가 size/2에 도달하면 검사 중단
*/