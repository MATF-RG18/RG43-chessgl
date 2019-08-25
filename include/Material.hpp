#ifndef MATERIAL_HPP
#define MATERIAL_HPP

/* glut zaglavlja*/
#include <GL/glut.h>

class Material {

    public:
        
        /* Get-eri i set-eri */
        void set_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
        void set_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
        void set_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
        void set_shininess(GLfloat shininess);
        void set_side(GLenum side);
        void draw();

        GLfloat *get_ambient() { return material_ambient; }
        GLfloat *get_diffuse() { return material_diffuse; }
        GLfloat *get_specular() { return material_specular; }
        GLfloat get_shininess() { return material_shininess; }

        GLfloat material_ambient[4] = {0};
        GLfloat material_diffuse[4] = {0};
        GLfloat material_specular[4] = {0};
        GLfloat material_shininess{0};
        GLfloat material_emission[4] = { 0.3, 0.2, 0.2, 0 };
        GLenum side{GL_FRONT};
};

#endif // MATERIAL_HPP