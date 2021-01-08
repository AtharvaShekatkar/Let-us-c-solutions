//
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int circ_L_shift(int*, int, int);
int main(){
    int arr[4][5] = {           //initializing matrix
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };
    int col = 5, row = 4;

    circ_L_shift(arr[0], col, row);
          
    int *ptr = arr[0], i;
    for(i = 0; i < 20; i++){
        printf("%d\t", *ptr);                  //printing the left-shifted matrix
        if(i % 5 == 4)
            printf("\n");
        ptr++;
    }
}
int circ_L_shift(int *p, int col, int row){
    static int count;
    if(count > row)             //exit condition for recursive function
        return 0;
    int i, temp1, temp2;
    temp1 = *p;
    temp2 = *(p + 1);
    for(i = 0; i < col - 2; i++){
        p[i] = p[i + 2];            //left-shifting the row by 2 elements
    }
    p[i] = temp1;
    p[i + 1] = temp2;
    count++;
    circ_L_shift((p + col), col, row);
}
