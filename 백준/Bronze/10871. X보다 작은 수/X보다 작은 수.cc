#include <stdio.h>

#define MAX 10000
int main() {
    /*
    입력받는 숫자 배열 변수 = inputs
    비교 수보다 큰 숫자 저장하는 변수 = biggers[입력받는개수]
    처음 입력받는 숫자 : 입력받는 숫자 개수 / 비교수 X
    그 다음 입력받는 수열 : 입력받은 개수(크기)만큼 입력받음
    
    inputs 크기만큼 반복
        input[i] > X이면 biggers에 저장하기
        biggers index++

    biggers에 저장된 숫자 모두 출력하기(index만큼 반복)
    */
    int size, num;
    int bindex=0;
    int inputs[MAX] = {0};
    int biggers[MAX] = {0};

    scanf("%d %d", &size, &num);
    for(int i=0; i<size; i++){
        scanf("%d", &inputs[i]);
        if(inputs[i]<num){
            biggers[bindex] = inputs[i];
            // printf("저장 : %d\n", biggers[bindex]);
            bindex++;
        }
    }

    // 작은 수들 모두 출력
    for(int i=0; i<bindex; i++){
        printf("%d ", biggers[i]);
    }

    return 0;
}