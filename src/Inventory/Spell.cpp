//
// Created by musique88 on 8/22/20.
//

#include "Inventory/Spell.h"
#include "Inventory/Inventory.h"
namespace CC
{
	static Effect table[NUMBER_OF_ELEMENTS][NUMBER_OF_ELEMENTS] = {
			{NORMAL_EFFECT, WEAK_EFFECT,        WEAK_EFFECT,   NORMAL_EFFECT,      NORMAL_EFFECT, IMMUNE_EFFECT, NORMAL_EFFECT},
			{NORMAL_EFFECT, HEAL_EFFECT,        IMMUNE_EFFECT, NORMAL_EFFECT,      STRONG_EFFECT, WEAK_EFFECT,   HEAL_EFFECT},
			{NORMAL_EFFECT, STRONG_EFFECT,      IMMUNE_EFFECT, IMMUNE_EFFECT,      IMMUNE_EFFECT, HEAL_EFFECT,   WEAK_EFFECT},
			{NORMAL_EFFECT, STRONG_HEAL_EFFECT, STRONG_EFFECT, STRONG_HEAL_EFFECT, STRONG_EFFECT, WEAK_EFFECT,   NORMAL_EFFECT},
			{NORMAL_EFFECT, STRONG_HEAL_EFFECT, WEAK_EFFECT,   IMMUNE_EFFECT,      HEAL_EFFECT,   WEAK_EFFECT,   WEAK_EFFECT},
			{NORMAL_EFFECT, STRONG_EFFECT,      STRONG_EFFECT, STRONG_EFFECT,      IMMUNE_EFFECT, WEAK_EFFECT,   IMMUNE_EFFECT},
			{NORMAL_EFFECT, HEAL_EFFECT,        STRONG_EFFECT, NORMAL_EFFECT,      NORMAL_EFFECT, WEAK_EFFECT,   NORMAL_EFFECT}
	};

	Spell::Spell(Element element, std::array<int,NUMBER_OF_ELEMENTS> requirements)
	{
		this->element_ = element;
		requirements_.swap(requirements);
	}

	int Spell::canUse(Inventory inventory)
	{
		int numberOfTimesCraftable = -1;
		bool stillCraftable = true;
		do{
			for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
			{
				inventory[i] -= requirements_[i];
				stillCraftable &= inventory[i] >= 0;
			}
			++numberOfTimesCraftable;
		} while (stillCraftable);
		return numberOfTimesCraftable;
	}

	bool Spell::use(Inventory &inventory)
	{
		if (canUse(inventory))
		{
			inventory.useSpell(*this);
			return true;
		}
		else
			return false;
	}

	Effect ElementRelationship::Relationship(Element attack, Element target)
	{
		return table[attack][target];
	}
}