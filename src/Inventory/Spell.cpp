//
// Created by musique88 on 8/22/20.
//

#include "Spell.h"
namespace CC
{
	bool Spell::use(Inventory *inventory)
	{

	}

	int Spell::canUse(Inventory inventory)
	{
		int numberOfTimesCraftable = -1;
		int tempInventory[NUMBER_OF_ELEMENTS];
		tempInventory = inventory.elemental;

		bool stillCraftable = true;
		do{
			for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
			{
				tempInventory[i] -= requirements[i];
				stillCraftable &= tempInventory[i] >= 0;
			}
			++numberOfTimesCraftable;
		} while (stillCraftable);
		return numberOfTimesCraftable;
	}

	Effect ElementRelationship::Relationship(Element attack, Element target)
	{
		Effect table[NUMBER_OF_ELEMENTS][NUMBER_OF_ELEMENTS] = {
				{NORMAL,	WEAK,		WEAK,	NORMAL,		NORMAL,	IMMUNE,	NORMAL},
				{NORMAL,	HEAL,		IMMUNE,	NORMAL,		STRONG,	WEAK,	HEAL},
				{NORMAL,	STRONG,		IMMUNE,	IMMUNE,		IMMUNE,	HEAL,	WEAK},
				{NORMAL,	STRONG_HEAL,STRONG,	STRONG_HEAL,STRONG,	WEAK,	NORMAL},
				{NORMAL,	STRONG_HEAL,WEAK,	IMMUNE,		HEAL,	WEAK,	WEAK},
				{NORMAL,	STRONG,		STRONG,	STRONG,		IMMUNE,	WEAK,	IMMUNE},
				{NORMAL,	HEAL,		STRONG,	NORMAL,		NORMAL,	WEAK,	NORMAL}
		};
		return table[attack][target];
	}
}