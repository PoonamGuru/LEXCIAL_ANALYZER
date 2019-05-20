scanf("%d",&num);
if ( num == 0 )  //poonam
{
    printf("special case:%d is even number\n",num);
    break;
}


if( num <= 1048576 )  //check whether the num is <2^20
{
    even_odd(num);
}

