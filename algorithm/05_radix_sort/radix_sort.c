#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000 // 10000개 배열까지 가능

// 자리수 기준으로 차례대로 데이터 정렬
// 기수 정렬 함수(멤버 변수 a포인터와 n)
void radixSort(int *a, int n){
    int res[MAX], maxValue = 0;
    int exp = 1;
    for( int i = 0; i < n; i++){
        if(a[i] > maxValue) maxValue = a[i];
    }
    while (maxValue / exp > 0){ // 1의 자리부터 계산 나눠서 나온 몫이 0보다 크면
        int bucket[10] = {0}; 
        for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++; // 자릿수 배열 처리
        for (int i = 1; i < 10; i++){bucket[i] += bucket[i-1];} // 누적 계산
        for (int i = n - 1; i >= 0; i--){
            res[--bucket[a[i] / exp % 10]] = a[i];
        }
        for (int i = 0; i < n; i++) a[i] = res[i]; // 기본 배열 갱신

        exp *= 10; // 자릿수 1, 10, 100, 1000
    }
}

int main(void){
    int a[MAX]; // 배열 선언
    int i, n; // 배열의 인덱스와 개수세는 변수 선언
    printf("배열의 개수를 입력하세요: ");
    scanf("%d" , &n); // 배열 개수 입력
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    radixSort(a, n);
    printf("배열 결과: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    system("pause");
}