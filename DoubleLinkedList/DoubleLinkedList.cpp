#include <iostream>
#include <string.h>
#include "DoubleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int HP)
{
	// ���͵��� ��� �ִ� ����ü�� ���� ( �����ͷ� )
	Monster* Index = new Monster;

	// ���ڿ��� �����ϴ� MS ���� �Լ�
	strcpy_s(Index->name, NAME_LENGTH, name);
	
	// ���� ����ü Index�� ���� ����ü�� HP�� ����Ű�� �ִµ�, �ű⿡ �Ű����� HP�� ���� ��������.
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

	// pMonster�� nullptr�� �ƴ� ��!!!
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
		// strcmp�� ��Ʈ�� �� �Լ�
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

	// �ٽ� ó������ �ʱ�ȭ
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