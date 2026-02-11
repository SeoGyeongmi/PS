#include <stdio.h>

int main() {
    int A, B, C;
    long long X;
    int cnt[10] = {0};

    scanf("%d %d %d", &A, &B, &C);

    X = (long long)A * B * C;

    if (X == 0) {
        cnt[0] = 1;
    } else {
        while (X > 0) {
            cnt[X % 10]++;
            X /= 10;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", cnt[i]);
    }

    return 0;
}