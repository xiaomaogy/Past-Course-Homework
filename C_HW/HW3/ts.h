//
//  ts.h
//  c.hw3a
//
//  Created by yuan gao on 11/22/14.
//  Copyright (c) 2014 yuan gao. All rights reserved.
//

#ifndef __c_hw3a__ts__
#define __c_hw3a__ts__

#include <stdio.h>

struct wordelement;

typedef struct wordelement wordelement;

typedef struct wordhead wordhead;

typedef wordelement * * wordlist;

typedef wordelement * wordpos;




//create a new word list
wordlist list_new();


//destroy a wordlist
void list_destroy(wordlist list);

// Add new item at the beginning of the list
wordpos list_append_begin (void * newword, wordlist list, int wordtype);

// Add new item at the end of the list
wordpos list_append_end(void * newword, wordlist list, int wordtype);

// give the item its nextsent position
void list_give_nextsent(wordpos item, wordlist list, wordpos nextsent);

//give the item its nextpara position
void list_give_nextpara(wordpos item, wordlist list, wordpos nextpara);

/// Get next word in the list
wordpos list_nextword (wordpos item, wordlist list);


/// Get next sentence pos in the list
wordpos list_nextsent (wordpos item, wordlist list);


/// Get next paragraph pos in the list
wordpos list_nextpara (wordpos item, wordlist list);

// Get value at specified position
void * list_getword (wordpos item, wordlist list);

// Get the word's type
int list_gettype(wordpos item,wordlist list);

// Takes a pointer to a function. The function needs to return non-zero or zero.
// If zero, keep iterating over the list. Else, stop and return value.
// The function takes one argument: void * , representing each data elements of
// the list.
//
// The function is not allowed to modify the list.
int list_apply (wordlist list, int (* func) (void * p, wordpos pos));

void list_destroy (wordlist list);


















#endif /* defined(__c_hw3a__ts__) */
