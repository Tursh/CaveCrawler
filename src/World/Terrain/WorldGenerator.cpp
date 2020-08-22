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

    const unsigned int MAX_WORLD_GENERATION_HEIGHT = 256;
    const unsigned int CLOUD_CHUNK_HEIGHT = 8;

    WorldGenerator::WorldGenerator(World *world, ChunkManager &chunkManager)
            : world_(world), chunkManager_(chunkManager) {}

    static void fillChunk(Block *blocks, Block block)
    {
        for (int i = 0; i < CUBED_CHUNK_SIZE; ++i)
            blocks[i] = block;
    }

    const unsigned int MID_X = 1 << 6, MID_Y = 1 << 5, MID_Z = 1 << 4, INV = 1 << 7;

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
            fillChunk(blocks, Blocks::AIR_BLOCK);

            auto *newChunk = new Chunk(blocks, world_, chunkPosition, false);
            world_->addChunk(newChunk);
            newChunk->updateChunksAround();

        }

    }

}