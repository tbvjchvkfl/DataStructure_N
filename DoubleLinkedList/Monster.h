#pragma once
#include"DoubleLinkedList.h"

const int NAME_LENGTH{ 10 };

struct Monster
{
	char name[NAME_LENGTH]{};
	int HP{};

	// �ڱ� ���� ����ü
	Monster* pNext{};
	Monster* pPrevious{};
};
