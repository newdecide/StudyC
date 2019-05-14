#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 10001

// 계수정렬 : 크기를 기준으로 데이터의 개수를 세는 정렬 알고리즘 
// 시간복잡도 0(N) 

// 2 1 0 2 2 1 3 1 0 3
// 0 0 1 1 1 2 2 2 3 3

// 이해한거 0 1 2 3을 각 배열로 관리하고 개수를 세서 개수대로 출력한다. 0 2개, 1 3개, 2 3개

int n, m; // 자리수 입력변수, 데이터 입력 변수 
int a[MAX_VALUE];

int main(){
    printf("배열의 개수를 입력하세요: ");
    scanf("%d", &n); // 자리수 입력
    for(int i = 0; i < n; i++) { scanf("%d", &m); a[m]++;}
    for(int i = 0; i < MAX_VALUE; i++){
        while(a[i] != 0) { printf("%d ", i); a[i]--;} 
    }
    system("pause");
}
