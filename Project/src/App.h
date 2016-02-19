#ifndef APP_H_
#define APP_H_

#include "Controllable.h"

#include "externals/gl3w/include/GL/gl3w.h"
#include "externals/GLFW/include/GLFW/glfw3.h"
#include "externals/GLM/glm/glm.hpp"

#include <vector>
#include <memory>
#include <src/Rendering/SSR.h>

#include "SparseOctree/SparseVoxelOctree.h"
#include "SparseOctree/BrickPool.h"
#include "SparseOctree/NodePool.h"

#include "Scene/Scene.h"
#include "Voxelization/Voxelization.h"
#include "Raycaster/OctreeRaycast.h"
#include "Rendering/VoxelConeTracing.h"
#include "Rendering/LightViewMap.h"
#include "Rendering/FullScreenQuad.h"
#include "PointCloud/PointCloud.h"
#include "VoxelVisualitation/Voxelcubes.h"
#include "Utilities/enums.h"

enum Visualization { RAYCASTING, VOXEL_CUBES, POINT_CLOUD, GBUFFER, PHONG, AMBIENT_OCCLUSION, VOXEL_CONE_TRACING, SHADOW_MAP,VOXEL_GLOW };

class App: public Controllable
{
public:
     // Some constants
    float VOLUME_EXTENT = 384.f;
    float DYNAMIC_OBJECT_SPEED = 10.0f;

    App();
    virtual ~App(); // Virtual not necessary
    void run();
    void registerControllable(Controllable* pControllable);
    void handleCamera(GLfloat deltaTime);

    void fillGui();

private:

    GLFWwindow* mpWindow;
    GLfloat mPrevTime;

    std::vector<Controllable*> mControllables; // Could be weak pointers
    std::unique_ptr<SparseVoxelOctree> m_svo;
    std::unique_ptr<Scene> m_scene;
    std::unique_ptr<Voxelization> m_voxelization;
    std::unique_ptr<FragmentList> mFragmentList;
    std::unique_ptr<OctreeRaycast> mupOctreeRaycast;
    std::unique_ptr<VoxelConeTracing> m_VoxelConeTracing;
    std::unique_ptr<LightViewMap> m_LightViewMap;
    std::unique_ptr<FullScreenQuad> m_FullScreenQuad;
    std::unique_ptr<PointCloud> m_PointCloud;
    std::unique_ptr<VoxelCubes> m_VoxelCubes;
    std::unique_ptr<SSR> mSSR;

    bool mVoxeliseEachFrame;
    bool mShowGBuffer;
};

#endif // APP_H_
