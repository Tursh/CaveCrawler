//
// Created by musique88 on 12/31/20.
//

#pragma once

#include <memory>
#include <World/Player.h>
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
		float precision_, fireRate_, damage_, projectileSpeed_;
		int duration_, cost_;
		bool automatic_;
		Weapon(
				Element element = NEUTRAL_ELEMENT,
				WeaponType weaponType = HAND,
				float precision = 0,
				float fireRate = 0.5,
				float damage = 1,
				float projectileSpeed = 1,
				int duration = 60,
				int cost = 0,
				bool automatic = false);
		std::shared_ptr<Entities::Projectile> getSharedProjectile();
		std::array<int, NUMBER_OF_ELEMENTS> requirements() const;
	};
}
