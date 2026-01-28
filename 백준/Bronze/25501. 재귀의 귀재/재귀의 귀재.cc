#include <stdio.h>
#include <string.h>

int callCount;
int recursion(const char *s, int l, int r){
    if(l >= r) return 1; // 제일 가운데 문자까지 다 검사 된 거면, 그 전 문자들은 다 일치했던 것. 1을 return 한다.
    else if(s[l] != s[r]) return 0; // 검사하는 두 문자가 같지 않으면 남은 문자 검사하지 않고 바로 return0;
    else{
        callCount++;
        // printf("callCount ++! 현재 %d\n", callCount);
        return recursion(s, l+1, r-1); 
    } 
} // argument로 들어오는 l과 r이 같으면 return 

int isPalindrome(const char *s){
    callCount=1; // 밑에 recursion 호출하는 거 미리 더해줌
    return recursion(s, 0, strlen(s)-1);
}
// 현재는 팰린드롬이면 1을 리턴, 아니라면 0을 리턴
// 변경 -> 재귀호출

int main() {
    int howIter;
    char str[1001];

    scanf("%d", &howIter);
    for(int i=0; i<howIter; i++){
        scanf("%s", str);
        int result = isPalindrome(str);
        printf("%d %d\n", result, callCount);
    }
    return 0;
}