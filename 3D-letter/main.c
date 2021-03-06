#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
// ----------------------------------------------------------
// Struct def
// ----------------------------------------------------------
typedef struct midPoints
{
    float x ;
    float y ;
    float z ;
}midPoints;
midPoints mid;
// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
int rotate=0;
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}
void display(){

    //  Clear screen and Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Rotate when user changes rotate_x and rotate_y
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );

    //The vertical rod
    //Multi-colored side - FRONT
    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( mid.x+0.15, mid.y-0.9, mid.z-0.15 );
    glVertex3f( mid.x+0.15, mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x-0.15, mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x-0.15, mid.y-0.9, mid.z-0.15 );
    glEnd();

    // White side - BACK
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f( mid.x+0.15, mid.y-0.9, mid.z+0.15 );
    glVertex3f( mid.x+0.15, mid.y+0.9, mid.z+0.15 );
    glVertex3f( mid.x-0.15, mid.y+0.9, mid.z+0.15 );
    glVertex3f( mid.x-0.15, mid.y-0.9, mid.z+0.15 );
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( mid.x+0.15, mid.y-0.9, mid.z-0.15 );
    glVertex3f( mid.x+0.15, mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x+0.15, mid.y+0.9, mid.z+0.15 );
    glVertex3f( mid.x+0.15, mid.y-0.9, mid.z+0.15 );
    glEnd();

    // Green side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( mid.x-0.15, mid.y-0.9, mid.z+0.15 );
    glVertex3f( mid.x-0.15, mid.y+0.9, mid.z+0.15 );
    glVertex3f( mid.x-0.15, mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x-0.15, mid.y-0.9, mid.z-0.15 );
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f( mid.x+0.15,  mid.y+0.9, mid.z+0.15 );
    glVertex3f( mid.x+0.15,  mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x-0.15,  mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x-0.15,  mid.y+0.9, mid.z+0.15 );
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(   0.4,  0.3,  0.0 );
    glVertex3f( mid.x+0.15, mid.y-0.9, mid.z-0.15 );
    glVertex3f( mid.x+0.15, mid.y-0.9, mid.z+0.15 );
    glVertex3f( mid.x-0.15, mid.y-0.9, mid.z+0.15 );
    glVertex3f( mid.x-0.15, mid.y-0.9, mid.z-0.15 );
    glEnd();
    
    //The 45 rod
    //side - FRONT
    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( mid.x+0.20, mid.y    , mid.z-0.15 );
    glVertex3f( mid.x+1.15, mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x+0.85, mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x-0.10, mid.y    , mid.z-0.15 );
    glEnd();

    // White side - BACK
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f( mid.x+0.20, mid.y    , mid.z+0.15 );
    glVertex3f( mid.x+1.15, mid.y+0.9, mid.z+0.15 );
    glVertex3f( mid.x+0.85, mid.y+0.9, mid.z+0.15 );
    glVertex3f( mid.x-0.10, mid.y    , mid.z+0.15 );
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( mid.x+0.20, mid.y    , mid.z-0.15 );
    glVertex3f( mid.x+1.15, mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x+1.15, mid.y+0.9, mid.z+0.15 );
    glVertex3f( mid.x+0.20, mid.y    , mid.z+0.15 );
    glEnd();

    // Green side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( mid.x-0.10, mid.y    , mid.z+0.15 );
    glVertex3f( mid.x+0.85, mid.y+0.9, mid.z+0.15 );
    glVertex3f( mid.x+0.85, mid.y+0.9, mid.z-0.15 );
    glVertex3f( mid.x-0.10, mid.y    , mid.z-0.15 );
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  mid.x+1.15,  mid.y+0.9, mid.z+0.15 );
    glVertex3f(  mid.x+1.15,  mid.y+0.9, mid.z-0.15 );
    glVertex3f(  mid.x+0.85,  mid.y+0.9, mid.z-0.15 );
    glVertex3f(  mid.x+0.85,  mid.y+0.9, mid.z+0.15 );
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(   0.4,  0.3,  0.0 );
    glVertex3f(  mid.x+0.20, mid.y, mid.z-0.15 );
    glVertex3f(  mid.x+0.20, mid.y, mid.z+0.15 );
    glVertex3f(  mid.x-0.1 , mid.y, mid.z+0.15 );
    glVertex3f(  mid.x-0.1 , mid.y, mid.z-0.15 );
    glEnd();
    
    //The 45 rod
    //side - FRONT
    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( mid.x+0.20, mid.y    , mid.z-0.15 );
    glVertex3f( mid.x+1.15, mid.y-0.9, mid.z-0.15 );
    glVertex3f( mid.x+0.85, mid.y-0.9, mid.z-0.15 );
    glVertex3f( mid.x-0.10, mid.y    , mid.z-0.15 );
    glEnd();

    // White side - BACK
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f( mid.x+0.20, mid.y    , mid.z+0.15 );
    glVertex3f( mid.x+1.15, mid.y-0.9, mid.z+0.15 );
    glVertex3f( mid.x+0.85, mid.y-0.9, mid.z+0.15 );
    glVertex3f( mid.x-0.10, mid.y    , mid.z+0.15 );
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( mid.x+0.20, mid.y    , mid.z-0.15 );
    glVertex3f( mid.x+1.15, mid.y-0.9, mid.z-0.15 );
    glVertex3f( mid.x+1.15, mid.y-0.9, mid.z+0.15 );
    glVertex3f( mid.x+0.20, mid.y    , mid.z+0.15 );
    glEnd();

    // Green side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( mid.x-0.10, mid.y    , mid.z+0.15 );
    glVertex3f( mid.x+0.85, mid.y-0.9, mid.z+0.15 );
    glVertex3f( mid.x+0.85, mid.y-0.9, mid.z-0.15 );
    glVertex3f( mid.x-0.10, mid.y    , mid.z-0.15 );
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  mid.x+1.15,  mid.y-0.9, mid.z+0.15 );
    glVertex3f(  mid.x+1.15,  mid.y-0.9, mid.z-0.15 );
    glVertex3f(  mid.x+0.85,  mid.y-0.9, mid.z-0.15 );
    glVertex3f(  mid.x+0.85,  mid.y-0.9, mid.z+0.15 );
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(   0.4,  0.3,  0.0 );
    glVertex3f(  mid.x+0.20, mid.y, mid.z-0.15 );
    glVertex3f(  mid.x+0.20, mid.y, mid.z+0.15 );
    glVertex3f(  mid.x-0.1 , mid.y, mid.z+0.15 );
    glVertex3f(  mid.x-0.1 , mid.y, mid.z-0.15 );
    glEnd();
    
    
    glFlush();
    glutSwapBuffers();

}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
 
    //  Right arrow - increase y-axis rotation by 5 degree
    if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

    //  Left arrow - decrease y-axis rotation by 5 degree
    else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
//  up arrow - increase x-axis rotation by 5 degree
    else if (key == GLUT_KEY_UP)
    rotate_x += 5;
//  Left arrow - decrease x-axis rotation by 5 degree
    else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
//  s key - start the z-axis rotation
    else if (key == 's')
    {
        rotate=1;
    }
//  p key - stop the z-axis rotation
    else if (key == 'p')
    {
        rotate=0;
    }

    //  Request display update
    glutPostRedisplay();

}
void idlefun(){
    if (rotate == 1)
    {
        rotate_z+=5;
        display();
    }
}
// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){
    //  Initialize mid points
    mid.x = 0;
    mid.y = 0;
    mid.z = 0;

    //  Initialize GLUT and process user parameters
    glutInit(&argc,argv);

    //  Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50);
    // Create window
    glutCreateWindow("3D K");

    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);

    // Callback functions
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutIdleFunc(idlefun);
    initGL();
    //  Pass control to GLUT for events
    glutMainLoop();

    //  Return to OS
    return 0;
 
}
