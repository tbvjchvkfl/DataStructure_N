#include <iostream>
#include "Stack.h"

// 링크드 리스트를 이용한 스택


int main()
{
	Stack myStack;

	Push(myStack, 1);
	Push(myStack, 2);
	Push(myStack, 3);

	Print(myStack);

	Pop(myStack);
	Print(myStack);
	Pop(myStack);
	Print(myStack);
	Pop(myStack);
	Print(myStack);

	RemoveAll(myStack);

}