#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glut.h>

namespace ch{

	class Camera{
		public:
			Camera();
			void init();
			void rotate_by_keyboard(GLint orientation);
			void rotate_by_mouse();

		private:
			GLfloat xyz_eye[3];
			GLfloat xyz_center[3];
			GLfloat xyz_up[3]; 	
			GLint angle;
	};

}
#endif //CAMERA_HPP