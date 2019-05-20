#include"lexical.h"


void string_parse(char * line_buffer)
{
    int i = 0;
    int flag = 1;



    while(line_buffer[i] != '\0')
    {

	if(line_buffer[i] == 34  )    //print from the " till the end of the "
	{
	    if(flag)
	    {
		printf("string literal	:	");     //inorder to print only once
		flag = 0;
	    }

	    i++;
	    while(line_buffer[i] != 34)
	    {
		putchar(line_buffer[i]);
		i++;
	    }


	}

	i++;
    }
    puts("");
}


void word_parse(char * line_buffer)
{

    int i = 0 , j = 0;
    char * token;
    char line_buf[100];
    strcpy(line_buf , line_buffer);

    /*get the word*/
    token = strtok(line_buffer , " (=");

    while(token != NULL)
    {
	/*remove tab*/
	if(token[0] == '\t' )
	    remove_delimiter(&token);


	/*remove the ;*/
	if(token[strlen(token)-1] == ';')
	    token[strlen(token)-1] = '\0';


	/*keyowrds*/
	if(key_word(token) != 0)
	{

	    if(token[0] == '/'&& token[1] == '/')
		break;


	    /*identifier*/
	    identifier(token);  //to find the identifier
	}

	token = strtok(NULL, " (=");
    }

}

#if 0
void identifier(char * token_t)
{

   char * token;
   int  f = 0;
    token = strtok(token_t , " (");
    while(token != NULL)
    {
        if( ident_keyword(token) == 1)
        {
	    f++;
	}

	else
	{
	    if(f == 0 )
	    {
		return;
	    }
	    else if( f == 1)
	    {
		printf("Identifierpoo : %s\n" , token);
		f = 0;
	    }

	    else if( f == 2)
	    {
		printf("Identifier : %s\n" , token);
		f = 0;
	    }
	}

      token = strtok(NULL , " (");
   }


}

int ident_keyword(char * token)
{

 char i = 0, j = 0;
    char f = 0;
    char keyword[19][10] = {"char", "const", "double", 
	"enum", "extren", "float", "int", "long", "register",
	"short", "signed", "static", "struct", "typedef", "union", "unsigned", "void", "volatile",};
    /*remove tab*/
///	if(token[0] == '\t' )
////	    remove_delimiter(&token);


    for(j = 0; j < 19 ; j++)
    {
	if(strcmp(keyword[j] , token) == 0)
	{
	    return 1;
	}

   }

    return 0;
}
#endif	
/*identifier*/

void identifier(char * token)
{
    int i = 0;

    if(!(token[0] >= '0' && token[0] <= '9')  )   //not a number
    {
	if(!(token[0] >= 33 && token[0] <= 47) )  // not a special character
	{
	    if(!(token[0] >= 58 && token[0] <= 64)) 
	    {
		if(!(token[0] >= 91 && token[0] <= 96))
		{
		    if(!(token[0] >=123 && token[0] <=126))

		    {
			if(token[strlen(token)-1] != ')')
			{
			    printf("Identifier	:	");
			    while(token[i] != '\0')
			    {
				if(token[i] != '-' && token[i] != '+')
				    printf("%c", token[i]);
				i++;
			    }

			    puts("");
			}
		    }
		}
	    }
	}
    }

}
/*operator*/

