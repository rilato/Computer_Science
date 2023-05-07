// 59_B735365_경영학과_이윤식
// 실수를 받아서 실수의 정수부분을 제곱하여 리턴 (type cast로 자료형 변환)
// 두 정수를 받아서 곱과 합을 만들어서 큰 값에서 작은 값을 빼서 리턴 >= 0

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int squareNumber(double);
int productNumber(int, int);

int main()
{
	double number1, number2; // 입력을 받을 실수 값을 변수 number1과 number2로 설정
	int squareResult1, squareResult2; // 제곱한 결과를 저장하는 변수
	int productResult;	// 곱과 합의 차를 저장하는 변수

	printf("두 실수를 입력하시오 : ");
	scanf("%lf %lf", &number1, &number2);

	squareResult1 = squareNumber(number1);	// 제곱한 결과를 squareResult1에 저장
	squareResult2 = squareNumber(number2);	// 제곱한 결과를 squareResult2에 저장

	productResult = productNumber(squareResult1, squareResult2);	// 제곱한 결과의 곱과 합의 차를 계산

	printf("%f과 %f의 정수 부분의 제곱 값의 곱과 합의 차는 %d입니다.", number1, number2, productResult);

	return 0;
}

/*
	함수 이름 : squareNumber
	기능 : 인자로 전달된 실수를 정수로 변환하여 제곱한 값을 반환.
	반환값 : 정수의 제곱값
	날짜 : 2021/10/15
*/

int squareNumber(double number)
{
	int result;

	result = ((int)number) * ((int)number);	// 실수 값을 정수로 바꾸어 제곱

	return result;
}

/*
	함수 이름 : productNumber
	기능 : 인자로 전달된 두 수의 곱과 합을 구하고, 그 차를 구함.
	반환값 : 두 수의 곱과 합의 차이 중 양의 값
	날짜 : 2021/10/15
*/

int productNumber(int number1, int number2)
{
	int product, total, difference;

	product = number1 * number2;	// 곱 계산
	total = number1 + number2;	// 합 계산
	difference = product - total;	// 곱과 합의 차 계산

	if (product >= total)	// 곱 >= 합이면
		return difference;	// 그대로 차이값 출력
	else					// 곱 < 합이면
		return (-1) * difference;	// 차이값에 -를 붙여 양수로 바꾼 후 출력
}