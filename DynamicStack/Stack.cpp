#include"Stack.h"
#include<iostream>

void Push(Stack& stack, int value)
{
	Element* pElement = new Element{};
	pElement->value = value;

	pElement->pNext = stack.ptop;
	stack.ptop = pElement;
	stack.count++;
}
void Pop(Stack& stack)
{
	if (stack.count == 0)
	{
		std::cout << "STACK IS EMPTY" << std::endl;
		return;
	}

	// 백업용
	Element* pPrevTop = stack.ptop;

	// Pop 시작
	stack.ptop = pPrevTop->pNext;
	stack.count--;
	delete pPrevTop;
}
void Print(Stack& stack)
{
	Element* pElement = stack.ptop;

	while (pElement)
	{
		std::cout << pElement->value << std::endl;
		pElement = pElement->pNext;
	}
}
void RemoveAll(Stack& stack)
{
	Element* pElement = stack.ptop;
	Element* pNext{};

	while (pElement)
	{
		pNext = pElement->pNext;
		delete pElement;
		pElement = pNext;
	}

	stack.count = 0;
	stack.ptop = nullptr;
}