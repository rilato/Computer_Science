#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend-hash.h"

#define HASH_PRIME 17
#define POOL_SIZE 100

int name_to_num(char name[3])
{
  int x;

  x=name[0];
  x=x<<8;
  x=x+name[1];
  x=x<<8;
  return x+name[2];
}

int hash(char name[3])
{
  return name_to_num(name)%HASH_PRIME;
}

struct record {
  char name[3];
  char number[4];
  struct record * next;
};


struct record pool[POOL_SIZE];
struct record * top=pool;


int compare(char key[3], struct record *);
void print_name(struct record *);
void print_number(struct record *);
void print_data(char *, int);


struct record * hash_table[HASH_PRIME];

void init_hash_table()
{
  int i;

  for(i=0;i<HASH_PRIME;i++)
    hash_table[i]=NULL;
}

void init_pool()
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

void init()
{
  init_pool();
  init_hash_table();
}

struct record * new_node()
{
  struct record *r;

  if(top==NULL)
    return NULL;

  r=top;
  top=r->next;
  return r;
}

void free_node(struct record *r)
{
  r->next=top;
  top=r;
}

void add(char *name, char *number)
{
  struct record *new;
  new=new_node();
  if(new==NULL) {
    printf("Can't add.  The pool is empty!\n");
    return;
  }
  else{
    strncpy(new->name,name,3);
    strncpy(new->number,number,4);
    new->next=NULL;
  }

  int hashVal=hash(name);
  struct record *hp=hash_table[hashVal];
  if(hp!=NULL){                                 // 포인터를 쓰고 안쓰고의 차이. 결국 코드는 비슷한 듯
    new->next=hp;
  }
  hash_table[hashVal]=new;                      // 중복이 안되어 더 깔끔함
  printf("The name was successfully added!\n");
  return;
}

void search(char name[3])
{
  int cnt=0;
  struct record *find=hash_table[hash(name)];

  while(find!=NULL){
    ++cnt;                                    // ++count를 써서 더 깔끔함
    if(compare(name,find)==0)                 // break문으로 간결함
      break;
    find=find->next;
  }

  if(find==NULL){
    printf("Couldn't find the name.\n");
  }
  else{
    print_name(find);
    printf(" : ");
    print_number(find);
    printf(" was found.\n");
  }
  printf("%d key comparisons were made.\n", cnt);
  return;
}

void delete(char name[3])
{
  int cnt=0;
  int hashVal=hash(name);
  struct record *del=hash_table[hashVal];
  struct record *preDel=hash_table[hashVal];      // 교수님이 더블포인터를 기본 코드로 주셨는데, 더블포인터로 구현해보는건 어떨지... 굳이 더블포인터를 쓴 이유가 있다면 혹시 아시나요?

  while(del!=NULL){
    ++cnt;
    if(compare(name,del)==0)
      break;
    preDel=del;
    del=del->next;
  }

  if(del==NULL){
    printf("Couldn't find the name.\n");
  }
  else{
    if(cnt==1){
      hash_table[hashVal]=hash_table[hashVal]->next;
    }
    else{
      preDel->next=del->next;
    }
    free_node(del);
    printf("The name was successfully deleted!\n");
  }

  printf("%d key comparisons were made.\n", cnt);
  return;
}

int compare(char key[3], struct record *r)
{
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

void print_data(char * s, int n)
{
  int i;
  for (i=0; i<n; i++)
    putchar(s[i]);
}

void print_dist()
{
  int i,cnt;
  for(i=0;i<HASH_PRIME;i++){
    cnt=0;
    if(hash_table[i]==NULL){
      printf("%d:0 ", i);
    }
    else{
      struct record *tour=hash_table[i];
      while(tour!=NULL){
        ++cnt;                    // cnt++해도 상관 없을지
        tour=tour->next;
      }
      printf("%d:%d ",i,cnt);
    }
  }
  printf("\n");
}
