#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000
typedef struct 
{
    int data[SIZE];
    int front;
    int rear;
    //  size 함수가 없는 이유는 rear로 바로 size확인이 가능하기 때문이다.
} Queue;

void initialize(Queue *q){
    q->front = -1;
    q->rear = -1;
    // enqueue시 ++rear로 시작하므로(인덱스가 0부터 시작)
    // front 출력 or dequeue 시에도 ++front로 접근하므로, 문제 없음
}
int isEmpty(Queue *q){
    return q->front == q->rear;
}
int isFull(Queue *q){
    return q->rear == SIZE-1;
}
void enqueue(Queue *q, int data){
    if(isFull(q)) return;
    q->data[++(q->rear)] = data;
}
int dequeue(Queue *q){
    if(isEmpty(q)) return -1;
    return q->data[++(q->front)];
}

int front(Queue *q){
    if(isEmpty(q)) return -1;
    else return q->data[(q->front)+1];
}

int back(Queue *q){
    if(isEmpty(q)) return -1;
    else return q->data[q->rear];
}
int size(Queue* q){
    return q->rear - q->front;
}
int main() {
    int n;
    Queue *q = (Queue*)malloc(sizeof(Queue));
    initialize(q);

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        char order[6];
        scanf("%s", order);

        if(strcmp(order, "push")==0){
            int num;
            scanf("%d", &num);
            enqueue(q, num);
        }
        else if(strcmp(order, "pop")==0){
            int num = dequeue(q);
            printf("%d\n", num);
        }
        else if(strcmp(order, "size")==0){
            printf("%d\n", size(q));
        }
        else if(strcmp(order, "empty")==0){
            printf("%d\n", isEmpty(q));
        }
        else if(strcmp(order, "front")==0){
            printf("%d\n", front(q));
            
        }
        else if(strcmp(order, "back")==0){
            printf("%d\n", back(q));
        }
    }

    return 0;
}