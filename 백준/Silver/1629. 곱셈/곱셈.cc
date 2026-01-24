#include <stdio.h>

int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    long long result = 1 % C;
    long long base = A % C;

    while (B > 0) {
        if (B & 1) result = (result * base) % C;
        base = (base * base) % C;
        B = B/2;
    }

    printf("%lld\n", result);
    return 0;
}
