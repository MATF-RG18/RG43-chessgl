#include "Game.hpp"
#include "Board.hpp"
#include "Field.hpp"

Field::Field(){};

Field::Field(int rank, int column){
    this->rank = rank;
    this->column = column;
}

Field::Field(int ordinal, int rank, int column, int center_x, 
          int center_y, int center_z, int length, int width, int height) {

    this->ordinal = ordinal;
    this->rank = rank;
    this->column = column;
    this->center_x = center_x;
    this->center_y = center_y;
    this->center_z = center_z;
    this->length = length;
    this->width = width;
    this->height = height;

}

void Field::draw(){

    /* Postavljanje materijala u zavisnosti od boje figura */
    float mat_difuzni[3];
    if( color == COLOR_WHITE){
        mat_difuzni[0] = 0.9;
        mat_difuzni[1] = 0.9;
        mat_difuzni[2] = 0.9;
    }
    else{
        mat_difuzni[0] = 0.1;
        mat_difuzni[1] = 0.1;
        mat_difuzni[2] = 0.1;
    }

    material.set_ambient(0.4, 0.4, 0.4, 1);
    material.set_diffuse(mat_difuzni[0], mat_difuzni[1], mat_difuzni[2], 1);
    material.set_specular(0.3, 0.5, 0.5, 1);
    material.set_shininess(10);
    material.draw();

    /* Crtanje polja */
    glPushMatrix();
        glColor3f (color, color, color);
        glTranslatef(center_x, center_y, center_z);
        glScalef(1,1,0.2);
        glutSolidCube(FIELD_SIZE);
    glPopMatrix();

};