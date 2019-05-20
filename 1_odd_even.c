#include<stdio.h>
void even_odd(int num)
{
    //---------------------even number----------------------------
    if(num % 2 == 0) //to check num is even
    {
	if(num > 0)
	    printf("%d is an even positive number\n",num);
	else
	    printf("%d is an even negative number\n",num);
    }
    //------------------------------odd num-----------------------------------------
    else // if num is odd
    {
	if(num < 0)
	    printf("%d is a odd negative number\n",num);	   
	else
	    printf("%d is an odd  positive number\n",num);
    }
}	


#if 0
#endif
int main()
{

    int num,i = 1;
    while(i <= 5)
    {
	printf("enter a number:\n");
	scanf("%d",&num);
	if (num == 0)
	{
	    printf("special case:%d is even number\n",num);
	    break;
	}


	if(num <= 1048576)  //check whether the num is <2^20
	{
	    even_odd(num);
	}

	else //if num is > 2^ 20
	    printf("invalid input");

	i++;
    }
    return 0;
}



