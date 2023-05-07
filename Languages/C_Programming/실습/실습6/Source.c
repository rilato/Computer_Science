#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int the_number_of_student(void);
void print_max_age(int inputMax);

/*
	함수 이름 : main
	기능 : 원하는 코드를 실행
	인자 : 없음
	반환값 : 정상적으로 종료시 0을 반환
	작성 날짜 : 2021 / 10 / 22
	작성자 : B735365 이윤식
*/

int main()
{
	int count = 0;	// 학생 수에 대한 변수명을 count로 지정
	int max = 0;
	int student_ages[10];	// 학생별로 나이를 저장할 배열

	count = the_number_of_student();	// 학생 수를 입력받는 함수 호출

	for (int i = 0; i < count; i++)	// 배열의 값들을 초기화하는 for문
	{
		printf("학생 %d 나이 : ", i + 1);
		scanf("%d", &student_ages[i]);
	}

	for (int j = 0; j < count; j++)	// 배열에 저장된 학생들의 나이를 토대로 최대 나이를 찾는 for문
	{
		if (student_ages[j] > max)
			max = student_ages[j];
	}

	printf("\n");
	print_max_age(max);	// 학생의 최대 나이를 출력하는 함수 호출
	
	return 0;
}

/*
	함수 이름 : the_number_of_student
	기능 : 학생 수를 입력받음
	인자 : 없음
	반환값 : 학생 수를 반환
	작성 날짜 : 2021 / 10 / 22
	작성자 : B735365 이윤식
*/

int the_number_of_student(void)
{
	int number;	// 학생 수를 변수 number로 지정

	printf("학생 수를 입력하시오 : ");
	scanf("%d", &number);
	printf("\n");
	return number;
}

/*
	함수 이름 : print_max_age
	기능 : 학생의 최대 나이를 출력하는 함수
	인자 : inputMax
	반환값 : 없음
	작성 날짜 : 2021 / 10 / 22
	작성자 : B735365 이윤식
*/

void print_max_age(int inputMax)
{
	printf("학생의 최대 나이 : %d", inputMax);
}