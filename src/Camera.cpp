#include "Camera.hpp"
#include <GL/glut.h>
#include <math.h>
#include <iostream>

static const GLfloat pi = 3.1419254;

namespace ch{

	Camera::Camera(){

		xyz_eye[0] = 12;
		xyz_eye[1] = 7;
		xyz_eye[2] = 8;

		xyz_center[0] = 5;
		xyz_center[1] = 5;
		xyz_center[2] = 0;

		xyz_up[0] = 0;
		xyz_up[1] = 0;
		xyz_up[2] = 1;	

		angle = 0;
	}

	void Camera::init(){
		//Postavljanje kamere
			
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(xyz_eye[0],    xyz_eye[1],    xyz_eye[2],
				  xyz_center[0], xyz_center[1], xyz_center[2],
				  xyz_up[0],     xyz_up[1],     xyz_up[2]);
		
		glEnable(GL_DEPTH_TEST);	
	}

	void Camera::rotate_by_keyboard(GLint orientation){

		// Rotacija kamere za 10* u pravcu kazaljke na satu, ako je orientation<0 ili kontra ako je orientation>0
		
		if(orientation>0)
			angle += 10;
		else 
			angle -= 10;
	
        angle %= 360;

		/* Hardcodovan poluprecnik */ 
		GLfloat r = 10;
        xyz_eye[0] = r + r * cos((GLfloat)angle*pi/180);
        xyz_eye[1] = r + r * sin((GLfloat)angle*pi/180);

        glutPostRedisplay();
	}

	void Camera::rotate_by_mouse(){
		//Rotacija pomeranjem misa levo desno
	}
}