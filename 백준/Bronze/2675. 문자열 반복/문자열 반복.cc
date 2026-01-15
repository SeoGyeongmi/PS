#include <stdio.h>
#include <string.h>
#define MAX 1000
int main() {
    int count;
    int repeat;
    char str[1000];
    // 첫 줄은 integer로 받기
    scanf("%d", &count);
    // 그 수 만큼 다음을 반복한다.
    for(int i=0; i<count; i++){
    // 각 테스트 케이스는 integer(반복횟수), string(문자열)로 받기
        scanf("%d %s", &repeat, str);
    // 각 문자를 횟수 만큼 반복하기
        for(int j=0; j<strlen(str); j++){
            for(int k=0; k<repeat; k++) printf("%c", str[j]);
        }
        printf("\n");
    }
    return 0;
}