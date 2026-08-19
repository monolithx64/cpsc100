#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXCHAR 1000

int main(){

    FILE *fptr;
    char row[MAXCHAR];
    char *token;
    int column;

    
    fptr = fopen("batsignal.txt","r");
    if (fptr == NULL){
        printf("Error opening file!");
        exit(1); // Program exits if the file pointer returns NULL.
    }
    while (fgets(row, MAXCHAR, fptr)){
        printf("%s", row);
    }
    printf("\n\"It's not who I underneath,\nbut what I do that defines me.\"");

    while( getchar() != '\n' ); // just used as a prompt for user to continue

    fptr = fopen("batman.txt","r");
    if (fptr == NULL){
        printf("Error opening file!");
        exit(1); // Program exits if the file pointer returns NULL.
    }
    while (fgets(row, MAXCHAR, fptr)){
        printf("%s", row);
    }
    printf("\n\"I'm Batman\"");
    
    fclose(fptr);
    return 0;
}