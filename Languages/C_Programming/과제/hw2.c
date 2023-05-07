#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/* 함수 선언.자세한 내용은 각 함수를 참고 */
void fill_the_array(int original_list[], int input);
void check_multiple_number(int original_list[], int modified_list[], int multiple_condition, int product_number, int len);
void calculate_two_end_values(int original_list[], int modified_list[], int len, int target);
void print_format(int list[], int len);
void get_max(int original_list[], int modified_list[], int len);
void get_min(int original_list[], int modified_list[], int len);


/*
	함수 이름 : main
	기능 : 원하는 코드를 실행
	인자 : 없음
	반환값 : 정상적으로 종료시 0을 반환
	작성 날짜 : 2021 / 11 / 5
*/

int main()
{
	/* 변수 선언 */
	int input;
	int len;
	int multiple_condition, product_number;
	int target;

	int original_list[10] = { 0 };	// 입력받은 값들을 저장할 배열을 선언하고 값들을 0으로 초기화
	int modified_list[10] = { 0 };	// 다른 함수에 의해 기존의 값들이 변경될 배열을 선언하고 값들을 0으로 초기화


	while (1)
	{
		printf("입력받을 정수의 수를 입력하시오 : ");
		scanf("%d", &input);	// 문제의 질문 조건에 맞는 정수 입력
		if (input >= 3 && input <= 10)
			break;
		else
		{
			printf("3 이상 10 이하의 정수로 다시 입력하시오");
			printf("\n");
			printf("\n");
		}
	}
	

	fill_the_array(original_list, input);	// 함수 호출. 함수의 내용은 함수 주석 참고


	len = input;	// 입력받은 값만큼을 배열의 길이로 선언


	printf("배수 조건에 사용될 양의 정수 하나와 곱해질 정수 하나를 입력하시오 : ");
	scanf("%d %d", &multiple_condition, &product_number);	// 문제의 질문 조건에 맞는 정수 입력

	check_multiple_number(original_list, modified_list, multiple_condition, product_number, len); // 함수 호출. 함수의 내용은 함수 주석 참고


	printf("특정 정수를 입력하시오 : ");
	scanf("%d", &target); // 문제의 질문 조건에 맞는 정수 입력


	printf("특정 정수와 리스트의 수정된 각 정수와의 값 차이 : ");

	calculate_two_end_values(original_list, modified_list, len, target); // 함수 호출. 함수의 내용은 함수 주석 참고

	return 0;
}


/*
	함수 이름 : fill_the_array
	기능 : original_list라는 배열에 입력받은 값들을 저장
	인자 : original_list[], input
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 5
*/

void fill_the_array(int original_list[], int input)
{
	/* 변수 선언 */
	int i;
	int numbers;

	printf("리스트에 저장할 정수 값을 모두 입력하시오 : ");

	/* 반복문을 통해 배열의 각 인덱스에 입력받은 값을 저장 */
	for (i = 0; i < input; i++)
	{
		scanf("%d", &numbers); // 값 입력
		original_list[i] = numbers; // 배열에 해당 값 저장
	}
}


/*
	함수 이름 : check_multiple_number
	기능 : 값이 입력된 배열을 전달받고, 다른 배열에 내용을 복사한 후, 기존 배열에서 조건에 맞는 값들로 복사된 배열을 갱신
	인자 : original_list[], modified_list[], multiple_condition, product_number, len
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 5
*/

void check_multiple_number(int original_list[], int modified_list[], int multiple_condition, int product_number, int len)
{
	/* 변수 선언 */
	int i;

	/* 반복문을 통해 old_list[]에 들어있는 값들을 list[]에 복사 */
	for (i = 0; i < len; i++)
		modified_list[i] = original_list[i];

	/* 반복문을 통해 old_list[]에 들어있는 값이 특정 조건에 맞는 경우, list[]값들을 갱신 */
	for (i = 0; i < len; i++)
	{
		if (original_list[i] % multiple_condition != 0) // 배열의 특정 값이 입력 받은 값의 배수가 아니면
			modified_list[i] *= product_number; // 해당 값에 product_number를 곱한 값으로 갱신
	}
}


