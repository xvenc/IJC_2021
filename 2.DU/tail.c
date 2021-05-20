/* 
*********************************************************************************
* tail.c                                                                        *
* Solution for IJC-DU2, assignment a), 9.4.2020                                 *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                *
* Compiled: gcc 10.2.1                                                          *
* Modul tail.c implemented as POSIX tail, line_limit is set to 511 characters   *
* also +n is implemented same as tail -n +n, where n is unsigned integer,       *
* prints all the lines starting from line n, there is no limit for line         *
*********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define IMPLICIT_READ 10
#define LINE_LENGTH 512 // 511 characters

//free alocated space
void free_lines(char **lines, int n_lines){
    for (int i = 0; i < n_lines; i++) {
        free(lines[i]);
    }
    free(lines);
}

//print n number of lines
void print_lines(char **lines, int n_lines, int file_lines){

    if (n_lines < file_lines) {
        for (int i = file_lines % n_lines; i < n_lines; i++) {
            printf("%s",lines[i]);
        }
        for (int i = 0; i < file_lines % n_lines; i++){
            printf("%s",lines[i]);
        }
    }else {
       for (int i = 0; i < file_lines; i++) {
            printf("%s",lines[i]);
        }
    }
    
}

//read lines from stdin/file
void read_lines(FILE *file, int n_lines){
    //allocate space for n_lines 
    char **line = malloc(sizeof(char *) * n_lines);
    if (line == NULL) {
        fprintf(stderr,"ERROR: Couldnt alloc memory\n");
        exit(1);
    }
    
    for (int i = 0; i < n_lines; i++) {
        line[i] = malloc(sizeof(char) * LINE_LENGTH);
        if (line[i] == NULL) {
            fprintf(stderr,"ERROR: Couldnt alloc memory\n");
            exit(1);
        }
    }
    int line_count = 0;
    int index = 0;
    bool first_time = true;
    //read max 511 characters if 512 character is \n print error
    while (fgets(line[index],LINE_LENGTH,file) != NULL) {
        //check if the line length is equal to the line limit
        if ((strlen(line[index]) == LINE_LENGTH - 1)) {
            //check if the last character of the line is /n
            if ((line[index][LINE_LENGTH-1] != '\n')) {
                //skip the rest of the line until i reach \n whic indicates new line
                char dummy;
                do
                {
                    dummy = fgetc(file);
                } while (dummy != '\n');
                line[index][LINE_LENGTH - 2] = '\n';
                line[index][LINE_LENGTH - 1] = '\0';
                first_time = false;
            }
        }
        index++;
        line_count++;
        if (index == n_lines) {
            index = 0;
        }
        
    }
    //print error if line is longer than 511 characters
    if (!first_time) {
        fprintf(stderr,"WARNING: Line is longer than %d characters, which is line limit\n",LINE_LENGTH-1);
    }
    
    print_lines(line,n_lines,line_count);

    free_lines(line, n_lines);
    
    return;
}

void print_lines_after(FILE *file, int skipd_lines) {
    
    int dummy = '\0';
    int n_lines = 1;
    int count = 0;
    //loop to skip n number of lines
    while (((dummy = fgetc(file)) != EOF) && (skipd_lines != n_lines) && (skipd_lines != 0)) {
        if (dummy == '\n') {
            n_lines++;  
        }
    }
    //loop to print the rest lines, its not limited by the line length
    do {
        printf("%c",dummy);
        count++;
    } while (((dummy = fgetc(file)) != EOF));
    //print error if line is longer than 511 characters
    if (count > LINE_LENGTH-1) {
        fprintf(stderr,"WARNING: Line is longer than %d characters, which is line limit\n",LINE_LENGTH-1);
    }
    return;
}


int main(int argc, char **argv){
    FILE *read_from;
    signed long number = 0;
    char *garbage = 0;

    //argument parser max 4 arguments
    if (argc == 1) {
        
        read_from = stdin;
        read_lines(read_from, IMPLICIT_READ);

    } else if (argc == 2) {
        
        if (!strcmp(argv[1],"-n")) {
            fprintf(stderr,"ERROR: There cant be -n without number\n");
            exit(1);
        }

        read_from = fopen(argv[1],"r");
        if (read_from == NULL) {
            fprintf(stderr, "ERROR: Couldnt open the file\n");
            exit(1);
        }
        
        read_lines(read_from, IMPLICIT_READ);

    } else if (argc == 3) {
        if (strcmp(argv[1],"-n") != 0) {
            fprintf(stderr, "ERROR: There must be -n as a second argument");
            exit(1);
        }
        read_from = stdin;
        number = strtol(argv[2],&garbage,10);

        if (number < 0 || *garbage != 0){
            fprintf(stderr, "ERROR: Number must be bigger that 0 and it mustnt contain letters\n");
            exit(1);
        }


        if (argv[2][0] == '+') {
            print_lines_after(read_from,number);
        }else {
            if (number == 0){
                return 0;
            }
            read_lines(read_from,number);
        }

    } else if (argc == 4) {
        if (strcmp(argv[1],"-n") != 0) {
            fprintf(stderr, "ERROR: There must be -n as a second argument");
            exit(1);
        }

        read_from = fopen(argv[3],"r");
        if (read_from == NULL) {
            fprintf(stderr, "ERROR: Couldnt open the file\n");
            exit(1);
        }


        number = strtol(argv[2],&garbage,10);
        if (number < 0 || *garbage != 0){
            fprintf(stderr, "ERROR: Number must be bigger that 0 and it mustnt contain letters\n");
            exit(1);
        }
                
        if (argv[2][0] == '+') {
            print_lines_after(read_from,number);
        }else {
            if (number == 0){
                return 0;
            }
            read_lines(read_from,number);
        }

    } else {
        fprintf(stderr,"ERROR: Too many parametrs were set\n");
        exit(1);
    }
    
    fclose(read_from);
    return 0;
}