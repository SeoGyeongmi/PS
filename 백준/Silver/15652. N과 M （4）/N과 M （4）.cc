#include <stdio.h>
int saveNum[9]={0};
void backTracking(int cur_dep, int R, int fixed_dep){ // 현재 depth, 고를 수 있는 숫자의 범위, 정해진 depth
    if(cur_dep>fixed_dep) {
        for(int i=1; i<=fixed_dep; i++){ // 정해진 depth까지만 출력하면 됨.
            printf("%d ", saveNum[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1; i<=R; i++){
        if(i >= saveNum[cur_dep-1]){
            saveNum[cur_dep]=i;
            backTracking(cur_dep+1, R, fixed_dep);
        }
    }
}
int main() {
    int cur_dep=1;
    int R, fixed_dep;
    scanf("%d %d", &R, &fixed_dep);

    backTracking(cur_dep, R, fixed_dep);
    return 0;
}

