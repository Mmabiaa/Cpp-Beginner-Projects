#include<GL/glu.h>
#include<GL/glut.h>

void Draw()
{
     glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5);
    glBegin(GL_POINTS);
     glVertex2f(-0.5,0.5);
     glVertex2f(0.5,0.5);
     glVertex2f(0.5,-0.5);
     glVertex2f(-0.5,-0.5);
    glEnd();

     glFlush();
}

int main(int argC, char *argV[])
{
    glutInit(&argC,argV);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Basic OpenGl Program");
    glutInitDisplayMode(GL_RGB | GLUT_SINGLE);


    glClearColor(0,0,0,1);
    glColor3f(1,0,0);
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
