/*
 * ChunkManager.cpp
 *
 * Created by tursh on 9/27/19.
*/

#include <Utils/TimeUtils.h>
#include <Utils/Log.h>
#include "World/Terrain/ChunkManager.h"
#include "World/World.h"
#include <glm/gtx/string_cast.hpp>
#include <Loader/RessourceManager.h>
#include <IO/Window.h>

namespace CC
{

    std::shared_ptr<CGE::Loader::Texture> tex;

    ChunkManager::ChunkManager(Entities::Player *player,
                               World *world,
                               std::map<int, std::map<int, std::map<int, Chunk *>>> &chunks)
            : player_(player), chunks_(chunks), worldGenerator_(world, *this, tunnelBody_), world_(world),
              tunnelGenerator_({0, 0, 0}, 4), tunnelBody_(new glm::ivec3[tunnelLength_])
    {
        tex = CGE::Loader::resManager::getTexture(1);
        CGE::Utils::TPSClock::init(2);
        CGE::Utils::TPSClock::setTPS(2, 2);

        for (int i = 0; i < tunnelLength_; ++i)
        {
            tunnelBody_[i] = (tunnelGenerator_.getNextTunnelHead());
            glm::ivec3 chunkPosition = World::getChunkPosition(tunnelBody_[i]);

            //Add the chunk if isn't already going to be loaded
            addChunkToLoad(chunkPosition);

            glm::ivec3 positionInChunk = World::getPositionInChunk(tunnelBody_[i]);
            //Check if the tunnel will touch other chunks
            for (int axis = 0; axis < 3; ++axis)
                if (positionInChunk[axis] < tunnelRadius_ && CHUNK_SIZE - tunnelRadius_ < positionInChunk[axis])
                {
                    glm::ivec3 neighbourChunk = chunkPosition;
                    neighbourChunk[axis] += positionInChunk[axis] < tunnelRadius_ ? -1 : 1;
                    //addChunkToLoad(neighbourChunk);
                }
        }


        worldGenerator_.start();
    }

    ChunkManager::~ChunkManager()
    {
        worldGenerator_.stop();
    }

    void ChunkManager::tick()
    {
        if (CGE::Utils::TPSClock::shouldTick(2))
        {
            //If there are chunk to load notify the world generator
            if (!chunkToLoad_.empty())
                worldGenerator_.notify();
        }
    }

    glm::ivec3 ChunkManager::getChunkToLoad()
    {
        if (chunkToLoad_.empty())
            return glm::ivec3(INT_MIN);
        glm::ivec3 chunkPosition = chunkToLoad_.back();
        chunkToLoad_.pop_back();
        return chunkPosition;
    }

    void ChunkManager::addChunkToLoad(glm::ivec3 chunkToLoad)
    {
        //Add the chunk if isn't already going to be loaded
        if (std::find(chunkToLoad_.begin(), chunkToLoad_.end(), chunkToLoad) == chunkToLoad_.end())
            chunkToLoad_.push_back(chunkToLoad);
    }

    void ChunkManager::run()
    {
        while (running_)
        {
            tick();
        }
    }

    glm::ivec3 *ChunkManager::getTunnelBody() const
    {
        return tunnelBody_;
    }

    int ChunkManager::getTunnelLength() const
    {
        return tunnelLength_;
    }

    const int &ChunkManager::getTunnelRadius() const
    {
        return tunnelRadius_;
    }

}