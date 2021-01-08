/*For the following set of n data points (x, y), compute the correlation coefficient r
  x           y
34.22       102.43
39.87       100.93
41.85       97.43
43.23       97.81
40.06       98.32
53.29       98.32
53.29       100.07
54.14       97.08
49.12       91.59
40.71       94.85
55.15       94.65
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
float getcorrelation(float *, float*, int);
int main(){
    float x[] = {34.22, 39.87, 41.85, 43.23, 40.06, 53.29, 53.29, 54.14, 49.12, 40.71, 55.15};
    float y[] = {102.43, 100.93, 97.43, 97.81, 98.32, 98.32, 100.07, 97.08, 91.59, 94.85, 94.65};   
    int num = 5;
    float corr = getcorrelation(x, y, num);           //getting correlation coefficient
    printf("Correlation Coefficient = %f", corr);
}   
float getcorrelation(float *x, float *y, int num){
    int i;
    float sumx, sumy, sumxy, sumx2, sumy2;
    sumx, sumy, sumxy, sumx2, sumy2 = 0;
    for(i = 0; i < num; i++){
        sumx += x[i];         //sum of x array elements
        
        sumy += y[i];         //sum of y array elements
        
        sumxy += x[i] * y[i];     //sum of x * y elements
                  
        sumx2 += pow(x[i], 2);      //sum of square of elemnts of x and y arrays
        sumy2 += pow(y[i], 2);
    }
    
    float r = ((num * sumxy) - (sumx * sumy)) / sqrt(((num * sumx2) - pow(sumx, 2)) * ((num * sumy2) - pow(sumy, 2)));        //applying formula
    
    return r;
}
