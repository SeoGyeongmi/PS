#include<stdio.h>

int main() {
    int H, W, N; // H: 층수 W: 층에 있는 방 개수 N: n번째 손님
    int tc; // testcase 개수
    int count; // 현재 몇번째 검사중인지

    scanf("%d", &tc);

    count=0;
    for(int t=0; t<tc; t++){ // testcase 만큼 반복
        scanf("%d %d %d", &H, &W, &N);
        count=0;
        for(int i=1; i<=W; i++){
            for(int j=1; j<=H; j++){
                count++;
                if(count==N){
                    if(i<10) printf("%d0%d\n", j,i);
                    else printf("%d%d\n", j,i);
                }
                else if(count>N) continue;
            }
        }
    }
    return 0;
}