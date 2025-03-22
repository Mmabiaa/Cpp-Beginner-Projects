#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>
GLfloat T = 0;

void Spin()
{
    T = T + 0.1;
    if(T>360)
        T = 0;
    glutPostRedisplay();
}
void Draw()
{
    GLfloat Pos[] = {0,1,0,1};
    GLfloat Col[] = {1,0,0,1};

    GLfloat M[] = {0,1,0,1}; // teapot color

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glLightfv(GL_LIGHT0, GL_POSITION,Pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,Col);


    gluLookAt(0,1,3,0,0,0,0,1,0);

    glRotatef(T,0,1,0);

    glPushMatrix();
        glScalef(1,0.05,1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5,-0.5,-0.5);
        glScalef(0.05,1,0.05);
        glutSolidCube(1);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(0.5,-0.5,-0.5);
        glScalef(0.05,1,0.05);
        glutSolidCube(1);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(0.5,-0.5,0.5);
        glScalef(0.05,1,0.05);
        glutSolidCube(1);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(-0.5,-0.5,0.5);
        glScalef(0.05,1,0.05);
        glutSolidCube(1);
    glPopMatrix();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
       glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,M);
       glPushMatrix();
           glTranslatef(0,0.25,0);
           glutSolidTeapot(0.25);
       glPopMatrix();
    glPopAttrib();


    glutSwapBuffers();

}

void MyInit()
{
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


}

int main(int argC, char *argV [])
{
    glutInit(&argC, argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Teapot");

    MyInit();
    glutDisplayFunc(Draw);

    glutIdleFunc(Spin);
    glutMainLoop();

    return 0;
}
