#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int doc; // 서류 점수
    int interview; // 면접 점수
} Applyer;

int compare(const void* a, const void* b){
    Applyer *x = (Applyer*)a; //x,y 엔 Applyer 변수의 주소가 각각 담기게 된다.
    Applyer *y = (Applyer*)b;

    if(x->doc > y->doc) return 1;
    if(x->doc < y->doc) return -1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int people;
        scanf("%d", &people); // 입력된 사람 수 만큼 서류/면접 점수를 입력받는다.
        Applyer* A = (Applyer*)malloc(sizeof(Applyer)*people);
        for(int j=0; j<people; j++){
            // 서류 점수 기준으로 sort한다.
            scanf("%d %d", &A[j].doc, &A[j].interview);
        }

        qsort(A,people,sizeof(Applyer), compare);

        int count=0;
        int bestInter = 1000000000;

        for(int j=0; j<people; j++){
            if(A[j].interview < bestInter){
                count++;
                bestInter = A[j].interview;
            }
        }

        printf("%d\n", count);
        free(A);
    }
    return 0;
}
/*

*/