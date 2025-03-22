#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>
void Draw()
{
     int x,y,i ;
     int LE[500],RE[500];
     GLint P1[] = {125, 250},P2[] = {250, 125},P3[] = {375, 250},P4[] = {250, 375};
    glClear(GL_COLOR_BUFFER_BIT);


    for(i=0;i<500;i++)
    {
        LE[i] = 0;
        RE[i] = 500;
    }


    glBegin(GL_POLYGON);
        glVertex2i(125, 250);
        glVertex2i(250, 125);
        glVertex2i(375, 250);
        glVertex2i(250, 375);
    glEnd();



    for(y=0;y<500;y++)
    {
        for(x=LE[y];x<RE[y];x++)
        {
            glBegin(GL_POINTS);
               glVertex2i(x,y);
            glEnd();


        }
    }
    glFlush();
}

void MyInit()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argC, char *argV [])
{

    glutInit(&argC, argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Scan Line Polygon Fill");
    MyInit();
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}
