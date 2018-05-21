#include "Mesh.h"

CMesh::CMesh() {}

CMesh::~CMesh() {}

void CMesh::SetCube(GLuint& _VAO, GLuint& _VBO, GLuint& _EBO)
{
	GLfloat vertices[] = {
		// Positions			// Colors			// Tex Coords
		-1.0f, 1.0f, 1.0f,		1.0f, 1.0f,	1.0f,	0.0f, 0.0f, // Front Face
		1.0f, 1.0f, 1.0f,		1.0f, 1.0f, 0.0f,	1.0f, 0.0f,
		1.0f, -1.0f, 1.0f,		0.0f, 1.0f, 1.0f,	1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,		1.0f, 0.0f, 1.0f,	0.0f, 1.0f,
		
		1.0f, 1.0f, 1.0f,		1.0f, 1.0f, 0.0f,	0.0f, 0.0f, // Right Face
		1.0f, 1.0f, -1.0f,		0.0f, 1.0f, 0.0f,	1.0f, 0.0f,
		1.0f, -1.0f, -1.0f,		0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,		0.0f, 1.0f, 1.0f,	0.0f, 1.0f,

		1.0f, 1.0f, -1.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f, // Back Face
		-1.0f, 1.0f, -1.0f,		1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
		-1.0f, -1.0f, -1.0f,	0.0f, 0.0f, 1.0f,	1.0f, 1.0f,
		1.0f, -1.0f, -1.0f,		0.0f, 0.0f, 0.0f,	0.0f, 1.0f,
		
		-1.0f, 1.0f, -1.0f,		1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Left Face
		-1.0f, 1.0f, 1.0f,		1.0f, 1.0f, 1.0f,	1.0f, 0.0f,
		-1.0f, -1.0f, 1.0f,		1.0f, 0.0f, 1.0f,	1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,	0.0f, 0.0f, 1.0f,	0.0f, 1.0f,

		-1.0f, 1.0f, -1.0f,		1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Top Face
		1.0f, 1.0f, -1.0f,		0.0f, 1.0f, 0.0f,	1.0f, 0.0f,
		1.0f, 1.0f, 1.0f,		1.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,		1.0f, 1.0f, 1.0f,	0.0f, 1.0f,
		
		-1.0f, -1.0f, 1.0f,		1.0f, 0.0f, 1.0f,	0.0f, 0.0f, // Bottom Face
		1.0f, -1.0f, 1.0f,		0.0f, 1.0f, 1.0f,	1.0f, 0.0f,
		1.0f, -1.0f, -1.0f,		0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,	0.0f, 0.0f, 1.0f,	0.0f, 1.0f,

	};

	GLuint indices[] = {
		0, 1, 2, // Front Face
		0, 2, 3,

		4, 5, 6, // Right Face
		4, 6, 7,

		8, 9, 10, // Back Face
		8, 10, 11,

		12, 13, 14, // Left Face
		12, 14, 15,

		16, 17, 18,// Top Face
		16, 18, 19,

		20, 21, 22, // Bottom Face
		20, 22, 23,
	};

	glGenBuffers(1, &_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	m_indiceCount = sizeof(indices) / sizeof(GLuint);
	m_drawType = GL_TRIANGLES;
}

void CMesh::SetSphere(GLuint& _VAO, GLuint& _VBO, GLuint& _EBO)
{
	float radius = 1.0f;

	const int sections = 20;
	const int vertexAttrib = 8;
	const int indexPerQuad = 6;

	double phi = 0;
	double theta = 0;

	float vertices[(sections) * (sections)* vertexAttrib];
	int offset = 0;
	for (int i = 0; i < sections; i++)
	{
		theta = 0;

		for (int j = 0; j < sections; j++)
		{
			float x = cos(phi) * sin(theta);
			float y = cos(theta);
			float z = sin(phi) * sin(theta);

			vertices[offset++] = x * radius;
			vertices[offset++] = y * radius;
			vertices[offset++] = z * radius;

			vertices[offset++] = x;
			vertices[offset++] = y;
			vertices[offset++] = z;

			vertices[offset++] = (float)i / (sections - 1);
			vertices[offset++] = (float)j / (sections - 1);

			theta += (M_PI / (sections - 1));
		}

		phi += (2 * M_PI) / (sections - 1);
	}


	GLuint indices[(sections) * (sections)* indexPerQuad];
	offset = 0;
	for (int i = 0; i < sections; i++)
	{
		for (int j = 0; j < sections; j++)
		{
			indices[offset++] = (((i + 1) % sections) * sections) + ((j + 1) % sections);
			indices[offset++] = (((i + 1) % sections) * sections) + (j);
			indices[offset++] = (i * sections) + (j);

			indices[offset++] = (i * sections) + ((j + 1) % sections);
			indices[offset++] = (((i + 1) % sections) * sections) + ((j + 1) % sections);
			indices[offset++] = (i * sections) + (j);
		}
	}

	glGenVertexArrays(1, &_VAO);
	glBindVertexArray(_VAO);

	glGenBuffers(1, &_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	m_indiceCount = sizeof(indices) / sizeof(GLuint);
	m_drawType = GL_TRIANGLES;
}

void CMesh::SetPyramid(GLuint& _VAO, GLuint& _VBO, GLuint& _EBO)
{
	GLfloat vertices[] = {
		// Positions			// Colors			// Tex Coords
		-1.0f, 0.0f, -1.0f,		1.0f, 1.0f, 0.0f,	0.0f, 1.0f, // 0  // Base
		1.0f, 0.0f, -1.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f, // 1
		1.0f, 0.0f, 1.0f,		0.0f, 1.0f, 0.0f,	1.0f, 0.0f, // 2
		-1.0f, 0.0f, 1.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f, // 3
		-1.0f, 0.0f, -1.0f,		1.0f, 1.0f, 0.0f,	0.0f, 1.0f, // 4  // Side 1
		-1.0f, 0.0f, 1.0f,		0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // 5
		-1.0f, 0.0f, 1.0f,		0.0f, 0.0f, 1.0f,	0.0f, 1.0f, // 6 
		1.0f, 0.0f, 1.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f, // 7
		1.0f, 0.0f, 1.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // 8  // Side 3
		1.0f, 0.0f, -1.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f, // 9
		1.0f, 0.0f, -1.0f,		1.0f, 0.0f, 0.0f,	0.0f, 1.0f, // 10 // Side 4
		-1.0f, 0.0f, -1.0f,		1.0f, 1.0f, 0.0f,	1.0f, 1.0f, // 11

		0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.5f, 0.0f, // 12 // Top Point
	};

	GLuint indices[] = {
		4, 12, 5, // Side 1
		6, 12, 7, // Side 2
		8, 12, 9, // Side 3
		10, 12, 11, // Side 4

		3, 2, 1, // Bottom Triangle 1
		3, 1, 0, // Bottom Triangle 2
	};

	glGenBuffers(1, &_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	m_indiceCount = sizeof(indices) / sizeof(GLuint);
	m_drawType = GL_TRIANGLES;
}

void CMesh::Render(GLuint _VAO)
{
	glBindVertexArray(_VAO);
	glDrawElements(m_drawType, m_indiceCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}