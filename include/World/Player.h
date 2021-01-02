//
// Created by tursh on 1/17/19.
//

#pragma once

#include <Entities/Entity.h>
#include <View/Camera.h>
#include <Skill/Progression.h>
#include <Inventory/Inventory.h>
#include <Inventory/Projectile.h>
#include <random>

namespace CC
{
    //To dodge some stupid errors
    class World;
}

namespace CC::Entities
{
    extern const float PLAYER_HEIGHT, PLAYER_WIDTH;

    class Player : public CGE::Entities::Entity
    {
		bool hasShot;
        CGE::View::Camera &camera_;
        Progression progression;

		void init();
		void Shoot(World *world, CC::Weapon &selectedWeapon);

    public:
        explicit Player(unsigned int texMeshID, CGE::View::Camera &camera);

        explicit Player(CGE::Loader::TexturedMesh *texMesh, CGE::View::Camera &camera,
                        glm::vec3 position = glm::vec3(0),
                        glm::vec3 rotation = glm::vec3(0));

        void move(float speed, World *terrain);

        const glm::vec3 getCameraVectorPointing() const;

        /**
         * Activate all player actions (ex: hit block, open inventory, etc...
         */
        void checkAction(World *world);

        void hit(World *world);

        const glm::vec3 &getSize() override;

        void update() override;

		Inventory inventory;
	};

}

