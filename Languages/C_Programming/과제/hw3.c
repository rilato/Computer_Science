#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*함수 선언. 자세한 내용은 각 함수를 참고*/
void fill_the_array(char input_str[]);
int fill_the_two_dimensional_array(char input_str[], char word_list[][20]);
void print_two_dimensional_array(char word_list[][20], int row_numbers);
void change_word(char original_word_list[][20], char modified_word_list[][20], int row_numbers);
void print_changed_word(char word_list[][20], int row_numbers);
int check_ascend(char word_list[][20]);
void compare_word(char word_list[][20], char my_list[], int check, int first_word_len, int second_word_len);
void print_missing_word(char my_list[], int check);

/*
	함수 이름 : main
	기능 : 원하는 코드를 실행
	인자 : 없음
	반환값 : 정상적으로 종료시 0을 반환
	작성 날짜 : 2021 / 11 / 25
*/
int main()
{
	/* 변수 선언 */
	int row_numbers;
	int check;
	int first_word_len, second_word_len;

	char input_str[50] = { 0, };
	char word_list[10][20] = { 0, };
	char modified_word_list[10][20] = { 0, };	// 함수를 통해 변경된 word_list를 저장함
	char my_list[50] = { 0, };				// 겹치지 않는 문자들을 저장

	/* 1번 */
	fill_the_array(input_str);	// 문자열을 입력받는 함수
	printf("- 1번\n");
	row_numbers = fill_the_two_dimensional_array(input_str, word_list);	// row_numbers는 함수에서 호출된 결과를 저장함
	print_two_dimensional_array(word_list, row_numbers);	// 문제 1번이 요구하는 출력 형식에 맞게 출력

	/* 2번 */
	printf("- 2번\n");
	change_word(word_list, modified_word_list, row_numbers);	// 문제 2번이 요구하는 조건에 맞게 word_list를 변경하여 modified_word_list에 저장
	print_changed_word(modified_word_list, row_numbers);	// 문제 2번이 요구하는 출력 형식에 맞게 출력

	/* 3번 */
	first_word_len = strlen(word_list[0]);	// word_list의 첫 번째 단어의 길이를 구함
	second_word_len = strlen(word_list[1]);	// word_list의 두 번째 단어의 길이를 구함

	printf("- 3번\n");
	check = check_ascend(word_list);	// 오름차순인지 확인하는 함수를 호출하고 결과를 저장
	compare_word(word_list, my_list, check, first_word_len, second_word_len);	// 첫 번째 단어와 두 번째 단어를 비교하여 겹치는 단어 자리를 0으로 변경
	print_missing_word(my_list, check);	// 문제 3번이 요구하는 출력 형식에 맞게 출력

	return 0;
}

/*
	함수 이름 : fill_the_array
	기능 : 문자열을 입력받음
	인자 : input_str[] (일차원 배열)
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 25
*/
void fill_the_array(char input_str[])
{
	printf("문자열을 입력하시오 : ");
	gets(input_str);	// 문자를 입력받아 input_str에 저장
	printf("\n");
}

/*
	함수 이름 : fill_the_two_dimensional_array
	기능 : 일차원 배열에서 단어를 구분하여 이차원 배열에 저장
	인자 : input_str[] (일차원 배열), word_list[][20] (이차원 배열)
	반환값 : 단어의 개수를 반환
	작성 날짜 : 2021 / 11 / 25
*/
int fill_the_two_dimensional_array(char input_str[], char word_list[][20])
{
	/* 변수 선언 */
	int i = 0, j, k;
	int count = 0;

	while (1)
	{
		if (i >= 50)	// input_str의 길이를 넘어서면 탈출
			break;

		for (j = 0; j < 10; j++)	// 이차원 배열의 순회를 위한 for문
		{
			while (input_str[i] == ' ')	// 빈 칸이 있으면 i를 늘림
				++i;

			for (k = 0; k < 20; k++)	// 이차원 배열의 순회를 위한 for문
			{
				if (input_str[i] != ' ' && input_str[i] != '.')	// 띄어쓰기 또는 마침표가 있으면 건너뜀
				{
					word_list[j][k] = input_str[i];	// 일차원 배열에서 한글자씩 받아서 이차원 배열의 알맞은 자리에 저장
					++i;	// 일차원 배열의 순회를 위한 것
				}
			}

			while (input_str[i] == ' ')	// 빈 칸이 있으면 i를 늘림
				++i;
		}
	}

	for (i = 0; i < 10; i++)
	{
		if (word_list[i][0] == 0)	// 이차원 배열의 맨 앞글자가 0이면 탈출
			break;
		++count;	// 이차원 배열에서 정상적인 문자열을 가진 것의 개수를 셈.
	}

	return count;	// 단어의 개수를 반환
}

