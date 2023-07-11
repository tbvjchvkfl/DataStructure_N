#pragma once
#include"DoubleLinkedList.h"

const int NAME_LENGTH{ 10 };

struct Monster
{
	char name[NAME_LENGTH]{};
	int HP{};

	// 자기 참조 구조체
	Monster* pNext{};
	Monster* pPrevious{};
};
