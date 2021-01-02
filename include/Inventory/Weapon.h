//
// Created by musique88 on 12/31/20.
//

#pragma once

#include <memory>
#include "Spell.h"
#include "Projectile.h"

namespace CC
{
	enum WeaponType
	{
		HAND, WAND, STAFF, RING, BRACELETS
	};

	class Weapon
	{
	public:
		Element elemental_;
		WeaponType weaponType_;
		float precision_, fireRate_, damage_, projectileSpeed_, projectileSize_;
		int duration_, cost_;
		bool automatic_;
		float timer_;
		explicit Weapon(
				Element element = NEUTRAL_ELEMENT,
				WeaponType weaponType = HAND,
				float precision = 100,
				float fireRate = 1.f,
				float damage = 1,
				float projectileSpeed = 1,
				float projectileSize = 1.f,
				int duration = 60,
				int cost = 0,
				bool automatic = false);
		std::shared_ptr<Entities::Projectile> getSharedProjectile() const;
		std::array<int, NUMBER_OF_ELEMENTS> requirements() const;
		bool canShoot();
		void update();
		void shoot();
	};
}
