#include <GL/glut.h>
#include <cstdlib>
#include "Game.hpp"

static int window_height, window_width;

/* Deklaracije callback funkcija */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

Game game;
int fullscreen = 0;

int main(int argc, char** argv){

 /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    /* Kreira se prozor. */
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("ChessGL");

    /* Registruju se callback funkcije. */
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutKeyboardFunc(on_keyboard);

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    // glEnable(GL_BLEND);
    glEnable(GL_LIGHT0);

    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.45, 0.45, 0.45, 0);

    /* Inicijalizacija komponenti */
    game.init();

    /* Program ulazi u glavnu petlju. */
    glutMainLoop();

}

static void on_keyboard(unsigned char key, int x, int y)
{   
    switch (key) {
    case 27:
        /* Zavrsava se program. */
        exit(0);
        break;
    case 'a':
        /* Horizontalna rotacija kamere u smeru kazaljke na satu */
        game.camera.rotate_by_keyboard(1);
        break;
    case 'd':
        /* Horizontalna rotacija kamere u smeru suprotnom od kazaljke na satu */
        game.camera.rotate_by_keyboard(-1);
        break;
    case 'c':
        /* Promena ugla gledanja u zavisnosti od igraca na potezu */
        game.camera.toggle_player_view();
        break;

    case 'w':
        /* Vertikalna translacija kamere nagore */
        game.camera.move_up();
        break;
    case 's':
        /* Vertikalna translacija kamere nadole */
        game.camera.move_down();
        break;
        /* Menjanje izmedju fullscreen i window moda */
    case 'f':
        fullscreen += 1;
        fullscreen %= 2;
        if(fullscreen == 1)
            glutFullScreen();
        else
            glutReshapeWindow(500, 500);
        break;
    }
}


static void on_reshape(int width, int height){

    /* Pamte se sirina i visina prozora. */
    window_height = height;
    window_width = width;

    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            0, 80);
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
            0, 80);

    /* Iscrtavanje svih objekata i pocetak igre */
    game.draw();
}