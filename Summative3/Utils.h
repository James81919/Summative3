#ifndef __UTILS_H__
#define __UTILS_H__

#include <glew.h>
#include <freeglut.h>
#include <SOIL.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include <glm.hpp>
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"

namespace utils
{
	struct TEXCOORD
	{

	};

	struct VERTEXFORMAT
	{

	};

	struct INDEXFORMAT
	{

	};

	// Stores the possible key states
	enum InputState
	{
		INPUT_FIRST_RELEASE,
		INPUT_RELEASED,
		INPUT_FIRST_PRESS,
		INPUT_HOLD
	};

	// Stores the posible mouse buttons
	enum InputMouse
	{
		MOUSE_LEFT = 0,
		MOUSE_MIDDLE = 1,
		MOUSE_RIGHT = 2,
	};

	// The width of the window
	const int WINDOW_WIDTH = 800;
	// The height of the window
	const int WINDOW_HEIGHT = 800;

	// The max number of bullets that can be on the screen
	const int MAX_BULLET_COUNT = 1;
	// The max number of mines than can be on the screen
	const int MAX_MINE_COUNT = 1;

	// Static Functions for Quad

	// Rounds float values to a set precision
	static float GetFloatPrecision(float _fValue, float _fPrecision)
	{
		return(floor((_fValue * powf(10.0f, _fPrecision) + 0.5f)) / powf(10.0f, _fPrecision));
	}
}

#endif // !__UTILS_H__
