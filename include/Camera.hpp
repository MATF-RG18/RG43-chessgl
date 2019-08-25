#ifndef CAMERA_HPP
#define CAMERA_HPP

/* glut zaglavlja */
#include <GL/glut.h>

class Camera{

public:
    Camera();
    void init();
    void rotate_by_keyboard(GLint orientation);
    void toggle_player_view();
    void move_up();
    void move_down();

private:
    GLfloat xyz_eye[3];
    GLfloat xyz_center[3];
    GLfloat xyz_up[3]; 	
    GLint angle;

};

#endif /* CAMERA_HPP */