#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

int cmp(const void* a, const void* b){
    int x1 = ((Point*)a)->x;
    int y1 = ((Point*)a)->y;
    int x2 = ((Point*)b)->x;
    int y2 = ((Point*)b)->y;

    if(y1!=y2){ // y좌표가 다르다면 -> 바로 구분가능
        if(y1 > y2) return 1;
        else return -1;
    } 
    else{ // y좌표가 서로 같다면 -> x좌표로 구분하기
        if(x1 > x2) return 1;
        if(x1 < x2) return -1;
        else return 0;
    }
 
}
int main() {
    // The number of coordinates is input.
    int noc;
    scanf("%d", &noc);
    Point *p = (Point*)malloc(sizeof(Point)*noc);

    for(int i=0; i<noc; i++){
        scanf("%d %d", &(p[i].x), &(p[i].y));
    }

    qsort(p, noc, sizeof(Point), cmp);

    for(int i=0; i<noc; i++){
        printf("%d %d\n", p[i].x, p[i].y);
    }


    return 0;

}