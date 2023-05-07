#include <stdio.h>
#include <string.h>

//함수 선언
void get_string(char str[]);
int count_space(char str[]);
void print_last_word(char str[], int space);

/*
함수 이름 : main
기능 : 원하는 함수 출력
반환값 : 0(정상 종료)
작성날짜 : 2021/11/26
*/
int main(void)
{
	/* 변수 선언 */
	char str[30] = { 0, }; // 초기화
	int space;

	/* 함수 호출 */
	get_string(str);
	space = count_space(str);
	print_last_word(str, space);

	return 0;
}

/*
함수 이름 : get_string
기능 : 문자열을 입력받아 배열에 저장함
인자 : char str[] (일차원 배열)
반환값 : 없음
작성날짜 : 2021/11/26
*/
void get_string(char str[])
{
	printf("문자열을 입력하시오: ");
	gets(str);	// 문자열을 입력받아 str에 저장
}

/*
함수 이름 : count_space
기능 : 문자열에서 띄어쓰기의 개수를 셈
인자 : char str[] (일차원 배열)
반환값 : 띄어쓰기의 개수
작성날짜 : 2021/11/26
*/
int count_space(char str[])
{
	/* 변수 선언 */
	int i;
	int count = 0;

	for (i = 0; i < 30; i++)
		if (str[i] == ' ')	// 띄어쓰기의 개수 세기
			++count;
	
	return count;
}

/*
함수 이름 : print_last_word
기능 : 문자열을 형식에 맞게 출력
인자 : char str[] (일차원 배열), int space (띄어쓰기 개수)
작성날짜 : 2021/11/26
*/
void print_last_word(char str[], int space)
{
	/* 변수 선언 */
	int i;
	int count = 0;

	for (i = 0; i < 30; i++)
	{
		if (str[i] == ' ')	// 띄어쓰기의 개수 세기
		{
			++count;
			continue;
		}

		if (count == space)	// 띄어쓰기를 세었을 때 기존에 센 띄어쓰기의 개수와 같다면
		{
			if (str[i] == '.')
				break;
			printf("%c", str[i]);	// 마침표를 빼고 문자열만 출력
		}
	}
}