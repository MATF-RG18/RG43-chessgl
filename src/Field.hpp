#ifndef FIELD_HPP
#define FIELD_HPP

#include <GL/glut.h>

namespace ch{
    class Field{
        public:

            Field();
            void draw();

            GLint ordinal;
            GLint rank;
            GLint column;
            GLint center_x;
            GLint center_y;
            GLint center_z;
            GLint length;
            GLint width;
            GLint height;
            GLint color;
    };
}

#endif