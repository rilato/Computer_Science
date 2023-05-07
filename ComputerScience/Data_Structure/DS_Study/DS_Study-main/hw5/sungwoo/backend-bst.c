#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend-bst.h"

#define POOL_SIZE 10

struct record {
  char name[3];
  char number[4];
  struct record *left;
  struct record *right;
};

void  print_name(struct record *);
void  print_number(struct record *);
int   compare(char key[3], struct record *);

static struct record pool[POOL_SIZE];
struct record *top = pool;
struct record *data = NULL;

void init_pool()
{
  int i;
  struct record *r = pool;
  struct record *s;

  pool[POOL_SIZE - 1].right = NULL;
  for(i = 1; i < POOL_SIZE; i++) {
    s = r++;
    s->right = r;
  }
}

struct record * new_node()
{
  struct record *r;

  if(top == NULL)
    return (NULL);
  r = top;
  top = r->right;
  return (r);
}

void free_node(struct record *r)
{
  r->right = top;
  top = r;
}

void search(char name[3])
{
  struct record *r;
  int result;
  r = data;

  while (r != NULL) {
    if ((result = compare(name,r)) < 0)
      r = r->left;
    else if (result == 0) {
      print_name(r);
      printf(" : ");
      print_number(r);
      printf(" was found.\n");
      return ;
    }
    else
      r = r->right;
  }
  printf("Couldn't find the name.\n");
}

void add(char *name, char *number)
{
  struct record *trail;
  struct record *cur;
  struct record *new;
  int           ret;

  trail = data;
  cur = data;
  while (cur)
  {
    ret = compare(name, cur);
    if (ret <= 0)
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
  new = new_node();
  if (new == NULL)
  {
    printf("Can't add.  The pool is empty!\n");
    return ;
  }
  strncpy(new->name, name, 3);
  strncpy(new->number, number, 4);
  new->left = NULL;
  new->right = NULL;
  if (data == NULL)
    data = new;
  else
  {
    ret = compare(new->name, trail);
    if (ret <= 0)
      trail->left = new;
    else
      trail->right = new;
  }
  printf("The name was successfully added!\n");
}

static void  link_node(struct record *trail, struct record *cur)
{
  struct record *suc_trail;
  struct record *suc;
  int           ret;

  if (cur->left && cur->right) // has two children
  {
    suc_trail = cur->right;
    suc = cur->right;
    while (suc->left)
    {
      suc_trail = suc;
      suc = suc->left;
    }
    strncpy(cur->name, suc->name, 3);
    strncpy(cur->number, suc->number, 4);
    if (suc == cur->right) // successor has no child
      cur->right = NULL;
    else
    {
      if (suc->right)
        suc_trail->left = suc->right;
      else
        suc_trail->left = NULL;
    }
    free_node(suc);
  }
  else if (cur->left || cur->right) // has a child
  {
    if (trail->left == cur)
    {
      if (cur->left)
        trail->left = cur->left;
      else
        trail->left = cur->right;
    }
    else
    {
      if (cur->left)
        trail->right = cur->left;
      else
        trail->right = cur->right;
    }
    free_node(cur);
  }
  else // has no child
  {
    if (trail->left == cur)
      trail->left = NULL;
    else
      trail->right = NULL;
    free_node(cur);
  }
}

void delete(char name[3])
{
  struct record *trail;
  struct record *cur;
  int           ret;

  trail = data;;
  cur = data;
  while (cur)
  {
    ret = compare(name, cur);
    if (ret < 0)
    {
      trail = cur;
      cur = cur->left;
    }
    else if (ret == 0)
      break ;
    else
    {
      trail = cur;
      cur = cur->right;
    }
  }
  if (cur == NULL)
  {
    printf("Couldn't find the name.\n");
    return ;
  }
  link_node(trail, cur);
  printf("The name was deleted.\n");
}

int compare(char key[3], struct record *r)
{
  return (strncmp(key, r->name, 3));
}

void print_data(char * s, int n)
{
  int i;

  for (i = 0; i < n; i++)
    putchar(s[i]);
}

void print_name(struct record *r)
{
  print_data(r->name, 3);
}

void print_number(struct record *r)
{
  print_data(r->number, 4);
}

void print_inorder(struct record *cur)
{
  if (cur == NULL)
    return ;
  print_inorder(cur->left);
  print_name(cur);
  printf(" : ");
  print_number(cur);
  printf("\n");
  print_inorder(cur->right);
}

void print_list()
{
  print_inorder(data);
}

int height(struct record *cur)
{
  int left;
  int right;

  if (cur == NULL)
    return (-1);
  left = height(cur->left);
  right = height(cur->right);
  if (left > right)
    return (left + 1);
  else
    return (right + 1);
}

void print_height()
{
  printf("The Address Book BST's height is %d.\n", height(data));
}
