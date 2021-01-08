//Write a function to compute the distance between two points and 
//use it to develop another function that will compute the area of the triangle whose vertices are A(x1, y1), B(x2, y2), and C(x3, y3).
//Use these functions to develop a function which returns a value 1 if the point (x, y) lines inside the triangle ABC, otherwise a value 0.
#include<stdio.h>
#include<conio.h>
#include<math.h>	
float dist(int, int, int, int);			//prototype declarations
float area(float, float, float);		
int inorout(float, float, float, float);
int main(){
	float dist1, dist2, dist3, distxy1, distxy2, distxy3, area_tot, area1, area2, area3;
	int x1, x2, x3, y1, y2, y3, x, y, i;
	printf("Enter X co-ordinate of point 1: ");
	scanf("%d", &x1);
	printf("Enter Y co-ordinate of point 1: ");
	scanf("%d", &y1);
	printf("Enter X co-ordinate of point 2: ");
	scanf("%d", &x2);
	printf("Enter Y co-ordinate of point 2: ");
	scanf("%d", &y2);
	printf("Enter X co-ordinate of point 3: ");
	scanf("%d", &x3);
	printf("Enter Y co-ordinate of point 3: ");
	scanf("%d", &y3);
	dist1 = dist(x1, y1, x2, y2);
	dist2 = dist(x2, y2, x3, y3);
	dist3 = dist(x1, y1, x3, y3);
	printf("Enter X co-ordinate of point that you want to test: ");
	scanf("%d", &x);
	printf("Enter Y co-ordinate of point that you want to test: ");
	scanf("%d", &y);
	distxy1 = dist(x, y, x1, y1);
	distxy2 = dist(x, y, x2, y2);
	distxy3 = dist(x, y, x3, y3);
	area_tot = area(dist1, dist2, dist3);
	area1 = area(dist1, distxy1, distxy2);
	area2 = area(dist2, distxy2, distxy3);
	area3 = area(dist3, distxy3, distxy1);
	i = inorout(area_tot, area1, area2, area3);
	if(i == 1)
		printf("Point (%f, %f) is inside the triangle\n", x, y);
	else
		printf("Point (%f, %f) is outside the triangle\n", x, y);
	return 0;
}
float dist(int x1, int y1, int x2, int y2){
	float distance;
	distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));				//distance formula
	printf("distance between (%f, %f) and (%f, %f) = %f\n", x1, y1, x2, y2, distance);
	return distance;
}
float area(float a, float b, float c){
	float area, s;
	s = (a + b + c) / 2;					
	area = sqrt(s * (s - a) * (s - b) * (s - c));		//using Heron's formula
	printf("Area of triangle = %f\n", area);
	return area;
}
int inorout(float area_tot, float area1, float area2, float area3){
	if(area_tot - (area1 + area2 + area3) <= 0.0001 && area_tot - (area1 + area2 + area3) >= -0.0001)	//comparing the difference because comparing two doubles or floats using "==" doesn't work 
		return 1;
	else
		return 0;	
}
