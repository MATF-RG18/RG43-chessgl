#include "Piece.hpp"
#include <GL/glut.h>
#include <vector>
#include <string>

namespace ch{
    Piece::Piece(GLint const color, std::string const name, GLint rank, GLint column) : color(color), name(name), rank(rank), column(column){
 
    }
}