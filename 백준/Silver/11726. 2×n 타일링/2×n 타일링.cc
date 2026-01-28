#include <stdio.h>

int main() {
    int n;
    long long way[1001]; 
    scanf("%d", &n);

    way[0]=0;
    way[1]=1;
    way[2]=2;

    for(int i=3; i<=n; i++){
        way[i] = way[i-1] + way[i-2];
        if(way[i] >= 10007) way[i]%=10007;
    }

    printf("%lld\n", way[n]%10007);

    return 0;
}