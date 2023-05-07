#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "backend.h"

#define UNDISCOVERED 0
#define DISCOVERED   1
#define PROCESSED    2

/****************************************
Implement Breadth-First Search on the graph constructed in "backend.c" and
use it in the find_path() below.

You can access functions and data structures constructed in "backend.c" via
"backend.h"

backend.c에 있는 내용들을 적절히 활용해 가면서 만들 것. adj_list 등을 이용할 것. 아마도 adj_list 등은 이미 구현(완성)되어 있는 듯.
*****************************************/

int state[5757] = { 0, };
int queue[5757] = { 0, };
int parent[5757] = { 0, };
int my_list[5757] = { 0, };

void array_init()
{
    int i;

    for (i = 0; i < N; i++)
    {
        state[i] = UNDISCOVERED;
        queue[i] = 0;
        parent[i] = -1;
    }
}

void push(int i, int *last)
{
    queue[*last] = i;
    ++(*last);
}

int pop(int *last, int *first)
{
    ++(*first);
    return queue[*first - 1];
}

int shortest_path(int i, int j)
{
    // i는 start의 index / j는 goal의 index
    int current = 0;
    int neighbor;
    int first = 0;
    int last = 0;

    state[i] = DISCOVERED;
    push(i, &last);    // i를 큐에 넣기

    while (first <= last)   // 큐가 NULL이 아닌동안
    {
        current = pop(&last, &first);    // 큐에서 하나 꺼내오기

        struct node *temp = adj_list[current];

        while (temp != NULL)   // adj list의 끝까지 탐색
        {
            neighbor = temp->index;

            if (state[neighbor] == UNDISCOVERED)
            {
                state[neighbor] = DISCOVERED;
                push(neighbor, &last);
                parent[neighbor] = current; // neighbor는 parent에서 index고 ('search_index(단어)' 로 찾아야함), current는 값
                if (neighbor == j)
                    return 1;
            }

            state[current] = PROCESSED;
            temp = temp->next;
        }
    }

    return 0;
}

/* 전역 변수 선언해야 함. */
/* parent 배열을 통해 부모 노드를 찾아가는 함수도 필요(?) */


/* 큐 구현. 큐 구현을 위한 적절한 data structure를 만들고 그 안에 push, pop 등을 구현. 큐는 shortest_path 안에서 사용될 것. */
/* 배열을 이용하여 큐를 구현하는 것이 더 간단할 것 *//* 큐를 의미할 배열은 queue[5757]이면 충분할 것 -> overflow가 날 일이 없음 */
/* 큐에 담기는 data는 int type임 (int type의 배열을 가지는 큐) !! backend.c에서 int type의 index로 꼭짓점을 표현했음 */
/* 큐는 push할 곳을 가리키는 것(포인터?)과 pop할 곳을 가리키는 것(포인터?)이 필요 */
/* 큐에서 pop한 것이 current(꼭짓점)가 되고, shortest_path while문에서 그 꼭짓점을 기준으로 인접한 것을 검사하도록 함.*/



/* 아래 함수도 고쳐야 함. */
void find_path(char start[5], char goal[5])
{
  int i,j,k,l = 0;
  
  i=search_index(start);    // start의 index를 계산
  j=search_index(goal);     // goal의 index를 계산

  /* 계산한 index가 range 안에 제대로 있는지 확인 */
  if (i<0) {
    printf("Sorry. ");
    print_five_chars(start);
    printf(" is not in the dicitonary.");
  }
  else if (j<0) {
    printf("Sorry. ");
    print_five_chars(goal);
    printf(" is not in the dicitonary.");
  }
  else { // i, j를 이용해서 shortest_path를 찾는 것에 관한 코드가 여기에 있어야 함. shortest_path라는 함수를 만들고 아래에서 부르도록 함. shortest_path == 1이면 print 진행. 아니면 경고.
      int a = 0;
      int b = j;

      array_init();
      k = shortest_path(i, j);

      if (k == 0)
      {
          printf("Sorry. There is no path from ");
          print_five_chars(start);
          printf(" to ");
          print_five_chars(goal);
          printf(".\n");
          return;
      }

      while (parent[b] != -1)
      {
          my_list[a++] = b;
          b = parent[b];
      }

      printf("          0 ");
      print_five_chars(start);
      printf("\n");

      for (i = a - 1; i > 0; i--)
      {
          printf("          %d ", a - i);
          print_word(my_list[i]);
          printf("\n");
      }

      printf("          %d ", a);
      print_five_chars(goal);
      printf("\n");
  }
}
