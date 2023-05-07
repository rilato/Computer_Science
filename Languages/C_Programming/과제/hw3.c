#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*�Լ� ����. �ڼ��� ������ �� �Լ��� ����*/
void fill_the_array(char input_str[]);
int fill_the_two_dimensional_array(char input_str[], char word_list[][20]);
void print_two_dimensional_array(char word_list[][20], int row_numbers);
void change_word(char original_word_list[][20], char modified_word_list[][20], int row_numbers);
void print_changed_word(char word_list[][20], int row_numbers);
int check_ascend(char word_list[][20]);
void compare_word(char word_list[][20], char my_list[], int check, int first_word_len, int second_word_len);
void print_missing_word(char my_list[], int check);

/*
	�Լ� �̸� : main
	��� : ���ϴ� �ڵ带 ����
	���� : ����
	��ȯ�� : ���������� ����� 0�� ��ȯ
	�ۼ� ��¥ : 2021 / 11 / 25
*/
int main()
{
	/* ���� ���� */
	int row_numbers;
	int check;
	int first_word_len, second_word_len;

	char input_str[50] = { 0, };
	char word_list[10][20] = { 0, };
	char modified_word_list[10][20] = { 0, };	// �Լ��� ���� ����� word_list�� ������
	char my_list[50] = { 0, };				// ��ġ�� �ʴ� ���ڵ��� ����

	/* 1�� */
	fill_the_array(input_str);	// ���ڿ��� �Է¹޴� �Լ�
	printf("- 1��\n");
	row_numbers = fill_the_two_dimensional_array(input_str, word_list);	// row_numbers�� �Լ����� ȣ��� ����� ������
	print_two_dimensional_array(word_list, row_numbers);	// ���� 1���� �䱸�ϴ� ��� ���Ŀ� �°� ���

	/* 2�� */
	printf("- 2��\n");
	change_word(word_list, modified_word_list, row_numbers);	// ���� 2���� �䱸�ϴ� ���ǿ� �°� word_list�� �����Ͽ� modified_word_list�� ����
	print_changed_word(modified_word_list, row_numbers);	// ���� 2���� �䱸�ϴ� ��� ���Ŀ� �°� ���

	/* 3�� */
	first_word_len = strlen(word_list[0]);	// word_list�� ù ��° �ܾ��� ���̸� ����
	second_word_len = strlen(word_list[1]);	// word_list�� �� ��° �ܾ��� ���̸� ����

	printf("- 3��\n");
	check = check_ascend(word_list);	// ������������ Ȯ���ϴ� �Լ��� ȣ���ϰ� ����� ����
	compare_word(word_list, my_list, check, first_word_len, second_word_len);	// ù ��° �ܾ�� �� ��° �ܾ ���Ͽ� ��ġ�� �ܾ� �ڸ��� 0���� ����
	print_missing_word(my_list, check);	// ���� 3���� �䱸�ϴ� ��� ���Ŀ� �°� ���

	return 0;
}

/*
	�Լ� �̸� : fill_the_array
	��� : ���ڿ��� �Է¹���
	���� : input_str[] (������ �迭)
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 25
*/
void fill_the_array(char input_str[])
{
	printf("���ڿ��� �Է��Ͻÿ� : ");
	gets(input_str);	// ���ڸ� �Է¹޾� input_str�� ����
	printf("\n");
}

/*
	�Լ� �̸� : fill_the_two_dimensional_array
	��� : ������ �迭���� �ܾ �����Ͽ� ������ �迭�� ����
	���� : input_str[] (������ �迭), word_list[][20] (������ �迭)
	��ȯ�� : �ܾ��� ������ ��ȯ
	�ۼ� ��¥ : 2021 / 11 / 25
*/
int fill_the_two_dimensional_array(char input_str[], char word_list[][20])
{
	/* ���� ���� */
	int i = 0, j, k;
	int count = 0;

	while (1)
	{
		if (i >= 50)	// input_str�� ���̸� �Ѿ�� Ż��
			break;

		for (j = 0; j < 10; j++)	// ������ �迭�� ��ȸ�� ���� for��
		{
			while (input_str[i] == ' ')	// �� ĭ�� ������ i�� �ø�
				++i;

			for (k = 0; k < 20; k++)	// ������ �迭�� ��ȸ�� ���� for��
			{
				if (input_str[i] != ' ' && input_str[i] != '.')	// ���� �Ǵ� ��ħǥ�� ������ �ǳʶ�
				{
					word_list[j][k] = input_str[i];	// ������ �迭���� �ѱ��ھ� �޾Ƽ� ������ �迭�� �˸��� �ڸ��� ����
					++i;	// ������ �迭�� ��ȸ�� ���� ��
				}
			}

			while (input_str[i] == ' ')	// �� ĭ�� ������ i�� �ø�
				++i;
		}
	}

	for (i = 0; i < 10; i++)
	{
		if (word_list[i][0] == 0)	// ������ �迭�� �� �ձ��ڰ� 0�̸� Ż��
			break;
		++count;	// ������ �迭���� �������� ���ڿ��� ���� ���� ������ ��.
	}

	return count;	// �ܾ��� ������ ��ȯ
}

