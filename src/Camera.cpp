#include <GL/glut.h>
#include <cmath>
#include "Camera.hpp"
#include <iostream>

#define FIELD_SIZE 8

static const GLfloat pi = 3.1419254;


/* Default konstruktor */
Camera::Camera(){
        xyz_eye[0] = 110;
		xyz_eye[1] = 4.5 * FIELD_SIZE;
		xyz_eye[2] = 60;

		xyz_center[0] = 4.5 * FIELD_SIZE;
		xyz_center[1] = 4.5 * FIELD_SIZE;
		xyz_center[2] = 0;

		xyz_up[0] = 0;
		xyz_up[1] = 0;
		xyz_up[2] = 1;	

		angle = 0;
}

/* Inicijalizacija */
void Camera::init(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(xyz_eye[0],    xyz_eye[1],    xyz_eye[2],
                xyz_center[0], xyz_center[1], xyz_center[2],
                xyz_up[0],     xyz_up[1],     xyz_up[2]);

}

void Camera::rotate_by_keyboard(GLint orientation){

    /*  Rotacija kamere za 10* u pravcu kazaljke na satu, ako je orientation<0 
        ili kontra ako je orientation > 0 
    */

    if(orientation>0)
        angle += 5;
    else 
        angle -= 5;

    angle %= 360;

    float x1, x2, y1, y2;
    x1 = xyz_center[0];
    y1 = xyz_center[1];
    x2 = xyz_eye[0];
    y2 = xyz_eye[1];

    GLfloat r = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    xyz_eye[0] = xyz_center[0] + r *cos((GLfloat)angle*pi/180);
    xyz_eye[1] = xyz_center[1] + r *sin((GLfloat)angle*pi/180);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(xyz_eye[0],    xyz_eye[1],    xyz_eye[2],
                xyz_center[0], xyz_center[1], xyz_center[2],
                xyz_up[0],     xyz_up[1],     xyz_up[2]);

    glutPostRedisplay();

}

void Camera:: move_up(){

    if(xyz_eye[2]<=95){
        xyz_eye[2] += 5;
        glutPostRedisplay();
    }
}


void Camera::move_down(){
    if(xyz_eye[2] >= 5){
        xyz_eye[2] -= 5;
        glutPostRedisplay();
    }
}

/* Prilagodjavanje ugla gledanja igracu koji je na potezu */
void Camera::toggle_player_view(){
    
    angle += 180;
    angle %= 360;

    float x1, x2, y1, y2;
    x1 = xyz_center[0];
    y1 = xyz_center[1];
    x2 = xyz_eye[0];
    y2 = xyz_eye[1];

    GLfloat r = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    xyz_eye[0] = xyz_center[0] + r *cos((GLfloat)angle*pi/180);
    xyz_eye[1] = xyz_center[1] + r *sin((GLfloat)angle*pi/180);

    glutPostRedisplay();
}