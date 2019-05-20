#ifndef LEXICAL_H
#define LEXICAL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum status_t
{
    SUCCESS ,
    FAILURE 
}Status;


	 

void red();
void reset();
void megenta();
void blue();
Status file_handling(int argc ,char ** argv , FILE ** fptr);
Status check_extension(const char * file_name);
Status open_file(const char * file_name , const char * mode, FILE ** fptr);
Status check_emptyness(const char * file_name , FILE ** fptr);

void word_parse(char * line_buffer);
int key_word(char * token);
void remove_delimiter(char ** token);
void int_literal(char * token);
void char_literal(char * token);
void float_literal( char * token);

void  string_parse(char * line_buffer);
void c_operator(char * line_buffer);
int comments(char * buffer);
int ident_keyword(char * token);
void identifier(char * token);
#endif
