// 59_B735365_�濵�а�_������
// �������� ���̸� �Է� �޾Ƽ� ��� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ��, �ݺ����� ����ϰ� ������ �Է� �޾Ƽ� ��� ���� �Ҽ� ù°¥������ ����Ͻÿ�.

#include <stdio.h>

int main()
{
	int i = 1;
	int num, age, sum = 0;
	double avg = 0;

	printf("���� ���� �Է��Ͻÿ� : ");
	scanf("%d", &num);	// ���� �� �Է�

	while (i <= num)
	{
		printf("���� %d ���� : ", i);
		scanf("%d", &age);	// ���� �Է�
		sum += age;
		i++;
	}

	avg = (double)sum / num;	// type casting�� �̿��� �� ��ȯ

	printf("%d�� �������� ���� ����� %.1f���Դϴ�.", num, avg);	// ��� ���� ���

	return 0;
}