#include "Board.hpp"
#include <GL/glut.h>
#include <iostream>

namespace ch{

    Board::Board(){
        
    }

    void Board::init(){
        int br=0;
        int color = 1; // crna boja
        for(int i=0; i<8; i++){
            color += 1;
            color %= 2;
            for(int j=0; j<8; j++){
                board[br].ordinal = br;
                board[br].rank = i;
                board[br].column = j;
                board[br].center_x = i+1;
                board[br].center_y = j+1;
                board[br].center_z = 0;
                board[br].length = 1;
                board[br].height = 1;
                board[br].width = 1;
                board[br].color = color;
                color += 1;
                color %= 2;
                br++;
            }
        }
    }

    void Board::draw(){

        //Draw coordinates
        glBegin(GL_LINES);
            glColor3f(1,0,0);
            glVertex3f(0,0,0);
            glVertex3f(10,0,0);
            
            glColor3f(0,1,0);
            glVertex3f(0,0,0);
            glVertex3f(0,10,0);
            
            glColor3f(0,0,1);
            glVertex3f(0,0,0);
            glVertex3f(0,0,10);
        glEnd();

        //Draw round
        glPushMatrix();
        glColor3f (1, 0, 0);
        glScalef(1,1,0.05);
        glTranslatef(4.5, 4.5, 0);
        glutSolidCube(9);
        glPopMatrix();

        //Draw table

        int len = sizeof(board) / sizeof(Field);
        for(int br = 0; br<len; br++)
            board[br].draw();

    }
  
}
