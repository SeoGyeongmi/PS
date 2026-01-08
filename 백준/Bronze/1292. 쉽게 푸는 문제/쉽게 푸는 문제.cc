#include <stdio.h>

int main(){
    int A,B;
    int sum=0; 
    int index=1;
    scanf("%d %d", &A, &B);
    for(int i=1; i<=B; i++){
        for(int j=1; j<=i; j++){
            if(index>=A && index<=B){
                sum += i;
            }
            index++;
        }
    }

    printf("%d\n", sum);
    return 0; 
}