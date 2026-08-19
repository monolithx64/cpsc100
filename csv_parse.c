#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAXCHAR 1000

// create a structure, "weather" that corresponds to column headers of weather.csv
struct weather {
    int year;
    int month;
    int day;
    float temp_mean;
    float temp_min;
    float temp_max;
    float dew_point;
    int humidity;
    int humidity_min;
    int humidity_max;
    float rain;
};

// function prototype for celcius to farhenheit function
float ctof(float c); 

int main() {
    FILE *fptr;
    char row[MAXCHAR];
    fptr = fopen("weather.csv","r");

    if (fptr == NULL){
        printf("Error opening file!");
        exit(1); // Program exits if the file pointer returns NULL.
    }

    int column;
    const char* token; // Need pointers here

    struct weather list[92]; // create an array of 92 weather readings and call it list

    // variable to index the rows in the csv
    int row_num = 0; 

    // go through rows of csv in a while-loop below
    // stores data in each row to elements of list[92]
    while (fgets(row, MAXCHAR, fptr)){

         // when row_num = 0, we ignore header row
        if (row_num == 0) {
            row_num++;
            continue;
        }
                
        column = 1; 
        token = strtok(row, ","); // split the row by commas, each cell value will be stored in "token" as a string

        // this loop cycles through all cells (each column) of the row
        while(token != NULL) 
        {            
            /*
                We cycle through rows and set the values of each member of list[0], list[1], etc by column number.
                since arrays begin with 0 and row_num begins at 1, there is a slight mismatch between indices.
                So we use list[row_num - 1] in the block of code below
            */

            if (column == 1) { // column 1 corresponds to year
                list[row_num - 1].year = atoi(token); // atoi() function converts string to int
            } else if (column == 2) { // column 2 corresponds to month, and so on...
                list[row_num - 1].month = atoi(token);
            } else if (column == 3) {
                list[row_num - 1].day = atoi(token);
            } else if (column == 4) {
                list[row_num - 1].temp_mean = atof(token); // atof() function converts string to float
            } else if (column == 5) {
                list[row_num - 1].temp_min = atof(token);
            } else if (column == 6) {
                list[row_num - 1].temp_max = atof(token);
            } else if (column == 7) {
                list[row_num - 1].dew_point = atof(token);
            } else if (column == 8) {
                list[row_num - 1].humidity = atoi(token);
            } else if (column == 9) {
                list[row_num - 1].humidity_min = atoi(token);
            } else if (column == 10) {
                list[row_num - 1].humidity_max = atoi(token);
            } else {
                list[row_num - 1].rain = atof(token);
            }

            column++; // go to next column
            token = strtok(NULL, ","); // reset token
        }
        row_num++; // increment row_num
    }
    fclose(fptr);


/* *****************************************************************************************
*   All your code sbould be added below this comment block (except possibly header files)  *
********************************************************************************************/   


    /*
    *   Run the code as-is. You should see weather data stored in list[92] displayed as sentences
    * 
    *   Use the loop below as an example and/or add more of your own to answer the questions given on Moodle
    *   Add any variables necessary for calculation.
    *   Your code should output answers on screen (use printf)
    *   Any hard-coded answers will be given 0. i.e. your code needs to calculate the answers, not just display them
    */

    for (int i = 0; i < 92; i++) { 
        printf("\nOn %d-%d-%d, the temerature was between %0.1fC and %0.1fC and mean humidity was %d%% with %0.1f mm of rainfall", list[i].day, list[i].month, list[i].year, list[i].temp_max, list[i].temp_min, list[i].humidity, list[i].rain);
    }
    
    return 0;

}

// function to convert celcius to fahrenheit
float ctof(float c) 
{
    // your code here
}