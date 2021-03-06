//VolumeTestScene- Represents a concrete scene to test with.
#ifndef VOLUME_TEST_SCENE_H
#define VOLUME_TEST_SCENE_H

#include "Scene.h"
#include "Debug.h"
#include "Collider.h"
#include "SuGameObject.h"
#include "BoxCollider.h"
#include "SphereCollider.h"

using namespace SushiEngine;

class VolumeTestScene: public SushiEngine::Scene
{
public:
	VolumeTestScene();
	~VolumeTestScene();
	void initialize(SceneContext* pSceneContext);
	void destroy();
};
#endif