/*
	함수 이름 : calculate_two_end_values
	기능 : 배열의 값들에서 target을 뺀 후, 각 값에 절대값을 취하여 modified_list[]에 저장. 또한 get_max와 get_min을 호출하여 값을 전달받아 출력
	인자 : modified_list[], len, target
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 5
*/

void calculate_two_end_values(int original_list[], int modified_list[], int len, int target)
{
	/* 변수 선언 */
	int i;

	/* 반복문을 통해 배열의 값에서 tqrget을 뺀 후, 절대값을 취하여 modified_list[]에 저장 */
	for (i = 0; i < len; i++)
	{
		modified_list[i] -= target; // 값 - target

		if (modified_list[i] < 0) // 갱신된 값이 음수이면
			modified_list[i] = -modified_list[i]; // 양수로 바꿔줌
	}

	print_format(modified_list, len); // print_format 함수 호출. 함수의 내용은 함수 주석 참고
	printf("\n");

	printf("특정 정수와 값 차이가 가장 큰 (수정되기 전의) 정수 : ");
	get_max(original_list, modified_list, len); // get_max 함수 호출. 함수의 내용은 함수 주석 참고
	printf("\n");

	printf("특정 정수와 값 차이가 가장 작은 (수정되기 전의) 정수 : ");
	get_min(original_list, modified_list, len); // get_min 함수 호출. 함수의 내용은 함수 주석 참고
	printf("\n");
}


/*
	함수 이름 : print_format
	기능 : 배열의 출력 형식을 지정
	인자 : list[], len
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 5
*/

void print_format(int list[], int len)
{
	/* 변수 선언 */
	int i;

	/* 반복문을 통해 list의 값들을 차례대로 출력 */
	for (i = 0; i < len; i++)
		printf("%d ", list[i]);
}


/*
	함수 이름 : get_max
	기능 : 배열의 값들 중 최대값을 찾고, 해당 최대값을 가진 인덱스를 찾음. 그 인덱스를 통해 old_list에서 해당 인덱스 값을 찾고 그것을 출력
	인자 : original_list[], modified_list[], len
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 5
*/

void get_max(int original_list[], int modified_list[], int len)
{
	/* 변수 선언 */
	int i;
	int max;

	max = modified_list[0]; // list의 0번째 값을 max로 선언

	/* 반복문을 통해 최대값 갱신 */
	for (i = 0; i < len; i++)
	{
		if (max < modified_list[i]) // 최대값이 특정 인덱스의 값보다 작으면
			max = modified_list[i]; // 그 값으로 최대값을 갱신
	}

	/* 반복문을 통해 최대값을 가질 수 있었던 수를 기존의 old_list에서 찾아냄 */
	for (i = 0; i < len; i++)
	{
		if (max == modified_list[i]) // 최대값이 나온 인덱스를 찾고
			printf("%d ", original_list[i]); // 그 인덱스에 해당하는 기존 배열의 값을 출력
	}
}


/*
	함수 이름 : get_min
	기능 : 배열의 값들 중 최소값을 찾고, 해당 최소값을 가진 인덱스를 찾음. 그 인덱스를 통해 old_list에서 해당 인덱스 값을 찾고 그것을 출력
	인자 : old_list[], list[], len
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 5
*/

void get_min(int original_list[], int modified_list[], int len)
{
	/* 변수 선언 */
	int i;
	int min;

	min = modified_list[0]; // list의 0번째 값을 min으로 선언

	/* 반복문을 통해 최소값 갱신 */
	for (i = 0; i < len; i++)
	{
		if (min > modified_list[i]) // 최소값이 특정 인덱스의 값보다 작으면
			min = modified_list[i]; // 그 값으로 최소값을 갱신
	}
	
	/* 반복문을 통해 최소값을 가질 수 있었던 수를 기존의 old_list에서 찾아냄 */
	for (i = 0; i < len; i++)
	{
		if (min == modified_list[i]) // 최소값이 나온 인덱스를 찾고
			printf("%d ", original_list[i]); // 그 인덱스에 해당하는 기존 배열의 값을 출력
	}
}