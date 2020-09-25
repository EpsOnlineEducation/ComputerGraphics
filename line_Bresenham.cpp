#include <GL/glut.h>
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-320,320,-240,240,-1,1);	
}
void LineBres(int x1,int y1,int x2,int y2)	
{
	
   	int Dx = x2-x1; 
	int Dy = y2-y1;
   	int p = 2*Dy-Dx;
  	int x = x1;	
	int y = y1;
  	glBegin(GL_POINTS);
	glVertex2i(x,y);
	while (x < x2)  
	{
		if (p <0)	 
            p+= 2*Dy;
		else
            {
            	p+=2*(Dy-Dx);
			    y++;
			}
		x++;
        glVertex2i(x,y);
	}
	glEnd();
  	
}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	LineBres(10, 10, 200, 200);
	glViewport(0,0,640,480);
	glFlush();

}

int main(int argc, char** argv){
	int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE DOAN THANG - BRESENHAM");
	 
	initGL();  
	glutDisplayFunc(mydisplay);    
	glutMainLoop();
}

