#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort_char (const void * a1, const void * a2)
{
   const char * s1 = (const char *) a1;
   const char * s2 = (const char *) a2;
   if (*s1 < (*s2))
      return -1;
   else if ((*s1) > (*s2))
      return 1;
   else
      return 0;
}


void do_sort (char * s)
{
   size_t len = strlen (s);
   qsort (s, len, sizeof (s[0]), &sort_char);

}


int main (int argc, char ** args)
{
   printf ("Number of cmd line arguments = %i\n", argc);
   int i;
   for (i=0; i<argc;++i)
   {
      printf ("Argument %i = %s\n", i, args[i]);

      do_sort (args[i]);

      printf ("Sorted = %s\n", args[i]);
   }

   return EXIT_SUCCESS;
}