/*
	함수 이름 : print_two_dimensional_array
	기능 : 이차원 배열의 항목을 형식에 맞게 출력
	인자 : word_list[][20] (이차원 배열), row_numbers (유효한 행의 길이)
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 25
*/
void print_two_dimensional_array(char word_list[][20], int row_numbers)
{
	/* 변수 선언 */
	int i;

	for (i = 0; i < row_numbers; i++)
		printf("word_list[%d] -> %s\n", i, word_list[i]);	// 형식에 맞게 출력

	printf("\n");
}

/*
	함수 이름 : change_word
	기능 : original_word_list를 조건에 맞게 변형하여 modified_word_list에 저장
	인자 : original_word_list[][20] (기존 이차원 배열), modified_word_list[][20] (수정된 이차원 배열), row_numbers (유효한 행의 길이)
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 25
*/
void change_word(char original_word_list[][20], char modified_word_list[][20], int row_numbers)
{
	/* 변수 선언 */
	int i, j, len;

	for (i = 0; i < row_numbers; i++)
	{
		len = strlen(original_word_list[i]);	// 기존 이차원 배열의 각 행의 길이를 저장

		if (len % 2 == 0)	// 행의 단어 길이가 짝수이면
		{
			for (j = 0; j < len / 2; j++)
			{
				modified_word_list[i][j] = original_word_list[i][len / 2 + j];	// 기존 이차원 배열의 절반을 기준으로 뒷쪽의 문자열을 새로운 이차원 배열의 앞쪽으로 이동
				modified_word_list[i][len / 2 + j] = original_word_list[i][j];	// 기존 이차원 배열의 절반을 기준으로 앞쪽의 문자열을 새로운 이차원 배열의 뒷쪽으로 이동
			}
		}
		else			// 행의 단어 길이가 홀수이면
		{
			for (j = 0; j < (len + 1) / 2; j++)
			{
				modified_word_list[i][j] = original_word_list[i][(len + 1) / 2 + j];	// 기존 이차원 배열의 절반을 기준으로 뒷쪽의 문자열을 새로운 이차원 배열의 앞쪽으로 이동
				modified_word_list[i][(len + 1) / 2 + j] = original_word_list[i][j];	// 기존 이차원 배열의 절반을 기준으로 앞쪽의 문자열을 새로운 이차원 배열의 뒷쪽으로 이동
			}

			for (j = 0; j < (len + 1) / 2; j++)
				modified_word_list[i][(len - 1) / 2 + j] = modified_word_list[i][(len + 1) / 2 + j];	// 홀수일때 코드를 수행하면 공백이 생기는데, 그 공백을 메워줌

			modified_word_list[i][len] = 0;	// 문자열임을 확실하게 하기 위해 마지막에 널 문자 추가
		}
	}
}

/*
	함수 이름 : print_changed_word
	기능 : 이차원 배열의 항목을 형식에 맞게 출력
	인자 : word_list[][20] (이차원 배열), row_numbers (유효한 행의 길이)
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 25
*/
void print_changed_word(char word_list[][20], int row_numbers)
{
	/* 변수 선언 */
	int i;

	for (i = 0; i < row_numbers; i++)
		printf("%s ", word_list[i]);	// 조건에 맞는 문자열 출력

	printf("\n");
	printf("\n");
}