void c_operator(char * line_buffer)
{

    int i = 0;
    while(line_buffer[i] != '\0')
    {
	/*decrement*/
	if(line_buffer[i] == '-' && line_buffer[i+1] == '-')
	{
	    printf("Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);

	    i++;
	}
	/*increment*/
	else if(line_buffer[i] == '+' && line_buffer[i+1] == '+' )
	{
	    printf("Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);
	    i++;
	}

	/*arithmatic */
	else if(line_buffer[i] == '+' || line_buffer[i] ==  '-' || line_buffer[i] == '/' || line_buffer[i] == '%' )
	    printf("Operator	:	%c\n", line_buffer[i]);

	/*brackets*/
	else if(line_buffer[i] == '(' || line_buffer[i] == ')')
	    printf("Parenthesis	:	%c\n" , line_buffer[i]);

	else if(line_buffer[i] == '{' ||line_buffer[i] == '}') 
	    printf("Brace	:	%c\n", line_buffer[i]);

	else if(line_buffer[i] == '[' ||line_buffer[i] == ']')
	    printf("Square bracket	:	%c\n" ,line_buffer[i]);

	/*shift*/
	else if(line_buffer[i] == '<' && line_buffer[i+1] == '<' )
	    printf("Left Shift Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);

	else if(line_buffer[i] == '>' && line_buffer[i+1] == '>')
	    printf("Right Shif Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);

	/*relational*/
	else if(line_buffer[i] == '>' && line_buffer[i+1] == '=')
	    printf("Relational  Operato	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);

	else if(line_buffer[i] == '<' && line_buffer[i+1] == '=')
	    printf("Relational  Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);

	else if(line_buffer[i] == '=' && line_buffer[i+1] == '=')
	{
	    printf("Relational  Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]); i++;
	}

	else if(line_buffer[i] == '!' && line_buffer[i+1] == '=')
	{
	    printf("Relational  Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);
	}

	else if(line_buffer[i] == '<' || line_buffer[i] == '>' )
	{
	    printf("Relational  Operator	:	%c\n" ,line_buffer[i]);
	}
	/*logical*/
	else if(line_buffer[i] == '&' && line_buffer[i+1] == '&')
	    printf("Logical  Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);

	else if(line_buffer[i] == '|' && line_buffer[i+1] == '|')
	    printf("Logical  Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);

	else if(line_buffer[i] == '!')

	    printf("Logical  Operator	:	%c\n" ,line_buffer[i]);
	/*bitwise*/
	/*and*/
	else if(line_buffer[i] == '&' )
	    printf("Bitwise  Operator	:	%c\n" , line_buffer[i]);
	/*or*/
	else if(line_buffer[i] == '|' )
	    printf("Bitwise  Operator	:	%c\n" , line_buffer[i]);

	/*not*/
	else if(line_buffer[i] == '~' )

	    printf("Bitwise  Operator	:	%c\n" , line_buffer[i]);

	/*conditional operator*/
	else if(line_buffer[i] == '?' && line_buffer[i+1] == '.')

	    printf("Conditional  Operator	:	%c%c\n" , line_buffer[i],line_buffer[i+1]);

	/*compound operator*/
	else if(line_buffer[i] ==  '=')
	    printf("Assignment operator		:	%c\n" , line_buffer[i]);

	else if(line_buffer[i+1] == '=')
	{
	    if(line_buffer[i] == '+' || line_buffer[i] ==  '-' || line_buffer[i] == '/' || line_buffer[i] == '%' )
		printf("Compound Operator	:	%c\n", line_buffer[i]);

	    if(line_buffer[i] == '&' || line_buffer[i] ==  '|' )
		printf("Compound Operator	:	%c\n", line_buffer[i]);
	}



	i++;
    }

}


/*find the int,char, string literal*/
void int_literal(char * token)
{
    char i = 0, f = 0, j = 0;

    char int_t[40];

    while(token[i] != '\0'&& (token[i] != '/' && token[i+1] != '/'))
    {
	if(token[i] >= '0' && token[i] <= '9')
	{
	    int_t[j] = token[i];
	    j++;
	}

	if(token[i] == '.')
	    f = 1;


	i++;
    }

    int_t[j] = '\0';
    //not a float 
    if( (f != 1)  && (int_t[0] != '\0') )
	printf("Int literal	:	%s\n" , int_t);

}
void char_literal(char * token)
{
    int i = 0;
    while(token[i] != '\0')
    {
	if(token[i] != 39) i++;

	else
	{
	    printf("char Literal	:	");
	    printf("%c\n",token[i+1]);
	    break;
	}
    }

}


void float_literal( char * token)
{
    int i = 0, j = 0 , flag = 0;
    char float_t[60];

    while(token[i] != '\0')
    {

	if((token[i] >= '0' && token[i] <= '9' ))
	{
	    float_t[j] = token[i];
	    j++;
	}

	if(token[i] == '.')
	{
	    float_t[j] = token[i];
	    flag = 1;
	    j++;
	}
	i++;
    }

    float_t[j] = '\0';
    if(flag == 1)
	printf("Float Identifier	:	%s\n", float_t);



}






/*remove the space or tab or ;*/
void remove_delimiter(char ** token)
{
    int i=0;

    while((*token)[i] != '\0')
    {

	if((*token)[i] == '\t')
	    (*token)++;
	i++;
    }

    //puts(*token);

}

/*keyowrd */

int key_word(char * token)
{
    char key_word[32][10] = { "auto","break", "case", "char", "const", "continue", "default", "do", "double", "else",
	"enum", "extren", "float", "for", "goto", "if", "int", "long", "regidter", "return",
	"short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    /*binary search*/


    int start = 0 , end = 31 , mid = 0;

    //  puts("poonam");
    while(start <= end)
    {


	/*find the mid*/
	mid = (start + end) / 2;
	//	printf("inside kw %s %s\n",token, key_word[mid]);


	if( strcmp(key_word[mid] , token) == 0)
	{
	    printf("keyword\t\t	 :	%s\n", token);
	    return 0;
	}

	else if( strcmp(token , key_word[mid]) < 0)
	    end = mid - 1;
	else if(strcmp(token,key_word[mid]) > 0)
	    start = mid +1;

    }
    return 1;
}






