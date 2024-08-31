#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>


void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
glBegin(GL_TRIANGLE_FAN);
for(int ii = 0; ii < num_segments; ii++)
{
float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

float x = rx * cosf(theta);
float y = ry * sinf(theta);

glVertex2f(x + cx, y + cy);

}
glEnd();
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glOrtho(-7,7,-7,7,-1,1);

}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.8f,0.1f);
    glBegin(GL_QUADS);
    glVertex3d(2.0,1.0,0.0);
    glVertex3d(2.0,-1.0,0.0);
    glVertex3d(-2.0,-1.0,0.0);
    glVertex3f(-2.0,1.0,0.0);
    glEnd();


    glColor3f(1.0f, 0.0f, 0.0f);

    DrawCircle(0,0,0.5,0.5,100);



    glColor3f(0.5f,0.5f,0.5f);
glBegin(GL_QUADS);
glVertex3d(-2.0,1.0,0.0);
glVertex3d(-2.0,-4.0,0.0);
glVertex3d(-2.4,-4,0.0);
glVertex3f(-2.4,1.0,0.0);
glEnd();

glColor3f(0.2f,0.0f,0.0f);
glBegin(GL_QUADS);
glVertex3d(-1.0,-4.0,0.0);
glVertex3d(-1.0,-4.6,0.0);
glVertex3d(-3.3,-4.6,0.0);
glVertex3f(-3.3,-4.0,0.0);
glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 100);
glutInit(&argc, argv);
glutCreateWindow ("Circle");
init();
    glutDisplayFunc(display);
glutMainLoop();
return 0;
}
