#include <stdio.h>
#include <stdlib.h>
#define INF 9999999

typedef struct {
    int data;
    struct Node *next;    
} Node;

// 원소의 개수를 구하고 front와 rear 노드가 들어간다.
typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue; 

void push(Queue *queue, int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    // count가 0이 아닌경우 rear는 다음노드가 된다.
    if(queue -> count == 0){
        queue -> front = node;
    
    } else {
        queue -> rear -> next = node;
    }
    queue -> rear = node;
    queue -> count++;

}

int pop(Queue *queue){
    if(queue -> count == 0){
        printf("큐 언더플로우가 발생했습니다.\n ");
    }
    Node *node = queue -> front;
    int data = node -> data;
    queue->front = node->next;
    free(node);
    queue -> count--;
    return data;
}

void show(Queue *queue){
    Node *cur = queue -> front;
    printf("---큐의 앞---\n");
    while(cur != NULL){
        printf("%d\n", cur -> data);
        cur=cur->next;
    }
    printf("---큐의 뒤---\n");
}

int main(void){
    Queue queue;
    queue.front = queue.rear = NULL;
    queue.count = 0;
    push(&queue, 7);
    push(&queue, 5);
    push(&queue, 4);
    pop(&queue);
    push(&queue, 6);
    pop(&queue);
    show(&queue);
    system("pause");
    return 0;
}
