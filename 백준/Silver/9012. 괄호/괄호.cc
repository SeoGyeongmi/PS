#include <stdio.h>
#include <string.h>
int main() {
    // push,pop만 구현하면 됨
    // 계산 끝난 후 balance가 !=0 이면 안 된다. 
    // 프로그램 실행 과정 중 balance < 0이되면 중간에 바로 종료
    // ( 이면 balance ++, ) 이면 balance--

    char str[51];
    int n;
    int balance=0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int flag=0;
        balance=0; // 새로운 문자열을 검사하므로 balance 초기화
        scanf("%s", str);
        // int len = strlen(str);
        for(int j=0; j<strlen(str); j++){
            if(str[j] == '(') balance++;
            else if(str[j] == ')') {
                balance--;
                if(balance<0){
                    printf("NO\n");
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1) continue;
        if(balance == 0){
            printf("YES\n");
        }
        else{
            // printf("balane : %d\n", balance);
            printf("NO\n");
        }
            
    }
    return 0;
}