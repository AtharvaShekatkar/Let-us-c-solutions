//The X and Y coordinates of 10 different points are entered through the keyboard. 
//Write a program to find the distance of last point from the first point (sum of distance between consecutive points).

#include<stdio.h>
#include<conio.h>
#include<math.h>

float distance(float*, float*);

int main(){
    float x[10], y[10];
    int i;
    for(i = 0; i < 10; i++){              //getting x and y coordinates from user
        printf("Enter X-coordinate: ");
        scanf("%f", &x[i]);
        printf("Enter Y-coordinate: ");
        scanf("%f", &y[i]);
    }
    
    float dist = distance(x, y); 
    printf("distance = %f", dist);
}

float distance(float x[],float y[]){      
    float dist = 0; 
    int i;
    
    for(i = 0; i < 9; i++){                   //calculating distance between first and last point
        dist += sqrt(pow(x[i] - x[i + 1], 2) + pow(y[i] - y[i + 1], 2));        
    }
    return dist;
}
