// 59_B735365_�濵�а�_������
// 1. �ҽ����ϰ�
// 2. �ܼ�â ĸ�� ��
// 3. �� ���� �����Ͽ� ����

#include <stdio.h>

int main()
{
	int score1, score2, score3, answer;

	printf("1�� �ǽ� ���� : ");
	scanf("%d", &score1);
	printf("2�� �ǽ� ���� : ");
	scanf("%d", &score2);
	printf("3�� �ǽ� ���� : ");
	scanf("%d", &score3);

	answer = score1 * 1 + score2 * 2 + score3 * 3;	// ��� ���� ������ ����

	printf("������ : %d*1 + %d*2 + %d*3 = %d", score1, score2, score3, answer);	// ������ ���
	
	return 0;
}