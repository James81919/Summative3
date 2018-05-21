#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "ShaderLoader.h"
#include "Mesh.h"

enum EShape
{
	PYRAMID = 0,
	CUBE = 1,
	SPHERE = 2
};

class CObject
{
public:
	CObject();
	CObject(std::string _sFilePath, glm::vec3 _pos, float _rotation, glm::vec3 _scale, EShape _meshShape);
	~CObject();

	std::string GetFilePath();
	void SetFilePath(std::string _sFilePath);

	glm::vec3 GetPos();
	void SetPos(glm::vec3 _newPosition);
	void SetPosX(float _fX);
	void SetPosY(float _fY);
	void SetPosZ(float _fZ);

	float GetRotation();
	void SetRotation(float _rotation);

	glm::vec3 GetScale();
	void SetScale(glm::vec3 _fScale);

	void Init();
	void Render(GLuint& _program, glm::mat4 _viewMat, glm::mat4 _projMat);

private:
	CMesh m_mesh;
	EShape m_shape;
	std::string m_sFilePath;
	glm::vec3 m_pos;
	float m_rotation;
	glm::vec3 m_scale;

	GLuint m_vbo, m_vao, m_ebo, m_tex;
};

#endif // !__OBJECT_H__
