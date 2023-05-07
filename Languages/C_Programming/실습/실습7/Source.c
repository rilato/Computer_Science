#include <stdio.h>
#include <stdlib.h>

void add_two_integers(int src1[], int src2[], int dest[], int len);
void print_array(char* array_name, int input_array[], int len);

/*
	함수 이름 : main
	기능 : 원하는 코드를 실행
	인자 : 없음
	반환값 : 정상적으로 종료시 0을 반환
	작성 날짜 : 2021 / 11 / 5
	작성자 : B735365 이윤식
*/

int main()
{
	int source1[5] = { -2, 4, -3, 1, 5 };	// 배열 선언 및 값 초기화
	int source2[5] = { 6, -7, 2, 3, -1 };
	int destination[5] = { 0 };
	int i;
	int len;

	len = sizeof(source1) / sizeof(int);	// 배열의 길이. 즉 5

	add_two_integers(source1, source2, destination, len);	// 배열의 항목을 더하는 함수 호출

	print_array("source1", source1, len); // 출력 형식을 정해놓은 함수를 호출
	print_array("source2", source2, len);
	print_array("destination", destination, len);

	return 0;
}

/*
	함수 이름 : add_two_integers
	기능 : 배열 두 개와 길이를 입력받고 배열을 출력
	인자 : int src1[], int src2[], int len
	반환값 : dest[]. src1[]과 src2[]의 항목들을 더한 값들을 저장한 배열을 반환
	작성 날짜 : 2021 / 11 / 5
	작성자 : B735365 이윤식
*/

void add_two_integers(int src1[], int src2[], int dest[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		dest[i] = src1[i] + src2[i];
}

/*
	함수 이름 : print_array
	기능 : 배열의 이름과 배열의 주소를 전달받고, 해당 배열의 값들을 출력형식에 맞추어 출력
	인자 : char* array_name, int input_array[], int len
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 5
	작성자 : B735365 이윤식
*/
void print_array(char* array_name, int input_array[], int len)
{
	int i;

	printf("%s : ", array_name);
	for (i = 0; i < len - 1; i++)
		printf("%d, ", input_array[i]);	// input_array[]에 저장된 값들을 출력
	printf("%d", input_array[len - 1]); // 배열의 마지막 값을 출력
	printf("\n");
}