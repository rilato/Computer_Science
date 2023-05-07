#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int the_number_of_student(void);
void print_max_age(int inputMax);

/*
	�Լ� �̸� : main
	��� : ���ϴ� �ڵ带 ����
	���� : ����
	��ȯ�� : ���������� ����� 0�� ��ȯ
	�ۼ� ��¥ : 2021 / 10 / 22
	�ۼ��� : B735365 ������
*/

int main()
{
	int count = 0;	// �л� ���� ���� �������� count�� ����
	int max = 0;
	int student_ages[10];	// �л����� ���̸� ������ �迭

	count = the_number_of_student();	// �л� ���� �Է¹޴� �Լ� ȣ��

	for (int i = 0; i < count; i++)	// �迭�� ������ �ʱ�ȭ�ϴ� for��
	{
		printf("�л� %d ���� : ", i + 1);
		scanf("%d", &student_ages[i]);
	}

	for (int j = 0; j < count; j++)	// �迭�� ����� �л����� ���̸� ���� �ִ� ���̸� ã�� for��
	{
		if (student_ages[j] > max)
			max = student_ages[j];
	}

	printf("\n");
	print_max_age(max);	// �л��� �ִ� ���̸� ����ϴ� �Լ� ȣ��
	
	return 0;
}

/*
	�Լ� �̸� : the_number_of_student
	��� : �л� ���� �Է¹���
	���� : ����
	��ȯ�� : �л� ���� ��ȯ
	�ۼ� ��¥ : 2021 / 10 / 22
	�ۼ��� : B735365 ������
*/

int the_number_of_student(void)
{
	int number;	// �л� ���� ���� number�� ����

	printf("�л� ���� �Է��Ͻÿ� : ");
	scanf("%d", &number);
	printf("\n");
	return number;
}

/*
	�Լ� �̸� : print_max_age
	��� : �л��� �ִ� ���̸� ����ϴ� �Լ�
	���� : inputMax
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 10 / 22
	�ۼ��� : B735365 ������
*/

void print_max_age(int inputMax)
{
	printf("�л��� �ִ� ���� : %d", inputMax);
}