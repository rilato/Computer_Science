#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for delay()

#define N 5757

// words of 5 letters
char word[N][5];

// adjacency matrix
char adj_mat[N][N];


// Function declarations
void print_word();
void init_data();
void init_adj_mat();



/********* For adjacency list and queue, 
           we need node structure and its memory pool.
********************************************/
// record structure
struct node {
  int index;
  struct node * next;
};

#define POOL_SIZE 6*5757  // What is an appropriate size?  The average degree
			  // is about 5.  So this must be enough.

// pool of memory
struct node pool[POOL_SIZE];
struct node * top=pool;  // a pointer variable for stack top.

// Still use the same memory management.
void init_pool() // Initialize the pool. 
{
  int i;
  struct node *r=pool;
  struct node *s;

  pool[POOL_SIZE-1].next=NULL;  

  for(i=1;i<POOL_SIZE;i++) { 
    s=r++;
    s->next=r;
  }
}

// When calling new_node(), make sure to check if it returns NULL. 
struct node * new_node()  
{
  struct node *r;
  
  if(top==NULL)
    return NULL;

  r=top;
  top=r->next;  
  return r;
}

// Push a node to the pool.
void free_node(struct node *r)
{
  r->next=top;  
  top=r;
}

/***************** End of Memory Mananagement *********************/






/***************** adjacency list *******************/
struct node * adj_list[N];

void init_adj_list()
{
  int i,j;
  struct node *p;

  for (i=0; i<N; i++)
    adj_list[i]=NULL;
  
  for (i=0; i<N; i++)
    for (j=N-1; j>=0; j--)    // a new node is put in front.  To make the
			      // list in ascending order, we check the
			      // vertices in reverse order.
      if (adj_mat[i][j]) {  // adj_mat = 1 이면 (인접한 값을 가지면, degree가 1이면)
	p=new_node();
	p->index=j;
	p->next=adj_list[i];    // 맨 앞에 추가
	adj_list[i]=p;
      }
  printf("Adjacency list was successfully constructed!\n");
}



void init_data()
{
  int i;
  FILE *f;
  
  if ((f=fopen("words.dat", "r")) == NULL) 
    printf("Sorry, I can't open words.dat.\n");

  // skip the first four lines
  for (i=1; i<=4; i++) {
    while (getc(f)!='\n');
  }

  // start reading data
  for (i=0; i<N; i++) {
    fscanf(f, "%5c", word[i]);
    while (getc(f)!='\n');
  }

  printf("All the words were successfully read!\n");
  fclose(f);
}

int adjacent(char u[5], char v[5])
{
  int i, check=0;

  for (i=0; i<5; i++)
    if (u[i]!=v[i]) check++;
  
  if (check==1)
    return 1;
  else
    return 0;
}
  
void init_adj_mat()
{
  int i,j;
  
  for (i=0;i<N;i++)
    for (j=0;j<N;j++)
      adj_mat[i][j]=adjacent(word[i],word[j]);  // adj matrix를 형성. 강의록의 내용처럼 생겼을 것.

  printf("Adjacency matrix was successfully constructed!\n");
}


void print_word(int k)
{
  int i;
  if(0<=k && k<N) {
    for (i=0; i<5; i++)
      putchar(word[k][i]);
  }
  else
    printf("ERROR: print_word() received a k=%d which is out of bound!\n", k);
}




/* u-v */
int compare(char u[5], char v[5])
{
  return strncmp(u, v, 5);
}

// Sequential search.  
// Returns the index of the found record. (between 0 and N-1)
// Returns -1, if not found.
int search_index(char key[5])  
{
  int i;
  
  for (i=0; i<N; i++) {
    if(compare(key,word[i])==0)
      return i;
  }
  return -1;    // 인덱스가 0-5756이므로 이 사이에 값이 없으면 -1.
}


