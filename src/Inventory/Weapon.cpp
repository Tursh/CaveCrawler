//
// Created by musique88 on 12/31/20.
//

#include <Utils/TimeUtils.h>
#include <Utils/Log.h>
#include <utility>
#include <World/Player.h>
#include <World/World.h>
#include "Inventory/Weapon.h"

CC::Entities::SharedProjectile CC::Weapon::getSharedProjectile() const
{
	return std::make_shared<Entities::Projectile>(Entities::Projectile(projectile_));
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

CC::Weapon::Weapon(
		CC::Element element, CC::WeaponType weaponType, float precision, float fireRate, float projectileSpeed,
		CC::Entities::Projectile projectile, int cost, bool automatic)
		: elemental_(element), weaponType_(weaponType), precision_(precision), fireRate_(fireRate),
		projectileSpeed_(projectileSpeed), projectile_(std::move(projectile)), cost_(cost), automatic_(automatic)
{}

void CC::Weapon::shoot(CC::Entities::Player *player, CC::World *world)
{
	std::uniform_real_distribution<float> distribution(-1.f, 1.f);
	std::shared_ptr<CC::Entities::Projectile> projectile = getSharedProjectile();
	projectile->setPositions(
			((CGE::Entities::Entity*)(player))->getPosition(), ((CGE::Entities::Entity*)(player))->getRotation(),
			player->getCameraVectorPointing() * projectileSpeed_ +
			glm::vec3(distribution(random_data),distribution(random_data),distribution(random_data)) * (1/precision_));
	world->addEntity(projectile);
	player->inventory[elemental_] -= cost_;
}


