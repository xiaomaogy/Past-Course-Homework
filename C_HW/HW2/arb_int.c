
#include "arb_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Free arb_int_t
void arb_free(arb_int_t i){
    if(i){
        if(*i)
            free(*i);
        free(i);
    }
    return;
}


// Duplicate arb_int_t. The returned arb_int_t needs to be freed
// using arb_free.
arb_int_t arb_duplicate(const arb_int_t i){
    int len = (int)strlen(*i);
    arb_int_t j=(arb_int_t)malloc(sizeof(char *));
    *j= (char *)malloc((len+1)*sizeof(char));
    memcpy(*j,*i,strlen(*i));
    (*j)[len]=0;
    arb_free(i);
    return j;
}


// Convert from string representation into arb_int_t.
// Return non-zero and set *i to the new arb_int_t if successful,
// do not change *i and return zero otherwise.
int arb_from_string (arb_int_t *i, const char* s){
    int j=0;
    
    //If string s does not exist, return 0
    if(s==NULL){
        return 0;
    }
    
    //If string s contain a non digit number, return 0
    while(s[j]!=0){
        if(!isdigit(s[j])){
            if(j==0 && s[j]=='-'){
                j++;
                continue;
            }else{
                return 0;
            }
        }
        j++;
    }
    
    //If string s is valid, store it into where arb_int_t is pointing to
    *i=(arb_int_t)malloc(sizeof(char *));
    *(*i)=(char *)malloc((strlen(s)+100)*sizeof(char));
    memset(**i,'\0',strlen(s)+100);
    memcpy(*(*i),s,strlen(s));
    return (int)strlen(s);
}


// Convert from long int to arb_int_t
//   Return non-zero on success, zero otherwise.
int arb_from_int (arb_int_t * i, signed long int source){
    char buf[2000];
    int fail = sprintf(buf,"%ld",source);
    
    if(fail==(-1)){
        return 0;
    }
    
    
    //*i = (arb_int_t)malloc(sizeof(char *));
    //**i=(char *)malloc((strlen(buf)+1)*sizeof(char));
    memset(**i,'\0',strlen(buf)+1);
    memcpy(**i,buf,strlen(buf));
    
    return 1;
}


// Convert arb_int_t to string
//  Return non-zero on success, or zero if buf is not big enough.
//  Make sure buf is always properly zero-terminated.
int arb_to_string (const arb_int_t i, char * buf, size_t max){
    if(strlen(*i)>max){
        return 0;
    }
    else{
        strcpy(buf,*i);
        return 1;
    }
}



// Convert arb_int_t to long int
// long arb_to_int (const arb_int_t i);
// If out of range, the function will return 0;

/*long arb_to_int(const arb_int_t i){
 char buf[20];
 
 arb_to_string(i,buf,11);
 
 return atol(buf);
 }*/

// Convert arb_int_t to long int
//   Return non-zero on success, zero otherwise.
int arb_to_int (const arb_int_t i, long int * out){
    int l=0;
    int j=0;
    int k=0;
    
    char bufs[100];
    char temp[9];
    
    arb_to_string(i,bufs,100);
    
    
    
    for(l =0; l*8+j< strlen(bufs);l++){
        if(l*8<strlen(bufs)){
            strncpy(temp, bufs+l*8,8);
            out[k++]=atol(temp);
        }
        else{
            j=(int)strlen(bufs)-8*l;
            strncpy(temp,bufs+l*8,j);
            out[k++]=atol(temp);
        }
    }
    
    return 1;
    
}


//if x>y return 1, if x<y return -1, if x==y return 0;
int arb_compare(arb_int_t x,arb_int_t y){
    if(strlen(*x)>strlen(*y)){
        return 1;
    }else if(strlen(*x)<strlen(*y)){
        return -1;
    }else{
        int i=0;
        for(i=0;i<strlen(*x);i++){
            if((*x)[i]>(*y)[i]){
                return 1;
            }else if((*x)[i]<(*y)[i]){
                return -1;
            }
        }
    }
    return 0;
}





// Add one arb_int_t to another one, modifying one of them.
// (x += y)
//add function only deal with cases where x and y are both positive
void arb_add (arb_int_t x, const arb_int_t y){
    char * add1=(char *)malloc((strlen(*x)+1)*sizeof(char));
    memset(add1,'\0',(strlen(*x)+1)*sizeof(char));
    char * add2=(char *)malloc((strlen(*x)+1)*sizeof(char));
    memset(add1,'\0',(strlen(*y)+1)*sizeof(char));
    
    if(**x=='-'){
        if(**y=='-'){
            strcpy(add1,*x+1);
            strcpy(add2,*y+1);
            arb_add_aux(&add1,&add2);
            (*x)[0]='-';
            strcpy(*x+1,add1);
            
        }
        else{
            strcpy(add1,*x+1);
            strcpy(add2,*y);
            arb_subtract_aux(&add2,&add1);
            strcpy(*x,add2);
            
        }
    }
    else{
        if(**y=='-'){
            strcpy(add1,*x);
            strcpy(add2,*y+1);
            arb_subtract_aux(&add1,&add2);
            strcpy(*x,add1);
            
        }
        else{
            strcpy(add1,*x);
            strcpy(add2,*y);
            arb_add_aux(&add1,&add2);
            strcpy(*x,add1);
            
        }
    }
    
    free(add1);
    free(add2);
    return;
    
    
}


