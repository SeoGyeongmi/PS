#include <stdio.h>
#include <string.h>
int main() 
{
    char c[101];
    char alphaCount[26]={0};

    scanf("%s", c);

    int len = strlen(c);
    for(int i=0; i<26; i++) alphaCount[i] = -1;
    for(int i=0; i<len; i++){
        if(alphaCount[c[i]-'a'] != -1) continue;
        alphaCount[c[i]-'a'] = i; 
    }

    for(int i=0; i<26; i++){
        printf("%d ", alphaCount[i]);
    }
    
    return 0;
}