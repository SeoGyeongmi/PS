#include <stdio.h>

#define MAX 100
int main() {

    int basNum, reverseCount;
    int basket[MAX] = {0};
    int b1, b2;
    int temp;
   
    scanf("%d %d", &basNum, &reverseCount);
    for(int i=0; i<basNum; i++){
        basket[i] = i+1;
    }
    for(int i=0; i<reverseCount; i++){
        scanf("%d %d", &b1, &b2);
        temp = basket[b1-1];
        // printf("temp : %d / basket[%d](%d)\n", temp, b1-1, basket[b1-1]);
        basket[b1-1] = basket[b2-1];
        // printf("basket[%d] : %d / basket[%d](%d)\n", b1-1, basket[b1-1], b2-1, basket[b2-1]);
        basket[b2-1] = temp;
        // printf("result : ");
        // for(int j=0; j<basNum; j++){
        //     printf("%d ", basket[j]);
        // }
        // printf("\n");
    }

    for(int i=0; i<basNum; i++){
        printf("%d ", basket[i]);
    }
    return 0;
}

/*
- 변수

- 입력
    바구니 개수 basNum / 바꿀 횟수(반복 횟수)
    바꿀 횟수 만큼 반복하여 입력
        바꿀 공 1 / 바꿀 공2 (서로 값을 바꿀 거임)

- 계산
    입력 받자마자
    temp = b1
    b1 = b2;
    b2 = temp;
*/