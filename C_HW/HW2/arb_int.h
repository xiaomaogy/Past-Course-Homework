//
//  arb_int.h
//  arb_int
//
//  Created by yuan gao on 10/31/14.
//  Copyright (c) 2014 yuan gao. All rights reserved.
//

#ifndef __arb_int__arb_int__
#define __arb_int__arb_int__

#include <stdio.h>
typedef char** arb_int_t;


void arb_free(arb_int_t i);

arb_int_t arb_duplicate(const arb_int_t i);


int arb_from_string (arb_int_t *i, const char* s);


int arb_from_int (arb_int_t * i, signed long int source);


int arb_to_string (const arb_int_t i, char * buf, size_t max);


//long arb_to_int(const arb_int_t i);

int arb_to_int (const arb_int_t i, long int * out);

void arb_add (arb_int_t x, const arb_int_t y);
void arb_add_aux (arb_int_t x, const arb_int_t y);


void arb_subtract (arb_int_t x, const arb_int_t y);
void arb_subtract_aux (arb_int_t x, const arb_int_t y);

void arb_multiply (arb_int_t x, const arb_int_t y);
void arb_multiply_aux (arb_int_t x, const arb_int_t y);


int arb_compare(arb_int_t x,arb_int_t y);




#endif /* defined(__arb_int__arb_int__) */
