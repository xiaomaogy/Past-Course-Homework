#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int is_numeric (char str[])
{
   int i = 0;
   //i /* note that this is incomplete, doesn't account for multiple '.' */
   while(str[i] != '\0')
   {
      if(!isdigit(str[i]))
         if (str[i] != '.')
            return 0;
      ++i;
   }

   return 1;
}

int main (int argc, char **argv)
{
   int stat = is_numeric(argv[1]);
   if (stat == 0)
      printf("%s %s\n", argv[1], "is not a numeric value");
   else
      printf("%s %s\n", argv[1], "is a numeric value");

   return EXIT_SUCCESS;
}
