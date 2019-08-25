#include "Light.hpp"

/* Postavljanje zadatih parametara svetla */
void Light::draw() {
    glLightfv(light_id, GL_POSITION, light_position);
    glLightfv(light_id, GL_AMBIENT, light_ambient);
    glLightfv(light_id, GL_DIFFUSE, light_diffuse);
    glLightfv(light_id, GL_SPECULAR, light_specular);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);  
}

/* Set-eri za svetla */
void Light::set_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    light_ambient[0] = r;
    light_ambient[1] = g;
    light_ambient[2] = b;
    light_ambient[3] = a;
}

void Light::set_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    light_diffuse[0] = r;
    light_diffuse[1] = g;
    light_diffuse[2] = b;
    light_diffuse[3] = a;
}

void Light::set_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    light_specular[0] = r;
    light_specular[1] = g;
    light_specular[2] = b;
    light_specular[3] = a;
}

/* Postavljanje ID-a svetla u slucaju da zelimo vise razlicitih osvetljenja*/
void Light::set_id(GLenum id) { 
    light_id = id;
}

/* Ukljucivanje svetla */
void Light::enable() { 
    glEnable(light_id); 
}
/* Iskljucivanje svetla */
void Light::disable() { 
    glDisable(light_id); 
}