void arb_add_aux (arb_int_t x, const arb_int_t y){
    int i;
    int j;
    
    int maxLen = (int)(strlen(*x)>strlen(*y)?strlen(*x):strlen(*y));
    char * temp1=(char *)malloc(100*sizeof(char));
    char * temp2=(char *)malloc(100*sizeof(char));
    char * temp3=(char *)malloc(100*sizeof(char));
    char * temp4=(char *)malloc(100*sizeof(char));
    
    memset(temp1,'\0',(strlen(*x)*2+1)*sizeof(char));
    memset(temp2,'\0',(strlen(*y)*2+1)*sizeof(char));
    memset(temp3,'\0',((maxLen*2)+1)*sizeof(char));
    memset(temp4,'\0',((maxLen*2)+1)*sizeof(char));
    
    
    
    for(i=0;i<strlen(*x);i++){
        temp1[strlen(*x)-1-i] = (*x)[i];
    }
    
    
    for(j=0;j<strlen(*y);j++){
        temp2[strlen(*y)-1-j] = (*y)[j];
    }
    
    
    int add=0;
    i=0;
    
    for (i=0;i<maxLen;i++){
        int add1=temp1[i]-'0';
        int add2=temp2[i]-'0';
        int sum;
        
        
        if(i<strlen(*x) && i>=strlen(*y)){
            
            if(add1+add>9){
                sum = add1+add-10;
                add =1;
            }else{
                sum = add1+add;
                add=0;
            }
            
        }
        
        if(i<strlen(*y) && i>=strlen(*x)){
            if(add1+add>9){
                sum = add2+add-10;
                add =1;
            }else{
                sum = add2+add;
                add=0;
            }
        }
        
        if(i<strlen(*y) && i<strlen(*x)){
            
            if((add1+add2+add) > 9){
                sum=add1+add2+add-10;
                add = 1;
            }else{
                sum=add1+add2+add;
                add =0;
            }
            
        }
        
        temp3[i]=(char)('0'+sum);
    }
    
    temp3[i]='\0';
    
    for(i=0;i<strlen(temp3);i++){
        temp4[strlen(temp3)-1-i] = temp3[i];
    }
    
    *x=(char *)malloc(100*sizeof(char));
    memset(*x,'\0',(strlen(temp4)*2+1)*sizeof(char));
    
    temp4[i]='\0';
    
    strcpy(*x,temp4);
    
    free(temp1);
    free(temp2);
    free(temp3);
    free(temp4);
}



// Subtract an arb_int_t from another.
// (x -= y);
//add function only deal with x and y are both positive
void arb_subtract(arb_int_t x, const arb_int_t y){
    char * add1=(char *)malloc((strlen(*x)+1)*sizeof(char));
    memset(add1,'\0',(strlen(*x)+1)*sizeof(char));
    char * add2=(char *)malloc((strlen(*x)+1)*sizeof(char));
    memset(add1,'\0',(strlen(*y)+1)*sizeof(char));
    
    if(**x=='-'){
        if(**y=='-'){
            strcpy(add1,*x+1);
            strcpy(add2,*y+1);
            arb_subtract_aux(&add2,&add1);
            strcpy(*x,add2);
        }
        else{
            strcpy(add1,*x+1);
            strcpy(add2,*y);
            arb_add_aux(&add1,&add2);
            (*x)[0]='-';
            strcpy(*x+1,add1);
        }
    }
    else{
        if(**y=='-'){
            strcpy(add1,*x);
            strcpy(add2,*y+1);
            arb_add_aux(&add1,&add2);
            strcpy(*x,add1);
        }
        else{
            strcpy(add1,*x);
            strcpy(add2,*y);
            arb_subtract_aux(&add1,&add2);
            strcpy(*x,add1);
        }
    }
    
    free(add1);
    free(add2);
    return;
}

