#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"
#include "memory.h"

void print_name(struct record *);
void print_number(struct record *);
void print_data(char *, int);
 
// data
struct record * data = NULL; // Initially NULL.

void init()
{
  init_pool();
}
 

void add(char *name, char *number)
{
  // Error Message for overflow:
  // printf("Can't add.  The address book is full!\n");
  
  struct record *new;

  new = new_node();

  if (new == NULL)
  {
    printf("Can't add.  The address book is full!\n");
    return;
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


/* Just a wrapper of strncmp(), except for the case r is NULL.
Regard strncmp(a,b) as a-b, that is,
Negative value if key is less than r.
​0​ if key and r are equal.
Positive value if key is greater than r. */
int compare(char key[3], struct record *r)
{
  if (r==NULL)
    return -1;
  else {
    return strncmp(key, r->name, 3);
  }
}


void search(char name[3])
{
  struct record *r=data;
  int result;

  while(r!=NULL && (result=compare(name,r))!=0)
    r=r->next;
  if(r==NULL)
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
  int result;
  struct record *p=data;

  if (p==NULL) {
    printf("Couldn't find the name.\n");
    return;
  }

  else if (compare(name,p) == 0) {
    printf("The name was deleted.\n");
    data = data->next;
  }
  
  else {
    struct record *r=p->next;
    while(r!=NULL && (result=compare(name,r))!=0) {
      p = r;
      r = r->next;
    }
    if(r==NULL) {
      printf("Couldn't find the name.\n");
    }
    else {
      p->next = r->next;
      free_node(r);
      printf("The name was deleted.\n");
    }
  }
    // Error Message:
    // printf("Couldn't find the name.\n");
}



// Prints ith name.
void print_name(struct record *r)
{
  print_data(r->name, 3);
}

// Prints ith number.
void print_number(struct record *r)
{
  print_data(r->number, 4);
}

void print_data(char * s, int n)
{
  int i;
  for (i=0; i<n; i++)
    putchar(s[i]);
}

void print_list()
{

  struct record *r=data;

  while (r!=NULL) {

    print_name(r);
    printf(" : ");
    print_number(r);
    printf("\n");
    r=r->next;
  }
  
}
