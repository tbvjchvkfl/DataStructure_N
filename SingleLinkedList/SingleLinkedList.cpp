#include <string.h>
#include <iostream>
#include "SingleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int HP)
{
	
	Monster* element = new Monster;

	// ���ڿ��� ����
	strcpy_s(element->name, NAME_LENGTH, name);
	element->HP = HP;

	// list.pTail -> pNext = element;
	// list.pTail = element;
	// �� ó�� ¥�� ù��° ���Ҹ� ���� �� 
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

	// while(p)�̷��� �ص� ��.
	//���� ����
	while (p != nullptr)
	{
		count++;
		p = p->pNext;
	}
	
	return count;
}

// �����͸� �̿��� ����
void PrintMonsters(const MonsterList& list)
{
	Monster* pp = list.pHead;
	while (pp)
	{
		std::cout << pp->name << "(" << pp->HP << ")" << std::endl;
		pp = pp->pNext;
	}
}

// �Լ��� ��� ȣ���� �̿��� ���
void PrintMonsterR(Monster* monster)
{
	if (monster == nullptr)
	{
		return;
	}

	std::cout << monster->name << "(" << monster->HP << ")" << std::endl;
	PrintMonsterR(monster->pNext);

	// ��� ȣ�� �ڿ� ����� ������ ������ ����� ȣ�� ���� ���� ����� �� ��!!!
	// std::cout << monster->name << "(" << monster->HP << ")" << std::endl;
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
	Monster* p = list.pHead;

	while(p)
	{
		// strcmp : string comparison �Լ� ( MS ���� ��� iostrea��� �־�� ��. )
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

