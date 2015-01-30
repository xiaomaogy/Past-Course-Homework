#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int atoi2(char str[]);

int main(int argc, char * argv[])
{

}

int atoi2 (char str[])
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

