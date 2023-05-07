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
  struct record *p = new_node();
  
  if(p==NULL){
    printf("Can't add.  The address book is full!\n");
    return;
  }
  if(data == NULL){
      data = p;
      data->next = NULL;
   }
   else{
     p->next = data;
     data = p;
   }
   data->name[0]=name[0];
   data->name[1]=name[1];
   data->name[2]=name[2];
   data->number[0]=number[0];
   data->number[1]=number[1];
   data->number[2]=number[2];
   data->number[3]=number[3];
  }
 
  /*if(p!=NULL){
    if(data == NULL){
      data = p;
      data->next = NULL;
    }
    else{
      p->next = data;
      data = p;
    }
    data->name[0]=name[0];
    data->name[1]=name[1];
    data->name[2]=name[2];
    data->number[0]=number[0];
    data->number[1]=number[1];
    data->number[2]=number[2];
    data->number[3]=number[3];
  }
  else{
    printf("Can't add.  The address book is full!\n");
  }*/
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
  else
    return strncmp(key, r->name, 3);
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
  struct record *r=data;
  struct record *p=NULL;
  int result;

  while(r!=NULL && (result=compare(name,r))!=0){
    p=r;
    r=r->next;
  }
  if(r==NULL)
    printf("Couldn't find the name.\n");
  else if(r==data){
    data=r->next;
    free_node(r);
    printf("The name was deleted.\n");
  }
  else {
    p->next = r->next;
    free_node(r);
    printf("The name was deleted.\n");
  }
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
  struct record *p = data;
  while(p!=NULL){
    print_name(p);
    printf(" : ");
    print_number(p);
    printf("\n");
    p=p->next;
  }
}
