#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include <ctype.h>

enum
{
   WORD      = 0x01,
   PARAGRAPH = 0x02,
   SENTENCE  = 0x04,
   END       = 0x08
};


// This function reads the next word from the file and sets the type
// accordingly, indicating if this word is the first word of a sentence
// (type & SENTENCE is true), first word of a paragraph (type & PARAGRAPH is
// true).
//
// It is up to you to free the string when you no longer need it.
//
// When there is nothing more in the file, the function returns NULL and sets
// type to END.
//
char * getNext (FILE * f, int * type)
{
   static char * buf = 0;
   static size_t buflen = 0;
   static bool first = true;

   static const char * sentence = ".!?";

   int t = 0;

   size_t next = 0;

   bool pre = true;
   // read up to enter, whitespace or EOF
   do
   {
      int c = fgetc (f);

      if (c == EOF)
      {
         t |= END;
         break;
      }

      if (c == ' ' || c == '\t')
      {
         if (pre)
            continue;
         else
            break;
      }

      if (strchr (sentence, c))
      {
         if (pre)
         {
            t |= SENTENCE;
            continue;
         }
         else
         {
            ungetc (c, f);
            break;
         }
      }

      if (c == '\n')
      {
         if (pre)
         {
            t |= PARAGRAPH;

            // Enforce that every paragraph also starts a sentence
            t |= SENTENCE;
         }
         else
            break;
      }

      // ignore certain characters
      int up = toupper (c);
      if ((up < 'A') || (up > 'Z'))
         continue;


      // non-blank character
      pre = false;
      if (next == buflen)
      {
         // reallocate
         size_t newlen = buflen ? buflen * 2 : 2;
         buf = realloc (buf, newlen);
         assert (buf);
         buflen = newlen;
      }

      assert (next < buflen);
      buf[next++] = (char) c;
   } while (true);

   char * word = 0;
   if (next)
   {
      word = (char*) malloc (next+1);
      strncpy (word, buf, next);
      word[next]=0;
      t |= WORD;
   }

   if (first)
   {
      t |= PARAGRAPH;
      t |= SENTENCE;
      first = false;
   }

   if (t & END)
   {
      free (buf); buf=0; buflen=0;
   }

   *type = t;
   return word;
}

// COMPLETE ME
int main (int argc, char ** args)
{
   if (argc != 2)
   {
      fprintf (stderr, "Need exactly one argument: file name\n");
      return 1;
   }

   FILE * f = fopen (args[1], "r");
   if (!f)
   {
      fprintf (stderr, "Could not open file!\n");
      return 1;
   }

   // Currently, the code just writes each token to the screen.
   // Replace below with code inserting the strings into your data structures.
   //
   // Don't forget to use functions! (don't write everything below)

   // Make sure to *store your data in memory*, don't simply count in the
   // loop.

   // ---- replace below, adding code which calls functions from your ts.h
   //      to add to the data structure instead ---
   do
   {
      int type;
      char * str = getNext (f, &type);
      if (type & END)
         break;

      if (type & WORD)
         printf ("W: ");
      if (type & SENTENCE)
         printf ("S: ");
      if (type & PARAGRAPH)
         printf ("P: ");

      if (str)
         puts (str);
      else
      {
         if (type & END)
            break;
      }

      free (str);
   } while (true);

   // --- replace above


   fclose (f);

   // --- Now analyze

   // Q1 -- place in separate function

   printf ("Q1 Results: Words (%u), Sentences (%u), Paragraphs (%u)\n",
         0, 0, 0);


   // Q2 -- place in separate function

   printf ("Q2 Results: Repeated: Words (%u), Sentences (%u), Paragraphs (%u)\n",
         0, 0, 0);


   // Q3 -- place in separate function

   printf ("Q3 Results: min/avg/max words(%u:%f:%u), sentences(%u:%f:%u)\n",
         0, 0.0, 0, 0, 0.0, 0);

   // Q4 -- place in separate function
   //  Remember: code duplication should usually be avoided
   printf ("Q4-1 Results: Words (%u), Sentences (%u), Paragraphs (%u)\n",
         0, 0, 0);
   printf ("Q4-2 Results: Repeated: Words (%u), Sentences (%u), Paragraphs (%u)\n",
         0, 0, 0);
   printf ("Q4-3 Results: min/avg/max words(%u:%f:%u), sentences(%u:%f:%u)\n",
         0, 0.0, 0, 0, 0.0, 0);

   return EXIT_SUCCESS;
}
