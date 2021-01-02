//
// Created by musique88 on 12/30/20.
//

#pragma once

#include <Loader/Meshes/TexturedMesh.h>
#include <Entities/Entity.h>
#include "Spell.h"

namespace CC::Entities
{
	class Projectile : public CGE::Entities::Entity
	{
		glm::vec3 velocity_;
		Element element_;
		float damage_;
		int duration_;
		bool explodes_;
		float size_;
	public:
		explicit Projectile(uint texMeshId,
				Element element = NEUTRAL_ELEMENT,
				bool explodes = false,
				uint duration = 60,
				float damage = 1.f,
				float size = 1.f,
				glm::vec3 position = glm::vec3(0),
				glm::vec3 rotation = glm::vec3(0),
				glm::vec3 velocity = glm::vec3(0));
		void update() override;
		//Projectile(const Projectile &projectile);
		void setPositions(glm::vec3 position = glm::vec3(0),
						  glm::vec3 rotation = glm::vec3(0),
						  glm::vec3 velocity = glm::vec3(1));
		bool shouldDie() override;
	};
}




