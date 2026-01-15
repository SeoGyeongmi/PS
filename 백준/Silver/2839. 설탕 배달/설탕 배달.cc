#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    // 5kg 봉지를 최대로 쓰는 개수부터 시작
    int maxFive = N / 5;

    // 5kg 봉지를 하나씩 줄여가며 확인
    for (int five = maxFive; five >= 0; five--) {
        int remain = N - (five * 5);

        // 남은 무게가 3으로 딱 나눠지면 성공
        if (remain % 3 == 0) {
            int three = remain / 3;
            printf("%d\n", five + three);
            return 0;
        }
    }

    // 끝까지 못 맞추면 불가능
    printf("-1\n");
    return 0;
}
