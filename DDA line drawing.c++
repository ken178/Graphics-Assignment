#include<iostream> 
#include<graphics.h>
#include<math.h>
using namespace std;
int main(){
	float x1, y1, x2, y2, dx, dy, steps, x_incr, y_incr;
	int gd= DETECT, gm; 	
    initgraph(&gd, &gm, "");
	
	cout<<"Enter the starting co-ordinates of x1 and y1: (x1 , y1):"<<endl;
	cin>> x1 >> y1 ;
	
	cout<<"Enter the co-ordinates of x2 and y2: (x2 , y2):"<<endl;
	cin>> x2 >> y2;
	
	dx= abs(x2 - x1) ;
	dy= abs(y2 - y1) ;

	if(dx >= dy)
	steps  = dx;

	else
	 steps = dy;
	 
	 x_incr = dx/steps;
	 y_incr = dy/steps;
	 
	 float x = x1, y = y1;
	 
	 cout << "Coordinates of the lines: " << endl;
	 cout << "x\t\ty" << endl;
	 
	for(int i=0; i<=steps; i++)
	{
		cout << x << "\t\t" << y << endl;
		putpixel(x, y, 10);
		x = x + x_incr;
		y = y + y_incr;
		delay(50);				
	}
	getch();
	closegraph(); 
}