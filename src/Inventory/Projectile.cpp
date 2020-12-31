//
// Created by musique88 on 12/30/20.
//

#include "Inventory/Projectile.h"

namespace CC::Entities
{
	Projectile::Projectile(
			uint texMeshId, Element element, bool explodes, uint duration,
			glm::vec3 position, glm::vec3 rotation,glm::vec3 velocity)
		:CGE::Entities::Entity(texMeshId, position, rotation),
		velocity_(velocity), element_(element), explodes_(explodes), duration_(duration)
	{
		setSpeed(velocity);
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

	Projectile::Projectile(const Projectile &projectile)
	:Entity(projectile.getTexMesh(), projectile.getPosition(), projectile.getRotation(), projectile.isVisible()),
	velocity_(projectile.velocity_), element_(projectile.element_), explodes_(projectile.explodes_)
	{
		setSpeed(projectile.velocity_);
	}

	void Projectile::setPositions(glm::vec3 position, glm::vec3 rotation, glm::vec3 velocity)
	{
		ap_ = position;
		op_ = position;
		ar_ = rotation;
		or_ = rotation;
		velocity_ = velocity;
		setSpeed(velocity);
	}

	bool Projectile::shouldDie()
	{
		return duration_ < 0;
	}
}