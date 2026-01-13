#include <stdio.h>

int main(){
    char str[1000];
    int index;
    scanf("%s %d", str, &index);
    printf("%c\n", str[index-1]);
    return 0;
}