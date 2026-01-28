#include <stdio.h>
#include <stdlib.h>
/*
1. 배열에 들어갈 수를 입력받는다.
2. 정렬 후 출력할 순서숫자를 입력받는다.
3. 배열에 들어갈 원소들을 입력받는다. -> 반복문
4. 정렬한다.
5. 정렬 후 배열의 (순서숫자-1)번째 숫자를 출력한다.
*/
int cmp(const void* a, const void*b){
    int x = *(int*)a;
    int y = *(int*)b;

    if(x>y) return 1;
    if(x<y) return -1;
    return 0;
}
int main() {
    int n;
    int seqeunce;
    scanf("%d %d", &n, &seqeunce);

    int *arr =  (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    // for(int i=0; i<n; i++){
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    printf("%d", arr[seqeunce-1]);
    return 0;
}