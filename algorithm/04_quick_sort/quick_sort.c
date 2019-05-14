#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

// 퀵소트
// 키값보다 왼쪽 비교변수가 작으면 1증가
void quickSort(int start, int end){
    if(start >= end)return; // start가 end보다 크거나 같으면 종료
    
    // 키값, 왼쪽 비교 변수, 오른쪽 비교 변수, swap 변수
    int key = start, i = start + 1, j = end, temp;
    while(i <= j) {
        while(i <= end && a[i] <= a[key]) i++; // 왼쪽 비교 변수 1씩 증가
        while(j > start && a[j] >= a[key]) j--; // 오른쪽 비교 변수 1씩 감소
        if(i > j) {
            swap(&a[key], &a[j]);
        } else {
            swap(&a[i], &a[j]);
        }
        quickSort(start, j - 1); // 키 기준 왼쪽 정렬
        quickSort(j + 1 , end); // 키 기준 오른쪽 정렬
    }
}
int main(void){
    int n; // 입력 개수 변수
    printf("배열의 개수를 입력하세요: ");
    scanf("%d", &n); // 입력 개수 입력
    for(int i = 0; i < n; i++) {scanf("%d", &a[i]);} // 배열 입력
    quickSort(0, n-1); // 0부터 시작하므로 1뺀 값 까지 정렬
    for(int i = 0; i < n; i++) {printf("%d ", a[i]);} // 정렬 후 출력

    system("pause");
    return 0;
}