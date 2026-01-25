#include <stdio.h>

int count;
int eCol[16]={0}; // 행
int eDiaA[33]={0}; // 대각선
int eDiaB[33]={0}; // 최대 N(8)*2 -1
void findPalce(int N, int curr_Q) {
    if(N == curr_Q){ // 현재까지 놓은 Q의 개수와 목표 Q의 개수가 같으면 return;
        count++;
        return;
    }
    int row = curr_Q;
    for(int col=0; col<N; col++){
        if(eCol[col] || eDiaA[col+row]==1 || eDiaB[col-row+(N-1)]) {
            continue;
        }
         // 여기까지 내려왔다면, Q를 하나 놓을 수 있는 상태
        eCol[col]=1;
        eDiaA[col+row]=1; 
        eDiaB[col-row+(N-1)]=1;
        // printf("현재 Q : %d\n", curr_Q+1);
        // 다음 행으로 간다.(놓은 Q의 개수도 1증가.) 놓은 Q의 개수가 곧 행의 번호로 볼 수도 있음.
        findPalce(N, curr_Q+1);
        // 탐색 종료 시 원복
        eCol[col]=0;
        eDiaA[col+row]=0;
        eDiaB[col-row+(N-1)]=0;
    }

}
int main() {
    int fixed_Q;
    count=0;
    scanf("%d", &fixed_Q);
    findPalce(fixed_Q, 0);
    printf("%d\n", count);
    return 0;
}