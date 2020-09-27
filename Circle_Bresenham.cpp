#include <GL/glut.h>
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-320,320,-240,240,-1,1);	
}

void draw8point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc + y, yc + x);
		glVertex2i(xc + y, yc - x);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc - y, yc - x);
		glVertex2i(xc - y, yc + x);
		glVertex2i(xc - x, yc + y);
	glEnd();
}
void CircleBres(int xc,int yc,int R )	
{	 
   	int p ;
	int y = R ; 
	int x = 0;
	p = 3 - 2*R;
	draw8point(xc,yc,x,y);
	while (x < y) 
    	{
		if (p <0)	
            p +=4*x+6;
		else
            {	
              p += 4*(x-y)+10;
		      y--;
		    }
		x++;
        draw8point(xc,yc,x,y);
		}
}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	CircleBres(0, 0, 200); //Tâm C(0,0) bán kính 200
	glViewport(0,0,640,480);
	glFlush();

}

int main(int argc, char** argv){
	int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 0);
	glutCreateWindow("DEMO THUAT TOAN VE PARABOL");
	
    initGL();
	glutDisplayFunc(mydisplay);    
	glutMainLoop();
}

