#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *arg=argv[1];

    int input = 0;

    for(int i=0; i<strlen(arg);i++){
        input = input *10;
        input = arg[i]-'0'+input;

    }

    int a = input;

    int temp = a;
    a = a >> 8;
    int temp2 = a << 8;
    int a1 = temp ^ temp2;
    printf("%x\n",a1);

    temp = a;
    a = a >> 8;
    temp2 = a <<8;
    int a2 = temp ^ temp2;
    printf("%x\n",a2);

    temp = a;
    a = a >> 8;
    temp2 = a <<8;
    int a3 = temp ^ temp2;
    printf("%x\n",a3);

    temp = a;
    a = a >> 8;
    temp2 = a <<8;
    int a4 = temp ^ temp2;
    printf("%x\n",a4);

    int output = (a1<<24)+(a2<<16)+(a3<<8)+a4;

    printf("%x\n",output);

    return 0;
}
