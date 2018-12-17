#ifndef PIECE_HPP
#define PIECE_HPP

#include <GL/glut.h>
#include <string>

class Board;

namespace ch{
    class Piece{
        public:
            Piece(GLint const color, std::string const name, GLint rank, GLint column);
            GLint const color;
            std::string const name;
            GLint rank;
            GLint column;
            Board* board;
            void moveTo(Board* board, GLint rank, GLint column);      
    };
}

#endif