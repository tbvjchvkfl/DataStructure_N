#include <iostream>
#include <string.h>
#include "DoubleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int HP)
{
	// 몬스터들을 담고 있는 구조체를 선언 ( 포인터로 )
	Monster* Index = new Monster;

	// 문자열을 복사하는 MS 제공 함수
	strcpy_s(Index->name, NAME_LENGTH, name);
	
	// 몬스터 구조체 Index는 몬스터 구조체의 HP를 가리키고 있는데, 거기에 매개변수 HP의 값을 배정해줌.
	Index->HP = HP;
	

	if (list.pTail == nullptr)
	{
		list.pHead = Index;
	}
	else
	{
		list.pTail->pNext = Index;
		list.pHead->pPrevious = Index;
	}

	list.pTail = Index;
	return Index;
}

int GetMonsterCount(const MonsterList& list)
{
	Monster* pMonster = list.pHead;
	int count{};

	// pMonster가 nullptr이 아닐 때!!!
	while (pMonster)
	{
		count++;
		pMonster = pMonster->pNext;
	}
	return count;
}

void PrintMonsters(const MonsterList& list)
{
	Monster* pMonster = list.pHead;
	
	while (pMonster)
	{
		std::cout << pMonster->name << "(" << pMonster->HP << ")" << std::endl;
		pMonster = pMonster->pNext;
	}
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
	Monster* pMonster = list.pHead;

	while (pMonster)
	{
		// strcmp는 스트링 비교 함수
		if (strcmp(pMonster->name, name) == 0)
		{
			return pMonster;
		}
		pMonster = pMonster->pNext;
	}
	return nullptr;
}

void DelelteAll(MonsterList& list)
{
	Monster* pMonster = list.pHead;
	Monster* NextIndex{};

	while (pMonster)
	{
		NextIndex = pMonster->pNext;
		delete pMonster;
		pMonster = NextIndex;
	}

	// 다시 처음으로 초기화
	list.pHead = list.pTail = nullptr;

}

bool DeleteMonster(MonsterList& list, const char* name)
{
	Monster* Index = list.pHead;

	while (Index)
	{
		if (strcmp(Index->name, name) == 0)
		{
			break;
		}

		list.pHead = Index;
		list.pTail = Index->pNext;

	}


	return false;
}