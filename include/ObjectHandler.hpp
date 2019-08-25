#ifndef OBJECTHANDLER_HPP
#define OBJECTHANDLER_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>
#include <string.h>

#include <GL/glut.h>


#define STEP 100

typedef struct Vertex
{
    double position[3];
    double texcoord[2];
    double normal[3];
} Vertex;

typedef struct VertRef
{
    int v, vt, vn;
} VertRef;


class ObjectHandler{

	public:

		ObjectHandler();
        void prepFile(char* niska);
		void loadModel();
        FILE* file;
        Vertex *model;
        int model_size = 0;
		void draw(int x, int y, int z);
		
		typedef struct Vector3f{
			float x;
			float y;
			float z;
		} Vector3f;

		typedef struct Vector2f{
			float x;
			float y;
		} Vector2f;


};      /* Class ObjectHandler */

#endif  /* OBJECTHANDLER_HPP */