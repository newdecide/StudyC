#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

// 초기화
Node* initNode(int data, Node* leftChild, Node* rightChild){
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> leftChild = leftChild;
    node -> rightChild = rightChild;

    return node;
}

// 30 - 17 - 5 - 23 - 48 - 37 - 50

//전위 순회
void preorder(Node* root){
    if(root){
        printf("%d ", root -> data);
        preorder(root -> leftChild);
        preorder(root -> rightChild);
    }
}
// 결과: 30 17 5 23 48 37 50 

// 중위순회
void inorder(Node* root){
    if(root){
        inorder(root -> leftChild);
        printf("%d ", root -> data);
        inorder(root -> rightChild);
    }
}
// 결과: 5 17 23 30 37 48 50 

// 후위순회
void postorder(Node* root){
    if(root){
        postorder(root -> leftChild);
        postorder(root -> rightChild);
        printf("%d ", root -> data);

    }
}
// 결과: 5 23 17 37 50 48 30 

// 30, 17, 48, 5, 23, 37, 50
// 이진트리

int main(void){
    Node* n7 = initNode(50, NULL, NULL);
    Node* n6 = initNode(37, NULL, NULL);
    Node* n5 = initNode(23, NULL, NULL);
    Node* n4 = initNode(5, NULL, NULL);
    Node* n3 = initNode(48, n6, n7);
    Node* n2 = initNode(17, n4, n5);
    Node* n1 = initNode(30, n2, n3);

    preorder(n1);
    printf("\n");
    inorder(n1);
    printf("\n");
    postorder(n1);
    printf("\n");
    return 0;

}