//
// Created by musique88 on 8/22/20.
//
#pragma once

#include <array>
#include "Spell.h"

namespace CC
{
	class Inventory
	{
		std::array<int, NUMBER_OF_ELEMENTS> elemental_;
	public:
		Inventory();
		Inventory(std::array<int,NUMBER_OF_ELEMENTS> elemental);
		void setElemental(std::array<int,NUMBER_OF_ELEMENTS> elemental);
		void useSpell(Spell &spell);
		int& operator[] (int index);
	};
}
