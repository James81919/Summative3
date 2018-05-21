#ifndef __MESH_H__
#define __MESH_H__

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

#include "Utils.h"

class CMesh
{
public:
	CMesh();
	~CMesh();

	void SetCube(GLuint& _VAO, GLuint& _VBO, GLuint& _EBO);
	void SetSphere(GLuint& _VAO, GLuint& _VBO, GLuint& _EBO);
	void SetPyramid(GLuint& _VAO, GLuint& _VBO, GLuint& _EBO);
	void Render(GLuint _VAO);

private:
	// Sphere
	GLuint m_indiceCount;
	int m_drawType;
};

#endif // !__MESH_H__
