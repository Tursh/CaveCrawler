/*
 * TunnelGenerator.cpp
 *
 * Created by tursh on 8/31/20.
*/

#include <glm/geometric.hpp>
#include <Utils/Log.h>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "World/Terrain/TunnelGenerator.h"

namespace CC
{

    TunnelGenerator::TunnelGenerator(glm::ivec3 startingPosition, int seed)
            : tunnelHead_(startingPosition), tunnelDirection_(1, 0, 0), random_(seed), distribution_(0, 0.3f)
    {
    }

    glm::ivec3 TunnelGenerator::getNextTunnelHead()
    {
        start:
        glm::vec3 directionChange = glm::vec3(distribution_(random_),
                                              distribution_(random_) * .15f,
                                              distribution_(random_));

        //directionChange.y = 0.1f;


        glm::vec3 newDirection = glm::normalize(tunnelDirection_ + directionChange);

        //If the new direction change to much, when we normalize, it makes weird stuff
        if(std::abs(newDirection.y - tunnelDirection_.y) > 0.25f)
            goto start;

        //to reduce de slope of the tunnel
        if(std::abs(newDirection.y) > .25f && tunnelDirection_.y * directionChange.y > 0)
            directionChange.y *= -1;

        newDirection = glm::normalize(tunnelDirection_ + directionChange);


        logInfo("New direction: " << glm::to_string(newDirection) << ". Direction change: " << glm::to_string(directionChange) << ". Angle between: "
                                  << glm::angle(tunnelDirection_, newDirection) * (180 / M_PI));

        tunnelDirection_ = newDirection;
        tunnelHead_ += tunnelDirection_ * (glm::vec3) distanceBetweenTunnelHeads_;

        return tunnelHead_;
    }
}
