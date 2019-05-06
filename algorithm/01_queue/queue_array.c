#include <stdio.h>
// 큐 뒤쪽으로 들어가서 앞쪽으로 나오는 자료구조
// 스케줄링, 탐색 알고리즘에 다방면으로 활용된다.
// PUSH 큐에 데이터를 넣는다.
// POP 큐에서 데이터를 빼냅니다.
#define SIZE 10000 // 촤대 사이즈
#define INF 99999999 // 무한대를 나타낸다.

int queue[SIZE];
int front = 0;
int rear = 0;

void push(int data){
    if( rear >= SIZE){
        printf("큐 오버플로우가 발생했습니다.");
        return;
    }
    queue[rear++] = data;
}
int pop(){
    if(front == rear){
        printf("큐 언더플로우가 발생했습니다.");
        return -INF;
    }
    return queue[front++];
}

void show(){
    printf("--- 큐의 앞---\n");
    for(int i = front; i< rear; i++){
        printf("%d\n", queue[i]);
    }
    printf("--- 큐의 뒤---\n");
}

int main(void){
    push(7);
    push(5);
    push(4);
    pop();
    push(6);
    pop();
    show();
    system("pause");
    return 0;
}