#include <GL/glut.h>//Calling directory
#include<math.h>

void drawCircle(float radius, int numSegments){
    glBegin(GL_POLYGON);
    for (int i = 0; i<numSegments; i++){
        float angle = 2 * 3.14159 * i/ numSegments;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void Draw()//A function to help draw and open the gui
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircle(0.5, 50);

    glPointSize(5);

    /*glBegin(GL_POLYGON);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(-0.5,-0.5);
        glVertex2f(-0.5,0.5);
    glEnd(); */

    /*glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        glVertex2f(0,0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(-0.5,-0.5);
    glEnd();*/

    glFlush();

}

int main (int argC, char *argV[]){

    glutInit(&argC, argV);

    glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,150);
    glutCreateWindow("Opengl 2D");

    glClearColor(0,0,0,1);
    glColor3f(1,0,0);

    glutDisplayFunc(Draw);

    glutMainLoop();
       return 0;
}
