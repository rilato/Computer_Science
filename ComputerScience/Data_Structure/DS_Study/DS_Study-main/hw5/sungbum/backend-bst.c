#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend-bst.h"

#define POOL_SIZE 10

// record structure
struct record {
  char name[3];
  char number[4];
  struct record * left;
  struct record * right;
};

void print_name(struct record *);
void print_number(struct record *);

// pool of memory
static struct record pool[POOL_SIZE]; // static because pool is strictly private
struct record * top=pool;  // a pointer variable for pool stack top.

// comparison function for records
int compare(char key[3], struct record *);

// data
struct record * data = NULL; // Initially NULL.


void init_pool() // Initialize the pool; Use right instead of next!!!
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

// Get a node from the pool. Returns NULL if pool is empty.
// When calling new_node(), make sure to check if it is NULL.
struct record * new_node()
{
  struct record *r;

  if(top==NULL)
    return NULL;

  r=top;
  top=r->right;  // Again, right instead of next.
  return r;
}

// Push a node to the pool.
void free_node(struct record *r)
{
  r->right=top;  // Again, right instead of next.
  top=r;
}


/***********************
Address Book by binary search tree
**************************/

void search(char name[3])
{
  struct record *r; // Pointer to record being compared.
                    //data or left/right field of a node.
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


void add(char *name, char *number) // 거의 같음
{
  struct record *r,*new,*tmp;
  int result;
  r=data;

  new=new_node(); // 이 부분이 while문 하단에 작성되어 있는데 NULL 고려하면 위치 적절
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


// The most complicated.
void delete(char name[3]) // 함수 길이 너무 길다. // 일반적으로 25줄 이상 -> 별개의 함수 사용
{
  struct record *del, *bf_del;
  int result;
  int is_left = 0; // ON/OFF flag 자료형은 bool로 사용하는것이 좋다.
  del=data;

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

  if(del->left==NULL&&del->right==NULL){ // has no child
    if(del==data){
      data=NULL; // 이거 저는 빠트렸네요
      free_node(del);
    }
    else{
      if(is_left)
        bf_del->left=NULL;
      else
        bf_del->right=NULL;
      free_node(del); // 중복코드
    }
  }//
  else if(del->left!=NULL&&del->right!=NULL){ // has two children
    struct record* successor, *bf_successor, *tmp;
    tmp=del->right;
    successor=tmp;
    while(tmp!=NULL){
      bf_successor=successor; // prev prv trail
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
  else{ // has a child
    struct record* tmp;
    if(is_left)
      tmp=bf_del->left; // del == data인 경우 bf_del의 초기화? // <- seg fault 발생
      // has no child인 경우와 마찬가지로 해당 경우 고려해주어야 하지 않을까요?
    else
      tmp=bf_del->right;

    if(del->left==NULL)
      tmp=del->right;
    else
      tmp=del->left;
    free_node(del);
  }
  printf("The name was deleted.\n");

}


/* Just a wrapper of strncmp().
Regard strncmp(a,b) as a-b.
Negative value if key is less than r.
​0​ if key and r are equal.
Positive value if key is greater than r. */
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
void print_inorder(struct record *t) // 똑같음
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

// returns the height of the BST.
int height(struct record *t) // 똑같음
{
  int l, r;

  if(t==NULL) return -1;
  if((l=height(t->left))<(r=height(t->right))) return r+1;
  else return l+1;
}

void print_height()
{
  printf("The Address Book BST's height is %d.\n", height(data));
}
