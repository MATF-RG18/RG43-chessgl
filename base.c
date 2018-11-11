#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

static int window_width, window_height;

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

static float camera_x = 20, camera_y = 5, camera_z = 10, r=15;

const static float pi = 3.141592653589793;
static int pomeraj = 0; //pomeraj

int main(int argc, char** argv){

    /*Inicijalizujemo GLUT*/
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    /*Kreiramo prozor*/
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);

    /*Registruju se callback funkcije.*/
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

     /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);    

    /* Program ulazi u glavnu petlju. */
    glutMainLoop();
    
    return 0;
}

static void on_reshape(int width, int height){

   /* Pamte se sirina i visina prozora. */
    window_width = width;
    window_height = height; 
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
            1, 50);

     /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            camera_x, camera_y ,camera_z,
            5, 5, 5,
            0, 0, 1
        );

    // glBegin(GL_LINES);
    //     glColor3f(1,0,0);
    //     glVertex3f(0,0,0);
    //     glVertex3f(10,0,0);
        
    //     glColor3f(0,1,0);
    //     glVertex3f(0,0,0);
    //     glVertex3f(0,10,0);
        
    //     glColor3f(0,0,1);
    //     glVertex3f(0,0,0);
    //     glVertex3f(0,0,10);
    // glEnd();
 
    /*
     * Kreira se kocka i primenjuje se geometrijska transformacija na
     * istu.
     */
    // glPushMatrix();

    // glColor3f(0, 0, 0);
    // glTranslatef(3, 3, 3);
    // glScalef(1, 1, 1);
    // glutWireCube(1);

    // glPopMatrix();

    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(10,0,0);
        
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,10,0);
        
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,10);
    glEnd();

    glPopMatrix();

    /*Crtamo 3d kvadrat*/

    int x_pocetna = 1, y_pocetno = 1;

    glColor3f(0, 0, 1);
    for(int i=x_pocetna; i<=8; i++){
        for(int j=y_pocetno; j<=8; j++){
            if((i+j)%2)
                glColor3f(1,0,0);
            else
                glColor3f(0,0,0);

            glBegin(GL_QUAD_STRIP);
                glVertex3f(i, j, 0);
                glVertex3f(i, j+1, 0);
                glVertex3f(i+1, j, 0);
                glVertex3f(i+1, j+1, 0);
            glEnd();

            glPushMatrix();

            glColor3f(0, 0, 1);
            glTranslatef(i+0.5, j+0.5, 0.5);
            glScalef(0.3, 0.3, 1);
            glutSolidCube(1);

            glPopMatrix();    

            }
        }

    /*Nova slika se salje na ekran*/
    glutSwapBuffers();
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Zavrsava se program. */
        //camera_x -= 5;
        //glutPostRedisplay();
        exit(0);
        break;
    case 'a':
        pomeraj -= 5;
        pomeraj %= 360;
        // printf("%d ", pomeraj);        
        camera_x = 5 + r * cos((float)pomeraj*pi/180);
        camera_y = 5 + r * sin((float)pomeraj*pi/180);
        //printf("%f --- %f", camera_x, camera_y);
        // printf("usao\n");
        glutPostRedisplay();
        break;
    case 'd':
        pomeraj += 5;
        pomeraj %= 360;
        // printf("%d ", pomeraj);        
        camera_x = 5 + r * cos((float)pomeraj*pi/180);
        camera_y = 5 + r * sin((float)pomeraj*pi/180);
        //printf("%f --- %f", camera_x, camera_y);
        // printf("usao\n");
        glutPostRedisplay();
        break;
    case 'w':
        camera_y += 5;
        //printf("usao\n");
        glutPostRedisplay();
        break;
    case 's':
        camera_y -= 5;
        //printf("usao\n");
        glutPostRedisplay();
        break;
    }
}