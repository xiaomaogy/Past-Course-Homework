//
//  main.c
//  arb_int
//
//  Created by yuan gao on 10/31/14.
//  Copyright (c) 2014 yuan gao. All rights reserved.
//
/*typedef char* arb_int_t;
void arb_free(arb_int_t i);
arb_int_t arb_duplicate(const arb_int_t i);
int arb_from_string (arb_int_t *i, const char* s);
int arb_from_int (arb_int_t * i, signed long int source);
int arb_to_string (const arb_int_t i, char * buf, size_t max);
long arb_to_int(const arb_int_t i);
 void arb_add (arb_int_t x, const arb_int_t y)*/



#include <stdio.h>
#include <string.h>
#include "arb_int.h"
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char * argv[]) {
    
    if(!argv[1]){
        printf("no argument was entered\n");
        printf("Begin self test\n");
        
        arb_int_t a;
        arb_int_t b;
        arb_int_t c;
        arb_int_t d;
        arb_int_t e;
        arb_int_t f;
        
        arb_from_string(&a,"123");
        arb_from_string(&b,"321");
        arb_from_string(&c,"444");
        
        f = arb_duplicate(a);
        
        arb_add(f,b);
        
        
        
        
        if(arb_compare(f,c)==0){
            printf("add function is good\n");
        }
        
        arb_from_string(&a,"123");
        arb_from_string(&b,"321");
        arb_from_string(&d,"-198");
        
        arb_subtract(a,b);
        
        if(arb_compare(a,d)==0){
            printf("subtract function is good\n");
        }
        
        arb_from_string(&a,"123");
        arb_from_string(&b,"321");
        arb_from_string(&e,"39483");
        
        arb_multiply(a,b);
        
        if(arb_compare(a,e)==0){
            printf("multiply function is good\n");
        }
        
        arb_free(a);
        arb_free(b);
        arb_free(c);
        arb_free(d);
        arb_free(e);
        arb_free(f);
        
        return 0;
    }
    else if(!argv[2] || !argv[3]){
        fprintf(stderr,"Instruction: use the format of [integer] [operation] [integer] to calculate the sum,subtraction,multiplication of two integers\n");
        fprintf(stderr,"Operation include +,-,*.\n");
        fprintf(stderr,"Integer can be negative, which is shown by a '-' symbol. \n");
        return EXIT_FAILURE;
        
    }
    else{
        arb_int_t a;
        arb_int_t b;
        arb_from_string(&a,argv[1]);
        arb_from_string(&b,argv[3]);
        int i=0;
        
        int j=0;
        
        if(argv[2][0]!='+' && argv[2][0]!='-' && argv[2][0]!='*'){
            fprintf(stderr,"Error:Invalid operation");
            return EXIT_FAILURE;
        }
        
        
        while(argv[1][i]){
            if(!isdigit(argv[1][i])){
                if(i==0 && argv[1][i]=='-'){
                    i++;
                    continue;
                }else{
                    fprintf(stderr,"Error:First number invalid");
                    return EXIT_FAILURE;
                }
            }
            i++;
        }
        
        while(argv[3][j]){
            if(!isdigit(argv[3][j])){
                if(j==0 && argv[3][j]=='-'){
                    j++;
                    continue;
                }else{
                    fprintf(stderr,"Error:Second number invalid");
                    return EXIT_FAILURE;
                }
            }
            j++;
        }
        
        
        
        if(argv[2][0]=='+'){
            arb_add(a,b);
            printf("%s",*a);
            return EXIT_SUCCESS;
        }
        
        if(argv[2][0]=='-'){
            arb_subtract(a,b);
            printf("%s",*a);
            return EXIT_SUCCESS;
            
        }
        
        if(argv[2][0]=='*'){
            arb_multiply(a,b);
            printf("%s",*a);
            return EXIT_SUCCESS;
        }
        
        fprintf(stderr,"Instruction: use the format of [integer] [operation] [integer] to calculate add,subtract,multiply\n");
        fprintf(stderr,"integer can be negative, which is shown by a '-' symbol, operation include +,-,*.\n");
        return EXIT_FAILURE;

    }
    
    
    
    
    
    return 0;
}

