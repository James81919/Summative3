#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "GameScene.h"

class CScenemanager
{
public:
	CScenemanager();
	~CScenemanager();

	void Init();
	void Render();

private:
	CGameScene m_gameScene;
};

#endif // !__SCENEMANAGER_H__
