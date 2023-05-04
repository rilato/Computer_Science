#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"
#include "memory.h"

void print_name(struct record *);
void print_number(struct record *);
void print_data(char *, int);

// comparison function for records
int compare(char key[3], struct record *);

// data
struct record * data = NULL; // Initially NULL.

void init()
{
  init_pool();
}

void add(char *name, char *number) // 함수 코드 too long
{
  struct record *new;
  new = new_node(); // 선언과 사용 분리
  //int result;
  struct record *p = data; // 변수명 p <-> pre 차이?
  struct record *pre;

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
    return;
  }

  if (p->next == NULL && compare(name,p) > 0) // 노드가 하나만 있는 경우 // compare 세버 중복 가독성, 효율
  {
   p->next = new;
   new->next = NULL;
   return;
  }

  if (compare(name,p) <= 0) // 노드 맨앞으로 삽입 // 굳이 탐색을 해야하나?
  {
    new->next = p;
    data = new;
    return;
  }

  while (compare(name,p) > 0) // 탐색
  {
    pre = p; // indenting
    p = p->next;
  }
  pre->next = new;
  new->next = p;
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
  } // 첫 노드가 삭제 // free_node 과정 없어도 되는건가? // 메모리 풀로 메모리 반납 하지 않아도 되는건가?

  else {
    struct record *r=p->next; // 변수명 왜 r?
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


/* Just a wrapper of strncmp(), except for the case r is NULL.
Regard strncmp(a,b) as a-b, that is,
Negative value if key is less than r.
​0​ if key and r are equal.
Positive value if key is greater than r. */

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

