#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 3

#include <stdio.h>
#include <string.h>

/* �Լ� ���� */
void get_string(struct order * my_order, int length);
void get_max(struct order * my_order, int length);
void get_average(struct order * my_order, int length);

/* ����ü ���� */
typedef struct order
{
	char product_name[15];
	int number_of_orders;
}Order;

/*
�Լ� �̸� : main
��� : ���ϴ� �Լ� ���
��ȯ�� : 0(���� ����)
�ۼ���¥ : 2021/12/03
*/
int main(void)
{
	/* ���� ���� */
	Order my_order[MAX_LENGTH];

	/* �Լ� ȣ�� */
	get_string(my_order, MAX_LENGTH);
	get_max(my_order, MAX_LENGTH);
	get_average(my_order, MAX_LENGTH);

	return 0;
}

/*
�Լ� �̸� : get_string
��� : ���ڿ��� �Է¹޾� �迭�� ������
���� : struct order * my_order, int length
��ȯ�� : ����
�ۼ���¥ : 2021/12/03
*/
void get_string(struct order * my_order, int length)
{
	/* ���� ���� */
	int i;
	
	for (i = 0; i < MAX_LENGTH; i++)
	{
		printf("%d�� ��ǰ �̸� : ", i + 1);
		gets((my_order + i)->product_name);	// ���ڿ��� �Է¹޾� �ش� �迭�� str�� ����

		printf("%d�� �ֹ� �� : ", i + 1);
		scanf("%d%*c", &((my_order + i)->number_of_orders));	// ���ڸ� �Է¹޾� �ش� �迭�� ���� �׸� ����
	}

	printf("\n");
}

/*
�Լ� �̸� : get_Max
��� : �ִ밪 ���
���� : struct order * my_order, int length
��ȯ�� : ����
�ۼ���¥ : 2021/12/03
*/
void get_max(struct order * my_order, int length)
{
	/* ���� ���� */
	int i;
	int max = my_order->number_of_orders;

	for (i = 0; i < length; i++)
	{
		if ((my_order + i)->number_of_orders > max)	// max���� �ش� �ε��� ���� �� ũ�ٸ�
			max = (my_order + i)->number_of_orders;	// max�� �� ū ������ ��ü
	}

	printf("�ִ� �ֹ� �� : %d\n", max);	// �ֹ� �ִ� ���
}

/*
�Լ� �̸� : get_Max
��� : ��հ� ���
���� : struct order * my_order, int length
��ȯ�� : ����
�ۼ���¥ : 2021/12/03
*/
void get_average(struct order * my_order, int length)
{
	/* ���� ���� */
	int i;
	int sum = 0;
	double average;

	for (i = 0; i < length; i++)
		sum += (my_order + i)->number_of_orders;	// �ֹ� �� ���

	average = (double)sum / length;	// �ֹ� ��� ���
	
	printf("��� �ֹ� �� : %f\n", average);	// �ֹ� ��� ���
}