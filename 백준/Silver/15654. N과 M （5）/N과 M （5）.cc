#include <stdio.h>
#include <stdlib.h>
int savedNum[9];
int visited[9]; // num와 같은 인덱스를 가짐(1이 아닌 큰 단위 숫자이더라도, nums와 같이 가면 ㄱㅊ)
int nums[9]; // 정렬된 배열

int cmp(const void* a, const void* b){
    int x = *(int*)a;
    int y = *(int*)b; 

    if(x>y) return 1;
    else if(x<y) return -1;
    else return 0;
}
void backtraking(int cur_depth, int fixed_depth, int R){ // 현재 깊이, 내려가야 하는 총 깊이, 주어진 숫자의 개수 R
    if(cur_depth==fixed_depth){
        for(int i=0; i<fixed_depth; i++){
            printf("%d ", savedNum[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0; i<R; i++){
        if(visited[i]==1) continue; // 이미 선택된 숫자라면..
        savedNum[cur_depth] = nums[i];
        visited[i]=1;
        backtraking(cur_depth+1, fixed_depth, R);
        visited[i]=0;
    }
}
int main() {
    int N,M;
    scanf("%d %d", &N, &M); // N개의 숫자 중 M개를 골라 수열을 만들어야 한다.
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    qsort(nums, N, sizeof(int), cmp);
    backtraking(0,M,N);
    return 0;
}