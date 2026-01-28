#include <stdio.h>
#define MODULER 1000000000
int main() {
    int N;
    int dp[101][10];

    scanf("%d", &N);

    dp[1][0] = 0;
    for(int k=1; k<=9; k++) 
        dp[1][k] = 1;

    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            if(j==0) dp[i][j] = dp[i-1][j+1]%MODULER; // 마지막 자리가 0이나 9이면 
            else if(j==9) dp[i][j] = dp[i-1][j-1]%MODULER;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MODULER;

        }
    }

    long long total=0;
    for(int i=0; i<=9; i++){
        total += (dp[N][i]%MODULER);
    }

    printf("%lld\n", total%MODULER);
    return 0;
}