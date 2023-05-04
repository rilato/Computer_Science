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
    int result;

    struct record* temp = data;
    struct record* prev = data;
    struct record* newNode = new_node();

    if (newNode == NULL)
    {
        printf("Can't add.  The pool is empty!\n");
        return;
    }

    while (temp != NULL)
    {
        if ((result = compare(name, temp)) <= 0)
        {
            prev = temp;
            temp = temp->left;
        }
        else
        {
            prev = temp;
            temp = temp->right;
        }
    }

    newNode->name[0] = name[0];
    newNode->name[1] = name[1];
    newNode->name[2] = name[2];
    newNode->number[0] = number[0];
    newNode->number[1] = number[1];
    newNode->number[2] = number[2];
    newNode->number[3] = number[3];
    newNode->left = NULL;
    newNode->right = NULL;
    printf("The name was successfully added!\n");

    if (data == NULL)
    {
        data = newNode;
        return;
    }

    if ((result = compare(name, prev)) <= 0)
        prev->left = newNode;
    else
        prev->right = newNode;

  // Messages to print
  //  printf("Can't add.  The pool is empty!\n");
  //  printf("The name was successfully added!\n");
}


// The most complicated.
void delete(char name[3])  
{
    int result;

    struct record* temp = data;
    struct record* prev = data;
    struct record* local_temp = data;
    struct record* local_prev = data;

    while (temp != NULL)
    {
        if ((result = compare(name, temp)) < 0)
        {
            prev = temp;
            local_prev = temp;
            temp = temp->left;
            local_temp = temp; 
        }

        else if ((result = compare(name, temp)) > 0)
        {
            prev = temp;
            local_prev = temp;
            temp = temp->right;
            local_temp = temp; // 아마 right?
        }

        else
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                if (prev == temp)
                    data = NULL;

                if (prev->left == temp)
                    prev->left = NULL;

                if (prev->right == temp)
                    prev->right = NULL;

                free_node(temp);
                printf("The name was deleted.\n"); //같은 printf를 반복하지 않아도 구현가능함
                return;
            }

            if (temp->left == NULL && temp->right != NULL)
            {
                if (prev == temp)
                    data = temp->right;

                if (prev->right == temp) // else if와 else를 사용했어도 좋을거같음
                    prev->right = temp->right;

                if (prev->left == temp)
                    prev->left = temp->right;

                free_node(temp);
                printf("The name was deleted.\n");
                return;
            }

            if (temp->left != NULL && temp->right == NULL)
            {
                if (prev == temp)
                    data = temp->left;

                if (prev->right == temp)
                    prev->right = temp->left;

                if (prev->left == temp)
                    prev->left = temp->left;

                free_node(temp);
                printf("The name was deleted.\n"); 
                return;
            }

            if (temp->left != NULL && temp->right != NULL) // 자식 2개인 노드 delete 할때 seg fault 발생
            {  
                local_temp = local_temp->right; // local_temp가 NULL인 경우에 처리가 이상해짐 아마 predecessor로 구현?
              
                if (local_temp->left == NULL)
                {
                    data = local_temp;
                    local_temp->left = temp->left;
                    free_node(temp);
                    printf("The name was deleted.\n");
                    return;
                }
              
                while (local_temp->left != NULL)
                {
                    local_prev = local_temp;
                    local_temp = local_temp->left;
                }

                if (prev == temp)
                {
                    local_prev->left = local_temp->right;
                    data = local_temp;
                    local_temp->right = temp->right;
                    local_temp->left = temp->left;
                }

                if (prev->right == temp)
                {
                    local_prev->left = local_temp->right;
                    prev->right = local_temp;
                    local_temp->right = temp->right;
                    local_temp->left = temp->left;
                }

                if (prev->left == temp)
                {
                    local_prev->left = local_temp->right;
                    prev->left = local_temp;
                    local_temp->right = temp->right;
                    local_temp->left = temp->left;
                }

                free_node(temp);
                printf("The name was deleted.\n");
                return;
            }
        }

    }

    if (temp == NULL)
        printf("Couldn't find the name.\n"); // abc add후 aaa 삭제하고자 하면 seg fault (다른 유사한 상황에도 마찬가지)

    // Messages to print
  //  printf("The name was deleted.\n");  
  //  printf("Couldn't find the name.\n");
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
    if (t == NULL)
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


// returns the height of the BST.
int height(struct record *t)
{
    if (t == NULL)
        return -1;
    if (height(t->left) < height(t->right))
        return height(t->right) + 1;
    else
        return height(t->left) + 1;
  // dummy return.  Should return a valid height.
  //return 0;
}

void print_height()  
{
  printf("The Address Book BST's height is %d.\n", height(data));
}
