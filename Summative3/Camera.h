#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Utils.h"

class CCamera
{
public:
	CCamera();
	CCamera(glm::vec3 _pos, glm::vec3 _target, glm::vec3 _up);
	~CCamera();

	glm::vec3 GetPos();
	void SetPos(glm::vec3 _pos);

	float GetPosX();
	void SetPosX(float _f);
	float GetPosY();
	void SetPosY(float _f);
	float GetPosZ();
	void SetPosZ(float _f);

	void ChangeX(float _fAmount);

	glm::vec3 GetTarget();
	void SetTarget(glm::vec3 _target);

	glm::vec3 GetUp();
	void SetUp(glm::vec3 _up);

	glm::mat4 GetViewMat();
	glm::mat4 GetProjectionMat();

	void Init();
	void Update();

private:
	glm::mat4 m_model;
	glm::mat4 m_view;
	glm::mat4 m_projection;

	glm::vec3 m_pos;
	glm::vec3 m_target;
	glm::vec3 m_up;

	GLuint m_program;
};

#endif // !__CAMERA_H__
