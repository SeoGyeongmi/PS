#include <stdio.h>

#define MAX -1000000
#define MIN 1000000
int main(){

    int N;
    int max=MAX;
    int min=MIN;

    scanf("%d", &N);
    int t;
    for(int i=0; i<N; i++){
        scanf("%d", &t);
        if(t>max) max=t;
        if(t<min) min=t;
    }

    printf("%d %d\n", min, max);
    return 0;
}