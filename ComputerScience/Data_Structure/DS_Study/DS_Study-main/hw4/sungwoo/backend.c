#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"
#include "memory.h"

void print_name(struct record *);
void print_number(struct record *);
void print_data(char *, int);
int  compare(char key[3], struct record *);

struct record *data = NULL;

void init()
{
  init_pool();
}

static void link_node(char *name, struct record *new)
{
  struct record *cur;
  struct record *prv;
  int           result;

  if (data == NULL)
  {
    new->next = NULL;
    data = new;
    return ;
  }
  prv = NULL;
  cur = data;
  while (cur && (result = compare(name, cur)) > 0)
  {
    prv = cur;
    cur = cur->next;
  }
  if (prv == NULL)
  {
    new->next = data;
    data = new;
    return ;
  }
  new->next = cur;
  prv->next = new;
}

void add(char *name, char *number)
{
  struct record *new;

  new = new_node();
  if (new == NULL)
  {
    printf("Can't add.  The address book is full!\n");
    return ;
  }
  strncpy(new->name, name, 3);
  strncpy(new->number, number, 4);
  link_node(name, new);
}

void search(char name[3])
{
  struct record *r = data;
  int result;

  while(r != NULL && (result = compare(name, r)) != 0)
    r = r->next;
  if(r == NULL)
    printf("Couldn't find the name.\n");
  else {
    print_name(r);
    printf(" : ");
    print_number(r);
    printf(" was found.\n");
  }
}

void delete(char name[3])
{
  struct record *cur;
  struct record *prv;
  int           result;

  prv = NULL;
  cur = data;
  while (cur && (result = compare(name, cur)) != 0)
  {
    prv = cur;
    cur = cur->next;
  }
  if (cur == NULL)
  {
    printf("Couldn't find the name.\n");
    return ;
  }
  if (prv == NULL)
    data = data->next;
  else
    prv->next = cur->next;
  free_node(cur);
  printf("The name was deleted.\n");
}

int compare(char key[3], struct record *r)
{
  if (r == NULL)
    return (-1);
  else
    return strncmp(key, r->name, 3);
}

void print_name(struct record *r)
{
  print_data(r->name, 3);
}

void print_number(struct record *r)
{
  print_data(r->number, 4);
}

void print_data(char *s, int n)
{
  int i;

  for (i = 0; i < n; ++i)
    putchar(s[i]);
}

void print_list()
{
  struct record *cur;

  cur = data;
  while (cur)
  {
    print_name(cur);
    printf(" : ");
    print_number(cur);
    printf("\n");
    cur = cur->next;
  }
}
