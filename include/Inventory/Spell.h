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
		WATER_ELEMENT,
		FIRE_ELEMENT,
		NATURE_ELEMENT,
		ELECTRICITY_ELEMENT,
		AIR_ELEMENT,
		ICE_ELEMENT
	};
#define NUMBER_OF_ELEMENTS 7

	enum Effect
	{
		STRONG_HEAL_EFFECT,
		HEAL_EFFECT,
		IMMUNE_EFFECT,
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