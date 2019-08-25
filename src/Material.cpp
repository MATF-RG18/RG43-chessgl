#include "Material.hpp"

void Material::set_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    material_ambient[0] = r;
    material_ambient[1] = g;
    material_ambient[2] = b;
    material_ambient[3] = a;
}

void Material::set_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    material_diffuse[0] = r;
    material_diffuse[1] = g;
    material_diffuse[2] = b;
    material_diffuse[3] = a;
}

void Material::set_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    material_specular[0] = r;
    material_specular[1] = g;
    material_specular[2] = b;
    material_specular[3] = a;
}

void Material::set_side(GLenum side_param) { 
    side = side_param; 
}

void Material::set_shininess(GLfloat shininess) {
    material_shininess = shininess;
}

void Material::draw() {
    glMaterialfv(side, GL_AMBIENT, material_ambient);
    glMaterialfv(side, GL_DIFFUSE, material_diffuse);
    glMaterialfv(side, GL_SPECULAR, material_specular);
    glMaterialf(side, GL_SHININESS, material_shininess);
}