#include "stdafx.h"

void myGlutIdle(void)
{
  if ( glutGetWindow() != main_window ) 
  glutSetWindow(main_window);  
  glutPostRedisplay();
}

void InitOpenGL()   // inicializa OpenGL
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45,w/h,0.1f,10000.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);  //fondo negro
	glMatrixMode(GL_MODELVIEW);
}

void Init(int argc, char* argv[]){  
	  glutInit(&argc, argv);  //Iniciando GLUT y OpenGL
	  glutInitWindowPosition(250,250);
	  glutInitWindowSize(w, h);
	  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE |GLUT_DEPTH);
	  main_window= glutCreateWindow("*****Sin Nombre******");
	  InitOpenGL();

	  glEnable(GL_TEXTURE_2D);							// Habilitando mapeo de texturas
	  glShadeModel(GL_SMOOTH);							// Shader
	  glClearDepth(1.0f);									// Estado inicial del depth buffer
	  glEnable(GL_DEPTH_TEST);							// Testeo del depth buffer
	  glDepthFunc(GL_LEQUAL);								// Tipo de testeo
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	  //Cargando modelo de nave
	  Load_3DS_Object("Assets/Models/Firebird/Firebird.3ds"); 

	// Turn on a lighting and enable it, we will just use the default values in this case
	// We also want color, so we turn that on
	  glEnable(GL_LIGHT0);								// Turn on a light with defaults set
	  glEnable(GL_LIGHTING);							// Turn on lighting
	  glEnable(GL_COLOR_MATERIAL);						// Allow color
}

int main(int argc, char* argv[])
{
	cout << "浜様様様様様様様様様様様様様様融" << endl;
	cout << "�                              �" << endl;
	cout << "�         Sin Nombre           �" << endl;
	cout << "�                              �" << endl;
	cout << "�        By: SupahTeam         �" << endl;
	cout << "�                              �" << endl;
	cout << "藩様様様様様様様様様様様様様様夕" << endl;
	Init(argc, argv); //inicializando ventana, opengl, glut |Inicializar.h
	Callbacks();	  //asignando callbacks de glut			|Callbacks.h
	glutMainLoop();
  
	return 0;
}