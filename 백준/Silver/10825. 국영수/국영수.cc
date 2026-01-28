#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    /* data */
    char name[11];
    int kor;
    int eng;
    int math;
} Student;
/*
1. 구조체 선언
2. 입력된 학생 수만큼 구조체 배열 크기만큼 메모리 할당
3. 배열로 입력받는다.(반복문)
4. qsort(+cmp 구현) - 내림차순
    1. 국어점수가 높은 순으로 - 내림차순
    2. 국어점수가 같다면 영어점수 - 오름차순
    3. 영어점수가 같아면 수학점수 - 내림차순
5. qsort된대로 출력한다.
*/
int cmp(const void* a, const void*b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;

    // 국어점수 - 내림차순(5,4,3,...)
    if(s1->kor < s2->kor) return 1;
    if(s1->kor > s2->kor) return -1;
    // 영어점수 - 오름차순(1,2,3,...)
    if(s1->eng > s2->eng) return 1;
    if(s1->eng < s2->eng) return -1;
    // 수학점수 - 내림차순
    if(s1->math < s2->math) return 1;
    if(s1->math > s2->math) return -1;
    // 모든 점수가 같다면 이름이 사전 순으로 증가
    int len1 = strlen(s1->name);
    int len2 = strlen(s2->name);
    int msl=len1; // 둘 중 더 문자열길이가 짧은 이름(검사시 인덱스 넘어가면 안 되니까. 일단 s1의 이름으로 초기화)
    if(len1 > len2) msl = len2;
    for(int i=0; i<msl; i++){
        if(s1->name[i] > s2->name[i]) return 1;
        if(s1->name[i] < s2->name[i]) return -1;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);

    Student *s = (Student*)malloc(sizeof(Student)*n);

    for(int i=0; i<n; i++){
        scanf("%s %d %d %d", s[i].name, &(s[i].kor), &(s[i].eng), &(s[i].math));
    }
    
    qsort(s, n, sizeof(Student), cmp);

    for(int j=0; j<n; j++){
        printf("%s\n", s[j].name);
    }
    return 0;
}

