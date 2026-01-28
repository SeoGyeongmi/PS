#include <stdio.h>
int count[100001];
int main() {
    int n, index;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &index);
        count[index]++;
    }
    for(int i=1; i<=10000; i++){ // 받는 수를 그대로 index로 사용하였으므로 i는 1부터 시작한다. N(1 ≤ N ≤ 10,000,000)
        while(count[i]--){
            printf("%d\n", i);
        }   
    }
    return 0;
}
/*
현재 문제는 입력 개수가 1000만, 
입력하는 수 최댓값이 1만 개이다.

따라서 저장하는 배열의 수를 1000만개로 놓기보다.
1만 길이의 배열을 저장하여서, 각 배열의 원소가 몇 번 나왔는지만 기록하면 된다.
예를 들어, 입력된 숫자가 500만, 800만, 40만 이면,
A[0] = 5,000,000
A[1] = 8,000,000
A[2] = 400,000
으로 기록한다.
다음과 같은 방법을 counting sort라고 한다.
*/