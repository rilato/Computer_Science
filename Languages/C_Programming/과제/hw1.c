#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void displayPattern1(int inputNumber);
void displayPattern2(int inputNumber);
void displayPattern3(int inputNumber);
void displayPattern4(int inputNumber);
void displayPattern5(int inputNumber);

int main()
{
	int input; // �Է��� ���� ���� ���� input���� ����

	printf("3 �̻� 7 ������ ���� Ȧ�� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &input);
	printf("\n");

	/*
		������ �Լ� ����
	*/
	displayPattern1(input);
	displayPattern2(input);
	displayPattern3(input);
	displayPattern4(input);
	displayPattern5(input);

	return 0;
}

/*
	�Լ� �̸� : displayPattern1
	��� : ���ڷ� ���޵� Ȧ���� ���� ���� ���� ������ ���� �����ϵ�, �� �����κ��� �ϳ��� �ٿ�������.
	���� : inputNumber
	��ȯ�� : ����
	��¥ : 2021/10/18
*/

void displayPattern1(int inputNumber)
{
	int row, column;	// ���� ��� ���� ��Ÿ���� ����

	for (row = 1; row <= inputNumber; row++)	// 1�� �ݺ���
	{
		for (column = 1; column <= inputNumber; column++)	// 2�� �ݺ���
		{
			if (column < row)	// ��ĭ�� ����ϱ� ���� ����
				printf(" ");
			else				// ���ڸ� ����ϱ� ���� ����
				printf("%d", row);
		}

		printf("\n");
	}

	printf("\n");
}

/*
	�Լ� �̸� : displayPattern2
	��� : ���ڷ� ���޵� Ȧ���� ���� ���� ���� ������ ���� �����ϵ�, �� ������ �����Ͽ� �� �������� �÷�������.
	���� : inputNumber
	��ȯ�� : ����
	��¥ : 2021/10/18
*/

void displayPattern2(int inputNumber)
{
	int row, column;	// ���� ��� ���� ��Ÿ���� ����

	for (row = inputNumber; row >= 1; row--)		// 1�� �ݺ���
	{
		for (column = inputNumber; column >= row; column--)	// 2�� �ݺ���
		{
			printf("%d", column);	// ���� ���
		}

		printf("\n");
	}

	printf("\n");
}

/*
	�Լ� �̸� : displayPattern3
	��� : ���ڷ� ���޵� Ȧ����ŭ ����� Ȯ���ϰ�, ¦���� �����ŭ ������ �� ������ Ȯ���Ͽ� ���ڸ� �����Ѵ�.
	���� : inputNumber
	��ȯ�� : ����
	��¥ : 2021/10/18
*/

void displayPattern3(int inputNumber)
{
	int row, column;	// ���� ��� ���� ��Ÿ���� ����

	for (row = 1; row <= inputNumber; row++)	// ������ ������ �پ��� ��쿡�� 1�� �ݺ���
	{
		for (column = 1; column <= inputNumber; column++)	// 2�� �ݺ���
		{
			if (row <= (inputNumber + 1) / 2)	// ��ü ���� ���ݱ���
			{
				if (column <= 2 * (row - 1))	// ��ĭ ��� ����
					printf(" ");

				else
					printf("%d", column);	// ���� ���
			}

			else
			{
				if (column <= 2 * (inputNumber - row))	// ��ü ���� ���ݺ��� ��ĭ ��� ����
					printf(" ");

				else
					printf("%d", column);	// ���� ���
			}
		}

		printf("\n");
	}

	printf("\n");
}

/*
	�Լ� �̸� : displayPattern4
	��� : ���ڷ� ���޵� Ȧ����ŭ ���� Ȯ���ϰ�, �� �࿡ �ϳ��� ���ڸ� ����, �ึ�� ��� ���� ĭ ���� �ϳ��� �÷�������.
	���� : inputNumber
	��ȯ�� : ����
	��¥ : 2021/10/18
*/

void displayPattern4(int inputNumber)
{
	int row, column;	// ���� ��� ���� ��Ÿ���� ����

	for (row = 1; row <= inputNumber; row++)		// 1�� �ݺ���
	{
		for (column = 1; column < row; column++)	// 2�� �ݺ���
		{
			printf(" ");	// ��ĭ ���
		}

		printf("%d", row);	// ���� ���
		printf("\n");
	}

	printf("\n");
}

/*
	�Լ� �̸� : displayPattern5
	��� : ���� ��ȣ�� ���� ���ڿ� �� ������ ������ ����ϵ�, Ȧ�� ���� �������ķ�, ¦�� ���� ���� ���ķ� �Ѵ�.
	���� : inputNumber
	��ȯ�� : ����
	��¥ : 2021/10/18
*/

void displayPattern5(int inputNumber)
{
	int row, column;	// ���� ��� ���� ��Ÿ���� ����

	for (row = 1; row <= inputNumber; row++)	// 1�� �ݺ���
	{
		for (column = 1; column <= inputNumber; column++)	// 2�� �ݺ���
		{
			if (row % 2 == 1)	// Ȧ�� ��
			{
				if (column <= row)
					printf("%d", row);	// ���� ���
			}

			else				// ¦�� ��
			{
				if (column <= inputNumber - row)	// ��ĭ ��� ����
					printf(" ");

				else
					printf("%d", row);	// ���� ���
			}
		}

		printf("\n");
	}

	printf("\n");
}