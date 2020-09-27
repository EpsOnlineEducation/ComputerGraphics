#include <GL/glut.h>
void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //R=0,G=0,B=0, anpha=1
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
void CircleMidpoint(int xc,int yc,int R )	
{	 
   	float P;
	int y = R; 
	int x = 0;
	P = 5/4 - R;
	draw8point(xc,yc,x,y);
	while (x < y) 
    	{
		if (P <0)	// Chon diem P
            {
			P += 2*x + 3;
            
            }
        else      // Chon diem S
            {	
            P += 2*(x - y) + 5;
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
	CircleMidpoint(0, 0, 200); //Tâm C(0,0) bán kính 200
	glViewport(0,0,640,480);
	glFlush();

}

int main(int argc, char** argv){
	int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE DUONG TRON - MIDPOINT");
	
	initGL();
	glutDisplayFunc(mydisplay);    
	glutMainLoop();
}

