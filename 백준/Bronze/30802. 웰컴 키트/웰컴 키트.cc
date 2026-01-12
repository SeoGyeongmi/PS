#include <stdio.h>

int main(void) {
    long long N;
    long long S, M, L, XL, XXL, XXXL;
    long long T, P;

    scanf("%lld", &N);
    scanf("%lld %lld %lld %lld %lld %lld", &S, &M, &L, &XL, &XXL, &XXXL);
    scanf("%lld %lld", &T, &P);

    long long shirts = 0;
    long long a[6] = {S, M, L, XL, XXL, XXXL};

    for (int i = 0; i < 6; i++) {
        shirts += (a[i] + T - 1) / T;
    }

    printf("%lld\n", shirts);
    printf("%lld\n", N / P);
    printf("%lld\n", N % P);

    return 0;
}
