#include <stdio.h>

int main() {
    int least[1000001];
    int N;

    scanf("%d", &N);
    least[1] = 0;
    least[2] = 1;
    least[3] = 1;

    for(int i=4; i<=N; i++){
        least[i] = least[i-1] + 1;

        if(i%3==0){
            int cmp = least[i/3]+1;
            if(cmp < least[i]) 
                least[i] = cmp;
        }
        if(i%2==0){
            int cmp = least[i/2]+1;
            if(cmp < least[i]) 
                least[i] = cmp;
        }
    }

    printf("%d", least[N]);
    return 0;
} 

/*
일단 현재 숫자의 최소 연산 횟수를 다음과 같이 정의한다.
least[1] = 0
least[2] = 1
least[3] = 1
i=4 부터는 다음을 반복한다.
least[i] = least[i-1]+1

만약 i가 3으로 나누어진다면
    - least[i] = min((위에서 미리 계산한)least[i], least[i/3]+1)
만약 i가 4로 나누어진다면
    - least[i] = min((위에서 미리 계산한)least[i], least[i/4]+1)
*/