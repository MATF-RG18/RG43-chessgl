#include "Field.hpp"
#include <GL/glut.h>
#include <iostream>

namespace ch{

    Field::Field(){
        ordinal = 0;
        rank = 0;
        column = 0;
        center_x = 1;
        center_y = 1;
        center_z = 0;
        length = 1;
        height = 1;
        width = 1;
        color = 0;
    }

    void Field::draw(){

        glPushMatrix();
        glColor3f (color, color, color);
        glTranslatef(center_x, center_y, center_z);
        glScalef(1,1,0.2);
        glutSolidCube(1);
        glPopMatrix();
    }
}