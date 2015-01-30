
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    FILE * fp;
    fp = fopen(argv[1],"r");
    
    char Src[]= "\t";
    
    char Dst[]= "  ";
    
    if(fp==NULL){
        printf("cannot open file\n");
        exit(1);
    }
    
    substitute(, , &Src, &Dst);
    
    
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