/*
	�Լ� �̸� : print_two_dimensional_array
	��� : ������ �迭�� �׸��� ���Ŀ� �°� ���
	���� : word_list[][20] (������ �迭), row_numbers (��ȿ�� ���� ����)
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 25
*/
void print_two_dimensional_array(char word_list[][20], int row_numbers)
{
	/* ���� ���� */
	int i;

	for (i = 0; i < row_numbers; i++)
		printf("word_list[%d] -> %s\n", i, word_list[i]);	// ���Ŀ� �°� ���

	printf("\n");
}

/*
	�Լ� �̸� : change_word
	��� : original_word_list�� ���ǿ� �°� �����Ͽ� modified_word_list�� ����
	���� : original_word_list[][20] (���� ������ �迭), modified_word_list[][20] (������ ������ �迭), row_numbers (��ȿ�� ���� ����)
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 25
*/
void change_word(char original_word_list[][20], char modified_word_list[][20], int row_numbers)
{
	/* ���� ���� */
	int i, j, len;

	for (i = 0; i < row_numbers; i++)
	{
		len = strlen(original_word_list[i]);	// ���� ������ �迭�� �� ���� ���̸� ����

		if (len % 2 == 0)	// ���� �ܾ� ���̰� ¦���̸�
		{
			for (j = 0; j < len / 2; j++)
			{
				modified_word_list[i][j] = original_word_list[i][len / 2 + j];	// ���� ������ �迭�� ������ �������� ������ ���ڿ��� ���ο� ������ �迭�� �������� �̵�
				modified_word_list[i][len / 2 + j] = original_word_list[i][j];	// ���� ������ �迭�� ������ �������� ������ ���ڿ��� ���ο� ������ �迭�� �������� �̵�
			}
		}
		else			// ���� �ܾ� ���̰� Ȧ���̸�
		{
			for (j = 0; j < (len + 1) / 2; j++)
			{
				modified_word_list[i][j] = original_word_list[i][(len + 1) / 2 + j];	// ���� ������ �迭�� ������ �������� ������ ���ڿ��� ���ο� ������ �迭�� �������� �̵�
				modified_word_list[i][(len + 1) / 2 + j] = original_word_list[i][j];	// ���� ������ �迭�� ������ �������� ������ ���ڿ��� ���ο� ������ �迭�� �������� �̵�
			}

			for (j = 0; j < (len + 1) / 2; j++)
				modified_word_list[i][(len - 1) / 2 + j] = modified_word_list[i][(len + 1) / 2 + j];	// Ȧ���϶� �ڵ带 �����ϸ� ������ ����µ�, �� ������ �޿���

			modified_word_list[i][len] = 0;	// ���ڿ����� Ȯ���ϰ� �ϱ� ���� �������� �� ���� �߰�
		}
	}
}

/*
	�Լ� �̸� : print_changed_word
	��� : ������ �迭�� �׸��� ���Ŀ� �°� ���
	���� : word_list[][20] (������ �迭), row_numbers (��ȿ�� ���� ����)
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 25
*/
void print_changed_word(char word_list[][20], int row_numbers)
{
	/* ���� ���� */
	int i;

	for (i = 0; i < row_numbers; i++)
		printf("%s ", word_list[i]);	// ���ǿ� �´� ���ڿ� ���

	printf("\n");
	printf("\n");
}

