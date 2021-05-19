/* 
*****************************************************************************************
* io.h                                                                                  *
* Solution for IJC-DU2, assignment b), 9.4.2020                                         *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                        *
* Compiled: gcc 10.2.1                                                                  *
* Module io.h, with declaration of function read_word, which of maximum max-1 characters*
* to given char* s and from given file (can be stdin)                                   *
*****************************************************************************************
*/

#include <stdio.h>

#ifndef _IO_H_
#define _IO_H_

int read_word(char *s, int max, FILE *f);

#endif /*END_IF_IO_H_*/