#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char s1[16];
    char s2[8];
    char s3[16];
    char s4[8];

    scanf("%s %s %s %s", s1,s2,s3,s4);
    strcat(s1,s2); strcat(s3,s4);
    
    long long n1 = atoll(s1);
    long long n2 = atoll(s3);
    
    printf("%lld", n1+n2);
    return 0;
}