/*
	함수 이름 : check_ascend
	기능 : 문자가 오름차순으로 정렬되어있는지 확인
	인자 : word_list[][20] (이차원 배열)
	반환값 : 오름차순으로 정렬되어있으면 1, 그렇지 않으면 -1을 반환
	작성 날짜 : 2021 / 11 / 25
*/
int check_ascend(char word_list[][20])
{
	/* 변수 선언 */
	int i;
	int first_word_len, second_word_len;
	int result1 = 0, result2 = 0;

	first_word_len = strlen(word_list[0]);	// 첫 번째 단어의 길이
	second_word_len = strlen(word_list[1]);	// 두 번째 단어의 길이

	for (i = 0; i < first_word_len - 1; i++)	// 첫 번째 단어의 오름차순 검사
	{
		result1 = word_list[0][i] - word_list[0][i + 1];	// ascii code를 통해 단어를 하나씩 비교하여 result1에 저장

		if (result1 <= 0)
			continue;
		else
			break;
	}

	for (i = 0; i < second_word_len - 1; i++)	// 두 번째 단어의 오름차순 검사
	{
		result2 = word_list[1][i] - word_list[1][i + 1];	// ascii code를 통해 단어를 하나씩 비교하여 result2에 저장

		if (result2 <= 0)
			continue;
		else
			break;
	}

	if (result1 <= 0 && result2 <= 0)	// result1과 result2가 모두 오름차순인 경우
		return 1;
	else							// 그렇지 않은 경우
		return -1;
}

/*
	함수 이름 : compare_word
	기능 : 첫 번째 단어와 두 번째 단어를 비교하여 겹치지 않는 단어를 my_list에 담음
	인자 : word_list[][20] (이차원 배열), my_list[](일차원 배열) check (오름차순인지 확인), first_word_len (첫 번째 단어의 길이), second_word_len (두 번째 단어의 길이)
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 25
*/
void compare_word(char word_list[][20], char my_list[], int check, int first_word_len, int second_word_len)
{
	/* 변수 선언 */
	int i = 0, j = 0;
	int k = 0;
	int count = 0;

	if (check == -1)	// 오름차순으로 정렬되어 있지 않은 경우
	{
		printf("단어가 오름차순으로 정렬되어 있지 않습니다.\n");
		return;
	}

	while (i < first_word_len && j < second_word_len)
	{
		if (word_list[0][i] == word_list[1][j])
		{
			++i;
			++j;
		}

		if (word_list[0][i] < word_list[1][j] && word_list[0][i] != 0)	// 첫번째 문자가 두번째 문자보다 작으면
		{
			my_list[k] = word_list[0][i];	// 첫번째 문자를 my_list에 추가
			++i;
			++k;
		}

		if (word_list[0][i] > word_list[1][j] && word_list[1][j] != 0)	// 첫번째 문자가 두번째 문자보다 크면
		{
			my_list[k] = word_list[1][j];	// 두번째 문자를 my_list에 추가
			++j;
			++k;
		}

		if (i == first_word_len)	// 첫번째 문자가 NULL문자에 도달하면
		{
			for (j; j < second_word_len; j++)
			{
				my_list[k] = word_list[1][j];	// 두번째 문자의 나머지 부분을 모두 추가
				k++;
			}
			++j;
		}

		if (j == second_word_len)	// 두번째 문자가 NULL문자에 도달하면
		{
			for (i; i < first_word_len; i++)
			{
				my_list[k] = word_list[0][i];	// 첫번째 문자의 나머지 부분을 모두 추가
				k++;
			}
			++i;
		}
	}
}

/*
	함수 이름 : print_missing_word
	기능 : 일차원 배열의 항목을 형식에 맞게 출력
	인자 : word_list[] (일차원 배열), check (오름차순인지 확인)
	반환값 : 없음
	작성 날짜 : 2021 / 11 / 25
*/
void print_missing_word(char my_list[], int check)
{
	/* 변수 선언 */
	int i = 0;

	if (check == -1)	// 오름차순이 아니면 종료
		return;

	for (i = 0; i < 50; i++)
	{
		if (my_list[i] != 0)
			printf("%c ", my_list[i]);	// 일차원 배열의 항목을 형식에 맞게 출력
	}
	printf("\n");
}