#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
    int x = *(int*)a;
    int y = *(int*)b;

    if(x>y) return 1;
    if(x<y) return -1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int *A = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    
    qsort(A,n,sizeof(int), cmp);

    for(int i=0; i<n; i++){
        printf("%d\n", A[i]);
    }
    return 0;
}
/*
첫째 줄에 입력 되는 숫자의 개수가 주어진다. 
그 개수 크기 만큼 동적으로 메모리를 할당한다.
qsort(배열의 첫번째, 배열의 개수, 배열 원소 하나의 크기, 비교함수),
오름차순(1,2,3,..)으로 정렬한다. -> cmp 함수가 a가 크면 -1, 작으면 1을 return 하도록
정렬된 배열을 출력한다.
*/