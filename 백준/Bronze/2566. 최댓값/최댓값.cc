#include <stdio.h>

int main() {
    int max = -1;
    int row, col;
    int mat[10][10];

    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            scanf("%d", &mat[i][j]);
            if(mat[i][j] > max){
                max = mat[i][j];
                row = i;
                col = j;
            }
        }
    }

    printf("%d\n%d %d\n", max, row, col);
    return 0;
}