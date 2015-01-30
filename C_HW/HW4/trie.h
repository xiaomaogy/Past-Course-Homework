#pragma once

struct trie_data_t;
typedef struct trie_data_t * trie_t;

struct trie_node_t;
typedef struct trie_node_t * trie_pos_t;

/// Analyse contents of trie
void trie_analyze (const trie_t trie);

/// Free trie (check for memory leaks using valgrind!)
void trie_destroy (trie_t trie);

/// Get value of a position
void * trie_get_value (trie_t trie, trie_pos_t pos);

/// Set value of a position
void trie_set_value (trie_t trie, trie_pos_t pos, void * value);

/// Create a new empty trie
trie_t trie_new ();

/// Insert a word in the trie; Return position of new (or existing) node
/// for the given word. For new nodes, set data to NULL.
trie_pos_t trie_insert_or_find (trie_t trie, const char * str);


