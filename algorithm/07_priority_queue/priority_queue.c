#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

// 우선순위 큐(힙 정렬)
// 완전이진트리와 같다.
// 최대 힙은 루트노드가 전체 트리의 가장 큰 값을 가진다.
// 부모노드가 자식노드보다 값이 커야한다.
// 데이터 삽입과 추출은 push와 pop으로 한다.

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct {
    int heap[MAX_SIZE]; // 힙배열
    int count; // 힙의 원소 담을 변수
} priorityqueue;

// 삽입은 상향식: 가장 큰경우 루트노드까지 올라간다. 최대힙 구성
void push(priorityqueue *pq, int data){
    if(pq -> count >= MAX_SIZE) return; // counter변수가 MAX_SIZE과 같거나 크면 종료
    pq->heap[pq->count] = data; // 힙배열[count] = 데이터 입력
    int now = pq -> count; // 삽입된 데이터
    int parent = (pq->count -1) / 2; // 부모변수ㅜ와 비교
    // 새 원소를 삽입한 이후에 상향식으로 힙을 구성한다.
    while (now > 0 && pq ->heap[now] > pq->heap[parent]) // 삽입데이터가 부모보다 크면 교환
    {
        swap(&pq -> heap[now], &pq -> heap[parent]); // now와 parent 교체
        now = parent;
        parent = (parent -1)/2;
    }
    pq -> count++; // 삽입이후 카운트 증가
    
}

// 삭제는 하향식: 루트노드를 삭제하고 마지막 원소를 루트노드로 위치후 최대힙 조정
int pop(priorityqueue *pq){ // 큐를 입력ㅂ다아 접근
    if(pq -> count <= 0) return -9999; // 지울게 없으면 문제가 있다.
    int res = pq->heap[0];
    pq->count--; // 삭제했으므로 1감소
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftChild = 1, rightChild = 2; // 루트부터 아래까지 비교한다.
    int target = now;

    // 원소를 추출한 이후에 하향식으로 힙을 구성합니다.
    while(leftChild < pq -> count){
        if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
        if (pq->heap[target] < pq->heap[rightChild]&& rightChild < pq->count) target = rightChild;
        if (target == now) break; // 더 이상 내려가지 않아도 될때 종료
        else{
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftChild = now * 2 + 1;
            rightChild = now *2 + 2;
        }
    } 
    return res;
}

int main(void){
    int n, data;
    printf("배열의 개수를 입력하세요: ");
    scanf("%d", &n);
    priorityqueue pq;
    pq.count = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        push(&pq, data);
    }
    for(int i = 0; i < n; i++){
        int data = pop(&pq);
        printf("%d ", data);
    }
    system("pause");
    return 0;
}
