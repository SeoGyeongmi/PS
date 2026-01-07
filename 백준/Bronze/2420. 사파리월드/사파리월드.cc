#include <stdio.h>

int main(){
    long long a,b;
    scanf("%lld %lld", &a, &b);

    long long gap;
    if(a<b) gap = b-a;
    else gap = a-b;

    printf("%lld\n", gap);
    return 0;
}