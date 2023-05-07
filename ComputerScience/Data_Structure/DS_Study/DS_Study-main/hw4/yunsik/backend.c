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


void add(char *name, char *number)
{
    struct record* newNode = new_node();
    struct record* temp = data;
    struct record* prev = data;
    int result = 0;

    if (newNode == NULL)
        printf("Can't add.  The address book is full!\n");
    else
    {
        newNode->name[0] = name[0];
        newNode->name[1] = name[1];
        newNode->name[2] = name[2];
        newNode->number[0] = number[0];
        newNode->number[1] = number[1];
        newNode->number[2] = number[2];
        newNode->number[3] = number[3];
        newNode->next = NULL;

        if (data == NULL)
            data = newNode;
        else
        {
            if (result = compare(name, temp) <= 0)
            {
                newNode->next = data;
                data = newNode;
                //temp = newNode;
                return;
            }

            else
            {
                while (result = compare(name, temp) > 0)
                {
                    prev = temp;
                    temp = temp->next;
                }

                if (result = compare(name, temp) <= 0)
                {
                    prev->next = newNode;
                    newNode->next = temp;
                    return;
                }
                else
                {
                    prev->next = newNode;
                    newNode->next = NULL;
                    return;
                }
            }
        }
    }

  //printf("add() was not implemented.\n");
  // Error Message for overflow:
  // printf("Can't add.  The address book is full!\n");
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
    struct record* temp = data;
    struct record* prev = data;
    int result = 0;

    // linked list -> 1st == name
    if (temp != NULL && (result = compare(name, temp)) == 0)
    {
        data = temp->next;
        free_node(temp);
        printf("The name was deleted.\n");
        return;
    }

    // linked list location
    while (temp != NULL && (result = compare(name, temp)) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Couldn't find the name.\n");
        return;
    }

    prev->next = temp->next;
    printf("The name was deleted.\n");
    free_node(temp);
  //printf("delete() is not implemented.\n");
  // Error Message:
  // printf("Couldn't find the name.\n");
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
    struct record* r = data;

    while (r != NULL)
    {
        print_name(r);
        printf(" : ");
        print_number(r);
        printf("\n");
        r = r->next;
    }
  //printf("print_list() was not implemented.\n");
}

