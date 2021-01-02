//
// Created by musique88 on 12/31/20.
//

#include <Utils/TimeUtils.h>
#include <Utils/Log.h>
#include "Inventory/Weapon.h"

CC::Weapon::Weapon(
		CC::Element element, CC::WeaponType weaponType, float precision,
		float fireRate, float damage, float size, float projectileSpeed,
		int duration, int cost, bool automatic)
		: elemental_(element), weaponType_(weaponType), precision_(precision),
		fireRate_(fireRate), damage_(damage), projectileSpeed_(projectileSpeed),
		projectileSize_(size),
		duration_(duration), cost_(cost), automatic_(automatic), timer_(fireRate_)
{

}

std::shared_ptr<CC::Entities::Projectile> CC::Weapon::getSharedProjectile() const
{
	Entities::Projectile projectile = Entities::Projectile(
			1, elemental_, false, duration_, damage_, projectileSize_);
	return std::make_shared<Entities::Projectile>(projectile);
}

bool CC::Weapon::canShoot()
{
	return timer_ > fireRate_;
}


void CC::Weapon::update()
{
	timer_ += CGE::Utils::TPSClock::getDelta();
	//logInfo(timer_);
}

void CC::Weapon::shoot()
{
	timer_ = 0.f;
}


