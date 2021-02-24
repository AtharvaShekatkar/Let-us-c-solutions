//Write a program that will read a line and delete from it all occurrences of a word entered by the user from the sentence.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 80

void remove_word(const char *, char *, char *);
int main(){
    char sentence[MAX] = {0};
    char delete_word[10]; 
    printf("Enter a sentence: ");
    fgets(sentence, 80, stdin);

    printf("Enter the word whose occurance is to be deleted: ");
    fgets(delete_word, 10, stdin);
    delete_word[strlen(delete_word) - 1] = 0;

    char *new_sentence = (char *) malloc(strlen(sentence) * sizeof(char));
    remove_word(sentence, delete_word, new_sentence);
    

    printf("Original sentence: \n%s\n", sentence);
    printf("Modified sentence:  \n%s", new_sentence);
    return 0;
}

void remove_word(const char *sentence, char *delete_word, char *new_sentence){
    while(*sentence != 0){
        int j = 0;
      
        //checks if word occurs
        while(delete_word[j] != 0){
            if(sentence[j] != delete_word[j]){
                break;
            }
            j++;
        }
        
        //skips copying the word if the word is found
        if(delete_word[j] == 0){
            sentence += j + 1;
        }
      
        //copies each character into the new_sentence string
        else{
            *new_sentence = *sentence;
            new_sentence++;
            sentence++;            
        }       
    }
}
