#include <stdio.h>

#define MAX 100
int main() {
    /*
    - 입력
        바구니 개수 / 입력할 줄의 개수
        i j k (i~j:바구니 개수, k : 공 번호)

    - 계산
        basket[MAX] : 바구니 (0으로 초기화)
        countLine : 줄 개수

        countLine만큼 반복
            temp_i ~ temp_j 까지 반복
                k로 바꾸기
    */
   int basSize, lineSize;
   int start_b, fin_b, ballNum;
   int basket[MAX] ={0};
   scanf("%d %d", &basSize, &lineSize);
   for(int i=0; i<lineSize; i++){
        scanf("%d %d %d", &start_b, &fin_b, &ballNum);
        // printf("입력된 숫자 : %d %d %d\n", start_b, fin_b, ballNum);
        for(int j=start_b-1; j<fin_b; j++) {
            basket[j] = ballNum;
            // printf("num that change : basket[%d] -> %d\n", j, ballNum);
        }
   }

   for(int i=0; i<basSize; i++){
    printf("%d ", basket[i]);
   }
    return 0;
}