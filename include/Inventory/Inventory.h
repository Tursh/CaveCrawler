//
// Created by musique88 on 8/22/20.
//
#pragma once

#include <array>
#include "Spell.h"
#include "Weapon.h"
#include <optional>

namespace CC
{
	class Inventory
	{
		std::array<std::optional<CC::Weapon>, 5> toolbar_;
		std::array<int, NUMBER_OF_ELEMENTS> elemental_;

	public:
		uint selectedWeapon;
		[[nodiscard]] std::array<std::optional<CC::Weapon>, 5> getToolbar() const;
		void setWeapon(CC::Weapon weapon, int index);
		Inventory();
		explicit Inventory(std::array<int,NUMBER_OF_ELEMENTS> elemental);
		void setElemental(std::array<int,NUMBER_OF_ELEMENTS> elemental);
		void useSpell(const Spell &spell);
		int& operator[] (int index);
	};
}
