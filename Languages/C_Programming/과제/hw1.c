#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void displayPattern1(int inputNumber);
void displayPattern2(int inputNumber);
void displayPattern3(int inputNumber);
void displayPattern4(int inputNumber);
void displayPattern5(int inputNumber);

int main()
{
	int input; // 입력을 받을 값을 변수 input으로 설정

	printf("3 이상 7 이하의 양의 홀수 하나를 입력하시오 : ");
	scanf("%d", &input);
	printf("\n");

	/*
		각각의 함수 실행
	*/
	displayPattern1(input);
	displayPattern2(input);
	displayPattern3(input);
	displayPattern4(input);
	displayPattern5(input);

	return 0;
}

/*
	함수 이름 : displayPattern1
	기능 : 인자로 전달된 홀수를 숫자 별로 행을 나누어 우측 정렬하되, 총 개수로부터 하나씩 줄여나간다.
	인자 : inputNumber
	반환값 : 없음
	날짜 : 2021/10/18
*/

void displayPattern1(int inputNumber)
{
	int row, column;	// 각각 행과 열을 나타내는 변수

	for (row = 1; row <= inputNumber; row++)	// 1차 반복문
	{
		for (column = 1; column <= inputNumber; column++)	// 2차 반복문
		{
			if (column < row)	// 빈칸을 출력하기 위한 조건
				printf(" ");
			else				// 숫자를 출력하기 위한 조건
				printf("%d", row);
		}

		printf("\n");
	}

	printf("\n");
}

/*
	함수 이름 : displayPattern2
	기능 : 인자로 전달된 홀수를 숫자 별로 행을 나누어 좌측 정렬하되, 한 개부터 시작하여 총 개수까지 늘려나간다.
	인자 : inputNumber
	반환값 : 없음
	날짜 : 2021/10/18
*/

void displayPattern2(int inputNumber)
{
	int row, column;	// 각각 행과 열을 나타내는 변수

	for (row = inputNumber; row >= 1; row--)		// 1차 반복문
	{
		for (column = inputNumber; column >= row; column--)	// 2차 반복문
		{
			printf("%d", column);	// 숫자 출력
		}

		printf("\n");
	}

	printf("\n");
}

/*
	함수 이름 : displayPattern3
	기능 : 인자로 전달된 홀수만큼 행렬을 확보하고, 짝수의 배수만큼 우측에 빈 공간을 확보하여 숫자를 정렬한다.
	인자 : inputNumber
	반환값 : 없음
	날짜 : 2021/10/18
*/

void displayPattern3(int inputNumber)
{
	int row, column;	// 각각 행과 열을 나타내는 변수

	for (row = 1; row <= inputNumber; row++)	// 숫자의 개수가 줄어드는 경우에서 1차 반복문
	{
		for (column = 1; column <= inputNumber; column++)	// 2차 반복문
		{
			if (row <= (inputNumber + 1) / 2)	// 전체 행의 절반까지
			{
				if (column <= 2 * (row - 1))	// 빈칸 출력 조건
					printf(" ");

				else
					printf("%d", column);	// 숫자 출력
			}

			else
			{
				if (column <= 2 * (inputNumber - row))	// 전체 행의 절반부터 빈칸 출력 조건
					printf(" ");

				else
					printf("%d", column);	// 숫자 출력
			}
		}

		printf("\n");
	}

	printf("\n");
}

/*
	함수 이름 : displayPattern4
	기능 : 인자로 전달된 홀수만큼 행을 확보하고, 한 행에 하나의 숫자만 적되, 행마다 띄어 쓰는 칸 수를 하나씩 늘려나간다.
	인자 : inputNumber
	반환값 : 없음
	날짜 : 2021/10/18
*/

void displayPattern4(int inputNumber)
{
	int row, column;	// 각각 행과 열을 나타내는 변수

	for (row = 1; row <= inputNumber; row++)		// 1차 반복문
	{
		for (column = 1; column < row; column++)	// 2차 반복문
		{
			printf(" ");	// 빈칸 출력
		}

		printf("%d", row);	// 숫자 출력
		printf("\n");
	}

	printf("\n");
}

/*
	함수 이름 : displayPattern5
	기능 : 행의 번호에 맞춘 숫자와 그 숫자의 개수를 출력하되, 홀수 행은 좌측정렬로, 짝수 행은 우측 정렬로 한다.
	인자 : inputNumber
	반환값 : 없음
	날짜 : 2021/10/18
*/

void displayPattern5(int inputNumber)
{
	int row, column;	// 각각 행과 열을 나타내는 변수

	for (row = 1; row <= inputNumber; row++)	// 1차 반복문
	{
		for (column = 1; column <= inputNumber; column++)	// 2차 반복문
		{
			if (row % 2 == 1)	// 홀수 행
			{
				if (column <= row)
					printf("%d", row);	// 숫자 출력
			}

			else				// 짝수 행
			{
				if (column <= inputNumber - row)	// 빈칸 출력 조건
					printf(" ");

				else
					printf("%d", row);	// 숫자 출력
			}
		}

		printf("\n");
	}

	printf("\n");
}