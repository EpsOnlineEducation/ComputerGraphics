#include <GL/glut.h>
void initGL()
{
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-1,1,-1,1,-1,1);	
}
void mydisplay()
{
  	glClear(GL_COLOR_BUFFER_BIT);
  	// Hinh vuong goc 1/4 thu nhat cua cua so ung dung
	glColor3f(1.0f, 0.0f, 0.0f); //red
	glViewport(320,240,300,300);	
	glBegin(GL_POLYGON);
    		glVertex2f(-0.5f, -0.5f);   
    		glVertex2f( 0.5f, -0.5f);
    		glVertex2f( 0.5f,  0.5f);
    		glVertex2f(-0.5f,  0.5f);
 	glEnd();
	// Hinh vuong goc 1/4 thu hai cua cua so ung dung
	glColor3f(0.0f, 1.0f, 0.0f); //Green
	glViewport(320,0,300,300);	
	glBegin(GL_POLYGON);
    		glVertex2f(-0.5f, -0.5f);   
    		glVertex2f( 0.5f, -0.5f);
    		glVertex2f( 0.5f,  0.5f);
    		glVertex2f(-0.5f,  0.5f);
 	glEnd();
	// Hinh vuong goc 1/4 thu ba 
	glColor3f(0.0f, 0.0f, 1.0f); //Blue
	glViewport(0,0,300,300);	
	glBegin(GL_POLYGON);
    		glVertex2f(-0.5f, -0.5f);   
    		glVertex2f( 0.5f, -0.5f);
    		glVertex2f( 0.5f,  0.5f);
    		glVertex2f(-0.5f,  0.5f);
 	glEnd();
	// hinh vuong goc 1/4 thu tu 
	glColor3f(1.0f, 1.0f, 1.0f); //White
	glViewport(0,240,300,300);
	glBegin(GL_POLYGON);
    		glVertex2f(-0.5f, -0.5f);   
    		glVertex2f( 0.5f, -0.5f);
    		glVertex2f( 0.5f,  0.5f);
    		glVertex2f(-0.5f,  0.5f);
 	glEnd();	
  	glFlush();
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
    glutCreateWindow("My OpenGL program");  
	glutDisplayFunc(mydisplay);
	initGL();
	glutMainLoop();
}

