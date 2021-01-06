//
// Created by musique88 on 8/22/20.
//

#include "Inventory/Spell.h"
#include "Inventory/Inventory.h"

namespace CC
{
	Inventory::Inventory(std::array<int,NUMBER_OF_ELEMENTS> elemental)
	:toolbar_({std::make_optional<CC::Weapon>(CC::Weapon()), std::nullopt,std::nullopt,std::nullopt,std::nullopt }),
	selectedWeapon_(0), elemental_(elemental)
	{}

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

	const std::array<std::optional<Weapon>, 5> &Inventory::getToolbar()
	{
		return toolbar_;
	}

	void Inventory::setWeapon(Weapon weapon, int index)
	{
		toolbar_[index] = weapon;
	}

	void Inventory::update()
	{
		for (std::optional<Weapon> &weapon : toolbar_)
			if (weapon)
				weapon.value().update();
	}

	Weapon Inventory::getWeapon() const
	{
		std::optional<CC::Weapon> selectedWeapon = toolbar_[selectedWeapon_];
		return selectedWeapon ? selectedWeapon.value() : toolbar_[0].value();
	}

	void Inventory::useWeapon(uint index, CC::Entities::Player *player, World *world)
	{
		std::optional<CC::Weapon>& selectedWeapon = toolbar_[selectedWeapon_] = toolbar_[index];
		(selectedWeapon ? selectedWeapon.value() : toolbar_[0].value()).shoot(player, world);
	}
}