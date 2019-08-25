#ifndef BOARD_HPP
#define BOARD_HPP

/* Korisnicke klase*/
#include "Field.hpp"
#include "Material.hpp"
#include "Field.hpp"

/* Utility */
#include <iostream>

/*GLUT*/
#include <GL/glut.h>

#define FIELD_SIZE 8
#define COLOR_WHITE 1
#define COLOR_BLACK 0

class Board{

public:
    Board();
    void init(Field fields[]);
    void draw(Field fields[]);
    int center_x;
    int center_y;

private:
    Material border_material;

};

#endif /* BOARD_HPP */