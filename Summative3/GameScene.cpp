#include <string.h>

#include "GameScene.h"

unsigned char g_keyState[255];

void Keyboard_Down(unsigned char key, int x, int y)
{
	g_keyState[key] = utils::INPUT_HOLD;
}

void Keyboard_Up(unsigned char key, int x, int y)
{
	g_keyState[key] = utils::INPUT_RELEASED;
}


unsigned char g_mouseState[3];
glm::vec2 g_mousePos;

void Mouse_Move(int x, int y)
{
	g_mousePos.x = (((float)x / utils::WINDOW_WIDTH) - 0.5f) * 2;
	g_mousePos.y = ((1 - (float)y / utils::WINDOW_HEIGHT) - 0.5f) * 2;
}

void Mouse_Click(int _button, int _glutState, int x, int y)
{
	if (_button < 3)
	{
		g_mouseState[_button] = (_glutState == GLUT_DOWN) ? utils::INPUT_HOLD : utils::INPUT_RELEASED;
	}

	g_mousePos.x = (((float)x / utils::WINDOW_WIDTH) - 0.5f) * 2;
	g_mousePos.y = ((1 - (float)y / utils::WINDOW_HEIGHT) - 0.5f) * 2;
}


CGameScene::CGameScene()
{
	m_camera = CCamera(glm::vec3(0, 5, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	m_sphere = CObject("Resources/Textures/Wall_Break4.bmp", glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f), SPHERE);
	m_pyramid = CObject("Resources/Textures/Wall_Break4.bmp", glm::vec3(2.0f, 0.0f, 0.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f), PYRAMID);
	m_cube = CObject("Resources/Textures/Wall_Break4.bmp", glm::vec3(2.0f, 2.0f, 0.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f), CUBE);
	//m_player = CPlayer("Resources/Textures/Player.bmp", 0.05f, 0.05f, 0.0f, glm::vec3(0.75f, 0.75f, 0.75f));
}

CGameScene::~CGameScene() {}

bool CGameScene::IsColliding(CObject _collider1, CObject _collider2)
{
	/*bool collisionX = _collider1.GetPos().fX + (_collider1.GetScale().x * 0.05f) >= _collider2.GetPos().fX - (_collider2.GetScale().x * 0.05f)
		&& _collider2.GetPos().fX + (_collider2.GetScale().x * 0.05f) >= _collider1.GetPos().fX - (_collider1.GetScale().x * 0.05f);

	bool collisionY = _collider1.GetPos().fY + (_collider1.GetScale().y * 0.05f) >= _collider2.GetPos().fY - (_collider2.GetScale().y * 0.05f)
		&& _collider2.GetPos().fY + (_collider2.GetScale().y * 0.05f) >= _collider1.GetPos().fY - (_collider1.GetScale().y * 0.05f);

	return(collisionX && collisionY);*/
	return (false);
}

void CGameScene::CollisionChecker()
{
	
}

void CGameScene::Init()
{
	m_camera.Init();

	m_programPlayer = m_shaderLoader.CreateProgram("Resources/Shaders/Object.vs", "Resources/Shaders/Player.fs");
	m_programAmbientLight = m_shaderLoader.CreateProgram("Resources/Shaders/Object.vs", "Resources/Shaders/AmbientLight.fs");
	//m_player.Init();
	m_pyramid.Init();
	m_sphere.Init();
	m_cube.Init();

	m_playerHealthText = new TextLabel("Health: 100", "Resources/Fonts/arial.ttf", glm::vec2(1.0f, 780.0f));
	m_playerHealthText = new TextLabel("Health: ", "Resources/Fonts/arial.ttf", glm::vec2(0.5f, 0.5f));
	m_playerHealthText->SetColor(glm::vec3(0.0f, 0.0f, 0.0f));
	m_playerHealthText->SetScale(0.5);
}

void CGameScene::Render()
{
	CollisionChecker();

	m_pyramid.Render(m_programAmbientLight, m_camera.GetViewMat(), m_camera.GetProjectionMat());
	m_sphere.Render(m_programAmbientLight, m_camera.GetViewMat(), m_camera.GetProjectionMat());
	m_cube.Render(m_programAmbientLight, m_camera.GetViewMat(), m_camera.GetProjectionMat());

	//m_player.Render(m_programPlayer, m_camera.GetViewMat(), m_camera.GetProjectionMat(), g_mousePos, g_mouseState);

	m_playerHealthText->Render();
	//m_playerHealthText->SetText("Health: " + std::to_string((int)m_player.GetCurrHealth()));
	m_camera.Update();

	if (g_keyState[(unsigned char)'w'] == utils::INPUT_HOLD)
	{
		m_camera.SetPosZ(m_camera.GetPosZ() - 1.0f);
	}
	if (g_keyState[(unsigned char)'s'] == utils::INPUT_HOLD)
	{
		m_camera.SetPosZ(m_camera.GetPosZ() + 1.0f);
	}
	if (g_keyState[(unsigned char)'a'] == utils::INPUT_HOLD)
	{
		m_camera.SetPosX(m_camera.GetPosX() - 1.0f);
	}
	if (g_keyState[(unsigned char)'d'] == utils::INPUT_HOLD)
	{
		m_camera.SetPosX(m_camera.GetPosX() + 1.0f);
	}
}