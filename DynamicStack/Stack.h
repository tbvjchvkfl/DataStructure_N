#pragma once

struct Element
{
	int value{};

	Element* pNext{};
};

struct Stack
{
	int count{};
	Element* ptop{};
};


void Push(Stack& stack, int value);
void Pop(Stack& stack);
void Print(Stack& stack);
void RemoveAll(Stack& stack);