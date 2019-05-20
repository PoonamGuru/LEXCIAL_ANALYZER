#include"lexical.h"

Status file_handling(int argc ,char ** argv , FILE ** fptr)
{
     if(argc <= 1)
     {
	 red();
         printf("ERROR : Enter the .c file\n");
	 reset();
         return FAILURE;
     }

     puts("\t\t\t\t\tFILE HANDLING ");
     /*check the extension*/
     if(check_extension(argv[1]) == FAILURE)
         return FAILURE;
 
 
     /*open the file in read mode */
     if( open_file(argv[1] , "r", fptr) == FAILURE)
         return FAILURE;
 
 
     /*check the emptyness */
     if(check_emptyness(argv[1] , fptr) == FAILURE)
         return FAILURE;


     return SUCCESS;
 
} 


Status check_extension(const char * file_name)
{
    int i = 0;


    /*increment till .*/
    while(file_name[i] != '\0')
    {
	if(file_name[i++] == '.')
	    break;
    }


    /*check the .c is there or not*/
    if(file_name[i] == 'c')
    {
	printf("INFO: %s has the correct extension\n",file_name);
    return SUCCESS;
    }

    else
    {
	red();
	printf("ERROR : %s does not have .c extension\n", file_name);
	reset();
	return FAILURE;
    }

}




/*function : open the file in the respective  mode*/

Status open_file(const char * file_name , const char * mode, FILE ** fptr)
{

    *fptr = fopen(file_name , mode);

    if(*fptr == NULL)
    {
	red();
	perror("ERROR : open");
	reset();
	return FAILURE;
    }


    else
    {
	printf("INFO (open) : %s : SUCCESSFULLY\n", file_name);
	return SUCCESS;
    }

}


/*function : file is empty or not*/


Status check_emptyness(const char * file_name , FILE ** fptr)
{
    fseek(*fptr , 0L , SEEK_SET);

    fseek(*fptr , 0L , SEEK_END);  // go to end of the file

    if(ftell(*fptr) == 0)
    {
	red();
	printf("ERROR : %s file is empty \n", file_name);
	reset();
	return FAILURE;
    }


    else
    {
	printf("INFO : %s file is not empty\n", file_name);
	rewind(*fptr);
	return SUCCESS;
    }
}
