/*
The area of a triangle can be computed by the sine law when 2 sides of the triangle and the angle between them are known.
Area = (1 / 2 ) ab sin ( angle )
Given the following 6 triangular pieces of land, write a program to find their area and determine which is largest,
Plot No.    a         b         angle
1         137.4     80.9        0.78
2         155.2     92.62       0.89
3         149.3     97.93       1.35
4         160.0     100.25      9.00
5         155.6     68.95       1.25
6         149.7     120.0       1.75
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
float area(float*);
int main(){
    int i;
    float data[6][4] = {
        {137.4, 80.9, 0.78, 0},
        {155.2, 92.62, 0.89, 0},
        {149.3, 97.93, 1.35, 0},
        {160.0, 100.25, 9.00, 0},
        {155.6, 68.95, 1.25, 0},
        {149.7, 120.0, 1.75, 0}    
    };
    
    //Calculating area for each triangle
    for(i = 0; i < 6; i++){
        data[i][3] = area(data[i]);
        printf("Area of triangle %d = %f\n", i, data[i][3]);
    }

    //checking which area is largest
    float largest = data[i][3];
    for(i = 0; i < 6; i++){
        if(largest < data[i][3]){
            largest = data[i][3];
        }
    }
    printf("Largest area = %f", largest);
}

float area(float *data){
    float area;
    area = (1.0 / 2.0) * data[0] * data[1] * sin(data[2]);
    return area;
}