void arb_subtract_aux(arb_int_t x, const arb_int_t y){
    int maxLen = (int)(strlen(*x)>strlen(*y)?strlen(*x):strlen(*y));
    int neg=0;
    int i;
    char * larger;
    char * smaller;
    
    
    char * revResult=(char *)malloc((maxLen+1)*sizeof(char));
    memset(revResult,'\0',(maxLen+1)*sizeof(char));
    char * Result=(char *)malloc((maxLen+1)*sizeof(char));
    memset(Result,'\0',(maxLen+1)*sizeof(char));
    
    
    if(arb_compare(x,y)==1){
        neg=1;
        larger=(char *)malloc((strlen(*x)+1)*sizeof(char));
        memset(larger,'\0',(strlen(*x)+1)*sizeof(char));
        smaller=(char *)malloc((strlen(*y)+1)*sizeof(char));
        memset(smaller,'\0',(strlen(*x)+1)*sizeof(char));
        
        for(i=0;i<strlen(*x);i++){
            larger[strlen(*x)-1-i] = (*x)[i];
        }
        for(i=0;i<strlen(*y);i++){
            smaller[strlen(*y)-1-i] = (*y)[i];
        }
    }else if(arb_compare(x,y)==-1){
        neg=-1;
        larger=(char *)malloc(strlen(*y)*sizeof(char));
        memset(larger,'\0',(strlen(*x)+1)*sizeof(char));
        smaller=(char *)malloc(strlen(*x)*sizeof(char));
        memset(larger,'\0',(strlen(*x)+1)*sizeof(char));
        for(i=0;i<strlen(*y);i++){
            larger[strlen(*y)-1-i] = (*y)[i];
        }
        for(i=0;i<strlen(*x);i++){
            smaller[strlen(*x)-1-i] = (*x)[i];
        }
    }else{
        (*x)[0]='0';
        (*x)[1]='\0';
        return;
    }
    
    int sub =0;
    
    for(i=0;i<maxLen;i++){
        int largerInt=larger[i]-'0';
        int smallerInt=smaller[i]-'0';
        int subres=0;
        
        if(i<strlen(larger) && i>=strlen(smaller)){
            
            if(largerInt-sub<0){
                subres = 10+largerInt-sub;
                sub=1;
            }else{
                subres = largerInt-sub;
                sub=0;
            }
        }
        
        
        if(i<strlen(*y) && i<strlen(*x)){
            
            if((largerInt-smallerInt-sub) < 0){
                subres=10+largerInt-smallerInt-sub;
                sub=1;
            }else{
                subres=largerInt-smallerInt-sub;
                sub =0;
            }
            
        }
        
        revResult[i]=(char)('0'+subres);
    }
    
    revResult[i]='\0';
    
    for(i=i-1;i>0;i--){
        if(revResult[i]!='0')
            break;
    }
    int j=0;
    for(;i>=0;i--){
        Result[j++] = revResult[i];
    }
    
    Result[j]='\0';
    
    
    
    
    if(neg == -1){
        (*x)[0]='-';
        strcpy((*x)+1,Result);
    }else if(neg == 1){
        strcpy((*x),Result);
    }else{
        printf("neg error");
    }
    
    
    free(larger);
    free(smaller);
    free(revResult);
    free(Result);
    
}


// Multiply
// x *= y

void arb_multiply (arb_int_t x, const arb_int_t y){
    char * add1=(char *)malloc((strlen(*x)+1)*sizeof(char));
    memset(add1,'\0',(strlen(*x)+1)*sizeof(char));
    char * add2=(char *)malloc((strlen(*x)+1)*sizeof(char));
    memset(add1,'\0',(strlen(*y)+1)*sizeof(char));
    
    if(**x=='-'){
        if(**y=='-'){
            strcpy(add1,*x+1);
            strcpy(add2,*y+1);
            arb_multiply_aux(&add1,&add2);
            strcpy(*x,add1);
        }
        else{
            strcpy(add1,*x+1);
            strcpy(add2,*y);
            arb_multiply_aux(&add1,&add2);
            (*x)[0]='-';
            strcpy(*x+1,add1);
        }
    }
    else{
        if(**y=='-'){
            strcpy(add1,*x);
            strcpy(add2,*y+1);
            arb_multiply_aux(&add1,&add2);
            (*x)[0]='-';
            strcpy(*x+1,add1);
        }
        else{
            strcpy(add1,*x);
            strcpy(add2,*y);
            arb_multiply_aux(&add1,&add2);
            strcpy(*x,add1);
        }
    }
    free(add1);
    free(add2);
    return;
    
}

void arb_multiply_aux (arb_int_t x, const arb_int_t y){
    int a = (int)strlen(*x);
    int b = (int)strlen(*y);
    
    arb_int_t sum;
    arb_from_string(&sum,"0");
    
    arb_int_t result;
    arb_from_string(&result,"0");
    
    int multi =0;
    int d = 0;
    
    int i;
    int j;
    int k;
    
    for(j=b-1;j>=0;j--){
        for(i=a-1;i>=0;i--){
            multi=((*x)[i]-'0') * ((*y)[j]-'0');
            
            if(multi>9){
                d = 1;
            }else{
                d = 0;
            }
            arb_from_int(&result,multi);
            if(multi!=0){
                for(k=0;k<a-1-i+b-1-j;k++){
                    if(d==1){
                        (*result)[2+k]='0';
                        (*result)[3+k]='\0';
                    }else if(d==0){
                        (*result)[1+k]='0';
                        (*result)[2+k]='\0';
                    }
                }
                if(d==1){
                    (*result)[2+k]='\0';
                }else if(d==0){
                    (*result)[1+k]='\0';
                }}
            
            arb_add_aux(sum,result);
        }
    }
    *x=(char *)malloc((strlen(*sum)+1)*sizeof(char));
    memset(*x,'\0',(strlen(*sum)+1)*sizeof(char));
    strcpy(*x,*sum);
    
    return;
    
}



















