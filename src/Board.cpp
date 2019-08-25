#include "Board.hpp"

Board::Board() {}

void Board::init(Field fields[]){

    int br=0;

    /* Postavljanje centra table */
    center_x = 4.5*FIELD_SIZE;
    center_y = 4.5*FIELD_SIZE;
    int color = COLOR_WHITE;


    /* Inicijalizacija polozaja polja */
    for(int i=0; i<8; i++){

        for (int j=0; j<8; j++){
            color %= 2;
            fields[br].ordinal = br;
            fields[br].rank = i;
            fields[br].column = j;
            fields[br].center_x = i*FIELD_SIZE + FIELD_SIZE*1;
            fields[br].center_y = j*FIELD_SIZE + FIELD_SIZE*1;
            fields[br].center_z = 0;
            fields[br].length = FIELD_SIZE;
            fields[br].height = FIELD_SIZE;
            fields[br].width = FIELD_SIZE;
            fields[br].color = color;
            color += 1;
            br++;
            
        }
        color += 1; /*  da se promeni pocetna boja u novom redu */
    } 
}

void Board::draw(Field fields[]){

    /* Crtanje koordinatnih osa zbog lakse izrade projekta */

    /*
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(100,0,0);
        
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,100,0);
        
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,100);
    glEnd();
    */

    /* Crtanje podloge */
    glPushMatrix();

        /* Postavljanje materijala podloge*/
        border_material.set_ambient(0.1, 0.1, 0.1, 1);
        border_material.set_diffuse(0.1, 0.9, 0.2, 1);
        border_material.set_specular(0.1, 0.1, 0.1, 1);
        border_material.set_shininess(30);
        border_material.draw();
        glDisable(GL_LIGHTING);
        glTranslatef(FIELD_SIZE*4.5,FIELD_SIZE*4.5, -0.36);
        glColor3f (1, 0, 0);
        glScalef(1,1,0.02);
        glutSolidCube(FIELD_SIZE*9);

    glPopMatrix();

    /* Crtanje polja */
    for(int br = 0; br<64; br++){
        fields[br].draw();
    }
}