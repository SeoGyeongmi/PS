#include <stdio.h>

int main() {
    char cs[5][15]={0};

    for(int i=0; i<5; i++)
        scanf("%s", cs[i]);

    for(int i=0; i<15; i++)
        for(int j=0; j<5; j++){
            if(cs[j][i] != NULL)
                printf("%c", cs[j][i]);
        }

   
    return 0;
}