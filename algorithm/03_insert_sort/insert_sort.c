#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 1000
// 삽입정렬 
// n^2의 시간복잡도를 가진다.
int a[SIZE]; // 초기배열의 크기

// 위치 바꾸는 함수
int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int main(void)
{
    int n; // min은 가장 작은 값을 받는다. 
    // 값 입력
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // 이중 반복문 정렬
    for (int i = 0; i < n - 1; i++)
    {
        int j = i;
        while(j >= 0 && a[j] > a[j+1]){
            swap(&a[j], &a[j + 1]); // 가장 작은값과 인덱스값 변경
            j--;
        }
    }
    // 정렬된 상태 출력
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    system("pause");
    return 0;
}