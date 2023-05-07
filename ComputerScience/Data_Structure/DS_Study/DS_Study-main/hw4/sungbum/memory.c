#include <stdio.h>
#include "memory.h"

#define POOL_SIZE 10

// pool of memory
struct record pool[POOL_SIZE]; 
struct record * top=pool;  // pool is constant; a pointer to the stack top.

void init_pool() // Initialize the pool
{
  int i;
  struct record *r=pool;
  struct record *s;

  pool[POOL_SIZE-1].next=NULL;  

  for(i=1;i<POOL_SIZE;i++) { 
    s=r++;
    s->next=r;
  }
}


// Gets a node from the pool. Returns NULL if pool is empty. (A BETTER DESIGN)
struct record * new_node()  
{
  struct record *p = top;
  
  if(top==NULL) 
    return NULL;
  else{
    top=p->next;
    return p;
  }
}


// Push a node to the pool.
void free_node(struct record *r)
{
  r->next=top;
  top=r;
}

