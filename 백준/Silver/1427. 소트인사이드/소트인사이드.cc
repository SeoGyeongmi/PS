#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int countingArr[10] ={0};
    char str[11];

    scanf("%10s", str);
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if (str[i] < '0' || str[i] > '9') continue;
        int num = str[i] - '0';
        countingArr[num]++;
    }

    for(int i=9; i>=0; i--){
        for(int j=0; j<countingArr[i]; j++){
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}
/*
counting sort
- 변수
char countingArr[10] = {0}

1. 문자열로 스캔
한자리(char)씩 저장해서 integer숫자로 바꾼다.
숫자 하나당 범위가 0~9(총 10개)이므로, counting 정렬 가능

2. 문자열 크기만큼 다음을 반복한다.
3. 문자 하나하나 씩 integer로 변환 후, countingArr[현재 수]++

내림차순으로 출력해야 하므로, 
인덱스 9~0 순으로 다음을 반복한다.
countingArr[현재 index]가 0이 아니면,
countingArr[현재 index]의 수 만큼 현재 index를 출력한다.
*/