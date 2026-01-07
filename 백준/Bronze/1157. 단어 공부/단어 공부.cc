#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#define MAX 1000000
int main() {
    char str[MAX] = {0};
    char alpha[26] = {0};
    int alphaIndex=0;
    int alphaCount[26] = {0};
    int len;
    // 문자열 입력 받음 , 받자마자 대문자로 변환
    scanf("%s", str);
    // 문자 하나하나 검사하면서(alpha len 만큼, 대문자로 바꿔서 검사), alpha에 없는 문자면, 
    len = strlen(str);
    for(int i=0; i<len; i++){ // char 문자 하나씩 검사한다.
        int flag=0;
        if(islower(str[i])) str[i] = toupper(str[i]); // 소문자면 대문자로 변환
        for(int j=0; j<alphaIndex; j++){ // alpha[]에서 찾는다.
            if(str[i]==alpha[j]){ // 현재 검사하는 str[i]가 이미 alpha에 존재하면
                flag=1;
                alphaCount[j]++;
                break;
            }
        }
        if(!flag){ // 현재 검사하는 str[i]가 alpha에 없는 문자면
            alpha[alphaIndex] = str[i];
            alphaCount[alphaIndex]++;
            alphaIndex++; // alpha에 새로운 문자가 추가되었으므로 index를 증가시킨다.
        }
    }

    // printf("지금 문자열 : %s\n", str);
    // printf("지금 alpha : ", str);  
    for(int i=0; i<alphaIndex; i++){
        // printf("%c ", alpha[i]);
    }
    // printf("\n지금 alphaCount : ");
    for(int i=0; i<alphaIndex; i++){
        // printf("%d ", alphaCount[i]);
    }
    // printf("\n");

    // 최대값 찾기
    // 먼저 최대값 확정
    // 이후에 최대값과 같은 값이 있는지 확인
    int maxCount = alphaCount[0];
    int maxIndex=0;
    int misFlag=0;
    for(int i=0; i<alphaIndex; i++){
        if(alphaCount[i] > maxCount){
            maxCount = alphaCount[i];
            maxIndex = i;
        }
    }
    // printf("현재 max alpha - %c(%d번)\n", alpha[maxIndex], maxCount);
    for(int i=0; i<alphaIndex; i++){
        if(i!=maxIndex && alphaCount[i]==maxCount){
            misFlag=1;
            // printf("maxIndex(%d번)이랑 현 index(%d번)이 같음\n", maxIndex, alphaCount[i]);
        }
    }
    
    // 출력
    if(misFlag==1) printf("?");
    else printf("%c", alpha[maxIndex]);
    return 0;
}
/*

*/