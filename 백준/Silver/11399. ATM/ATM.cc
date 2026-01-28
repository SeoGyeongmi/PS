#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
    int x = *(int*)a;
    int y = *(int*)b;

    if(x>y) return 1;
    if(x<y) return -1;
    return 0;
}
int main() {

    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a,n,sizeof(int), compare);

    int nujuk=0;
    int totalTime=0;
    for(int i=0; i<n; i++){
        //printf("totalTime = %d + %d\n", totalTime, a[i]);
        totalTime = totalTime+a[i];
        nujuk += totalTime;
        //printf("계산 후 totalTime : %d\n", totalTime);
    }
    printf("%d", nujuk);
    return 0;
}
/*
첫번째 줄에는 사람의 수가 주어진다.
둘째 줄에는 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다.

사람 수 n을 입력받는다.
int * n 만큼 메모리를 할당받아서 포인터 변수 A에 넣는다.

A를 배열처럼 접근할 수 있다. 반복문을 통해 A[i]에 각 사람의 인출 시간을 스캔받는다.
인출 시간을 오름차순으로 정리한다.(그리디알고리즘)
인출 시간을 totalTime에 누적하여 더한다. totalTime += (totalTime+A[i])
*/