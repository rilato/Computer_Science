#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 3

#include <stdio.h>
#include <string.h>

/* 함수 선언 */
void get_string(struct order * my_order, int length);
void get_max(struct order * my_order, int length);
void get_average(struct order * my_order, int length);

/* 구조체 선언 */
typedef struct order
{
	char product_name[15];
	int number_of_orders;
}Order;

/*
함수 이름 : main
기능 : 원하는 함수 출력
반환값 : 0(정상 종료)
작성날짜 : 2021/12/03
*/
int main(void)
{
	/* 변수 선언 */
	Order my_order[MAX_LENGTH];

	/* 함수 호출 */
	get_string(my_order, MAX_LENGTH);
	get_max(my_order, MAX_LENGTH);
	get_average(my_order, MAX_LENGTH);

	return 0;
}

/*
함수 이름 : get_string
기능 : 문자열을 입력받아 배열에 저장함
인자 : struct order * my_order, int length
반환값 : 없음
작성날짜 : 2021/12/03
*/
void get_string(struct order * my_order, int length)
{
	/* 변수 선언 */
	int i;
	
	for (i = 0; i < MAX_LENGTH; i++)
	{
		printf("%d번 제품 이름 : ", i + 1);
		gets((my_order + i)->product_name);	// 문자열을 입력받아 해당 배열의 str에 저장

		printf("%d번 주문 수 : ", i + 1);
		scanf("%d%*c", &((my_order + i)->number_of_orders));	// 숫자를 입력받아 해당 배열의 숫자 항목에 저장
	}

	printf("\n");
}

/*
함수 이름 : get_Max
기능 : 최대값 출력
인자 : struct order * my_order, int length
반환값 : 없음
작성날짜 : 2021/12/03
*/
void get_max(struct order * my_order, int length)
{
	/* 변수 선언 */
	int i;
	int max = my_order->number_of_orders;

	for (i = 0; i < length; i++)
	{
		if ((my_order + i)->number_of_orders > max)	// max보다 해당 인덱스 값이 더 크다면
			max = (my_order + i)->number_of_orders;	// max를 더 큰 값으로 교체
	}

	printf("최대 주문 수 : %d\n", max);	// 주문 최대 출력
}

/*
함수 이름 : get_Max
기능 : 평균값 출력
인자 : struct order * my_order, int length
반환값 : 없음
작성날짜 : 2021/12/03
*/
void get_average(struct order * my_order, int length)
{
	/* 변수 선언 */
	int i;
	int sum = 0;
	double average;

	for (i = 0; i < length; i++)
		sum += (my_order + i)->number_of_orders;	// 주문 합 계산

	average = (double)sum / length;	// 주문 평균 계산
	
	printf("평균 주문 수 : %f\n", average);	// 주문 평균 출력
}