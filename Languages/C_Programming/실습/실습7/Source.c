#include <stdio.h>
#include <stdlib.h>

void add_two_integers(int src1[], int src2[], int dest[], int len);
void print_array(char* array_name, int input_array[], int len);

/*
	�Լ� �̸� : main
	��� : ���ϴ� �ڵ带 ����
	���� : ����
	��ȯ�� : ���������� ����� 0�� ��ȯ
	�ۼ� ��¥ : 2021 / 11 / 5
	�ۼ��� : B735365 ������
*/

int main()
{
	int source1[5] = { -2, 4, -3, 1, 5 };	// �迭 ���� �� �� �ʱ�ȭ
	int source2[5] = { 6, -7, 2, 3, -1 };
	int destination[5] = { 0 };
	int i;
	int len;

	len = sizeof(source1) / sizeof(int);	// �迭�� ����. �� 5

	add_two_integers(source1, source2, destination, len);	// �迭�� �׸��� ���ϴ� �Լ� ȣ��

	print_array("source1", source1, len); // ��� ������ ���س��� �Լ��� ȣ��
	print_array("source2", source2, len);
	print_array("destination", destination, len);

	return 0;
}

/*
	�Լ� �̸� : add_two_integers
	��� : �迭 �� ���� ���̸� �Է¹ް� �迭�� ���
	���� : int src1[], int src2[], int len
	��ȯ�� : dest[]. src1[]�� src2[]�� �׸���� ���� ������ ������ �迭�� ��ȯ
	�ۼ� ��¥ : 2021 / 11 / 5
	�ۼ��� : B735365 ������
*/

void add_two_integers(int src1[], int src2[], int dest[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		dest[i] = src1[i] + src2[i];
}

/*
	�Լ� �̸� : print_array
	��� : �迭�� �̸��� �迭�� �ּҸ� ���޹ް�, �ش� �迭�� ������ ������Ŀ� ���߾� ���
	���� : char* array_name, int input_array[], int len
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 5
	�ۼ��� : B735365 ������
*/
void print_array(char* array_name, int input_array[], int len)
{
	int i;

	printf("%s : ", array_name);
	for (i = 0; i < len - 1; i++)
		printf("%d, ", input_array[i]);	// input_array[]�� ����� ������ ���
	printf("%d", input_array[len - 1]); // �迭�� ������ ���� ���
	printf("\n");
}