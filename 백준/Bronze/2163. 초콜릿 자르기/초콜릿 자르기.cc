#include <stdio.h>

int main() {
    int w, h;
    int w_count=0, h_count=0;
    int splitCount=0;
    scanf("%d %d", &w, &h);
    int fw = w;
    // 입력받는 숫자는 1~300(0이 아님)이라고 가정
    while(w>1){
        w--;
        w_count++;
    }
    while(h>1){
        h--;
        h_count++;
    }
    h_count = h_count * fw;
    // printf("w_count : %d, h_count : %d\n", w_count, h_count);
    splitCount = w_count + h_count;
    printf("%d", splitCount);
    
    return 0;
}
/*

*/