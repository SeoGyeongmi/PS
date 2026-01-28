/*
+ qsort 위한 cmp 함수 구현

최대 1000 길이의 str을 입력받는다.

미리 접미사 제거된 배열에 대한 메모리를 할당해 놓는다.

문자열 길이 len에 대해 다음을 반복한다.
    i는 0~(문자열 끝)len-1까지 +1 씩 증가
    문자열 i 이후의 문자열을 새로운 문자열에 저장한다.

qsort(배열의 첫번째 포인터, 배열 개수, 배열 하나의 크기, 비교함수)


순서대로 출력
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;
    return strcmp(s1, s2);
}

int main() {
    char s[1001];
    scanf("%s", s);

    int len = strlen(s);

    // 접미사 포인터 배열
    char *suffix[1000];

    // 각 접미사의 시작 위치를 저장
    for (int i = 0; i < len; i++) {
        suffix[i] = s + i;
    }

    // 사전순 정렬
    qsort(suffix, len, sizeof(char *), cmp);

    // 출력
    for (int i = 0; i < len; i++) {
        printf("%s\n", suffix[i]);
    }

    return 0;
}
