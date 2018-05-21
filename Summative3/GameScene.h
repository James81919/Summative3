#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "TextLabel.h"
#include "Player.h"
#include "Camera.h"
#include "ShaderLoader.h"
#include "Mesh.h"

void Mouse_Move(int x, int y);
void Mouse_Click(int _button, int _glutState, int _x, int _y);

void Keyboard_Down(unsigned char key, int x, int y);
void Keyboard_Up(unsigned char key, int x, int y);

class CGameScene
{
public:
	CGameScene();
	~CGameScene();

	bool IsColliding(CObject _collider1, CObject _collider2);
	void CollisionChecker();

	void Init();
	void Render();

private:
	CCamera m_camera;
	TextLabel* m_playerHealthText;

	CObject m_pyramid;
	CObject m_sphere;
	CObject m_cube;

	CPlayer m_player;

	GLuint m_programPlayer;
	GLuint m_programAmbientLight;

	ShaderLoader m_shaderLoader;
};

#endif // !__GAMESCENE_H__