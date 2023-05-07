// 59_B735365_경영학과_이윤식

#include <stdio.h>

int main()
{
	int hw1, hw2, hw3; // hw1 : 1번 과제, hw2 : 2번 과제, hw3 : 3번 과제
	double c_hw1, c_hw2, c_hw3, avg;
	// c_hw1 : 1번 과제 변환값, c_hw2 : 2번 과제 변환값, c_hw3 : 3번 과제 변환값, avg : 평균

	printf("1번 과제 점수 : ");
	scanf("%d", &hw1);	// 과제1 점수 입력
	printf("2번 과제 점수 : ");
	scanf("%d", &hw2);	// 과제2 점수 입력
	printf("3번 과제 점수 : ");
	scanf("%d", &hw3);	// 과제3 점수 입력

	c_hw1 = 0.2 * hw1;	// 변환값
	c_hw2 = 0.3 * hw2;
	c_hw3 = 0.5 * hw3;

	avg = c_hw1 + c_hw2 + c_hw3;	// 평균

	printf("1번 과제 변환 점수(20%%) : %f\n", c_hw1);
	printf("1번 과제 변환 점수(30%%) : %f\n", c_hw2);
	printf("1번 과제 변환 점수(50%%) : %f\n", c_hw3);

	printf("총 변환 점수의 합 : %f", avg);

	return 0;
}