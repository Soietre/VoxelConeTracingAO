//
// Created by nils1990 on 06.12.15.
//

#ifndef SPARSEVOXELOCTREE_H
#define SPARSEVOXELOCTREE_H

#include "Controllable.h"
#include "BrickPool.h"
#include "NodePool.h"

class SparseVoxelOctree : public Controllable
{
public:
    SparseVoxelOctree(App* pApp): Controllable(pApp, "SparseVoxelOctree") {};
    ~SparseVoxelOctree();
    void init();
    void updateOctree();

private:
    virtual void fillGui() override; // Implementation of Controllable

    BrickPool m_brickPool;
    NodePool m_nodePool;
};


#endif //REALTIMERENDERING_SPARSEVOXELOCTREE_H