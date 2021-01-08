//Write macro definitions with arguments for calculation of area and perimeter of a triangle, a square and a circle. Store these macro definitions in a file called “areaperi.h”. Include this file in your program, and call the macro definitions for calculating area and perimeter for different squares, triangles and circles.
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<areaperi.h>        //custom header file required in question. Is uploaded on github in Chapter 7 folder
int main(){
    float triside1, triside2, triside3, sqside, radius;
    printf("Enter side 1 of triangle: ");
    scanf("%f", &triside1);
    printf("Enter side 2 of triangle: ");
    scanf("%f", &triside2);
    printf("Enter side 3 of triangle: ");
    scanf("%f", &triside3);
    TRIANGLE(triside1, triside2, triside3);
    printf("Area = %f\t Perimeter = %f\n", area, peri);
    printf("Enter side of square: ");
    scanf("%f", &sqside);
    SQUARE(sqside);
    printf("Area = %f\t Perimeter = %f\n", area, peri);
    printf("Enter radius: ");
    scanf("%f", &radius);
    CIRCLE(radius);
    printf("Area = %f\t Circumference = %f\n", area, peri);
    getch();
    return 0;
}
