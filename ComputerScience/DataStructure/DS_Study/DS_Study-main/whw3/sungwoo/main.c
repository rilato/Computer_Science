#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void  read_file(char words[5757][5])
{
  FILE  *fp;
  int   i;
  char  buf[5];
  char  dummy[100];

  fp = fopen("words.dat", "r");
  if (fp == NULL)
    exit(1);
  i = 0;
  while (i < 4)
  {
    fgets(dummy, 100, fp);
    ++i;
  }
  i = 0;
  while (i < 5757)
  {
    fgets(words[i], 6, fp);
    fgets(dummy, 100, fp);
    ++i;
  }
  fclose(fp);
}

int get_hash(char key[5], int hash_prime)
{
	int       i;
	long long x;

	x = 0;
	for (i = 0; i < 4; ++i)
  {
		x = x + key[i];
		x = x << 8;
	}
	x = x + key[4];
	return (x % hash_prime);
}

size_t  get_sum(int hash_prime, int *mark, int flag_question_nbr)
{
  int     i;
  size_t  sum;

  i = 0;
  sum = 0;
  while (i < hash_prime)
  {
    if (flag_question_nbr == 1)
    {
      if (mark[i] > 1)
        sum += (mark[i] - 1);
    }
    else
	    sum += (mark[i] * (mark[i] + 1) / 2);
    ++i;
  }
  return (sum);
}

size_t  process_m(int hash_prime, char words[5757][5], int flag_question_nbr)
{
  int    *mark;
  int     i;
  size_t  sum;

  mark = malloc(sizeof(int) * hash_prime);
  if (mark == NULL)
    exit (1);
  i = 0;
  while (i < hash_prime)
  {
    mark[i] = 0;
    ++i;
  }
  i = 0;
  while (i < 5757)
  {
    ++(mark[get_hash(words[i], hash_prime)]);
    ++i;
  }
  sum = get_sum(hash_prime, mark, flag_question_nbr);
  free(mark);
  mark = NULL;
  return (sum);
}

int main(void)
{
  char  words[5757][5];;

  read_file(words);
  printf("For all following experiments, the number of words(keys): 5757\n");
  printf("For HASH_PRIME: 7000(composite), then the number of collisions: ");
  printf("%ld\n", process_m(7000, words, 1));
  printf("For HASH_PRIME: 6997(prime), then the number of collisions: ");
  printf("%ld\n", process_m(6997, words, 1));
  printf("For HASH_PRIME: 12000(composite), then the number of collisions: ");
  printf("%ld\n", process_m(12000, words, 1));
  printf("For HASH_PRIME: 11117(prime), then the number of collisions: ");
  printf("%ld\n", process_m(11117, words, 1));
  printf("For HASH_PRIME: 22000(composite), then the number of collisions: ");
  printf("%ld\n", process_m(22000, words, 1));
  printf("For HASH_PRIME: 22307(prime), then the number of collisions: ");
  printf("%ld\n", process_m(22307, words, 1));
  printf("For HASH_PRIME: 11117, then the number of key comparisons: ");
  printf("%ld\n", process_m(11117, words, 2));
  return (0);
}
