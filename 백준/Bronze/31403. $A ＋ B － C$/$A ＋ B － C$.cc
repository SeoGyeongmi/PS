#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int A,B,C;
    char temp[5];
    char ApB[10];
    scanf("%d %d %d", &A, &B, &C);
    snprintf(ApB, sizeof(ApB), "%d", A);
    snprintf(temp, sizeof(temp), "%d", B);
    strcat(ApB, temp);

    printf("%d\n", A+B-C);
    printf("%d\n", atoi(ApB)-C);
    return 0;
}