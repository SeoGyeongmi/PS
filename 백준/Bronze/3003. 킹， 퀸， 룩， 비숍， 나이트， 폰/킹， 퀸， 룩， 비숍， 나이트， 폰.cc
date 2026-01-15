#include <stdio.h>

int main() {
    int normal[6] = {1,1,2,2,2,8};
    int recent[6] = {0};
    int needAdd[6] = {0};
    for(int i=0; i<6; i++){
        scanf("%d", &recent[i]);
        if(recent[i]!=normal[i]){
            needAdd[i] = normal[i]-recent[i];
        }
    }

    for(int i=0; i<6; i++){
        printf("%d ", needAdd[i]);
    }
    return 0;
}
/*
정상 개수 : 1 1 2 2 2 8

*/