//
// Created by musique88 on 12/31/20.
//

#pragma once

#include <memory>
#include <random>
#include "Spell.h"
#include "Projectile.h"

namespace CC
{
	class World;
	class Inventory;
	namespace Entities
	{
		class Player;
	}

	enum WeaponType
	{
		HAND, WAND, STAFF, RING, BRACELETS
	};

	class Weapon
	{
		std::default_random_engine random_data;
	public:
		Element elemental_;
		WeaponType weaponType_;
		float precision_, fireRate_, projectileSpeed_;
		int cost_;
		bool automatic_;
		float timer_;
		Entities::Projectile projectile_;
		explicit Weapon(
				Element element = NEUTRAL_ELEMENT,
				WeaponType weaponType = HAND,
				float precision = 100,
				float fireRate = 1.f,
				float projectileSpeed_ = 1.f,
				Entities::Projectile projectile = Entities::Projectile(1),
				int cost = 0,
				bool automatic = false);
		Entities::SharedProjectile getSharedProjectile() const;
		bool canShoot();
		void update();
		void shoot(Entities::Player* player, World* world);
	};
}
