#include<GL/glu.h>
#include<GL/glut.h>
GLfloat T =0;

void Spin()
{
     T =T+0.05;
     if(T> 360)
        T=0;
     glutPostRedisplay();
}

void Face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])

{
    glBegin(GL_POLYGON);
     glVertex3fv(A);
     glVertex3fv(B);
     glVertex3fv(C);
     glVertex3fv(D);
    glEnd();

}

void Cube(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[],GLfloat V5[],GLfloat V6[],GLfloat V7[])
{
    glColor3f(1,0,0);
    Face(V0,V1,V2,V3);  //front

    glColor3f(1,0,1);
    Face(V4,V5,V6,V7);  //back

    glColor3f(0,1,0);
    Face(V0,V3,V7,V4);  //left

    glColor3f(0,0,1);
    Face(V0,V1,V5,V4);  //right

    glColor3f(1,1,0);
    Face(V0,V3,V7,V4);  //top

    glColor3f(0,1,1);
    Face(V3,V2,V6,V7);  //down
}

void Draw()
{
    GLfloat V[8][3] =   {

                                   {-0.5, 0.5,0.5},
                                   { 0.5, 0.5,0.5},
                                   { 0.5,-0.5,0.5},
                                   {-0.5,-0.5,0.5},

                                   {-0.5, 0.5,-0.5},
                                   { 0.5, 0.5,-0.5},
                                   { 0.5,-0.5,-0.5},
                                   {-0.5,-0.5,-0.5},
                               };

     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     glLoadIdentity();
     glRotatef(T,1,1,0);

     Cube(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);

     glutSwapBuffers();
}

int main(int argC, char *argV[])
{
    glutInit(&argC, argV);

    glutInitWindowPosition(400, 50);
    glutInitWindowSize(600,600);
    glutCreateWindow("Basic Opengl Program Cube Spin");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    glClearColor(0,0,0,1);
    glColor3f(0,1,0);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}
