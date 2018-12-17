#ifndef BOARD_HPP
#define BOARD_HPP

#include <GL/glut.h>
#include "Field.hpp"

namespace ch{

	class Board{
		public:
			Board();
			void init();
			void draw();
			Field board[64];
	};
}

#endif