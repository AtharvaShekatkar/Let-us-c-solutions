//Implement insertion sort for 10 numbers:
#include<stdio.h>
#include<conio.h>
int main(){
    int arr[10], i, j, key;
    printf("Filling array now:\n");
    for(i = 0; i <= 9; i++){
        printf("Enter a number: ");
        scanf("%d", arr + i);
    }
    for ( i = 1; i < 10; i++)
    {
        key = arr[i];
        for ( j = i - 1; (j >= 0) && (arr[j] > key); j--)
        {
            arr[j + 1] = arr[j];        //Moving elements greater than key up by one position
        }
        arr[j + 1] = key;               
    }
    for ( i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}