/********** Written Homework 4 *****************/
void whw4()
{
  // You may use this space for your homework :)
    // search index를 통해 hello의 인덱스를 찾아냄 -> 1178에 hello가 있구나! / world의 인덱스를 찾아냄 -> 5116에 있구나! 이걸 통해 linked list와 matrix를 찾아낼 수 있음

    int hello, graph;
    int i, j;
    int count1 = 0, count2 = 0;
    int my_array[N] = { 0, };
    int max = 0;
    int count = 0;
    int sum = 0, weighted_sum = 0;
    double average;
    int minimum;

    /*     1 번     */
    printf("\n");
    printf("Question 1.\n");

    hello = search_index("hello"); // 2290
    printf("Index of hello is %d\n", hello); // 2290
    graph = search_index("graph"); // 2215
    printf("Index of graph is %d\n", graph); // 2115
    printf("\n");

    struct node* r = adj_list[hello];   // hello의 인덱스를 adj_list에 대입
    struct node* l = adj_list[graph];

    while (r != NULL)
    {
        ++count1;
        print_word(r->index);   // hello와 adjacent한 word를 출력
        printf("\n");
        r = r->next;
    }
    printf("\nhello's degree is %d\n", count1);
    printf("\n");

    while (l != NULL)
    {
        ++count2;
        print_word(l->index);
        printf("\n");
        l = l->next;
    }
    printf("\ngraph's degree is %d\n", count2);
    printf("\n");
    printf("\n");

    /*     2 번     */
    printf("Question 2.\n");

    for (i = 0; i < N; i++)
    {
        struct node* p = adj_list[i];

        while (p != NULL)
        {
            ++count;
            p = p->next;
        }
        if (count > max) // 3번, 4번을 위한 max
            max = count;
        my_array[count] += 1;
        count = 0;
    }

    for (i = 0; i < N; i++)
    {
        if (my_array[i] != 0)
            printf("%d : %d\n", i, my_array[i]);
    }
    printf("\n");
    printf("\n");

    /*     3 번     */
    printf("Question 3.\n");

    printf("The maximum degree is %d\n", max);

    printf("\n");
    printf("\n");

    /*     4 번     */
    printf("Question 4.\n");

    for (i = 0; i < N; i++)
    {
        struct node* q = adj_list[i];

        while (q != NULL)
        {
            ++count;
            q = q->next;
        }
        if (count == max) // 3번, 4번을 위한 max
        {
            for (j = 0; j < 5; j++)
                printf("%c", word[i][j]);
            printf("\n");
        }
            
        count = 0;
    }

    printf("\n");
    printf("\n");

    /*     5 번     */
    printf("Question 5.\n");

    for (i = 0; i < N; i++)
    {
        if (my_array[i] != 0)
        {
            sum += my_array[i];
            weighted_sum += i * my_array[i];
            average = (double)weighted_sum / sum;
        }
    }
    printf("%d\n", weighted_sum);
    printf("The average degree is %f\n", average);
    printf("\n");
    printf("\n");

    /*     6 번     */
    printf("Question 6.\n");

    for (i = 0; i < N; i++)
    {
        struct node* s = adj_list[i];

        while (s != NULL)
        {
            ++count;
            s = s->next;
        }
    }

    printf("The number of nodes : %d\n", count);
    printf("\n");
    printf("\n");

    /*     7 번     */
    printf("Question 7.\n");
    minimum = average * N;  // 평균 * 5757하여 최소한의 POOL_SIZE를 구함 또는 노드의 총 개수가 최소한으로 필요한 노드의 수 이므로 6번의 답과 동일
    printf("The minimum possible size required of POOL_SIZE is %d\n", minimum);
    printf("\n");
    printf("\n");


    //int i, j, k, answer;
    //int count1 = 0, count2 = 0;
    //int my_array[N] = { 0, };
    //int max = 0;
    //int count = 0;
    //int end_count = -1;
    //int sum = 0, weighted_sum = 0;
    //double average;
    //double minimum;
    //
    ///*     1 번     */
    //printf("\n");
    //printf("Question 1.\n");

    //printf("\n");

    //for (i = 0; i < N; i++)
    //{
    //    answer = adjacent("hello", word[i]);
    //    
    //    if (answer == 1)
    //    {
    //        ++count1;
    //        printf("Adjacent word's index is %d. ", i);
    //        printf("The word is ");
    //        for (j = 0; j < 5; j++)
    //            printf("%c", word[i][j]);
    //        printf("\n");
    //    }
    //}
    //printf("hello's degree is %d", count1);
    //printf("\n");
    //printf("\n");

    //for (i = 0; i < N; i++)
    //{
    //    answer = adjacent("graph", word[i]);

    //    if (answer == 1)
    //    {
    //        ++count2;
    //        printf("Adjacent word's index is %d. ", i);
    //        printf("The word is ");
    //        for (j = 0; j < 5; j++)
    //            printf("%c", word[i][j]);
    //        printf("\n");
    //    }
    //}
    //printf("graph's degree is %d", count2);

    //printf("\n");
    //printf("\n");

    ///*     2 번     */
    //printf("Question 2.\n");

    //for (i = 0; i < N; i++)
    //{
    //    for (j = 0; j < N; j++)
    //    {
    //        answer = adjacent(word[i], word[j]);

    //        if (answer == 1)
    //            ++count;
    //    }
    //    my_array[count] += 1;
    //    count = 0;
    //}

    //printf("\n");

    //for (i = 0; i < N; i++)
    //{
    //    if (my_array[i] != 0)
    //    {
    //        printf("%d : %d\n", i, my_array[i]);
    //        ++end_count;
    //    }
    //}
    //printf("\n");
    //printf("\n");

    ///*     3 번     */
    //printf("Question 3.\n");

    //printf("\nThe maximum degree is %d\n", end_count);

    //printf("\n");
    //printf("\n");

    ///*     4 번     */
    //printf("Question 4.\n");

    //for (i = 0; i < N; i++)
    //{
    //    for (j = 0; j < N; j++)
    //    {
    //        answer = adjacent(word[i], word[j]);

    //        if (answer == 1)
    //            ++count;
    //    }

    //    if (count == end_count)
    //    {
    //        for (k = 0; k < 5; k++)
    //            printf("%c", word[i][k]);
    //        printf("\n");
    //    }

    //    count = 0;
    //}
    //printf("\n");
    //printf("\n");

    ///*     5 번     */
    //printf("Question 5.\n");

    //for (i = 0; i < N; i++)
    //{
    //    if (my_array[i] != 0)
    //    {
    //        sum += my_array[i];
    //        weighted_sum += i * my_array[i];
    //        average = (double)weighted_sum / sum;
    //    }
    //}
    //printf("The average degree is %f", average);
    //printf("\n");
    //printf("\n");

    ///*     6 번     */
    //printf("Question 6.\n");
    //printf("The number of nodes : %d", weighted_sum);
    //printf("\n");
    //printf("\n");

    ///*     7 번     */
    //printf("Question 7.\n");
    //minimum = average * N;  // 평균 * 5757하여 최소한의 POOL_SIZE를 구함
    //printf("%f\n", minimum);
    //printf("\n");
}


// All the initializations
void init()
{
  init_data();
  init_adj_mat();
  init_pool();
  init_adj_list();
  whw4();
}


void find_path(char start[5], char goal[5])
{
  int i,j,k,l;
  
  i=search_index(start);
  j=search_index(goal);

  if (i<0) printf("Sorry. %5s is not in the dictionary.", start);
  else if (j<0) printf("Sorry. %5s is not in the dictionary.", goal);
  else {
    printf("Hmm... I am trying to figure out the shortest path from ");
    print_word(i); printf(" to "); print_word(j); printf(".\n");
    for (l=0; l<150; l++) {
      for (k=0; k<N; k++) {
	printf("Considering about ");
	print_word(k);
	printf("\r"); fflush(stdout);
      }
    }
    printf("\nWell..., I don't know.  Please enlighten me ;)\n");
  }
}
