#include "SceneManager.h"

#include <iostream>

CScenemanager g_sceneManager;

void Init()
{
	g_sceneManager = CScenemanager();
	g_sceneManager.Init();
}

void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLES, 0, 5);

	g_sceneManager.Render();

	glutSwapBuffers();
}

void runMainLoop(int val) {
	render();
	glutTimerFunc(1000 / 60, runMainLoop, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(utils::WINDOW_WIDTH, utils::WINDOW_HEIGHT);
	glutCreateWindow("Summative 2");

	glewInit();
	Init();

	glutKeyboardFunc(Keyboard_Down);
	glutKeyboardUpFunc(Keyboard_Up);
	glutMouseFunc(Mouse_Click);
	glutPassiveMotionFunc(Mouse_Move);

	glutDisplayFunc(render);

	glutTimerFunc(1000 / 60, runMainLoop, 0);

	glutMainLoop();


	return(0);
}

