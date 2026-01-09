#include <stdio.h>
#include <stdbool.h>


int main() {
    int h,m;
    int temp; // 45를 뺀 값을 저장하는 변수
    bool change = false; // temp가 0분 미만이 되었는지?
    scanf("%d %d", &h, &m);

    if(m < 45) {
        change = true;
        temp = 45 - m;
        m = 60 - temp;
    }
    
    if(change){
        if(h == 0)
            h = 23;
        else
            h--;
    }
    else m = m-45;

    printf("%d %d", h, m);
    return 0;
}