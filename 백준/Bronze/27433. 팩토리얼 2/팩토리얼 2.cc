#include <stdio.h>

long long factorial(long long n){
    if(n==0) return 1;
    else return n*factorial(n-1);
}

int main() {
    long long n;

    scanf("%lld", &n);

    printf("%lld\n", factorial(n));
    return 0;
}