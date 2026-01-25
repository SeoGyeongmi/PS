#include <stdio.h>

int main() {
    int ic; // iterate count
    int n;
    int way[11]; // available from 0 to 10

    way[1] = 1; // 1
    way[2] = 2; // 2 , 1+1
    way[3] = 4; // 3, 1+2, 2+1, 1+1+1

    scanf("%d", &ic);
    for(int i=0; i<ic; i++){
        scanf("%d", &n);
        for(int j=4; j<=n; j++){
            // j-3에는 3을, j-2에는 2를, j-1엔 1을 각각 더해주면 된다.
            way[j] = way[j-3] + way[j-2] + way[j-1];
        }
        printf("%d\n", way[n]);
    }
    return 0;
}