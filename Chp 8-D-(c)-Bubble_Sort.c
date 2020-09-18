//Implement Bubble sort for 10 elements:
#include<stdio.h>
#include<conio.h>
int main(){
    int arr[10], i, j, temp;
    printf("Filling array now:\n");
    for(i = 0; i <= 9; i++){
        printf("Enter a number: ");
        scanf("%d", arr + i);
    }
    for(i = 0; i <= 9; i++){
        for(j = 0; j <= 9 -i; j++){
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];          
                arr[j] = arr[j + 1];        //swapping if element at position j is greater than one at position (j + 1)
                arr[j + 1] = temp;
            }
        }
    }
    for(i = 0; i <= 9; i++){
        printf("%d\n", arr[i]);
    }
}
