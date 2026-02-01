#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    
    int A,B;
    for(int i=0; i<num; i++){
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i+1, A+B);
    }
    return 0;
}