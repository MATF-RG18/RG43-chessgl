#ifndef PIECE_HPP
#define PIECE_HPP

#include "Material.hpp"
#include "ObjectHandler.hpp"

#define COLOR_WHITE 1
#define COLOR_BLACK 0
#define FIELD_SIZE 8


class Piece{

public:

    Piece();
    Piece(int rank, int column, int color);
    void init(int rank, int column, int color);
    void draw();


    int rank;
    int column;
    int color;
    int x, y, z;
    Material material;
    
    ObjectHandler objHandler;
    
};

#endif /* PIECE_HPP */