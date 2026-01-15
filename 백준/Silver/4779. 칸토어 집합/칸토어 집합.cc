#include <stdio.h>
#include <math.h>
char str[531442]; // 3의 12제곱
// recursive function
// cantore : 중간 부분을 계속해서 공백으로 채운다.
// 만약 n == 1이면 종료
void cantore(int n, int start, int finish){
    if(n==0) return;

    // 구간으로 나눌 단위의 수. ex) n=9이면 단위는 3, n=27이면 단위는 9
    // 중간 부분의 시작지점을 가리키는 index역할도 함.
    int uni = n/3;
     
    cantore(uni, start, start+uni-1);
    for(int i=start+uni; i<start+(uni*2); i++)
        str[i] = ' ';
    cantore(uni, start+(uni*2), finish);
    
}
int main() {
    int N;
    
    while(scanf("%d", &N) != -1){
        N = pow(3,N); // N을 3의 N제곱으로 바꿔줌

        for(int i=0; i<N; i++) // N만큼의 dash 문자열 생성(전역 변수)
            str[i] = '-';
        str[N]='\0';

        cantore(N, 0, N);
        printf("%s\n", str);
    }
    
    return 0;
}