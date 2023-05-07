#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* �Լ� ����, �ڼ��� ������ �� �Լ� ���� */
void print_arrange(char* str, int src[][2]);
int compare_rows_of_arrays(int src1[][2], int src2[][2], int target_row);

/*
	�Լ� �̸� : main
	��� : ���ϴ� �ڵ带 ����
	���� : ����
	��ȯ�� : ���������� ����� 0�� ��ȯ
	�ۼ� ��¥ : 2021 / 11 / 12
*/

int main()
{
	/* ���� ���� �� �迭 �ʱ�ȭ */
	int i, answer;
	int source1[3][2] = { {1, 2}, {3, 4}, {5, 6} };
	int source2[3][2] = { {1, 2}, {3, 5}, {5, 6} };

	print_arrange("source1 :", source1);
	print_arrange("source2 :", source2);

	printf("�� ���� �� ���:");
	printf("\n");

	for (i = 0; i < 3; i++)	// �ݺ����� ���� �� �迭�� ���� ���� ���ϰ�, �� ���� ��� 
	{
		answer = compare_rows_of_arrays(source1, source2, i);
		printf("%d", answer);

		if (i == 2)	// ������ �Ϳ��� �޸��� ������ ���� �����ϱ� ����
			break;

		printf(", ");
	}
		
	return 0;
}

/*
	�Լ� �̸� : print_arrange
	��� : �迭�� ��� ������ ����
	���� : char* str, src[][2]
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 12
*/

void print_arrange(char* str, int src[][2])
{
	/* ���� ���� */
	int i, j;

	printf("%s", str);
	printf("\n");

	for (i = 0; i < 3; i++)	// �ݺ����� ���� �迭�� �׸��� ���
	{
		for (j = 0; j < 2; j++)
			printf("%d ", src[i][j]);
		printf("\n");
	}

}

/*
	�Լ� �̸� : compare_rows_of_arrays
	��� : �� �迭�� ���� ���� ���ϰ�, �� ���� ������ 1�� ��ȯ�ϰ�, �׷��� ������ 0�� ��ȯ
	���� : src1[][2], src2[][2], target_row
	��ȯ�� : 1 �Ǵ� 0
	�ۼ� ��¥ : 2021 / 11 / 12
*/

int compare_rows_of_arrays(int src1[][2], int src2[][2], int target_row)
{
	/* ���� ���� */
	int j;
	int sum_of_src1 = 0;
	int sum_of_src2 = 0;

	for (j = 0; j < 2; j++)	// �ݺ����� ���� �迭 src1�� ���� ���� ����
		sum_of_src1 += src1[target_row][j];

	for (j = 0; j < 2; j++)	// �ݺ����� ���� �迭 src2�� ���� ���� ����
		sum_of_src2 += src2[target_row][j];

	if (sum_of_src1 == sum_of_src2)	// �� �迭�� ���� ���� ������ 1�� ��ȯ
		return 1;
	else // �� �迭�� ���� ���� �ٸ��� 0�� ��ȯ
		return 0;
}