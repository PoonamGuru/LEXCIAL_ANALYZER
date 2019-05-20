#include<stdio.h>
/*
void to_lower( char *str )
{
    int i = 0;
    while(str[i] != '\0')
    {
	str[i] |= 0x20;
	i++;
    }
}
*/
int main()
  {
  char str[100];
  puts("Enter the str:");
  scanf("%s",str);
  to_lower(str);
  puts(str);
  return 0;
  }
 
