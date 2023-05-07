// 59_B735365_�濵�а�_������
// �Ǽ��� �޾Ƽ� �Ǽ��� �����κ��� �����Ͽ� ���� (type cast�� �ڷ��� ��ȯ)
// �� ������ �޾Ƽ� ���� ���� ���� ū ������ ���� ���� ���� ���� >= 0

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int squareNumber(double);
int productNumber(int, int);

int main()
{
	double number1, number2; // �Է��� ���� �Ǽ� ���� ���� number1�� number2�� ����
	int squareResult1, squareResult2; // ������ ����� �����ϴ� ����
	int productResult;	// ���� ���� ���� �����ϴ� ����

	printf("�� �Ǽ��� �Է��Ͻÿ� : ");
	scanf("%lf %lf", &number1, &number2);

	squareResult1 = squareNumber(number1);	// ������ ����� squareResult1�� ����
	squareResult2 = squareNumber(number2);	// ������ ����� squareResult2�� ����

	productResult = productNumber(squareResult1, squareResult2);	// ������ ����� ���� ���� ���� ���

	printf("%f�� %f�� ���� �κ��� ���� ���� ���� ���� ���� %d�Դϴ�.", number1, number2, productResult);

	return 0;
}

/*
	�Լ� �̸� : squareNumber
	��� : ���ڷ� ���޵� �Ǽ��� ������ ��ȯ�Ͽ� ������ ���� ��ȯ.
	��ȯ�� : ������ ������
	��¥ : 2021/10/15
*/

int squareNumber(double number)
{
	int result;

	result = ((int)number) * ((int)number);	// �Ǽ� ���� ������ �ٲپ� ����

	return result;
}

/*
	�Լ� �̸� : productNumber
	��� : ���ڷ� ���޵� �� ���� ���� ���� ���ϰ�, �� ���� ����.
	��ȯ�� : �� ���� ���� ���� ���� �� ���� ��
	��¥ : 2021/10/15
*/

int productNumber(int number1, int number2)
{
	int product, total, difference;

	product = number1 * number2;	// �� ���
	total = number1 + number2;	// �� ���
	difference = product - total;	// ���� ���� �� ���

	if (product >= total)	// �� >= ���̸�
		return difference;	// �״�� ���̰� ���
	else					// �� < ���̸�
		return (-1) * difference;	// ���̰��� -�� �ٿ� ����� �ٲ� �� ���
}