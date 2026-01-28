#include <stdio.h>

int main() {
    int n;
    int way[1001];

    scanf("%d", &n);

    way[1] = 1;
    way[2] = 3;
    for(int i=3; i<=n; i++){
        way[i] = way[i-1] + (way[i-2]*2);
        if(way[i]>=10007) way[i] %= 10007;
    }
    printf("%d\n", way[n]);
    return 0;
}