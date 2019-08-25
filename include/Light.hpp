#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <GL/glut.h>

class Light{

public:
    Light(GLenum id) : light_id(id) {}
    void set_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void set_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void set_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void set_id(GLenum id);
    void draw();
    void enable();
    void disable();

private:
    /* Inicijalizacija svetla*/
    GLfloat light_ambient[4] = {0.8, 0.8, 0.8, 1};
    GLfloat light_diffuse[4] = {0.7, 0.7, 0.7, 1};
    GLfloat light_specular[4] = {0.9, 0.9, 0.9, 1};
    GLfloat light_position[4] = {36, 36, 30, 1};
    GLfloat model_ambient[4] = {0.4, 0.4, 0.4, 1};
    GLenum light_id;

};

#endif /* LIGHT_HPP */