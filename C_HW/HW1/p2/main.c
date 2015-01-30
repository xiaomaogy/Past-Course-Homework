#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void substitute(char *pInput, char *pOutput, char *pSrc, char *pDst);
int main(int argc, const char * argv[]) {

    FILE * fp;
    fp = fopen(argv[1],"r");

    char Src[]= "\t";

    char Dst[]= "  ";

    char input[10000];
    char output[10000];

    char ch;

    int i=0;
    int j=0;

    if(fp==NULL){
        printf("cannot open file\n");
        exit(1);
    }

    while((ch=fgetc(fp))!=EOF){
        input[i++] = ch;
    }
    input[i]=0;
    substitute(input,output, Src, Dst);

    printf("%s\n\n",output);

    while(output[j]!=0)
        printf("%c",output[j++]);

    printf("\n");


    return 0;
}

void substitute(char *pInput, char *pOutput, char *pSrc, char *pDst){
    char *pi, *po, *p;
    int nScrLen; int nDstLen; int nLen;

    pi = pInput;
    po = pOutput;

    nScrLen = strlen(pSrc);
    nDstLen = strlen(pDst);

    p = strstr(pi, pSrc);

    while (p){
        nLen = (int) (p-pi);
        memcpy(po,pi,nLen);
        memcpy(po+nLen, pDst, nDstLen);

        pi = p+nScrLen;
        po = po+nLen+nDstLen;
        p = strstr(pi, pSrc);
    }
}



