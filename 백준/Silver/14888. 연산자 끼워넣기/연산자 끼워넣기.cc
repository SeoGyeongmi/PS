#include <stdio.h>
#include <limits.h> // 최대, 최소값 초기화용

int N;
int num[105]; // 숫자들은 고정
int op[4];    // 연산자 개수: 0(+), 1(-), 2(*), 3(/)
int max_res = INT_MIN; 
int min_res = INT_MAX;

// idx: 현재 몇 번째 연산자를 고를 차례인지 (또는 몇 번째 숫자를 보고 있는지)
// sum: 지금까지 계산된 결과값
void dfs(int idx, int sum) {
    // [1] 종료 조건: 모든 숫자를 다 썼을 때 (연산자는 N-1개 사용됨)
    if (idx == N) {
        if (sum > max_res) max_res = sum;
        if (sum < min_res) min_res = sum;
        return;
    }

    // [2] 백트래킹 로직: 4가지 연산자를 하나씩 시도해봄
    
    // (1) 덧셈이 남아있다면?
    if (op[0] > 0) {
        op[0]--; // 개수 하나 쓰고
        dfs(idx + 1, sum + num[idx]); // 다음 숫자를 더해서 넘김
        op[0]++; // (복귀) 개수 복구
    }

    // (2) 뺄셈이 남아있다면?
    if (op[1] > 0) {
        op[1]--;
        dfs(idx + 1, sum - num[idx]);
        op[1]++;
    }

    // (3) 곱셈이 남아있다면?
    if (op[2] > 0) {
        op[2]--;
        dfs(idx + 1, sum * num[idx]);
        op[2]++;
    }

    // (4) 나눗셈이 남아있다면?
    if (op[3] > 0) {
        op[3]--;
        dfs(idx + 1, sum / num[idx]); // C언어는 알아서 몫만 취함
        op[3]++;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &num[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &op[i]);

    // 첫 번째 숫자(num[0])는 이미 계산 결과에 넣고, 인덱스 1부터 시작!
    dfs(1, num[0]);

    printf("%d\n", max_res);
    printf("%d\n", min_res);

    return 0;
}