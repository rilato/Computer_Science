#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <time.h>
#include <math.h>

#define POOL_SIZE 500

// record structure
struct record {
  int number;
  struct record * left;
  struct record * right;
};

// pool of memory
static struct record pool[POOL_SIZE]; // static because pool is strictly private
struct record * top=pool;  // a pointer variable for pool stack top.

// comparison function for records
int compare(int key, struct record *);

// data
struct record * data = NULL; // Initially NULL.


void init_pool() // Initialize the pool; Use right instead of next!!!
{
  int i;
  struct record *r=pool;
  struct record *s;

  pool[POOL_SIZE-1].right=NULL;  

  for(i=1;i<POOL_SIZE;i++) {  
    s=r++;
    s->right=r;
  }
}

// Get a node from the pool. Returns NULL if pool is empty. 
// When calling new_node(), make sure to check if it is NULL. 
struct record * new_node()  
{
  struct record *r;
  
  if(top==NULL) 
    return NULL;
    
  r=top;
  top=r->right;  // Again, right instead of next.
  return r;
}

// Push a node to the pool.
void free_node(struct record *r)
{
  r->right=top;  // Again, right instead of next.
  top=r;
}

void add(int number)
{
  struct record *r;
  struct record *p;
  struct record *q = NULL;
  r = new_node();

  if (r==NULL)
  {
    return;
  }

  p = data;
  
  while (p!=NULL) {
    if (compare(number,p)<=0)
    {
      q = p;
      p = p->left;
    }
    else
    {
      q = p;
      p = p->right;
    }
  }

  r->number = number;
  r->left = NULL;
  r->right = NULL;

  if (data == NULL)
  {
    data = r;
  }
  else if (compare(number,q)<=0)
  {
    q->left = r;
  }
  else
  {
    q->right = r;
  }
}

int compare(int key, struct record *r)
{
  if (key > r->number)
    return 1;
  else if (key < r->number)
    return -1;
  else
    return 0;
}

int height(struct record *t)
{
  int lefth; 
  int righth; 

  if (t==NULL)
    return -1;

  lefth = height(t->left);
  righth = height(t->right);

  if (lefth < righth)
    return righth+1;
  else
    return lefth+1;
}

void print_height()  
{
  printf("BST's height is %d.\n", height(data));
}

int rand_num[POOL_SIZE];

void generate(int n)
{
  int i;
  //srand((time(NULL)));
  for(i=0; i<n; ++i)
  {
    rand_num[i] = rand();
  }
}

void print_generate(int n)
{
  int i;
  for(i=0; i<n; i++)
  {
    printf("Random data %d: %d ", i, rand_num[i]);
  }
}

void insert_data(int n)
{
  int i;
  for(i=0; i<n; i++)
  {
    add(rand_num[i]);
  }
}

void free_all(struct record *r)
{
  if (r!=NULL)
  {
    free_all(r->left);
    free_all(r->right);
    free_node(r);
  }
  data = NULL;
}
  
void process(int number, int n)
{
  int height_tmp[number];
  int height_cnt[n];
  double sum = 0;
  double var = 0;
  double ave;
  double std;
  int i;
  int j;
  srand((time(NULL)));
  for(i=0; i<number; i++)
  {
    init_pool();
    generate(n);
    insert_data(n);
    height_tmp[i] = height(data);
    sum += height(data);
    free_all(data);
  }
  ave = sum/number;
    
  for (i=0; i<number; i++)
    var += pow((double)(height_tmp[i] - ave), 2);
  var = var/number;
  std = sqrt(var);
  printf("Iteration:%d\nN:%d\nSum height of BST:%.0f\nAverage height of BST:%.2lf\nVariance height of BST:%.2lf\nStandard deviation height of BST:%.2lf\n", number, n, sum, ave, var,std);
}

int main()
{
  process(10000, 50);
  process(10000, 100);
  process(10000, 200);
  process(10000, 500);
  process(1000000, 50);
  process(1000000, 100);
  process(1000000, 200);
  process(1000000, 500);
}
    
