#include <stdio.h>

int main() {
    int daysMount[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    char dayOfWeek[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int x,y,i;

    scanf("%d %d", &x, &y);

    for(i=0; i<x-1; i++){ // 입력한 달이 1월이면 이 for문이 실행되지 않아도 된다.
        y += daysMount[i];
    }

    printf("%s", dayOfWeek[y%7]);
    return 0;
}