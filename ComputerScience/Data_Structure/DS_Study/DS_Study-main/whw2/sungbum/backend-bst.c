#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend-bst.h"

#define POOL_SIZE 500

// record structure
struct record {
  char name[3];
  char number[4];
  struct record * left;
  struct record * right;
};

void print_name(struct record *);
void print_number(struct record *);

static struct record pool[POOL_SIZE];
struct record * top=pool;

int compare(char key[3], struct record *);
struct record * data = NULL;

void delete_all(struct record*);
void init_pool()
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

struct record * new_node()
{
  struct record *r;

  if(top==NULL)
    return NULL;

  r=top;
  top=r->right;
  return r;
}

void free_node(struct record *r)
{
  r->right=top;
  top=r;
}

void search(char name[3])
{
  struct record *r;

  int result;
  r=data;

  while (r!=NULL) {
    if ((result=compare(name,r))<0)
      r=r->left;
    else if (result==0) {
      print_name(r);
      printf(" : ");
      print_number(r);
      printf(" was found.\n");
      return;
    }
    else // case >0
      r=r->right;
  }
  printf("Couldn't find the name.\n");
}


void add(char *name, char *number)
{
  struct record *r,*new,*tmp;
  int result;
  r=data;

  new=new_node();
  if(new==NULL){
    printf("Can't add.  The pool is empty!\n");
    return;
  }
  strncpy(new->name,name,3);
  strncpy(new->number,number,4);
  new->left=NULL;
  new->right=NULL;

  while(r!=NULL){
    if((result=compare(name,r))<=0){
      tmp=r;
      r=r->left;
    }
    else{
      tmp=r;
      r=r->right;
    }
  }

  if(data==NULL) data=new;
  else if((result=compare(name,tmp))<=0) tmp->left=new;
  else tmp->right=new;
  //printf("The name was successfully added!\n");
}

void delete(char name[3])
{
  struct record *del, *bf_del;
  int result;
  int is_left = 0;
  del=data;
  bf_del=del;

  while(del!=NULL){
    result=compare(name,del);
    if(result==0)
      break;
    else if(result<0){
      bf_del=del;
      del=del->left;
      is_left=1;
    }
    else{
      bf_del=del;
      del=del->right;
      is_left=0;
    }

  }
  if(del==NULL){
    printf("Couldn't find the name.\n");
    return;
  }

  if(del->left==NULL&&del->right==NULL){
    if(del==data){
      data=NULL;
    }
    else{
      if(is_left)
        bf_del->left=NULL;
      else
        bf_del->right=NULL;
    }
    free_node(del);
  }//
  else if(del->left!=NULL&&del->right!=NULL){
    struct record* successor, *bf_successor, *tmp;
    tmp=del->right;
    successor=tmp;
    while(tmp!=NULL){
      bf_successor=successor;
      successor=tmp;
      tmp=tmp->left;
    }
    strncpy(del->name,successor->name,3);
    strncpy(del->number,successor->number,4);

    if(bf_successor==successor){
      del->right=successor->right;
    }
    else{
      bf_successor->left=successor->right;
    }
    free_node(successor);
  }//
  else{
    struct record* tmp;
    if(del==data){
      if(del->left==NULL) data=del->right;
      else data=del->left;
    }
    else{
      if(is_left)
        tmp=bf_del->left;
      else
        tmp=bf_del->right;

      if(del->left==NULL)
        tmp=del->right;
      else
        tmp=del->left;
    }
    free_node(del);
  }
  printf("The name was deleted.\n");
}

/*****************************/

void delete_all(struct record* r){
  if(r!=NULL){
    delete_all(r->left);
    delete_all(r->right);
    free_node(r);
  }
}

void free_data(){
  delete_all(data);
  data=NULL;
}
/*****************************/


int compare(char key[3], struct record *r)
{
    return strncmp(key, r->name, 3);
}


void print_data(char * s, int n)
{
  int i;
  for (i=0; i<n; i++)
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
void print_inorder(struct record *t)
{
  if(t==NULL) return;
  print_inorder(t->left);
  print_name(t);
  printf(" : ");
  print_number(t);
  printf("\n");
  print_inorder(t->right);
}

void print_list()
{
  print_inorder(data);
}

int height(struct record *t)
{
  int l, r;

  if(t==NULL) return -1;
  if((l=height(t->left))<(r=height(t->right))) return r+1;
  else return l+1;
}

int height_val(){
  return height(data);
}
void print_height()
{
  printf("Height is %d.\n", height(data));
}
