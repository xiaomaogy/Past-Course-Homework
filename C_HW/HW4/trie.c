#include "trie.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>

///
/// Note that each node has a single pointer to a child; the list of children
/// of a node can be found
/// by going to the first child (if it exists) and then following the 'sibling'
/// list until the end.
///
///  So,     T
//         E
//       S
//     T
//   S   I
//         N
//           G
//
//  the trie with words 'tests' and 'testing': the second 'T' node has 2
//  children, so the child pointer of that T node will point 'S', and the
//  sibling pointer of 'S' will point to 'I'. The sibling pointer of 'I' will
//  be NULL.
// 
struct trie_node_t
{
   char letter;
   bool valid_data;
   struct trie_node_t * sibling;
   struct trie_node_t * child;
   void * data;
};

typedef struct trie_node_t trie_node_t;

typedef struct trie_data_t
{
   struct trie_node_t * root;
} trie_data_t;


/// Analyse contents of trie
/// 
///  NOTE: This method isn't really trie specific (and so should be using
///        trie methods to iterate over the trie, but to keep the amount of
///        work down for this homework it is OK to assume internal knowledge
///        of the trie and to access it directly.

void trie_analyze (const trie_t trie)
{
   int count = 0;

   // COMPLETE ME

   // print all words in the trie:
   // printf ("%s: %i\n", ... );

   printf ("Number of words in trie: %i\n", (int) count);
}

static void trie_destroy_helper (trie_node_t * node)
{
   while (node)
   {
      trie_node_t * next = node->sibling;

      // Destroy children
      trie_destroy_helper (node->child);
      
      // Destroy self
      free (node);

      // Go to next sibling
      node = next;
   }
}

/// Free trie (check for memory leaks using valgrind!)
void trie_destroy (trie_t trie)
{
   // Free nodes, followed by freeing trie_data_t
   trie_destroy_helper (trie->root);
   free (trie);
}

/// Create a new empty trie
trie_t trie_new ()
{
   trie_data_t * n = (trie_data_t *) malloc (sizeof (trie_data_t));
   
   // Allocate root node
   trie_node_t * newn = (trie_node_t *) malloc (sizeof (trie_node_t));
   newn->letter = 0;
   newn->valid_data = false;
   newn->child = NULL;
   newn->sibling = NULL;
   n->root = newn;

   return n;
}

/// Insert a word in the trie if it doesn't already exist. Return a trie_pos_t
/// which can be used by trie_get_value and trie_set_value.
trie_pos_t trie_insert_or_find (trie_t trie, const char * str)
{
   // COMPLETE ME

   // return trie_pos_t pointing to the node that was added
}

/// Get value of a position
void * trie_get_value (trie_t trie, trie_pos_t pos)
{
   // Silence warning and some sanity check
   assert (trie);
   assert (pos);

   return pos->data;
}

/// Set value of a position
void trie_set_value (trie_t trie, trie_pos_t pos, void * value)
{
   // Silence warning and some sanity check
   assert (trie);
   pos->data = value;
}


