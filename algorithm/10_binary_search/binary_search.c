#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

// 이진탐색
// 조건1 숫자가 정렬이 되어 있어야 한다.
// 중간값과 키값을 확인 후 키값보다 크면 오른쪽 탐색 작으면 왼쪽 탐색
int a[MAX_SIZE]; // a 배열

int search(int start, int end, int target){ // 멤버변수(시작값, 끝값, 키 값)
    if(start > end) return -9999; // 시작값이 끝값보다 크면 종료 or 정렬 안 된 경우 종료
    int mid = (start+end)/2; // 시작값과 끝값을 더하고 중간값 세팅
    if(a[mid] == target) return mid; // 중간값과 키값이 같으면 중간값 반환
    else if(a[mid] > target) return search(start, mid -1, target); // 중간값보다 탐색 값이 작으면 왼쪽으로 탐색
    else return search(mid+1, end, target); // 중간값보다 탐색값이 크면 오른쪽으로 탐색
}

int main(void){
    int n, target;// 입력받는 배열의 개수와 찾고자 하는 키값 변수 선언
    printf("배열의 개수와 찾고자 하는 수를 입력하세요: ");
    scanf("%d %d", &n, &target);
    printf("%d개의 배열을 입력하세요: ", n);
    for(int i= 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int result = search(0, n - 1, target);
    printf("찾은 값은: ");
    if(result != -9999) printf("%d번째 원소입니다. \n", result + 1);
    else printf("원소를 찾을 수 없습니다. \n");
    system("pause");
    return 0;
}