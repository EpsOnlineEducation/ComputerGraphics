#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

using namespace std;
float xmin=-100;    // Bien luu toa do 4 dinh hinh chu nhat
float ymin=-100;
float xmax=200;
float ymax=150;
float xdA,ydA,xdB,ydB; // Bien luu toa do diem A và B


void initGL(void)
{
    glClearColor(1,1,1,0);
    gluOrtho2D(-300,300,-300,300);
}

// Ve hinh chu nhat va doan thang
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINE_LOOP); //Ve hinh vuong
   		glVertex2i(xmin,ymin);
   		glVertex2i(xmin,ymax);
   		glVertex2i(xmax,ymax);
   		glVertex2i(xmax,ymin);
   glEnd();
   
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);  //Ve duong thang
   		glVertex2i(xdA,ydA);
   		glVertex2i(xdB,ydB);
   glEnd();

   glFlush();
}

int code(float x,float y)  //Tinh Code cua diem
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=2;
    if(x<xmin)c=1;
    return c;
}

void cohen_Line(float xA,float yA,float xB,float yB)
{
    int cA=code(xA,yA); // Code cua diem A
    int cB=code(xB,yB); // Code cua diem B
    float m=(yB-yA)/(xB-xA);
    
	while((cA|cB)>0)  
    {
    	//Truong Hop 1: Diem A va B nam cung phia
    	if((cA & cB)!=0){exit(0);} 

    	//Truong hop 2: diem A hoac B nam trong cua so
		//Hoan doi A voi B
    	float xi=xA;float yi=yA;  // Lay toa do diem A
    	int c=cA;  
    	if(c==0){c=cB;xi=xB;yi=yB;}  
    	// Truong hop 3
    	// Tinh toa do cat voi cac canh hinh chu nhat
    	float x,y;
    	if((c & 8)){y=ymax;x=xi+ 1.0/m*(ymax-yi);}
    	else if((c & 4)){y=ymin;x=xi+1.0/m*(ymin-yi);}
      		 else if((c & 2)){x=xmax;y=yi+m*(xmax-xi);}
       			  else if((c & 1)){x=xmin;y=yi+m*(xmin-xi);}
    
		//Cap nhat lai toa do diem A va B de ve lai doan thang
		//Tính ma diem A va B
    	if(c==cA){ xdA=x; ydA=y;  cA=code(xdA,ydA); }   
    	if(c==cB){ xdB=x; ydB=y;  cB=code(xdB,ydB); }  
	}
// Ve lai hinh chu nhat và doan thang da cat xen
 display();
}

void mykey(unsigned char key,int x,int y)
{
    if(key=='c')//Nhan phim c de xen (ve lai doan thang)
    { 
        cohen_Line(xdA,ydA,xdB,ydB);
        glFlush();
    }
}

int main(int argc,char** argv)
{
    printf("Nhap toa do 2 diem A(xd1,yd1) và B(xd2,yd2):");
    cin>>xdA>>ydA>>xdB>>ydB;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("DEMO XET DOAN THANG BANG HCN - Cohen - Sutherland");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey); //goi ham xu ly xu kien nhan phim
    initGL();
    glutMainLoop();
    return 0;
}

