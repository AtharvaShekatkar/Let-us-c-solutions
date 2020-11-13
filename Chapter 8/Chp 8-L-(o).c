//For the following set of sample data, compute the standard deviation and the mean.
//data: -6, -12, 8, 13, 11, 6, 7, 2, -6, -9, -10, 11, 10, 9, 2
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
    int a[15] = {-6, -12, 8, 13, 11, 6, 7, 2, -6, -9, -10, 11, 10, 9, 2}; 
    float mean = 0, std_dev = 0;
    
    //Calculating mean
    int i;
    for(i = 0; i < 15; i++){
        mean += a[i];               
    }
    mean /= 15;
    printf("Mean of given data = %f\n", mean);
    
    //Calculating SD
    for(i = 0; i < 15; i++){
        std_dev += pow((a[i] - mean), 2);
    }
    std_dev = sqrt(std_dev / 15);
    printf("Standard deviation of given data = %f\n", std_dev);
}
