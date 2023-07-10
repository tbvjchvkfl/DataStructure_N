#include <string.h>
#include <iostream>
#include "SingleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int HP)
{
	
	Monster* element = new Monster;

	// 문자열을 복사
	strcpy_s(element->name, NAME_LENGTH, name);
	element->HP = HP;

	// list.pTail -> pNext = element;
	// list.pTail = element;
	// 위 처럼 짜면 첫번째 원소를 만들 때 
	if (list.pTail == nullptr)
	{
		list.pHead = element;
	}
	else
	{
		list.pTail->pNext = element;
	}
	
	list.pTail = element;

	return element;
}

int GetMonsterCount(const MonsterList& list)
{
	Monster* p = list.pHead;
	int count{};

	// while(p)이렇게 해도 됨.
	//같은 뜻임
	while (p != nullptr)
	{
		count++;
		p = p->pNext;
	}
	
	return count;
}

// 포인터를 이용한 버전
void PrintMonsters(const MonsterList& list)
{
	Monster* pp = list.pHead;
	while (pp)
	{
		std::cout << pp->name << "(" << pp->HP << ")" << std::endl;
		pp = pp->pNext;
	}
}

// 함수의 재귀 호출을 이용한 방법
void PrintMonsterR(Monster* monster)
{
	if (monster == nullptr)
	{
		return;
	}

	std::cout << monster->name << "(" << monster->HP << ")" << std::endl;
	PrintMonsterR(monster->pNext);

	// 재귀 호출 뒤에 출력이 나오면 역순을 출력함 호출 스택 개념 까먹지 말 것!!!
	// std::cout << monster->name << "(" << monster->HP << ")" << std::endl;
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
	Monster* p = list.pHead;

	while(p)
	{
		// strcmp : string comparison 함수 ( MS 제공 기능 iostrea헤더 있어야 함. )
		if (strcmp(p->name, name) == 0)
		{
			return p;
		}
		p = p->pNext;
	}
	return nullptr;
}

void DelelteAll(MonsterList& list)
{
	Monster* p = list.pHead;

	Monster* pNext{};

	while (p != nullptr)
	{
		pNext = p->pNext;
		delete p;
		p = pNext;
	}

	list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
	return false;
}

