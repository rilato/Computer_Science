// 59_B735365_�濵�а�_������

#include <stdio.h>

int main()
{
	int hw1, hw2, hw3; // hw1 : 1�� ����, hw2 : 2�� ����, hw3 : 3�� ����
	double c_hw1, c_hw2, c_hw3, avg;
	// c_hw1 : 1�� ���� ��ȯ��, c_hw2 : 2�� ���� ��ȯ��, c_hw3 : 3�� ���� ��ȯ��, avg : ���

	printf("1�� ���� ���� : ");
	scanf("%d", &hw1);	// ����1 ���� �Է�
	printf("2�� ���� ���� : ");
	scanf("%d", &hw2);	// ����2 ���� �Է�
	printf("3�� ���� ���� : ");
	scanf("%d", &hw3);	// ����3 ���� �Է�

	c_hw1 = 0.2 * hw1;	// ��ȯ��
	c_hw2 = 0.3 * hw2;
	c_hw3 = 0.5 * hw3;

	avg = c_hw1 + c_hw2 + c_hw3;	// ���

	printf("1�� ���� ��ȯ ����(20%%) : %f\n", c_hw1);
	printf("1�� ���� ��ȯ ����(30%%) : %f\n", c_hw2);
	printf("1�� ���� ��ȯ ����(50%%) : %f\n", c_hw3);

	printf("�� ��ȯ ������ �� : %f", avg);

	return 0;
}