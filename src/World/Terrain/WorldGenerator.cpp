/*
 * WorldGenerator.cpp
 *
 * Created by tursh on 9/28/19.
*/

#include <Utils/Log.h>
#include <World/Terrain/Block.h>
#include <World/Terrain/Chunk.h>
#include "World/Terrain/WorldGenerator.h"
#include <World/World.h>

namespace CC
{

    WorldGenerator::WorldGenerator(World *world, ChunkManager &chunkManager, glm::ivec3 *tunnelBody)
            : world_(world), chunkManager_(chunkManager), tunnelBody_(tunnelBody) {}

    static void fillChunk(Block *blocks, Block block)
    {
        for (int i = 0; i < CUBED_CHUNK_SIZE; ++i)
            blocks[i] = block;
    }

    const unsigned int MID_X = 0b01000000, MID_Y = 0b00100000, MID_Z = 0b00010000, INV = 0b10000000;

    void WorldGenerator::run()
    {
        while (running_)
        {
            glm::ivec3 chunkPosition = chunkManager_.getChunkToLoad();
            //If the chunk manager returns this position, it means, there no chunk to load
            if (chunkPosition == glm::ivec3(INT_MIN))
            {
                wait();
                continue;
            }

            //Create the block 3D matrix and fill it with air
            auto *blocks = new Block[CUBED_CHUNK_SIZE];
            fillChunk(blocks, Blocks::STONE_BLOCK);

            for (int i = 0; i < chunkManager_.getTunnelLength(); ++i)
            {
                //Check if the tunnel point is close to the chunk to load
                if (World::getChunkPosition(tunnelBody_[i]) == chunkPosition)
                {
                    glm::ivec3 blockPosition = World::getPositionInChunk(tunnelBody_[i]);
                    for (int x = -chunkManager_.getTunnelRadius(); x < chunkManager_.getTunnelRadius(); ++x)
                        for (int y = -chunkManager_.getTunnelRadius(); y < chunkManager_.getTunnelRadius(); ++y)
                            for (int z = -chunkManager_.getTunnelRadius(); z < chunkManager_.getTunnelRadius(); ++z)
                            {

                                glm::ivec3 aroundBlockPosition = blockPosition + glm::ivec3(x, y, z);
                                bool valid = true;
                                for (int axis = 0; axis < 3; ++axis)
                                    if (aroundBlockPosition[axis] < 0 || aroundBlockPosition[axis] >= CHUNK_SIZE)
                                        valid = false;

                                if (valid)
                                    blocks[aroundBlockPosition.x + aroundBlockPosition.y * CHUNK_SIZE +
                                           aroundBlockPosition.z * SQUARED_CHUNK_SIZE] = Blocks::AIR_BLOCK;
                            }
                }
            }


            auto *newChunk = new Chunk(blocks, world_, chunkPosition, false);
            world_->addChunk(newChunk);
            newChunk->updateChunksAround();

        }

    }

}