#include <stdio.h>

int main() {
    int listSize;
    int numForFind;
    int count=0;
    int list[100]={0};

    scanf("%d", &listSize);
    
    for(int i=0; i<listSize; i++) {
        scanf("%d", &list[i]);
    }
    scanf("%d", &numForFind);

    for(int i=0; i<listSize; i++) {
        if(list[i]==numForFind) 
            count++;
    }
    printf("%d", count);

    return 0;
}