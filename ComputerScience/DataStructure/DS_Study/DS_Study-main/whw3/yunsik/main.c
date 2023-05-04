#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M1 7000
#define M2 6997
#define M3 12000
#define M4 11117
#define M5 22000
#define M6 22307
#define LINE 5762

int hash(char key[5], int number);
void make_hash_table(char hash_table[], int number);
int count_collision(char hash_table[], int number);
void print_sum(char hash_table[], int number);
void init_hash_table(char hash_table[], int number);
void count_comparison(char hash_table[], int number);

int main()
{
	char hash_table1[M1] = { 0, }; // init 쓰지 않은 이유?
	char hash_table2[M2] = { 0, };
	char hash_table3[M3] = { 0, };
	char hash_table4[M4] = { 0, };
	char hash_table5[M5] = { 0, };
	char hash_table6[M6] = { 0, };

	printf("the number of five words in \"words.dat\" : 5757");
	printf("\n");
	printf("\n");

	print_sum(hash_table1, M1);
	print_sum(hash_table2, M2);
	print_sum(hash_table3, M3);
	print_sum(hash_table4, M4);
	print_sum(hash_table5, M5);
	print_sum(hash_table6, M6);

	printf("\n");

	init_hash_table(hash_table4, M4);
	count_comparison(hash_table4, M4);

	printf("\n");

	return 0;
}

int hash(char key[5], int number)
{
	int i;
	long long x;

	x = 0;

	for (i = 0; i < 4; i++) {
		x = x + key[i];
		x = x << 8;
	}

	x = x + key[4];

	return x % number;
}

void make_hash_table(char hash_table[], int number)
{
	int i, j;
	
	char five_words[6] = { 0,};
	char words[100];
	const char* filename = "words.dat";

	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Can't open %s file.\n", filename);
		exit(EXIT_FAILURE); //EXIT_FAILURE 사용 이유?
	}

	for (i = 0; i < LINE; i++)
	{
		fgets(words, 100, fp);

		if (words[0] == '*') //words[0] == '*' 인 경우가 ?
			continue; 

		for (j = 0; j < 5; j++)
			five_words[j] = words[j];

		hash_table[hash(five_words, number)] += 1;	
	}

	fclose(fp);
}

int count_collision(char hash_table[], int number)
{
	int i;
	int sum = 0;

	for (i = 0; i < number; i++)
	{
		if (hash_table[i] == 0)
			continue;

		hash_table[i]--;
	}

	for (i = 0; i < number; i++)
		sum += hash_table[i];

	return sum;
}

void print_sum(char hash_table[], int number)
{
	int sum;

	make_hash_table(hash_table, number);
	sum = count_collision(hash_table, number);

	printf("number : %d -> the number of collisions : %d", number, sum);
	printf("\n");
}

void init_hash_table(char hash_table[], int number)
{
	int i;
	
	for (i = 0; i < number; i++)
		hash_table[i] = 0;
}

void count_comparison(char hash_table[], int number)
{
	int i;
	int sum = 0;

	make_hash_table(hash_table, number);

	for (i = 0; i < number; i++)
		sum += hash_table[i] * (hash_table[i] + 1) / 2;
	
	printf("the number of total comparisons : %d", sum);
}
