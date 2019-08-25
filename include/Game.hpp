#ifndef GAME_HPP
#define GAME_HPP

/* Utility*/
#include <iostream>
#include <vector>
#include <list>

/* Glut zaglavlja*/
#include <GL/glut.h>

/* Korisnicke klase */
#include "Camera.hpp"
#include "Light.hpp"
#include "Material.hpp"
#include "Board.hpp"
#include "Field.hpp"
#include "Piece.hpp"
#include "ObjectHandler.hpp"

/* Makroi */
#define COLOR_WHITE 0
#define COLOR_BLACK 1
#define FIELD_SIZE 8


class Game{

public:

    Game();
    void init();
    void update();
    void draw();
    void init_pieces();

    int player_turn;

    Camera camera;
    Light light{GL_LIGHT0};
    Board board;
    Piece pieces[32];
    Field fields[64];
};



#endif /* GAME_HPP */

