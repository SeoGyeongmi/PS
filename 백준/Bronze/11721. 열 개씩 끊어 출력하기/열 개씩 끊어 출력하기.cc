#include <stdio.h>
#include <string.h>
int main() {
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    int count = 1;
    for(int i=0; i<len; i++){
        printf("%c", str[i]);
        if(count%10 == 0) printf("\n");
        count++;
    }
    return 0;
}