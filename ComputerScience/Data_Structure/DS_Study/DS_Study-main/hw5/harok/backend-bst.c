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


void add(char *name, char *number)
{
  struct record *r;
  struct record *p;
  struct record *q = NULL;

  r = new_node();

  if (r==NULL)
  {
    printf("Can't add.  The pool is empty!\n");
    return;
  }
    
  p = data;
  
  while (p!=NULL) {
    if (compare(name,p)<=0)
    {
      q = p;
      p = p->left;
    }
    else
    {
      q = p;
      p = p->right;
    }
  }

  (r->name)[0] = name[0];
  (r->name)[1] = name[1];
  (r->name)[2] = name[2];
  (r->number)[0] = number[0];
  (r->number)[1] = number[1];
  (r->number)[2] = number[2];
  (r->number)[3] = number[3];
  r->left = NULL;
  r->right = NULL;

  if (data == NULL)
  {
    data = r;
  }
  else if (compare(name,q)<=0)
  {
    q->left = r;
  }
  else
  {
    q->right = r;
  }
  printf("The name was successfully added!\n");
}

void delete(char name[3])
{
  struct record *p;
  struct record *r;
  struct record *s;
  struct record *t;
  int result;
  p=data;
  r=data;

  while (r!=NULL) 
  {   
    result = compare(name,r);
    if (result<0)
    {
      p=r;
      r=r->left;
    }
    else if (result==0)
      break;
    else 
    {
      p=r;
      r=r->right;
    }
  }

  if (r == NULL)
  {
    printf("Couldn't find the name.\n");
    return;
  }

  if (r->left == NULL && r->right == NULL) // no child
  {
    if (p->left == r)
      p->left = NULL;
    else if (p->right == r)
      p->right = NULL;
    else // p == r
      data = NULL;
    free_node(r);
  }

  else if (r->left != NULL && r->right == NULL) // only left child
  {
    if (p->left == r)
      p->left = r->left;
    else if (p->right == r)
      p->right = r->left;
    else
      data = r->left;
    free_node(r);
  }

  else if (r->left == NULL && r->right != NULL) // only right child
  {
    if (p->left == r)
      p->left = r->right;
    else if (p->right == r)
      p->right = r->right;
    else
      data = r->right;
    free_node(r);
  }

  else if (r->left != NULL && r->right != NULL) // 2 children
  {
    t = r->right;
    s = r->right;
    while (s->left != NULL)
    {
      t = s;
      s = s->left;
    }
    strncpy(r->name, s->name, 3);
    strncpy(r->number, s->number, 4);

    if (s == r->right)
      r->right = s->right;
    else
    {
      if (s->right)
        t->left = s->right;
      else
        t->left = NULL;
    }
    
    free_node(s);
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

void print_inorder(struct record *t)
{
  if (t==NULL)
    return;
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
  int lefth; 
  int righth; 

  if (t==NULL)
    return -1;

  lefth = height(t->left);
  righth = height(t->right);

  if (lefth < righth)
    return righth+1;
  else
    return lefth+1;
}




void print_height()  
{
  printf("The Address Book BST's height is %d.\n", height(data));
}
