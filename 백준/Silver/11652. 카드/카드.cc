#include <stdio.h>
#include <stdlib.h>
// -2^63-1 < x < 2^63-1 이라는 범위를 가진 long long 변수를 사용해야 한다.
/*
counting sort로는 모든 정수를 index로 저장하기에는 메모리 낭비가 심하다. 메모리 자살행위
일단은 모든 변수를 배열에 저장한다.
qsort를 통해 모든 수를 정렬한다. 
이전과 같은수라면 그 수의 count를 ++
현재 수가 이전수와 다르다면
- 지금까지 쌓인 count와 max_count를 비교
만약 count > max_count라면 
    max_count = count
    max_num = 현재 수 (가장 많이 나온 숫자를 현재 숫자로 변경한다.)
수를 현재 수로 변경.
count=1로 초기화
다음 수로 넘어감
- 필요한 변수
모든 수를 저장할 변수
가장 많이 나온 정수를 저장할 변수 
가장 많이 나온 정수의 빈도수(몇개가 있는지)를 저장할 변수

정렬 해야함

일단 반복문 전에 최대 count, 최대 count를 가진 수를 다음과 같이 정의한다.
best_count = 0;
best_num = 0;

current_count=1;
current_num=n[i];

반복문을 통해 다음을 반복한다.(i=1부터 시작, i<배열 길이, i++)
    current_num와 n[i]가 같은 수인지 판단
        같은 수라면, 
            corrent_count++;
            continue;
        다른 수라면, 
            best_count < current_count라면,
                best_count = current_count;
            current_count=1;
            current_num[i];
*/
int cmp(const void* a, const void*b){
    long long x = *(long long*)a;
    long long y = *(long long*)b;

    if(x>y) return 1;
    else if(x<y) return -1;
    else return 0;
}

int main() {
    long long cards[100000];
    // 입력받을 카드 수 scanf
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", &cards[i]); // 카드 n번 입력받기
    // 입력받은 수 정렬
    qsort(cards, n, sizeof(long long), cmp);
    // 개수 세기 반복문
    int best_count = 0;
    long long best_num = cards[0];

    int current_count=1;
    long long current_num= cards[0];
    for(int j=1; j<n; j++){
        if(current_num==cards[j]){ // 현재 검사하는 수가 이전 수와 같으니
            // printf("이전 수와 같음. 현재 수 : %lld\n", cards[j]);
            current_count++; // 카운트 증가
            continue; // 밑 과정은 필요 없음
        }
        else {// 다른 수라면
            // printf("이전 %d과 다른 수 %lld\n", current_num, cards[j]);
            
            if(best_count < current_count){
                // printf("best_count(%d) < current_count(%d) 이므로 현재 best_num -> %lld\n", best_count, current_count, best_num);
                best_count = current_count;
                best_num = current_num;
            }
            current_count=1; // 현재 수도 count 해주어야 함
            current_num = cards[j];
        }
    }
    if(current_count > best_count) {
        best_count = current_count;
        best_num = current_num;
    }
    // best_num 출력
    printf("%lld", best_num);
    return 0;
}