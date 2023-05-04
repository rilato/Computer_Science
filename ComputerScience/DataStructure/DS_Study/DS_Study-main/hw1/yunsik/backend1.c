#include <stdio.h>
#include "backend1.h"

#define NUMBER_OF_RECORDS 5

int search_index(char [3]);
void print_name(int);
void print_number(int);
void print_data(char *, int);

// External Variables

char data_name[NUMBER_OF_RECORDS][3];
char data_number[NUMBER_OF_RECORDS][4];

int k=0;  // index of the first empty slot

void add(char name[3], char number[4])
{
  if (k<NUMBER_OF_RECORDS) {
    data_name[k][0]=name[0];
    data_name[k][1]=name[1];
    data_name[k][2]=name[2];
    data_number[k][0]=number[0];
    data_number[k][1]=number[1];
    data_number[k][2]=number[2];
    data_number[k][3]=number[3];
    print_name(k);
    printf(" : ");
    print_number(k);
    printf(" was successfully added!\n");
    k++;
  }
  else
    printf("Can't add.  Address book is full.\n");
}


// Returns the index of the found record.
// Returns -1, if not found.
int search_index(char name[3])
{
    int i;

    for (i = 0; i < k; i++)
    {
        if (data_name[i][0] == name[0] && data_name[i][1] == name[1] && data_name[i][2] == name[2]) // 세 글자 모두 같으면 그 인덱스인 i를 반환
        {
            return i;
        }
    }
  //printf("Search was not implemented yet.\n");
  return -1;    // 세 글자 중 하나라도 다르면 -1을 반환
}


void search(char name[3])
{
  int s_result;

  s_result=search_index(name);
  if (s_result==-1)
    printf("Couldn't find the name.\n");
  else {
    print_name(s_result);
    printf(" : ");
    print_number(s_result);
    printf(" was found.\n");
  }
}


void delete(char name[3])
{
// Use search_index()
    int i, a, max;

    max = k;
    a = search_index(name); // 검색한 이름과 같은 이름을 찾았을 때의 그 이름의 인덱스가 a에 저장

    if (a == -1)    // 같은 것이 없었을 때
    {
        printf("The name is not in the address book.\n");
        return;
    }

    for (i = a; i < k; i++) // 같았던 이름의 자리를 그 다음 이름으로 덮어 씌움
    {
        if (i < k-1)
        {
            data_name[i][0] = data_name[i + 1][0];
            data_name[i][1] = data_name[i + 1][1];
            data_name[i][2] = data_name[i + 1][2];
            data_number[i][0] = data_number[i + 1][0];
            data_number[i][1] = data_number[i + 1][1];
            data_number[i][2] = data_number[i + 1][2];
            data_number[i][3] = data_number[i + 1][3];
        }
        else                // i = k인경우 k를 하나 줄여버려서 프린트할 때 보이지 않도록 함
        {
            max--;
            break;
        }
    }

    k = max;
    printf("The name was successfully deleted.\n");
    return;

  //printf("Deletion was not implemented yet.\n");
}


// Prints ith name.
void print_name(int i)
{
  print_data(data_name[i], 3);
}

// Prints ith number.
void print_number(int i)
{
  print_data(data_number[i], 4);
}


void print_data(char * s, int n)
{
  int i;
  for (i=0; i<n; i++)
    putchar(s[i]);
}

void print_list()
{
  int i;
  for (i=0; i<k; i++) {
    print_name(i);
    printf(" : ");
    print_number(i);
    printf("\n");
  }
}
