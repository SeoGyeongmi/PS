#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int stack[50000];
    int size;
}Stack;

void push(Stack* s, char c){
    s->stack[s->size] = c;
    s->size++;
}
void pop(Stack* s){
    s->size--;
}
int empty(Stack* s){
    if(s->size == 0) return 1;
    else return 0; 
}

int main() {
    char str[1000001]; // 괄호 입력받을 string
    char preChar;
    int count=0; // 막대기 count
    scanf("%s", str);
    Stack* s = (Stack*)malloc(sizeof(Stack));

    s->size=0;
    push(s, str[0]);
    preChar = str[0];

    int lazer=0;
    int i=1; // 문자열 검사용 index
    while(1){
        if(str[i] == '('){ // preChar 관계 없이 일단 push
            push(s, str[i]);
        }
        else if(str[i] == ')'){
            if(preChar == '('){ // 직전 괄호가 (이면 -> 레이저 쏴야함
                pop(s);
                //printf("%d번 레이저로 자름! 조각 %d개 추가됨..\n", ++lazer,s->size);
                count += s->size; 
            }
            else if(preChar == ')'){
                count += 1; // 막대기의 마지막 조각 더해주어야 함
                pop(s);
            }
        }
        preChar = str[i];
        //printf("prechar %c로 저장됨\n", str[i]);
        i++;
        if(i==strlen(str)) break; // 현재 문자가 문자열의 끝이면 break;
    }

    printf("%d\n", count);

    return 0;
}
/*
stack에 str[0]을 채우고 시작한다.
다음을 스택이 eempty가 아닐때까지 반복한다. while(!s.empty())
    1. 검사하는 현재 문자가 '(' 이면
        - 일단 stack 에 push + 스택 size++

    2. 검사하는 현재 문자가 ')' 이면 [ 문자 )은 스택에 넣지 않는다. ]
        - preChar == '(' 이면 : 레이저 쏴서 잘라야 한다는 뜻
            - 이전에 집어넣은 ( size도 문자가 stack을 의미하는 것이 아니었으므로,
              이전에 더한  감소시켜주어야 한다.
            - 스택에서 '('를 pop.(그냥 top 꺼내면 됨)
            - 그리고 (막대기)count += size; (현재 스택에 쌓인 막대기 개수만큼 더하는 것.)
        - preChar == ')' 이면 : 막대기 하나의 끝이라는 의미
            - ( 하나를 pop한다. : 막대기의 시작 부분을 꺼내는 것.
            - count +1을 한다. : 막대기 하나의 마지막 조각을 꺼낸 것.
            - 마지막 막대기를 꺼냈으므로 스택 size--; (pop함수에서 size감소 시킬 수 있도록)

    검사 후 모든 문자는 preChar에 저장하기
*/