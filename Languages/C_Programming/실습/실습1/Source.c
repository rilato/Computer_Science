// 59_B735365_경영학과_이윤식
// 1. 소스파일과
// 2. 콘솔창 캡쳐 후
// 3. 두 개를 압축하여 제출

#include <stdio.h>

int main()
{
	int score1, score2, score3, answer;

	printf("1번 실습 점수 : ");
	scanf("%d", &score1);
	printf("2번 실습 점수 : ");
	scanf("%d", &score2);
	printf("3번 실습 점수 : ");
	scanf("%d", &score3);

	answer = score1 * 1 + score2 * 2 + score3 * 3;	// 결과 값을 변수에 저장

	printf("가중합 : %d*1 + %d*2 + %d*3 = %d", score1, score2, score3, answer);	// 가중합 출력
	
	return 0;
}