/*
 
*/
#include <stdio.h>
#include <stdlib.h>
#include "ts.h"


struct wordelement{
    void * word;
    int type;
    wordpos nextword;
    wordpos nextsent;
    wordpos nextpara;
};


wordlist list_new(){
    wordlist newlist = (wordlist)malloc(sizeof(wordpos));
    *newlist=NULL;
    return newlist;
}

wordpos list_append_begin(void * newword, wordlist list, int wordtype){
    wordpos newelement=(wordpos)malloc(sizeof(wordelement));
    newelement->word=newword;
    newelement->type=wordtype;
    newelement->nextword=*list;
    *list=newelement;
    return newelement;
}

void list_give_nextsent(wordpos item, wordlist list, wordpos nextsent){
    item->nextsent=nextsent;
    return;
}

void list_give_nextpara(wordpos item, wordlist list, wordpos nextpara){
    item->nextpara=nextpara;
    return;
}

wordpos list_nextword(wordpos item,wordlist list){
    return item->nextword;
}

wordpos list_nextsent(wordpos item,wordlist list){
    return item->nextsent;
}

wordpos list_nextpara(wordpos item,wordlist list){
    return item->nextpara;
}

void * list_getword (wordpos item, wordlist list){
    return item->word;
}

int list_gettype(wordpos item,wordlist list){
    return item->type;
}


static int deletenode (void * data, wordpos pos)
{
    free (pos);
    return 0;
}

void list_destroy (wordlist list)
{
    // Remove all elements
    list_apply (list, &deletenode);
    
    // Now free head pointer
    free (list);
}

int list_apply (wordlist list, int (* func) (void * p, wordpos pos))
{
    wordpos current = *list;
    while (current)
    {
        // do something
        int ret;
        wordpos previous = current;
        current = list_nextword (current, list);
        if ((ret = func (list_getword (previous, list), previous)))
        {
            return ret;
        }
    }
    return 0;
}













