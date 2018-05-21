#include "Camera.h"

CCamera::CCamera()
	: m_pos(glm::vec3(0, 0, 0)), m_target(glm::vec3(0, 0, 0)), m_up(glm::vec3(0, 1, 0))
{

}

CCamera::CCamera(glm::vec3 _pos, glm::vec3 _target, glm::vec3 _up)
	: m_pos(_pos), m_target(_target), m_up(_up)
{

}

CCamera::~CCamera()
{

}

glm::vec3 CCamera::GetPos()
{
	return(m_pos);
}

void CCamera::SetPos(glm::vec3 _pos)
{
	m_pos = _pos;
}

float CCamera::GetPosX()
{
	return(m_pos.x);
}

void CCamera::SetPosX(float _fX)
{
	m_pos.x = _fX;
}

float CCamera::GetPosY()
{
	return(m_pos.y);
}

void CCamera::SetPosY(float _fY)
{
	m_pos.y = _fY;
}

float CCamera::GetPosZ()
{
	return(m_pos.z);
}

void CCamera::SetPosZ(float _fZ)
{
	m_pos.z = _fZ;
}

glm::vec3 CCamera::GetTarget()
{
	return(m_target);
}

void CCamera::SetTarget(glm::vec3 _target)
{
	m_target = _target;
}

glm::vec3 CCamera::GetUp()
{
	return(m_up);
}

void CCamera::SetUp(glm::vec3 _up)
{
	m_up = _up;
}

glm::mat4 CCamera::GetViewMat()
{
	return(m_view);
}

glm::mat4 CCamera::GetProjectionMat()
{
	return(m_projection);
}

void CCamera::ChangeX(float _fAmount)
{
	m_pos.x += _fAmount;
}

void CCamera::Init()
{
	m_view = glm::lookAt(
		m_pos,	// Camera Position
		glm::vec3(0.0f, 0.0f, 0.0f),	// Target Position
		glm::vec3(0.0f, 1.0f, 0.0f));	// Up Vector

	m_projection = glm::perspective(45.0f, (GLfloat)utils::WINDOW_WIDTH / (GLfloat)utils::WINDOW_HEIGHT, 0.1f, 2000.0f);
}

void CCamera::Update()
{
	float currentTime = glutGet(GLUT_ELAPSED_TIME);
	currentTime = currentTime * 0.001f;

	GLfloat camY = 3.0f;
	GLfloat radius = 4.0f;
	GLfloat camX = sin(currentTime) * radius;
	GLfloat camZ = sin(currentTime) * radius;

	m_view = glm::lookAt(
		m_pos,	// Camera Position
		glm::vec3(0.0f, 0.0f, 0.0f),	// Target Position
		glm::vec3(0.0f, 1.0f, 0.0f));	// Up Vector

	m_projection = glm::perspective(45.0f, (GLfloat)utils::WINDOW_WIDTH / (GLfloat)utils::WINDOW_HEIGHT, 0.1f, 2000.0f);
}