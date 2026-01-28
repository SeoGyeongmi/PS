#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int age;
    char name[101];
    struct Node* next; // 이 node와 연결된 또 다른 Node    
} Node;

int main() {
    int n;
    scanf("%d", &n);

    // head[age] : age리스트의 첫 노드를 가리킴
    Node* head[201] = {0}; // head가 age만큼 있는 이유는 age마다 사람을 관리할 것이기 때문이다. 
    Node* tail[201] = {0};

    for(int i=0; i<n; i++){
        int age;
        char name[101];
        scanf("%d %100s", &age, name);

        // 입력받은 수를 저장한 node하나 만들기
        Node* node = (Node*)malloc(sizeof(Node));
        node->age = age;
        strcpy(node->name, name);
        node->next = NULL;

        // 만약 입력받은 나이의 list가 비어있으면,
        if(head[age] == NULL){
            head[age] = node;
            tail[age] = node;
        }
        else{ // 이미 그 나잇대 사람들이 list에 존재한다면,
            tail[age]->next = node; // 현재 tail로 가리키고 있는 node의 next를 현재 node로
            tail[age] = node; // tail 을 현재 노드로 변경함(현 나이의 젤 마지막 노드로)
        }
    }

    // 나이 1~200 순서대로 출력하면 자동 정렬됨
    for(int i=1; i<=200; i++){
        Node *current = head[i];
        while(current != NULL){
            printf("%d %s\n", current->age, current->name);
            current = current->next;
        }
    }
    return 0;
}
/*
첫째 줄에 사람 수를 입력 받는다.
사람 수 만큼 다음을 반복한다.
    나이, 이름 을 입력받는다.
    나이 순으로 정렬하되, 같은 나이이면 입력된(가입된) 순서대로 정렬하도록 한다.
*/