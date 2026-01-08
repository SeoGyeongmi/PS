#include <stdio.h>

int main(){
    int d1, d2, d3;
    int temp; 
    int reward=0;
    scanf("%d %d %d", &d1, &d2, &d3);
    
    if((d1==d2)&&(d2==d3)&&(d1==d3)){
        reward = 10000 + d1*1000;
    }
    else if(d1==d2){
        // dupnum = d1;
        reward = 1000+d1*100;
    }
    else if(d2==d3){
        // dupnum = d2;
        reward = 1000+d2*100;
    }
    else if(d1==d3){
        // dupnum = d1;
        reward = 1000+d1*100;
    }
    else{
        if(d1>d2) temp=d1;
        else temp=d2;

        if(d3>temp) temp = d3;
        reward = temp*100;
    }
        
    printf("%d\n", reward);
    
    return 0;
}