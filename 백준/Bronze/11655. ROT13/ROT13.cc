#include <stdio.h>
#include <string.h>
int main() {
    char origin[103];
    char encoded[103];
    fgets(origin, sizeof(origin), stdin);
    int len = strlen(origin);

    for(int i=0; i<len; i++){
        int range = origin[i] - 0;
        
        if(range>=65 && range<=90) { // 만약 현재 문자가 대문자라면
            int temp = range+13;
            if(temp>90){
                encoded[i] = 'A' + (temp-91);
            }
            else encoded[i] = origin[i] + 13;
        }
        else if(range>=97 && range<=122) { // 만약 현재 문자가 소문자라면
            int temp = range+13;
            if(temp>122){
                encoded[i] = 'a' + (temp-123);
            }
            else encoded[i] = origin[i] + 13;
        }
        else { // 대문자도 소문자도 아니라면 그냥 그대로 저장
            encoded[i] = origin[i];
        }
    }
    encoded[len] = '\0';
    printf("%s", encoded);


    return 0;
}
/*

*/