//
// Created by musique88 on 12/30/20.
//

#include <Utils/Log.h>
#include <glm/gtx/string_cast.hpp>
#include "Inventory/Projectile.h"

namespace CC::Entities
{
	Projectile::Projectile(
			uint texMeshId, Element element, bool explodes, uint duration, float damage, float size,
			const glm::vec3& position, const glm::vec3& rotation,const glm::vec3& velocity)
			:CGE::Entities::Entity(texMeshId, position, rotation),
			velocity_(velocity), element_(element), explodes_(explodes),
			duration_(duration), damage_(damage), size_(size)//, as_(velocity)
	{
	}

	void Projectile::update()
	{
		op_ = ap_;
		or_ = ar_;
		os_ = as_;
		oa_ = aa_;

		//Acceleration
		//Get acceleration from the forces
		aa_ = glm::vec3(0);
		auto it = forces_.begin();
		while (it != forces_.end())
		{
			//Add force to player acceleration
			aa_ += std::get<1>(*it);
			//Check duration
			int &duration = std::get<0>(*it);
			--duration;
			if (duration == 0)
				forces_.erase(it);
			else
				++it;
		}

		//Speed
		//Add acceleration to speed
		as_ += aa_;

		//Position
		ap_ += as_;
		if (checkCollision_ != nullptr)
		{
			ap_ = checkCollision_(this);
		}

		duration_--;
	}

	void Projectile::setPositions(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& velocity)
	{
		ap_ = position;
		op_ = position;
		ar_ = rotation;
		or_ = rotation;
		velocity_ = velocity;
		setSpeed(velocity);
		logInfo(glm::to_string(velocity_));
	}

	bool Projectile::shouldDie()
	{
		return duration_ < 0;
	}

	Projectile::Projectile(const Projectile &projectile)
			:CGE::Entities::Entity(projectile.texMesh_, projectile.getPosition(), projectile.getRotation()),
			 velocity_(projectile.velocity_), element_(projectile.element_), explodes_(projectile.explodes_),
			 duration_(projectile.duration_), damage_(projectile.damage_), size_(projectile.size_)
	{
	}
}