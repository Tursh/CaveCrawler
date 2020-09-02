/*
 * ChunkManager.h
 *
 * Created by tursh on 9/27/19.
*/

#pragma once

#include <map>
#include "World/Player.h"
#include "Chunk.h"
#include "WorldGenerator.h"
#include "TunnelGenerator.h"

namespace CC
{

    class ChunkManager : public CGE::Utils::ThreadProcess
    {

        CC::Entities::Player *player_;

        std::map<int, std::map<int, std::map<int, Chunk *>>> &chunks_;

        int chunkCount_;

        glm::ivec3 centerChunkPosition_ = glm::ivec3(INT_MAX);

        std::vector<glm::ivec3> chunkToLoad_;

        World *world_;

        TunnelGenerator tunnelGenerator_;

        int tunnelLength_ = 100;

        int tunnelRadius_ = 4;

        glm::ivec3 *tunnelBody_;

        WorldGenerator worldGenerator_;

        void run() override;

    public:
        ChunkManager(CC::Entities::Player *player,
                     World *world,
                     std::map<int, std::map<int, std::map<int, Chunk *>>> &chunks);

        ~ChunkManager();

        /**
         * Check if chunks are loaded
         */
        void tick();

        /**
         * Search for a chunk that needs to be loaded and returns it
         * @return A chunk position to load a chunk
         */
        glm::ivec3 getChunkToLoad();

        void addChunkToLoad(glm::ivec3 chunkToLoad);

        glm::ivec3 *getTunnelBody() const;

        int getTunnelLength() const;

        const int &getTunnelRadius() const;

    };

}