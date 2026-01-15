#include <stdio.h>

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int mat1[100][100];
    int mat2[100][100];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &mat2[i][j]);
            mat1[i][j] += mat2[i][j];
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }
    return 0;
}