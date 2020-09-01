/*
 * TunnelGenerator.h
 *
 * Created by tursh on 8/31/20.
*/

#pragma once


#include <glm/ext/vector_int3.hpp>
#include <glm/vec3.hpp>
#include <random>

namespace CC
{

    class TunnelGenerator
    {
        glm::ivec3 tunnelHead_;

        glm::vec3 tunnelDirection_; //This is a normalized vector

        /**
         * This it needed so that no tunnel will be created in a preexisting chunk
         */
        glm::ivec3 chunksUsed_;

        int distanceBetweenTunnelHeads_ = 5;

        std::default_random_engine random_;
        std::normal_distribution<float> distribution_;
    public:
        explicit TunnelGenerator(glm::ivec3 startingPosition, int seed = 0);

        glm::ivec3 getNextTunnelHead();


    };

}