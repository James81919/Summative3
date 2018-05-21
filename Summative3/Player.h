#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Object.h"

//void Keyboard_Down(unsigned char key, int x, int y);
//void Keyboard_Up(unsigned char key, int x, int y);

class CPlayer
{
public:
	CPlayer();
	CPlayer(std::string _sFilePath, glm::vec3 _pos, float _rotation, glm::vec3 _scale);
	~CPlayer();

	void SetControls(char _leftKeys[], char _rightKeys[], char _upKeys[], char _downKeys[]);

	CObject GetSprite();

	glm::vec3 GetPos();
	void SetPosX(float _fX);
	void SetPosY(float _fY);

	float GetCurrHealth();

	void TakeDamage(float _fDamage);

	void Init();
	void Render(GLuint& _program, glm::mat4 _viewMat, glm::mat4 _projMat, unsigned char _mouseState[3]);

private:
	char* m_cLeftKeys;
	char* m_cRightKeys;
	char* m_cUpKeys;
	char* m_cDownKeys;

	float m_fMaxHealth;
	float m_fCurrHealth;

	ShaderLoader m_shaderLoader;
	CObject m_object;
};

#endif // !__PLAYER_H__