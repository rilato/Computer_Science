#include <stdio.h>
#include <string.h>

//�Լ� ����
void get_string(char str[]);
int count_space(char str[]);
void print_last_word(char str[], int space);

/*
�Լ� �̸� : main
��� : ���ϴ� �Լ� ���
��ȯ�� : 0(���� ����)
�ۼ���¥ : 2021/11/26
*/
int main(void)
{
	/* ���� ���� */
	char str[30] = { 0, }; // �ʱ�ȭ
	int space;

	/* �Լ� ȣ�� */
	get_string(str);
	space = count_space(str);
	print_last_word(str, space);

	return 0;
}

/*
�Լ� �̸� : get_string
��� : ���ڿ��� �Է¹޾� �迭�� ������
���� : char str[] (������ �迭)
��ȯ�� : ����
�ۼ���¥ : 2021/11/26
*/
void get_string(char str[])
{
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets(str);	// ���ڿ��� �Է¹޾� str�� ����
}

/*
�Լ� �̸� : count_space
��� : ���ڿ����� ������ ������ ��
���� : char str[] (������ �迭)
��ȯ�� : ������ ����
�ۼ���¥ : 2021/11/26
*/
int count_space(char str[])
{
	/* ���� ���� */
	int i;
	int count = 0;

	for (i = 0; i < 30; i++)
		if (str[i] == ' ')	// ������ ���� ����
			++count;
	
	return count;
}

/*
�Լ� �̸� : print_last_word
��� : ���ڿ��� ���Ŀ� �°� ���
���� : char str[] (������ �迭), int space (���� ����)
�ۼ���¥ : 2021/11/26
*/
void print_last_word(char str[], int space)
{
	/* ���� ���� */
	int i;
	int count = 0;

	for (i = 0; i < 30; i++)
	{
		if (str[i] == ' ')	// ������ ���� ����
		{
			++count;
			continue;
		}

		if (count == space)	// ���⸦ ������ �� ������ �� ������ ������ ���ٸ�
		{
			if (str[i] == '.')
				break;
			printf("%c", str[i]);	// ��ħǥ�� ���� ���ڿ��� ���
		}
	}
}