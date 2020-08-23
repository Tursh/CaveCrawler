//
// Created by musique88 on 8/22/20.
//

#ifndef CAVECRAWLER_SPELL_H
#define CAVECRAWLER_SPELL_H

#include <vector>
#include "Elemental.h"
#include "Inventory.h"

namespace CC
{
#define NUMBER_OF_ELEMENTS 7
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
	protected:
		int requirements[NUMBER_OF_ELEMENTS] = {};
	public:
		Element element = NEUTRAL;
		//returns the number of times it can be used
		int canUse(Inventory inventory);

		//returns if the spell has been used successfully
		bool use(Inventory* inventory);
	};
}

#endif //CAVECRAWLER_SPELL_H