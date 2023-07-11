#pragma once
#include"Monster.h"


struct MonsterList
{
	Monster* pHead{};
	Monster* pTail{};
};

// Create
Monster* CreateMonster(MonsterList& list, const char* name, const int HP);

// Count
int GetMonsterCount(const MonsterList& list);

// Print
void PrintMonsters(const MonsterList& list);

// Print( Recursive ver. )
//void PrintMonsterR(Monster* Monster);

// Search
Monster* FindMonster(const MonsterList& list, const char* name);

// Delete All
void DelelteAll(MonsterList& list);

// Delete Element
bool DeleteMonster(MonsterList& list, const char* name);