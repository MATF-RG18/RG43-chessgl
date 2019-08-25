#ifndef FIELD_HPP
#define FIELD_HPP

#include "Board.hpp"
#include "Material.hpp"

#include <GL/glut.h>
#define COLOR_WHITE 1
#define COLOR_BLACK 0
#define FIELD_SIZE 8

class Field{

public:
    
    Field();
    Field(int rank, int column);
    Field(int ordinal, int rank, int column, int center_x, 
        int center_y, int center_z, int length, int width, int height);

    void draw();
    
    int ordinal;
    int rank;
    int column;
    int center_x;
    int center_y;
    int center_z;
    int length;
    int width;
    int height;
    int color;
    Material material;
};

#endif 