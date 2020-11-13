/*
For the following set of point given by (x, y) fit a straight line given by
y = a + bx
coordinates: 
x          y
3.0       1.5
4.5       2.0
5.5       3.5
6.5       5.0
7.5       6.0
8.5       7.5
8.0       9.0
9.0       10.5
9.5       12.0
10.0      14.0
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>

void st_line(float*, float*, int, float*, float*);

int main(){
    float x[] = {3.0, 4.5, 5.5, 6.5, 7.5, 8.5, 8.0, 9.0, 9.5, 10.0};        //initializing x and y coordinates array
    float y[] = {1.5, 2.0, 3.5, 5.0, 6.0, 7.5, 9.0, 10.5, 12.0, 14.0};
    int num = sizeof(x) / sizeof(x[0]);                                 //getting size of array
    float a, b;
    st_line(x, y, num, &a, &b); 
    printf("Line is y = %f + %fx", a, b);             
}

void st_line(float x[], float y[], int num, float *a, float *b){          
    int i;
    float sumx, sumy, sumx2, sumxy;
    sumx, sumy, sumx2, sumxy = 0;
    
    for(i = 0; i < num; i++){           
        sumx += x[i];               //sum of x array elements
        
        sumy += y[i];               //sum of y array elements
        
        sumxy += x[i] * y[i];       //sum of x * y elements
        
        sumx2 += pow(x[i], 2);      //sum of squared elements of x array 
    }
    *b = ((num * sumxy) - (sumx * sumy)) / ((num * sumx2) - (sumx * sumx));     //b is slope
    
    *a = (sumy - (*b * sumx)) / num;            //a is y-intercept
}
