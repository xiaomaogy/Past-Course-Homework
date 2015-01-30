#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *s="Golden Global View";
    char *l="lob";
    char *p;


    p=strstr(s,l);
    if(p)
        printf("%s/n",p);
    else
        printf("Not Found!");

    return 0;
}
