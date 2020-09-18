//Implement selection sort for 10 elements:
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int arr[10], i, j, temp;
    printf("Filling array now:\n");
    for(i = 0; i <= 9; i++){
        printf("Enter a number: ");
        scanf("%d", arr + i);
    }
    for(i = 0; i < 9; i++){
        for(j = i + 1; j <= 9; j++){
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for ( i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}
