//Write macro definitions with arguments for calculation of area and perimeter of a triangle, a square and a circle. Store these macro definitions in a file called “areaperi.h”. Include this file in your program, and call the macro definitions for calculating area and perimeter for different squares, triangles and circles.
//Note:custom header file as required to be defined in question(header file is uploaded in the Chapter 7 folder as well)
#include<math.h>
float area, peri, s;
#define TRIANGLE(a, b, c) peri = a + b + c;\
    s = (a + b + c) / 2;\
    area = sqrt(s * (s - a) * (s - b) * (s - c));
#define SQUARE(x) area = x * x;\
    peri = 4 * x;
#define CIRCLE(r) area = 3.1415 * r * r;\
    peri = 3.1415 * 2 * r;
