#include "Piece.hpp"

Piece::Piece(){};

Piece::Piece(int rank, int column, int color){
    this->rank = rank;
    this->column = column;
    this->color = color;
}

/* Iscrtavanje figure */
void Piece::draw(){
        GLfloat colors[3];
        if (color == COLOR_WHITE){
            colors[0] = 0.7;
            colors[1] = 0.7;
            colors[2] = 0.8;
        }

        if(color == COLOR_BLACK){
            colors[0] = 0.2;
            colors[1] = 0.2;
            colors[2] = 0.2;
        }

        /* Postavljanje svetla */
        material.set_ambient(0.2, 0.2, 0.2, .1);
        material.set_diffuse(0.9, 0.9, 0.9, .1);
        material.set_specular(0.3, 0.4, 0.4, .1);
        material.set_shininess(0);
        material.draw();

    glPushMatrix();

        glTranslatef(rank*FIELD_SIZE + FIELD_SIZE, column*FIELD_SIZE + FIELD_SIZE, 5);

        glColor3fv(colors);
        glTranslatef(0, 0, 1.6);
        glScalef(1,1,1);
        glutSolidSphere(2, 20, 20);

        glTranslatef(0, 0, -2);
        glScalef(1,1,3);
        glutSolidCube(2);

    glPopMatrix();

}