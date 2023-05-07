#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/* �Լ� ����.�ڼ��� ������ �� �Լ��� ���� */
void fill_the_array(int original_list[], int input);
void check_multiple_number(int original_list[], int modified_list[], int multiple_condition, int product_number, int len);
void calculate_two_end_values(int original_list[], int modified_list[], int len, int target);
void print_format(int list[], int len);
void get_max(int original_list[], int modified_list[], int len);
void get_min(int original_list[], int modified_list[], int len);


/*
	�Լ� �̸� : main
	��� : ���ϴ� �ڵ带 ����
	���� : ����
	��ȯ�� : ���������� ����� 0�� ��ȯ
	�ۼ� ��¥ : 2021 / 11 / 5
*/

int main()
{
	/* ���� ���� */
	int input;
	int len;
	int multiple_condition, product_number;
	int target;

	int original_list[10] = { 0 };	// �Է¹��� ������ ������ �迭�� �����ϰ� ������ 0���� �ʱ�ȭ
	int modified_list[10] = { 0 };	// �ٸ� �Լ��� ���� ������ ������ ����� �迭�� �����ϰ� ������ 0���� �ʱ�ȭ


	while (1)
	{
		printf("�Է¹��� ������ ���� �Է��Ͻÿ� : ");
		scanf("%d", &input);	// ������ ���� ���ǿ� �´� ���� �Է�
		if (input >= 3 && input <= 10)
			break;
		else
		{
			printf("3 �̻� 10 ������ ������ �ٽ� �Է��Ͻÿ�");
			printf("\n");
			printf("\n");
		}
	}
	

	fill_the_array(original_list, input);	// �Լ� ȣ��. �Լ��� ������ �Լ� �ּ� ����


	len = input;	// �Է¹��� ����ŭ�� �迭�� ���̷� ����


	printf("��� ���ǿ� ���� ���� ���� �ϳ��� ������ ���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d %d", &multiple_condition, &product_number);	// ������ ���� ���ǿ� �´� ���� �Է�

	check_multiple_number(original_list, modified_list, multiple_condition, product_number, len); // �Լ� ȣ��. �Լ��� ������ �Լ� �ּ� ����


	printf("Ư�� ������ �Է��Ͻÿ� : ");
	scanf("%d", &target); // ������ ���� ���ǿ� �´� ���� �Է�


	printf("Ư�� ������ ����Ʈ�� ������ �� �������� �� ���� : ");

	calculate_two_end_values(original_list, modified_list, len, target); // �Լ� ȣ��. �Լ��� ������ �Լ� �ּ� ����

	return 0;
}


/*
	�Լ� �̸� : fill_the_array
	��� : original_list��� �迭�� �Է¹��� ������ ����
	���� : original_list[], input
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 5
*/

void fill_the_array(int original_list[], int input)
{
	/* ���� ���� */
	int i;
	int numbers;

	printf("����Ʈ�� ������ ���� ���� ��� �Է��Ͻÿ� : ");

	/* �ݺ����� ���� �迭�� �� �ε����� �Է¹��� ���� ���� */
	for (i = 0; i < input; i++)
	{
		scanf("%d", &numbers); // �� �Է�
		original_list[i] = numbers; // �迭�� �ش� �� ����
	}
}


/*
	�Լ� �̸� : check_multiple_number
	��� : ���� �Էµ� �迭�� ���޹ް�, �ٸ� �迭�� ������ ������ ��, ���� �迭���� ���ǿ� �´� ����� ����� �迭�� ����
	���� : original_list[], modified_list[], multiple_condition, product_number, len
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 5
*/

void check_multiple_number(int original_list[], int modified_list[], int multiple_condition, int product_number, int len)
{
	/* ���� ���� */
	int i;

	/* �ݺ����� ���� old_list[]�� ����ִ� ������ list[]�� ���� */
	for (i = 0; i < len; i++)
		modified_list[i] = original_list[i];

	/* �ݺ����� ���� old_list[]�� ����ִ� ���� Ư�� ���ǿ� �´� ���, list[]������ ���� */
	for (i = 0; i < len; i++)
	{
		if (original_list[i] % multiple_condition != 0) // �迭�� Ư�� ���� �Է� ���� ���� ����� �ƴϸ�
			modified_list[i] *= product_number; // �ش� ���� product_number�� ���� ������ ����
	}
}


