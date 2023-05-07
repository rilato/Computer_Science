// ArrayBaseStackMain.c / 메인함수

#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
	// Stack의 생성 및 초기화 //
	Stack stack;
	StackInit(&stack);

	// 데이터 넣기 //
	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);

	// 데이터 꺼내기 //
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}



// ArrayBaseStack.h / 헤더파일

#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE		1
#define FALSE		0
#define STACK_LEN	100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);	// 스택의 초기화
int SIsEmpty(Stack* pstack);	// 스택이 비어있는지 확인

void SPush(Stack* pstack, Data data);	// 스택의 push 연산
Data SPop(Stack* pstack);				// 스택의 pop연산
Data SPeek(Stack* pstack);				// 스택의 peek 연산

#endif



// ArrayBaseStack.c / 백엔드 파일

#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}


void SPush(Stack* pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;	// 제거한 값을 리턴하기 위해 rIdx에 인덱스를 임시 저장
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];	// 제거한 값을 리턴
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
