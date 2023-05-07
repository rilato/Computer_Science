#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* 함수 선언, 자세한 내용은 각 함수 참고 */
void print_arrange(char* str, int src[][2]);
int compare_rows_of_arrays(int src1[][2], int src2[][2], int target_row);

/*
	함수 이름 : main
	기능 : 원하는 코드를 실행
	인자 : 없음
	반환값 : 정상적으로 종료시 0을 반환
	작성 날짜 : 2021 / 11 / 12
*/

int main()
{
	/* 변수 선언 및 배열 초기화 */
	int i, answer;
	int source1[3][2] = { {1, 2}, {3, 4}, {5, 6} };
	int source2[3][2] = { {1, 2}, {3, 5}, {5, 6} };

	print_arrange("source1 :", source1);
	print_arrange("source2 :", source2);

	printf("각 행의 비교 결과:");
	printf("\n");

	for (i = 0; i < 3; i++)	// 반복문을 통해 두 배열간 행의 합을 비교하고, 그 값을 출력 
	{
		answer = compare_rows_of_arrays(source1, source2, i);
		printf("%d", answer);

		if (i == 2)	// 마지막 것에서 콤마가 찍히는 것을 방지하기 위함
			break;

		printf(", ");
	}
		
	return 0;
}

/*
	함수 이름 : print_arrange
	기능 : 배열의 출력 형식을 지정
	인자 : char* str, src[][2]
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 12
*/

void print_arrange(char* str, int src[][2])
{
	/* 변수 선언 */
	int i, j;

	printf("%s", str);
	printf("\n");

	for (i = 0; i < 3; i++)	// 반복문을 통해 배열의 항목을 출력
	{
		for (j = 0; j < 2; j++)
			printf("%d ", src[i][j]);
		printf("\n");
	}

}

/*
	함수 이름 : compare_rows_of_arrays
	기능 : 두 배열의 행의 합을 구하고, 그 값이 같으면 1을 반환하고, 그렇지 않으면 0을 반환
	인자 : src1[][2], src2[][2], target_row
	반환값 : 1 또는 0
	작성 날짜 : 2021 / 11 / 12
*/

int compare_rows_of_arrays(int src1[][2], int src2[][2], int target_row)
{
	/* 변수 선언 */
	int j;
	int sum_of_src1 = 0;
	int sum_of_src2 = 0;

	for (j = 0; j < 2; j++)	// 반복문을 통해 배열 src1의 행의 합을 구함
		sum_of_src1 += src1[target_row][j];

	for (j = 0; j < 2; j++)	// 반복문을 통해 배열 src2의 행의 합을 구함
		sum_of_src2 += src2[target_row][j];

	if (sum_of_src1 == sum_of_src2)	// 두 배열의 행의 합이 같으면 1을 반환
		return 1;
	else // 두 배열의 행의 합이 다르면 0을 반환
		return 0;
}