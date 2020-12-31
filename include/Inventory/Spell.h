//
// Created by musique88 on 8/22/20.
//
#pragma once
#include <vector>
#include <array>

namespace CC
{
	class Inventory;
	enum Element
	{
		NEUTRAL_ELEMENT,
		THUNDER_ELEMENT,
		WATER_ELEMENT,
		FIRE_ELEMENT,
		AIR_ELEMENT
	};
#define NUMBER_OF_ELEMENTS 5

	enum Effect
	{
		WEAK_EFFECT,
		NORMAL_EFFECT,
		STRONG_EFFECT
	};

	struct ElementRelationship
	{
		static Effect Relationship(Element attack, Element target);
	};

	class Spell
	{
	public:
		Spell(Element element, std::array<int,NUMBER_OF_ELEMENTS> requirements);

		Element element_ = NEUTRAL_ELEMENT;
		//returns the number of times it can be used
		int canUse(Inventory inventory);
		std::array<int, NUMBER_OF_ELEMENTS> requirements_ = {};
		//returns if the spell has been used successfully
		bool use(Inventory &inventory);
	};
}