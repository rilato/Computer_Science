// 59_B735365_경영학과_이윤식
// 직원들의 나이를 입력 받아서 평균 나이를 구하는 프로그램을 작성하시오.
// 단, 반복문을 사용하고 정수로 입력 받아서 결과 값은 소수 첫째짜리까지 출력하시오.

#include <stdio.h>

int main()
{
	int i = 1;
	int num, age, sum = 0;
	double avg = 0;

	printf("직원 수를 입력하시오 : ");
	scanf("%d", &num);	// 직원 수 입력

	while (i <= num)
	{
		printf("직원 %d 나이 : ", i);
		scanf("%d", &age);	// 나이 입력
		sum += age;
		i++;
	}

	avg = (double)sum / num;	// type casting을 이용한 형 변환

	printf("%d명 직원들의 나이 평균은 %.1f세입니다.", num, avg);	// 평균 나이 출력

	return 0;
}