#include "Mesh.h"

#include "Object.h"

CObject::CObject()
{
	m_pos = glm::vec3(0.0f, 0.0f, 0.0f);

	m_sFilePath = "";
	m_mesh = CMesh();
}

CObject::CObject(std::string _sFilePath, glm::vec3 _pos, float _rotation, glm::vec3 _scale, EShape _meshShape)
{
	m_sFilePath = _sFilePath;
	m_pos = _pos;
	m_rotation = _rotation;
	m_scale = _scale;
	m_shape = _meshShape;
}

CObject::~CObject()
{

}

std::string CObject::GetFilePath()
{
	return(m_sFilePath);
}

void CObject::SetFilePath(std::string _sFilePath)
{
	m_sFilePath = _sFilePath;
}

glm::vec3 CObject::GetPos()
{
	return(m_pos);
}

void CObject::SetPos(glm::vec3 _newPos)
{
	m_pos = _newPos;
}

void CObject::SetPosX(float _fX)
{
	m_pos.x = _fX;
}

void CObject::SetPosY(float _fY)
{
	m_pos.y = _fY;
}

void CObject::SetPosZ(float _fZ)
{
	m_pos.z = _fZ;
}

float CObject::GetRotation()
{
	return(m_rotation);
}

void CObject::SetRotation(float _rotation)
{
	m_rotation = _rotation;
}

glm::vec3 CObject::GetScale()
{
	return(m_scale);
}

void CObject::SetScale(glm::vec3 _scale)
{
	m_scale = _scale;
}

void CObject::Init()
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	switch (m_shape)
	{
	case SPHERE: m_mesh.SetSphere(m_vao, m_vbo, m_ebo); break;
	case PYRAMID: m_mesh.SetPyramid(m_vao, m_vbo, m_ebo); break;
	case CUBE: m_mesh.SetCube(m_vao, m_vbo, m_ebo);  break;
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		8 * sizeof(GLfloat),
		(GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		8 * sizeof(GLfloat),
		(GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(
		2,
		2,
		GL_FLOAT,
		GL_FALSE,
		8 * sizeof(GLfloat),
		(GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glGenTextures(1, &m_tex);
	glBindTexture(GL_TEXTURE_2D, m_tex);

	int width, height;
	unsigned char* image = SOIL_load_image(
		m_sFilePath.c_str(),
		&width,
		&height,
		0,
		SOIL_LOAD_RGB);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGB,
		width,
		height,
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		image);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void CObject::Render(GLuint& _program, glm::mat4 _viewMat, glm::mat4 _projMat)
{
	glUseProgram(_program);

	//GLfloat currentTime = (float)glutGet(GLUT_ELAPSED_TIME);
	//currentTime = currentTime / 1000.0f;
	//GLint currentTimeLoc = glGetUniformLocation(_program, "currentTime");
	//glUniform1f(currentTimeLoc, currentTime);

	glm::mat4 translate = glm::translate(glm::mat4(), m_pos);
	glm::mat4 rotation = glm::rotate(glm::mat4(), glm::radians(m_rotation), glm::vec3(0, 0, 1));
	glm::mat4 scale = glm::scale(glm::mat4(), m_scale);

	glm::mat4 Model = translate * rotation * scale;

	glm::mat4 MVP = _projMat * _viewMat * Model;

	GLuint transformLoc = glGetUniformLocation(_program, "MVP");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(MVP));

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_tex);
	glUniform1i(glGetUniformLocation(_program, "tex"), 0);

	glBindVertexArray(m_vao);

	m_mesh.Render(m_vao);
}