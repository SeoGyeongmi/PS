/*
시, 분을 입력받는다.
요리 시간을 입력받는다.

(분 + 요리시간) 값 변수에 따로 저장한다.

만약 (분 + 요리시간)이 60을 넘으면,
    만약 시가 23시라면
        시값을 (분 + 요리시간)/60-1값으로 할당한다.
(분 + 요리시간)/60 값을 시에 더하고,
(분 + 요리시간)%60 값을 분에 더한다.
 
만약 (분 + 요리시간)이 60을 넘지 않는다면,
그냥 분에 요리시간을 더한다.
*/
#include <stdio.h>

int main() {
    int h,m;
    int cookingTime;
    int added_m=0;
    int added_h=0;

    scanf("%d %d", &h, &m);
    scanf("%d", &cookingTime);

    added_m = m + cookingTime;
    added_h = h + added_m/60;

    
    h = added_h % 24;
    m = added_m % 60;

    printf("%d %d\n", h, m);
    return 0;
}