#include <stdio.h>
#include <string.h>
int main() {
    char str[103];
    while(fgets(str, sizeof(str), stdin) != NULL){
        int len = strlen(str);
        int small=0;
        int big=0;
        int num=0;
        int space=0;
        int sentenc=0;
        for(int i=0; i<len; i++){
            int range = str[i] - 0;
            if(range>=48 && range<=57) num++;
            else if(range>=65 && range<=90) big++;
            else if(range>=97 && range<=122) small++;
            else if(range == 32) space++; 
        }
        printf("%d %d %d %d\n", small, big, num, space);
    }

    return 0;
}
