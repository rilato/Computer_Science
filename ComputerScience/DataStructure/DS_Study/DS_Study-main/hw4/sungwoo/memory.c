#include <stdio.h>
#include "memory.h"

#define POOL_SIZE 10

struct record pool[POOL_SIZE];
struct record * top = pool;

void init_pool()
{
  int i;
  struct record *r=pool;
  struct record *s;

  pool[POOL_SIZE - 1].next = NULL;
  for(i = 1; i < POOL_SIZE; ++i) {
    s = r++;
    s->next = r;
  }
}

struct record *new_node()
{
  struct record *ret;

  if (top == NULL)
    return (NULL);
  ret = top;
  top = ret->next;
  return (ret);
}

void free_node(struct record *r)
{
  r->next = top;
  top = r;
}

