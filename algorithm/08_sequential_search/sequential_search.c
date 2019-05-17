#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 문자열 헤더파일
#define LENGTH 100

// 순차탐색 1개씩 찾기때문에 시간복잡도 n을 갖는다.
char **array; // 2차원 배열
int founded; // 특정 발견했는지 확인 변수

int main(void){
    int n;
    char *word;
    word = malloc(sizeof(char) * 100); // 데이터크기 100자까지 들어갈수 있음.
    printf("문자열 개수와 찾고자 하는 단어를 입력하세요: ");
    scanf("%d %s", &n, word); // 문자열 개수와 찾고자 하는 단어
    array = (char**)malloc(sizeof(char*)* n ); // 캐릭터 포인터로 데이터 동적할당
    for(int i = 0; i < n; i++){
        array[i] = malloc(sizeof(char) * LENGTH); // 배열에 문자열 데이터 입력
        scanf("%s", array[i]);
    }
    for(int i = 0; i < n; i++){
        if(!strcmp(array[i], word)){
            printf("%d번째 원소입니다. \n", i + 1); // 단어가 몇번째 원소에 있는지 확인
            founded = 1; // 있으면 밖에 있는 if문 작동안함
        }   
    }
    if(!founded) printf("원소를 찾을 수 없습니다. \n"); // 0이면 찾을 수 없다.
    system("pause");
}