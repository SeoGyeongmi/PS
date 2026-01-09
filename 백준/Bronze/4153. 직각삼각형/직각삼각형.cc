#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c;
    // printf("%.0f\n", pow(2,3));
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a==0&&b==0&&c==0) break;
        if(a>c){
            int t=a;
            a=c;
            c=t;
        }
        if(b>c){
            int t=b;
            b=c;
            c=t;
        }
        if (a*a + b*b == c*c) printf("right\n");
        else printf("wrong\n");
    }
    

    return 0;
}