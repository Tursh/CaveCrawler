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
            : tunnelHead_(startingPosition), tunnelDirection_(1, 0, 0), random_(seed), distribution_(0, 0.25f)
    {
    }

    glm::ivec3 TunnelGenerator::getNextTunnelHead()
    {
        glm::vec3 directionChange = glm::vec3(distribution_(random_),
                                              distribution_(random_),
                                              distribution_(random_) * .15f);

        //to reduce de slope of the tunnel
        if(std::abs(tunnelDirection_.z) > .15f && tunnelDirection_.z * directionChange.z > 0)
            directionChange *= -1;

        glm::vec3 newDirection = glm::normalize(tunnelDirection_ + directionChange);

        //logInfo("New direction: " << glm::to_string(newDirection) << ". Direction change: " << glm::to_string(directionChange) << ". Angle between: "
        //                          << glm::angle(tunnelDirection_, newDirection) * (180 / M_PI));

        tunnelHead_ += newDirection * (glm::vec3) distanceBetweenTunnelHeads_;
        tunnelDirection_ = newDirection;

        return tunnelHead_;
    }
}
