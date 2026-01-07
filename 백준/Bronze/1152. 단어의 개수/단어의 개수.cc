#include <stdio.h>
#include <string.h>

#define MAX 1000002
int main() {

    // bis는 공백 이전에 문자가 있어야 활성화 되어야 함.
    // if(i==0 && str[i]=' ') 이면 그냥 무시함 -> 첫번째 문자가 공백이면 무시
    // 공백이 처음 나오면 이제 그 이후로는 공백+문자 기준으로 단어를 센다.(공백+끝이면 단어 세지 x)
    int blankIsAppear=0;
    int nextCharOfBlank=0;
    int wordCount=0;

    char str[MAX] = {0};
    // scanf("%s", str);
    fgets(str,MAX,stdin);
    int len = strlen(str);
    for(int i=0; i<len; i++){
        // printf("현재 문자 : %c\n", str[i]);
        if(i==(len-1)) break;
        if(i==0 && str[i]!=' '){
            blankIsAppear=1;
        }
        if(str[i]==' '){
            // printf("공백나옴! BIA를 1로 바꿈\n");
            blankIsAppear=1;
            continue;
        }
        else if(str[i]!=' '){ // 현재 char에서,
            // printf("공백 아닌 문자,\n");
            if(blankIsAppear){ // 만약 직전 문자가 공백이었다면
                // printf("직전 char가 공백임, COUNT++ !!\n");
                wordCount++;
                blankIsAppear=0; // 현재 문자는 char이므로 다시 비활성화
                continue;
            }
            else
                continue;
        }
        // else if(!blankIsAppear && str[i]!=' ') continue;
        // else if(blankIsAppear){
        //     if(str[i]!=' ') wordCount++;
        // }
    }

    printf("%d", wordCount);
    return 0;
}
/*
단어를 세는 기준은,
공백이 나오기 전의 문자인지 / 공백인지 / 이전 조건 모두 만족 이후의 문자인지
로 구분한다. flag로.
- blankIsAppear(공백 나오기 전)=0 인 상태에서 공백이나 개행문자를 만났을 때 - worldCount++
- 공백이 나오면 blankIsAppear=1로 바꾸기
- blankIsAppear=1(공백 나옴)=1 인 상태에서 첫번째로 나온 문자가 공백이 아닌 char이고, 
nextCharOfBlank==0이면 
    nextCharOfBlank=1
    worldCount++

1. 첫번째로 나온 단어 세는 것 - 공백이 하나도 안 나온 상태에서, 이 문자가 캐릭터(공백 아님)면 단어 수 +1
2. 공백 나옴 + 그 다음 캐릭터가 존재할 때 - 단어 수 +1
*/