#include <stdio.h> 
#include <math.h>
// int count=0;

void move(int N, int s, int f){
    if(N>1){
        move(N-1, s, 6-s-f);
    }
    printf("%d %d\n", s,f);// 실제로 원반을 옮기는 구간
    // count++; 
    if(N>1){
        move(N-1, 6-s-f, f);
    }
    // if(N==1) printf("%d\n", count);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int count = pow(2,N)-1;
    printf("%d\n", count);
    move(N, 1, 3);
    return 0;
}