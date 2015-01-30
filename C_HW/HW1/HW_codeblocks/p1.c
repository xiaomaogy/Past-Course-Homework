#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define LONG_MAX 2147483647L

int is_numeric (char str[])
{
    int i = 0;
    int j = 0;
    
    //i /* note that this is incomplete, doesn't account for multiple '.' */
    
    int dotNum=0;
    //dotNum keep track of number of dots in the argument, if it has more than
    //two dots, then it is not a numeric number
    
    if(str[0] == '0'){
        if(str[1] != '.'){
            return 0;
        }
    }
    
    
    
    while(str[i] != '\0')
    {
        if(!isdigit(str[i])){
            if (str[i] != '.')
                return 0;
            else{
                ++dotNum;
            }

        }
        ++i;
        if (dotNum ==0){
            ++j;
            if (j >= 9 && (str[0]-'0')>1){
                return 2;
            }
        }
    }
    
    if(dotNum<=1){
        return 1;
    }else{
        return 0;
    }
    
    
}

void showBit(int,int);

int main (int argc, char **argv)
{
    if(argv[1] == NULL){
        printf("%s\n", "no string is entered");
    }
    int stat = is_numeric(argv[1]);
    if (stat == 0)
        printf("%s %s\n", argv[1], "is not a numeric value");
    else if(stat == 1)
        printf("%s %s\n", argv[1], "is a numeric value");
    else
        printf("%s %s\n", argv[1], "is too large");
        
    
    
    return EXIT_SUCCESS;
}

