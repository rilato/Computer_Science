#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"
#include "memory.h"

void print_name(struct record *);
void print_number(struct record *);
void print_data(char *, int);

struct record *data = NULL;

void init()
{
  init_pool();
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
  (new->name)[0] = name[0];
  (new->name)[1] = name[1];
  (new->name)[2] = name[2];
  (new->number)[0] = number[0];
  (new->number)[1] = number[1];
  (new->number)[2] = number[2];
  (new->number)[3] = number[3];
  if (data == NULL)
  {
    new->next = NULL;
    data = new;
  }
  else
  {
    new->next = data;
    data = new;
  }
}

int compare(char key[3], struct record *r)
{
  if (r == NULL)
    return (-1);
  else
    return (strncmp(key, r->name, 3));
}

void search(char name[3])
{
  struct record *r = data;
  int result;

  while (r != NULL && (result = compare(name, r)) != 0)
    r = r->next;
  if (r == NULL)
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
  struct record *node_to_del;
  struct record *node_to_reconnect;
  int           result;

  node_to_del = data;
  while (node_to_del && (result = compare(name, node_to_del)) != 0)
    node_to_del = node_to_del->next;
  if (node_to_del == NULL)
  {
    printf("Couldn't find the name.\n");
    return ;
  }
  node_to_reconnect = data;
  while (node_to_reconnect)
  {
    if (node_to_reconnect->next == node_to_del)
      break ;
    node_to_reconnect = node_to_reconnect->next;
  }
  node_to_reconnect->next = node_to_del->next;
  free_node(node_to_del);
  printf("The name was deleted.\n");
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