/*
	�Լ� �̸� : check_ascend
	��� : ���ڰ� ������������ ���ĵǾ��ִ��� Ȯ��
	���� : word_list[][20] (������ �迭)
	��ȯ�� : ������������ ���ĵǾ������� 1, �׷��� ������ -1�� ��ȯ
	�ۼ� ��¥ : 2021 / 11 / 25
*/
int check_ascend(char word_list[][20])
{
	/* ���� ���� */
	int i;
	int first_word_len, second_word_len;
	int result1 = 0, result2 = 0;

	first_word_len = strlen(word_list[0]);	// ù ��° �ܾ��� ����
	second_word_len = strlen(word_list[1]);	// �� ��° �ܾ��� ����

	for (i = 0; i < first_word_len - 1; i++)	// ù ��° �ܾ��� �������� �˻�
	{
		result1 = word_list[0][i] - word_list[0][i + 1];	// ascii code�� ���� �ܾ �ϳ��� ���Ͽ� result1�� ����

		if (result1 <= 0)
			continue;
		else
			break;
	}

	for (i = 0; i < second_word_len - 1; i++)	// �� ��° �ܾ��� �������� �˻�
	{
		result2 = word_list[1][i] - word_list[1][i + 1];	// ascii code�� ���� �ܾ �ϳ��� ���Ͽ� result2�� ����

		if (result2 <= 0)
			continue;
		else
			break;
	}

	if (result1 <= 0 && result2 <= 0)	// result1�� result2�� ��� ���������� ���
		return 1;
	else							// �׷��� ���� ���
		return -1;
}

/*
	�Լ� �̸� : compare_word
	��� : ù ��° �ܾ�� �� ��° �ܾ ���Ͽ� ��ġ�� �ʴ� �ܾ my_list�� ����
	���� : word_list[][20] (������ �迭), my_list[](������ �迭) check (������������ Ȯ��), first_word_len (ù ��° �ܾ��� ����), second_word_len (�� ��° �ܾ��� ����)
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 25
*/
void compare_word(char word_list[][20], char my_list[], int check, int first_word_len, int second_word_len)
{
	/* ���� ���� */
	int i = 0, j = 0;
	int k = 0;
	int count = 0;

	if (check == -1)	// ������������ ���ĵǾ� ���� ���� ���
	{
		printf("�ܾ ������������ ���ĵǾ� ���� �ʽ��ϴ�.\n");
		return;
	}

	while (i < first_word_len && j < second_word_len)
	{
		if (word_list[0][i] == word_list[1][j])
		{
			++i;
			++j;
		}

		if (word_list[0][i] < word_list[1][j] && word_list[0][i] != 0)	// ù��° ���ڰ� �ι�° ���ں��� ������
		{
			my_list[k] = word_list[0][i];	// ù��° ���ڸ� my_list�� �߰�
			++i;
			++k;
		}

		if (word_list[0][i] > word_list[1][j] && word_list[1][j] != 0)	// ù��° ���ڰ� �ι�° ���ں��� ũ��
		{
			my_list[k] = word_list[1][j];	// �ι�° ���ڸ� my_list�� �߰�
			++j;
			++k;
		}

		if (i == first_word_len)	// ù��° ���ڰ� NULL���ڿ� �����ϸ�
		{
			for (j; j < second_word_len; j++)
			{
				my_list[k] = word_list[1][j];	// �ι�° ������ ������ �κ��� ��� �߰�
				k++;
			}
			++j;
		}

		if (j == second_word_len)	// �ι�° ���ڰ� NULL���ڿ� �����ϸ�
		{
			for (i; i < first_word_len; i++)
			{
				my_list[k] = word_list[0][i];	// ù��° ������ ������ �κ��� ��� �߰�
				k++;
			}
			++i;
		}
	}
}

/*
	�Լ� �̸� : print_missing_word
	��� : ������ �迭�� �׸��� ���Ŀ� �°� ���
	���� : word_list[] (������ �迭), check (������������ Ȯ��)
	��ȯ�� : ����
	�ۼ� ��¥ : 2021 / 11 / 25
*/
void print_missing_word(char my_list[], int check)
{
	/* ���� ���� */
	int i = 0;

	if (check == -1)	// ���������� �ƴϸ� ����
		return;

	for (i = 0; i < 50; i++)
	{
		if (my_list[i] != 0)
			printf("%c ", my_list[i]);	// ������ �迭�� �׸��� ���Ŀ� �°� ���
	}
	printf("\n");
}