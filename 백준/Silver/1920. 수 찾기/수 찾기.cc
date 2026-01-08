#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

/*
Search문제 :
찾는 과정을 좀 더 효율적으로 해야함
선형적으로 다 훑으면 X, 반절씩 날릴 수 있도록 bineary search하기
bineary search를 하기 위해서는 일단 정렬(sort)필요함

배열도 그때그때 할당한다. -> malloc
- qsort(1,2,3,4) :
1 - 정렬할 배열의 첫번째 포인터
2 - 배열의 개수
3 - 배열 하나의 크기
4 - 비교함수
    비교만 해야하므로(값을 바꾸면 X) const로 받는다.
    : qsort가 오름차순으로 정렬할 지, 내림차순으로 할 지는 이 함수에 따라서 달렸다.
    만약 오름차순(1,2,3,..)으로 정렬하고 싶으면, a(큰 수)가 b(작은 수)보다 앞에 있다면 음수를 반환하도록,
    뒤에 있다면 양수를 반환하도록 하면 된다.
    - 정리
    만약 비교함수 cmp가 있고, 오름차순으로 정렬하고 싶다면 a-b 를 return(앞의 a가 더 크면 음수를 return)하고, 
                           내림차순으로 정렬하고 싶다면 b-a를 return(앞의 a가 더 크면 양수,정상임을 return

- int binary_search(int arr[], int n, int x)
정렬이 완료되면 이진탐색을 할 수 있다.
위 함수는 다음과 같은 역할을 한다.
: 정렬된 배열 arr 안에 값 x가 있으면 1, 없으면 0 반환
int left = 0 -> 탐색 시작 index
int right = n - 1 -> 탐색 끝 인덱스
- 처음엔 배열 전체를 탐색 대상으로 둔다.

while(left <= right) 아직 확인할 구간이 남아있다면 반복
중간 인덱스를 계산한다.(탐색의 기준이 될 부분)
arr[index] == x 중간값이 같으면 끝(바로 종료)

가운데 값이 x보다 더 작을 때 가운데 기준 왼쪽은 다 작은 것
오른쪽만 탐색하면 된다.
else if (arr[mid] < x)
    left = mid + 1;

클 때는
else
    right = mid - 1;

*/
int cmp(const void *a, const void *b){ // 오름차순 정렬을 위한 비교 함수
    int x = *(int*)a;
    int y = *(int*)b;
    if(x>y) return 1;
    if(x<y) return -1;
    return 0; // 같다면 0 return
}

int binary_search(int arr[], int n, int x){
    int left=0; // 탐색 시작 위치
    int right=n-1; // 탐색 끝 위치

    while(left <= right) {
        int mid = (left+right) / 2;

        if(arr[mid] == x) return 1; // 중간에서 바로 찾음. 사실상 찾는 수가 중간으로 올 때까지 left, right를 조절한다.
        else if(arr[mid] < x) left = mid + 1; // 탐색 시작 위치를 중간 바로 오른쪽으로
        else right = mid-1; // 만약 중간값이 더 크다면 탐색 끝 위치를 중간 직전 인덱스로 옮긴다.
    }
    return 0;
}

int main() {
    int n,m;
    scanf("%d", &n);
    int *A = (int*) malloc(sizeof(int)*n); // n개의 integer숫자가 들어갈 수 있을만한 크기를 할당한다.
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]); // A[i]  ≡  *(A + i)
    }

    // 숫자들을 모두 입력받았으면 정렬하도록.
    qsort(A, n, sizeof(int), cmp);

    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int x;
        scanf("%d", &x);
        printf("%d\n", binary_search(A,n,x));
    }

    return 0;
}