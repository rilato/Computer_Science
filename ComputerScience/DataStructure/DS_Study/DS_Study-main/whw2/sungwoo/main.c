// Written Homework 2
// B617065 신성우

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

struct record
{
  int           nbr;
  struct record *left;
  struct record *right;
};

struct record *data = NULL;

void  gen_n_rand_nbr(int n, int *rand_nbr_n)
{
  int i;

  i = 0;
  while (i < n)
  {
    rand_nbr_n[i] = rand() % n + 1;
    ++i;
  }
}

struct record *get_new_node(int nbr_to_add)
{
  struct record *new;

  new = (struct record *)malloc(sizeof(struct record) * 1);
  if (new == NULL)
    exit(1);
  new->nbr = nbr_to_add;
  new->left = NULL;
  new->right = NULL;
  return (new);
}

void  add(int nbr_to_add)
{
  struct record *trail;
  struct record *cur;
  struct record *new;
  int           tmp;

  trail = data;
  cur = data;
  while (cur)
  {
    tmp = nbr_to_add - cur->nbr; // compare(name, cur);
    if (tmp <= 0)
    {
      trail = cur;
      cur = cur->left;
    }
    else
    {
      trail = cur;
      cur = cur->right;
    }
  }
  new = get_new_node(nbr_to_add);
  if (data == NULL)
    data = new;
  else
  {
    tmp = new->nbr - trail->nbr; // compare(new->name, trail);
    if (tmp <= 0)
      trail->left = new;
    else
      trail->right = new;
  }
}

void  init_bst(int n, int *rand_nbr_n)
{
  int i;

  i = 0;
  while (i < n)
  {
    add(rand_nbr_n[i]);
    ++i;
  }
}

int  get_height(struct record *data)
{
  int left;
  int right;

  if (data == NULL)
    return (-1);
  left = get_height(data->left);
  right = get_height(data->right);
  if (left > right)
    return (left + 1);
  else
    return (right + 1);
}

void  free_bst(struct record *node)
{
  if (node)
  {
    free_bst(node->left);
    free_bst(node->right);
    free(node);
  }
}

void  process_n(int n, int iter, int *rand_nbr_n, int *height_n)
{
  int i;

  i = 0;
  while (i < iter)
  {
    srand((unsigned int)i);
    gen_n_rand_nbr(n, rand_nbr_n);
    init_bst(n, rand_nbr_n);
    height_n[i] = get_height(data);
    assert(((log((double)n) / log((double)2)) <= height_n[i]) && \
          (height_n[i] <= n - 1));
    free_bst(data);
    data = NULL;
    ++i;
  }
}

void  print_result_n(int n, int iter, int *height_n)
{
  int                 i;
  unsigned long long  sum;
  double              avg;
  double              var;
  double              std_dev;

  printf("About height of BST for N = %d\n", n);
  i = 0;
  sum = 0;
  while (i < iter)
  {
    sum += (unsigned long long)height_n[i];
    ++i;
  }
  avg = sum / (double)iter;
  printf("Average: %.4lf \\ ", avg);
  i = 0;
  var = 0;
  while (i < iter)
  {
    var += pow((double)(height_n[i]) - avg, 2);
    ++i;
  }
  var /= iter;
  printf("Variance: %.4lf \\ ", var);
  std_dev = sqrt(var);
  printf("Standard deviation: %.4lf\n", std_dev);
}

int main(void)
{
  int rand_nbr_50[50];
  int rand_nbr_100[100];
  int rand_nbr_200[200];
  int rand_nbr_500[500];
  int height_50[100000];
  int height_100[100000];
  int height_200[100000];
  int height_500[100000];

  printf("==================== Result for 1,000 iterations ====================\n");
  process_n(50, 1000, rand_nbr_50, height_50);
  print_result_n(50, 1000, height_50);
  process_n(100, 1000, rand_nbr_100, height_100);
  print_result_n(100, 1000, height_100);
  process_n(200, 1000, rand_nbr_200, height_200);
  print_result_n(200, 1000, height_200);
  process_n(500, 1000, rand_nbr_500, height_500);
  print_result_n(500, 1000, height_500);
  printf("==================== Result for 10,000 iterations ====================\n");
  process_n(50, 10000, rand_nbr_50, height_50);
  print_result_n(50, 10000, height_50);
  process_n(100, 10000, rand_nbr_100, height_100);
  print_result_n(100, 10000, height_100);
  process_n(200, 10000, rand_nbr_200, height_200);
  print_result_n(200, 10000, height_200);
  process_n(500, 10000, rand_nbr_500, height_500);
  print_result_n(500, 10000, height_500);
  printf("==================== Result for 100,000 iterations ====================\n");
  process_n(50, 100000, rand_nbr_50, height_50);
  print_result_n(50, 100000, height_50);
  process_n(100, 100000, rand_nbr_100, height_100);
  print_result_n(100, 100000, height_100);
  process_n(200, 100000, rand_nbr_200, height_200);
  print_result_n(200, 100000, height_200);
  process_n(500, 100000, rand_nbr_500, height_500);
  print_result_n(500, 100000, height_500);
  return (0);
}
