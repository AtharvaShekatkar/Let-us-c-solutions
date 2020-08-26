#include<stdio.h>
#include<conio.h>
#include<math.h>
double dist(double, double, double, double);
double area(double, double, double);
int inorout(double, double, double, double);
int main(){
	double x1, x2, x3, y1, y2, y3, x, y, dist1, dist2, dist3, distxy1, distxy2, distxy3, area_tot, area1, area2, area3;
	int i;
	printf("Enter X co-ordinate of point 1: ");
	scanf("%lf", &x1);
	printf("Enter Y co-ordinate of point 1: ");
	scanf("%lf", &y1);
	printf("Enter X co-ordinate of point 2: ");
	scanf("%lf", &x2);
	printf("Enter Y co-ordinate of point 2: ");
	scanf("%lf", &y2);
	printf("Enter X co-ordinate of point 3: ");
	scanf("%lf", &x3);
	printf("Enter Y co-ordinate of point 3: ");
	scanf("%lf", &y3);
	dist1 = dist(x1, y1, x2, y2);
	dist2 = dist(x2, y2, x3, y3);
	dist3 = dist(x1, y1, x3, y3);
	printf("Enter X co-ordinate of point that you want to test: ");
	scanf("%lf", &x);
	printf("Enter Y co-ordinate of point that you want to test: ");
	scanf("%lf", &y);
	distxy1 = dist(x, y, x1, y1);
	distxy2 = dist(x, y, x2, y2);
	distxy3 = dist(x, y, x3, y3);
	area_tot = area(dist1, dist2, dist3);
	area1 = area(dist1, distxy1, distxy2);
	area2 = area(dist2, distxy2, distxy3);
	area3 = area(dist3, distxy3, distxy1);
	i = inorout(area_tot, area1, area2, area3);
	printf("%d\n", i);
	if(i == 1)
		printf("Point (%lf, %lf) is inside the triangle\n", x, y);
	else if(i == 0)
		printf("Point (%lf, %lf) is outside the triangle\n", x, y);
	return 0;
}
double dist(double x1, double y1, double x2, double y2){
	double distance;
	distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	printf("distance between (%lf, %lf) and (%lf, %lf) = %lf\n", x1, y1, x2, y2, distance);
	return distance;
}
double area(double a, double b, double c){
	double area, s;
	s = (a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
	printf("Area of triangle = %lf\n", area);
	return area;
}
int inorout(double area_tot, double area1, double area2, double area3){
	printf("%lf and %lf\n", (area1 + area2 + area3), area_tot);
	if(area_tot == (area1 + area2 + area3))
		return 1;
	else
		return 0;
}
