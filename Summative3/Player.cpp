#include "Player.h"

//unsigned char g_keyState[255];
//
//void Keyboard_Down(unsigned char key, int x, int y)
//{
//	g_keyState[key] = utils::INPUT_HOLD;
//}
//
//void Keyboard_Up(unsigned char key, int x, int y)
//{
//	g_keyState[key] = utils::INPUT_RELEASED;
//}

CPlayer::CPlayer() {}

CPlayer::CPlayer(std::string _sFilePath, glm::vec3 _pos, float _rotation, glm::vec3 _scale) : m_fMaxHealth(100), m_fCurrHealth(m_fMaxHealth)
{
	m_object = CObject(_sFilePath, _pos, _rotation, _scale, CUBE);

	char up[] = { 'w', 72 };
	char down[] = { 's', 80 };
	char left[] = { 'a', 75 };
	char right[] = { 'd', 77 };

	m_cUpKeys = up;
	m_cDownKeys = down;
	m_cLeftKeys = left;
	m_cRightKeys = right;
}

CPlayer::~CPlayer()
{

}

void CPlayer::SetControls(char _cLeftKeys[], char _cRightKeys[], char _cUpKeys[], char _cDownKeys[])
{
	m_cLeftKeys = _cLeftKeys;
	m_cRightKeys = _cRightKeys;
	m_cUpKeys = _cUpKeys;
	m_cDownKeys = _cDownKeys;
}

CObject CPlayer::GetSprite()
{
	return(m_object);
}

glm::vec3 CPlayer::GetPos()
{
	return(m_object.GetPos());
}

void CPlayer::SetPosX(float _fX)
{
	m_object.SetPosX(_fX);
}

void CPlayer::SetPosY(float _fY)
{
	m_object.SetPosY(_fY);
}

float CPlayer::GetCurrHealth()
{
	return(m_fCurrHealth);
}

void CPlayer::TakeDamage(float _fDamage)
{
	if (m_fCurrHealth > 0)
	{
		m_fCurrHealth -= _fDamage;
	}
}

void CPlayer::Init()
{
	m_object.Init();
}

void CPlayer::Render(GLuint& _program, glm::mat4 _viewMat, glm::mat4 _projMat, unsigned char _mouseState[3])
{
	m_object.Render(_program, _viewMat, _projMat);
}