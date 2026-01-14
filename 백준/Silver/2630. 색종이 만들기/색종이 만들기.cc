#include <stdio.h>
/*
단위 정사각형이 1이면 파란색, 0이면 하얀색이다.

재귀 함수 부분(크기, 시작점x, 시작점y)

만약 N==1이라면 return한다.
아니라면, 밑의 코드 실행

이중 for문(mat크기가 8이면, 8*8로 검사한다.)
    받은 matrics를 검사한다.
    첫 숫자를 저장해놓고, 
    만약 다른 숫자가 이후에 나온 다면
        devide(1번째 조각) -> 크기 : N/2 , 시작좌표 : (시작점x, 시작점y)
        devide(2번째 조각) -> 크기 : N/2 , 시작좌표 : (N/2, 시작점y)
        devide(3번째 조각) -> 크기 : N/2 , 시작좌표 : (시작점x, N/2)
        devide(4번째 조각) -> 크기 : N/2 , 시작좌표 : (N/2, N/2)
    다 같은 조각이라면, 첫 숫자를 보고(그 이후에 다 같은 색이므로)
    color[첫숫자]++
*/
int color[2]={0}; // 0 = 하얀색, 1 = 파란색
int paper[128][128]={0};

void divide(int size, int start_X, int start_Y){

    int firstColor = paper[start_X][start_Y]; // 매트릭스 맨 처음 수
    if(size==1){
        color[firstColor]++;
        return;
    }

    // 현재 색종이가 모두 같은 색인지 검사하는 반복문
    // 만약 하나라도 다르면 그냥 자르기만 하면 됨.
     for(int r=0; r<size; r++)
        for(int c=0; c<size; c++){
            if(paper[start_X+r][start_Y+c] != firstColor){
                divide(size/2, start_X, start_Y);
                divide(size/2, start_X+(size/2), start_Y);
                divide(size/2, start_X, start_Y+(size/2));
                divide(size/2,start_X+(size/2),start_Y+(size/2));
                return; // 나누는 작업이 끝나면 함수를 끝내도 됨.
            }
        }
    // 여기까지 도달했다는 것은 검사한 모든 색이 같다는 것
    color[firstColor]++;
}
int main() {
    int N;
    color[0]=0;
    color[1]=0;
    scanf("%d", &N);

    for(int row=0; row<N; row++)
        for(int col=0; col<N; col++)
            scanf("%d", &paper[row][col]);

    divide(N, 0, 0);

    printf("%d\n%d\n", color[0], color[1]);

    return 0;
}