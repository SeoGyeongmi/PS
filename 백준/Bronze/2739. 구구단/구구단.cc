#include <stdio.h>

int main() {
    /*
    9줄 출력 (9번 반복)
    입력받은 숫자 * i = 그 결과
    */
   int n;
   scanf("%d", &n);
   for(int i=1; i<=9; i++){
    printf("%d * %d = %d\n", n, i, n*i);
   }
    return 0;
}