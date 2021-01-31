/*Develop a program that receives the month and year from the keyboard as integers and prints the calendar in the following format.
                    
              September 2004
              
Mon   Tue   Wed   Thu   Fri   Sat   Sun
            1     2     3     4     5
6     7     8     9     10    11    12
13    14    15    16    17    18    19
20    21    22    23    24    25    26
27    28    29    30

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int find_day(int, int);

int main(void){
    char *months[] = {    //storing names of months
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    int month, year;
    printf("Enter month number: ");
    scanf("%d", &month);
    if(month <= 0 || month > 12){                       //checking if month is valid
        printf("Please enter valid month number!");
        exit(0);
    }
    
    printf("Enter year(before 2500): ");
    scanf("%d", &year);
    if(year < 1900 || year >= 2500){                  //checking if year is valid
        printf("Please enter a valid year!");
        exit(0);
    }
    
    int no_of_days, st_day;

    switch(month){                                    //assigning number of days to given month number
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            no_of_days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            no_of_days = 30;
            break;
        case 2:
            if(year % 4 == 0)
                no_of_days = 29;
            else
                no_of_days = 28;
            break;    
    }

    st_day = find_day(month, year);                         //finds the start day of the given month 

    //printing the month in the required format
    
    printf("\n\n\t\t%s %d", months[month - 1], year);       

    printf("\n\nMon\tTue\tWed\tThu\tFri\tSat\tSun\n");
    
    for(int i = 0; i < st_day; i++){
        printf("\t");
    }

    for(int i = 1; i <= no_of_days; i++){
        printf("%d\t", i);
        
        if((i + st_day) % 7 == 0)                       //goes to next line if the condition is satisfied
            printf("\n");
    }
}

int find_day(int month, int year){
    year = year - 1900;
    int leaps = year / 4;                 //finds number of leap years
    

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(year % 4 == 0){                                      //checks if current year is leap. If it is, then 
        days[1] = 29;                                       //discard's current one leap year count from the "leaps" variable and changes days of Feb month to 29
        leaps--;
    }

    if(year > 400)                                          //since 2100, 2200, 2300 are not leap years, it removes required amount of extra leap years counted
        leaps -= 3;
    else if(year > 300)
        leaps -= 2;
    else if(year > 200)
        leaps--;
    
    int first = ((2 * leaps) + (year - leaps)) % 7;               //gets first day of the given year

    for(int i = 0; i < month - 1; i++){                           //gets first day of required month
        first = (first + days[i]) % 7;                            
    }

    return first;
}
