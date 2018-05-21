#include "SceneManager.h"

CScenemanager::CScenemanager()
{

}

CScenemanager::~CScenemanager() {}

void CScenemanager::Init()
{
	m_gameScene.Init();
}

void CScenemanager::Render()
{
	m_gameScene.Render();
}