/*
	�Լ� �̸� : calculate_two_end_values
	��� : �迭�� ���鿡�� target�� �� ��, �� ���� ���밪�� ���Ͽ� modified_list[]�� ����. ���� get_max�� get_min�� ȣ���Ͽ� ���� ���޹޾� ���
	���� : modified_list[], len, target
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 5
*/

void calculate_two_end_values(int original_list[], int modified_list[], int len, int target)
{
	/* ���� ���� */
	int i;

	/* �ݺ����� ���� �迭�� ������ tqrget�� �� ��, ���밪�� ���Ͽ� modified_list[]�� ���� */
	for (i = 0; i < len; i++)
	{
		modified_list[i] -= target; // �� - target

		if (modified_list[i] < 0) // ���ŵ� ���� �����̸�
			modified_list[i] = -modified_list[i]; // ����� �ٲ���
	}

	print_format(modified_list, len); // print_format �Լ� ȣ��. �Լ��� ������ �Լ� �ּ� ����
	printf("\n");

	printf("Ư�� ������ �� ���̰� ���� ū (�����Ǳ� ����) ���� : ");
	get_max(original_list, modified_list, len); // get_max �Լ� ȣ��. �Լ��� ������ �Լ� �ּ� ����
	printf("\n");

	printf("Ư�� ������ �� ���̰� ���� ���� (�����Ǳ� ����) ���� : ");
	get_min(original_list, modified_list, len); // get_min �Լ� ȣ��. �Լ��� ������ �Լ� �ּ� ����
	printf("\n");
}


/*
	�Լ� �̸� : print_format
	��� : �迭�� ��� ������ ����
	���� : list[], len
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 5
*/

void print_format(int list[], int len)
{
	/* ���� ���� */
	int i;

	/* �ݺ����� ���� list�� ������ ���ʴ�� ��� */
	for (i = 0; i < len; i++)
		printf("%d ", list[i]);
}


/*
	�Լ� �̸� : get_max
	��� : �迭�� ���� �� �ִ밪�� ã��, �ش� �ִ밪�� ���� �ε����� ã��. �� �ε����� ���� old_list���� �ش� �ε��� ���� ã�� �װ��� ���
	���� : original_list[], modified_list[], len
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 5
*/

void get_max(int original_list[], int modified_list[], int len)
{
	/* ���� ���� */
	int i;
	int max;

	max = modified_list[0]; // list�� 0��° ���� max�� ����

	/* �ݺ����� ���� �ִ밪 ���� */
	for (i = 0; i < len; i++)
	{
		if (max < modified_list[i]) // �ִ밪�� Ư�� �ε����� ������ ������
			max = modified_list[i]; // �� ������ �ִ밪�� ����
	}

	/* �ݺ����� ���� �ִ밪�� ���� �� �־��� ���� ������ old_list���� ã�Ƴ� */
	for (i = 0; i < len; i++)
	{
		if (max == modified_list[i]) // �ִ밪�� ���� �ε����� ã��
			printf("%d ", original_list[i]); // �� �ε����� �ش��ϴ� ���� �迭�� ���� ���
	}
}


/*
	�Լ� �̸� : get_min
	��� : �迭�� ���� �� �ּҰ��� ã��, �ش� �ּҰ��� ���� �ε����� ã��. �� �ε����� ���� old_list���� �ش� �ε��� ���� ã�� �װ��� ���
	���� : old_list[], list[], len
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 5
*/

void get_min(int original_list[], int modified_list[], int len)
{
	/* ���� ���� */
	int i;
	int min;

	min = modified_list[0]; // list�� 0��° ���� min���� ����

	/* �ݺ����� ���� �ּҰ� ���� */
	for (i = 0; i < len; i++)
	{
		if (min > modified_list[i]) // �ּҰ��� Ư�� �ε����� ������ ������
			min = modified_list[i]; // �� ������ �ּҰ��� ����
	}
	
	/* �ݺ����� ���� �ּҰ��� ���� �� �־��� ���� ������ old_list���� ã�Ƴ� */
	for (i = 0; i < len; i++)
	{
		if (min == modified_list[i]) // �ּҰ��� ���� �ε����� ã��
			printf("%d ", original_list[i]); // �� �ε����� �ش��ϴ� ���� �迭�� ���� ���
	}
}