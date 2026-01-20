#include <stdio.h>

int main() {
    long long A, B;
    scanf("%lld %lld", &A, &B);

    int cnt = 0;

    while (B > A) {
        if (B % 10 == 1) {
            B /= 10;
        } else if (B % 2 == 0) {
            B /= 2;
        } else {
            printf("-1\n");
            return 0;
        }
        cnt++;
    }

    if (B == A)
        printf("%d\n", cnt + 1);
    else
        printf("-1\n");

    return 0;
}