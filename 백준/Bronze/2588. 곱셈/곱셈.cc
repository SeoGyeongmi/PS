#include <stdio.h>

int main(void) {
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);

    int ans1 = B % 10;         // 1의 자리
    int ans2 = (B / 10) % 10;  // 10의 자리
    int ans3 = B / 100;        // 100의 자리

    printf("%d\n", A * ans1);
    printf("%d\n", A * ans2);
    printf("%d\n", A * ans3);
    printf("%d\n", A * B);

    return 0;
}
