//
//  main.c
//  p8
//
//  Created by yuan gao on 10/25/14.
//  Copyright (c) 2014 yuan gao. All rights reserved.
//

#include <stdio.h>

void toBit(size_t, void *);

int main(int argv, char* argc[])
{
    
    float f = 2.45f;
    toBit(sizeof(f), &f);
    return 0;
}

void toBit(size_t size, void *ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}



