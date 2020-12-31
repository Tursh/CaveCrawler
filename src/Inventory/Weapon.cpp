//
// Created by musique88 on 12/31/20.
//

#include "Inventory/Weapon.h"

CC::Weapon::Weapon(
		CC::Element element, CC::WeaponType weaponType, float precision,
		float fireRate, float damage, float projectileSpeed,
		int duration, int cost, bool automatic)
		: elemental_(element), weaponType_(weaponType), precision_(precision),
		fireRate_(fireRate), damage_(damage), projectileSpeed_(projectileSpeed),
		duration_(duration), cost_(cost), automatic_(automatic)
{

}

std::shared_ptr<CC::Entities::Projectile> CC::Weapon::getSharedProjectile()
{
	Entities::Projectile projectile = Entities::Projectile(
			1, elemental_, false, duration_);
}

std::array<int, NUMBER_OF_ELEMENTS> CC::Weapon::requirements() const
{
	std::array<int, NUMBER_OF_ELEMENTS> array = std::array<int, NUMBER_OF_ELEMENTS>();
	array[elemental_] = cost_;
	return array;
}


