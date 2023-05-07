// add()함수는 랜덤한 숫자를 POOL_SIZE만큼 생성하고 해당 BST의 높이값을 반환합니다.
// height()함수는 이진 탐색 트리를 REPEAT만큼 반복시켜, 높이의 평균과 분산, 표준편차를 구합니다.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "backend-bst.h"

#define POOL_SIZE 50 // 변수 처리 하거나 표준입력을 통해 진행?
#define REPEAT 10000 // iteration이 일반적 표현?

int max_height = 0;

// record structure
struct record {
    int num;
    struct record* left;
    struct record* right;
};

void height();

// pool of memory
static struct record pool[POOL_SIZE]; // static because pool is strictly private
struct record* top = pool;  // a pointer variable for pool stack top.

// data
struct record* data = NULL; // Initially NULL.


void init_pool() // Initialize the pool; Use right instead of next!!!
{
    int i;
    struct record* r = pool;
    struct record* s;

    pool[POOL_SIZE - 1].right = NULL;

    for (i = 1; i < POOL_SIZE; i++) {
        s = r++;
        s->right = r;
    }
}

// Get a node from the pool. Returns NULL if pool is empty.
// When calling new_node(), make sure to check if it is NULL.
struct record* new_node()
{
    struct record* r;

    if (top == NULL)
        return NULL;

    r = top;
    top = r->right;  // Again, right instead of next.
    return r;
}

// Push a node to the pool.
void free_node(struct record* r)
{
    r->right = top;  // Again, right instead of next.
    top = r;
}

void free_all()
{
    int i;

    for (i = 0; i < POOL_SIZE; i++)
        free_node(data);

    data = NULL;
}

void add_sub()
{
    int number;
    int temp_height = 0;

    struct record* temp = data;
    struct record* prev = data;
    struct record* newNode = new_node();

    if (newNode == NULL)
    {
        ("Can't add.  The pool is empty!\n");
        return;
    }

    number = rand(); // srand와 인접?

    while (temp != NULL)
    {
        if (number <= temp->num)
        {
            prev = temp;
            temp = temp->left;
            temp_height++;
        }

        else
        {
            prev = temp;
            temp = temp->right;
            temp_height++;
        }
    }

    newNode->num = number;
    newNode->left = NULL;
    newNode->right = NULL;

    if (data == NULL)
    {
        data = newNode;
        temp_height++;
        return;
    }
    else if (number <= prev->num)
        prev->left = newNode;
    else
        prev->right = newNode;

    if (max_height < temp_height)
        max_height = temp_height; // <- height 측정 마지막에 하는것이 좋지 않을까
}

int add()
{
    int i;

    for (i = 0; i < POOL_SIZE; i++)
        add_sub();

    return max_height; // max를 리턴?
}

void height() //average height
{
    int arr[POOL_SIZE];
    int i;
    int sum = 0; // 자료형 더 큰것? unsigned long long
    double variance_sum = 0;
    double average, variance, standard_Deviation; // 표기법?

    for (i = 0; i < POOL_SIZE; i++)
    {
        arr[i] = 0;
    } // 일정한 스타일?

    for (i = 0; i < REPEAT; i++)
    {
        int result = add(); // add는 height를 반환, height에 맞는 배열의 인덱스에 들어가서 숫자가 하나씩 증가 // 선언과 할당 분리 일정한 스타일?
        arr[result]++;
        free_all();
        init_pool();
        max_height = 0;
    }

    for (i = 0; i < POOL_SIZE; i++)
    {
        printf("the number of height %d : %d",i, arr[i]);
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < POOL_SIZE; i++)
        sum += i * arr[i];  // i는 height고, arr[i]는 height = i인 것이 나온 횟수

    average = (double)sum / REPEAT;

    for (i = 0; i < POOL_SIZE; i++)
        variance_sum += ((double)i - average) * ((double)i - average) * (double)arr[i]; // var 계속해서 더해가면 따로변수 하나 더 선언하지 않아도 될것 같다?

    variance = variance_sum / REPEAT;

    standard_Deviation = sqrt(variance);


    printf("average of height : %f", average);
    printf("\n");
    printf("variance of height : %f", variance);
    printf("\n");
    printf("standard deviation of height : %f", standard_Deviation);
    printf("\n");
}

void print_inorder(struct record* t)
{
    if (t == NULL)
        return;

    print_inorder(t->left);
    printf("%d", t->num);
    printf("\n");
    print_inorder(t->right);
}

void print_list()
{
    print_inorder(data);
}
