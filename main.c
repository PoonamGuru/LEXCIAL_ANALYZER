#include"lexical.h"

int main(int argc, char ** argv)
{
    FILE * fptr;
    char line_buffer[250];
    char ret = 1;

    puts("---------------------------------------------------------------------------------------------------------------------------");
    megenta();
    puts("\t\t\t\t\t\tLEXICAL ANALYZER");
    reset();
    puts("---------------------------------------------------------------------------------------------------------------------------");
    if( file_handling( argc , argv , &fptr) == FAILURE)
	exit(1);

    puts("--------------------------------------------------------------------------------------------------------------------------------");

    printf("-----------------------------------paring : %s : Started-------------------------------------------------------------- \n" , argv[1]);
    /*parse the file*/
    while(!feof(fptr))    //feof return 0 on success and non zero when it reaches the endof  the file
    {


	/*read each line*/
	fgets(line_buffer , 250, fptr);
	line_buffer[strlen(line_buffer) - 1] = '\0';

	/*comments*/
	ret = comments(line_buffer);   /*operator*/



	/*preprocessor directive*/
	if(line_buffer[0] == '#')
	    printf("Prepocessor Directive : %s\n" , line_buffer);

	/*printf */
	else if (strstr(line_buffer, "printf") != NULL)
	{
	    printf("Identifier : %s\n" , "printf");
	    string_parse(line_buffer);
	}

	else
	{

	    /*string*/
	    string_parse(line_buffer); 
	    int_literal(line_buffer);
	    char_literal(line_buffer);
	    float_literal(line_buffer);

	    if(ret == 1)
		c_operator(line_buffer);

	    /*parse the words*/

	    word_parse(line_buffer);
	}


    }


    printf("------------------------------------------paring : %s : done---------------------------------------- \n" , argv[1]);



    return 0;
}



/*dont consider  the comments */
int comments(char * buffer)
{
    int i = 0;
    while(buffer[i] != '\0')
    {
	if(buffer[i] == '/' && buffer[i+1] == '/')

	    return 0 ;

	if(buffer[i] == '/' && buffer[i+1] == '*')return 0;


	i++;
    }
    return 1;
}

