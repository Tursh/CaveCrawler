//
// Created by musique88 on 8/22/20.
//

#include "Inventory/Spell.h"
#include "Inventory/Inventory.h"

namespace CC
{
	Inventory::Inventory(std::array<int,NUMBER_OF_ELEMENTS> elemental)
	{
		toolbar_ = {
				std::make_optional<CC::Weapon>(CC::Weapon()),
				std::nullopt,std::nullopt,std::nullopt,std::nullopt };
		setElemental(elemental);
	}

	Inventory::Inventory()
	: Inventory({0,0,0,0,0})
	{}

	void Inventory::setElemental(std::array<int, NUMBER_OF_ELEMENTS>elemental)
	{
		elemental_.swap(elemental);
	}

	int& Inventory::operator[](int index)
	{
		return elemental_[index];
	}

	void Inventory::useSpell(const Spell &spell)
	{
		for(int i = 0; i < NUMBER_OF_ELEMENTS; i++)
			elemental_[i] -= spell.requirements_[i];
	}

	std::array<std::optional<CC::Weapon>, 5> Inventory::getToolbar() const
	{
		return toolbar_;
	}

	void Inventory::setWeapon(CC::Weapon weapon, int index)
	{
		toolbar_[index] = weapon;
	}
}