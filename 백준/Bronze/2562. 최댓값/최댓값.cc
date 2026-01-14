#include <stdio.h>

int main() {
    int max=0;
    int maxIndex;
    int n[9]={0};
    // 입력엔 9줄의 값이 주어진다.
    // 그 9개의 숫자 중 최댓값을 찾고, 그 최댓값이 몇번째 숫자였는지도 출력한다.
    for(int i=0; i<9; i++){
        scanf("%d", &n[i]);
        if(n[i]>max){
            max = n[i];
            maxIndex = i;
        }
    }

    printf("%d\n%d", max, maxIndex+1);
    
    
    return 0;
}
/*

*/