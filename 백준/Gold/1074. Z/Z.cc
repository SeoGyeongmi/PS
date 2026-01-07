#include <stdio.h>
#include <math.h>
int sequence;
int findX, findY; // 1 0
void check(int size, int x, int y){ // 찾으면 1, 못 찾으면 0 return
    // if(size==1) return 0;

    int nextSize = size/2;
    if(size!=2){
        // if(!check(nextSize, x, y))
        //     if(!check(nextSize, x, nextSize+y))
        //         if(!check(nextSize, nextSize+x, y))
        //             if(!check(nextSize, nextSize+x, nextSize+y))
        //                 return 0; // 마지막 조각까지 검사했는데 못 찾았으면 0 return;
        if(findX < x+nextSize && findY < y+nextSize){
            check(nextSize, x, y);
        }
        else if(findX < x+nextSize && findY < y+nextSize*2){
            sequence+=1*(nextSize*nextSize); // 뛰어 넘은 크기만큼 곱해줌
            check(nextSize, x, nextSize+y);
        }
        else if(findX < x+nextSize*2 && findY < y+nextSize){
            sequence+=2*(nextSize*nextSize);
            check(nextSize, nextSize+x, y);
        }
        else{
            sequence+=3*(nextSize*nextSize);
            check(nextSize, nextSize+x, nextSize+y);
        }
    }
    else{
        for(int i=x; i<x+2; i++)
        for(int j=y; j<y+2; j++){
            sequence++;
            if(i == findX && j == findY){
                printf("%d\n", sequence);
                return;
            }
        }
        return;
    }
    
}
/*
입력된 배열을 2x2 배열로 쪼갠 후 왼위, 오위, 왼아, 오아 순서로 검사하는 재귀함수
check 함수(size, 시작x, 시작y)
    size == 1이면 return (최소 검사 가능 크기가 2x2이므로)
    아니라면 아래 코드 실행

    // 이때, 아래처럼 모든 경우를 순차적으로 검사하면 시간 내에 통과가 되지 않아서 다음과 같이 수정함.
    // 입력받은 findX, findY가 있으니, 재귀호출 전 어느 분단에 속해있는지 조건문으로 확인 후
    // 적절한 구간만 검사하면 된다.
    // 이때 건너뛴 구간만큼 seq += 건너뛴 n사이즈*(1~3) 해줘야 함.
    size!=2가 아니라면 
    check(size/2, 시작x, 시작y)
    check(size/2, 시작x + size/2, 시작y)
    check(size/2, 시작x, 시작y + size/2)
    check(size/2, 시작x + size/2, 시작y + size/2)
    후 return;
    이 밑으로 내려온 거면 해당 검사 범위 크기가 2x2인 것.
    검사를 진행한다.

    for(int i=start_x; i<start_x+2; i++){
        for(int j=start_y; i<start_y+2; i++){
            sequence++; // 검사할 때마다 방문 횟수 증가
            if(i == findX && j == findY){
                printf("%d\n", sequence);
                return 1;
            }
        }
    }
    시간초과되면, 숫자 찾자마자 프로그램 종료될 수 있게, 
    check return 값을 0,1로 해서 
    if(!check)
        if(!check) 이런식으로 검사하기. 나머지 뒷 검사 생략할 수 있도록.
*/

int main() {
    sequence=-1; // 첫번째 횟수가 0부터 시작함.
    int N;
    scanf("%d %d %d", &N, &findX, &findY);

    N = pow(2,N);
    check(N, 0, 0);
    return 0;
}
