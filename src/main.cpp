#include <GL/glut.h>
#include "Camera.hpp"
#include "Board.hpp"
#include <stdlib.h>
#include <iostream>

ch::Camera camera;
ch::Board chessBoard;

static int window_width, window_height;

/* Deklaracije callback funkcija. */
static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);

int main(int argc, char **argv){
    
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    /* Kreira se prozor. */
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    /* Registruju se callback funkcije. */
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutKeyboardFunc(on_keyboard);

    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.75, 0.75, 0.75, 0);

    /* Program ulazi u glavnu petlju. */
    glutMainLoop();
    
    return 0;
}

static void on_display(void){

    /* Brise se prethodni sadrzaj prozora. */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Podesava se viewport. */
    glViewport(0, 0, window_width, window_height);

    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            0, 50);

    camera.init();
    chessBoard.init();
    chessBoard.draw();

    glutSwapBuffers();
}

static void on_reshape(int width, int height){
    /* Pamte se sirina i visina prozora. */
    window_height = height;
    window_width = width;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Zavrsava se program. */
        exit(0);
        break;
    case 'a':
        camera.rotate_by_keyboard(1);
        break;
    case 'd':
        camera.rotate_by_keyboard(-1);
        break;
    }
}