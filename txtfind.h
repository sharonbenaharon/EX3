#ifndef _TXTFIND_H
#define _TXTFIND_H
#define WORD_LEN_MAX 30                                                      
#define LINE_LEN_MAX 256

#include <stdio.h>
#include <string.h>   
#include <stdlib.h>                                                            
#include <ctype.h>  

FILE* file;



int getLine(char* s);
int getWord(char* w); 
int containStringCheak( char* w, char* inputWord);
int similarCheck( char* w,  char* inputWord,int n);
int countChar(char* w, char* inputWord, char checkCT);
void printWordSimilar( char* w);
void printLineSimilar( char* s);

#endif
