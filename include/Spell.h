//
// Created by musique88 on 8/22/20.
//
#pragma once
#include <vector>
#include "Inventory.h"

namespace CC
{

	enum Element
	{
		NEUTRAL, WATER, FIRE, NATURE, ELECTRICITY, AIR, ICE
	};

	enum Effect
	{
		STRONG_HEAL,
		HEAL,
		IMMUNE,
		WEAK,
		NORMAL,
		STRONG
	};

	struct ElementRelationship
	{
		static Effect Relationship(Element attack, Element target);
	};

	class Spell
	{
	public:
		Spell(Element element, int *requirements);

		Element element = NEUTRAL;
		//returns the number of times it can be used
		int canUse(int *inventory);
		int requirements[NUMBER_OF_ELEMENTS] = {};
		//returns if the spell has been used successfully
		bool use(int *inventory);
	};
}