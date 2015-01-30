#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    // insert code here...
    double test[100];
    FILE * fp;
    char *widthstr=argv[2];

    int width = atoi(widthstr);

    fp = fopen(argv[1], "r");
    memset(test, '0', 100*sizeof(double));
    double *win = (double *)malloc(width*sizeof(double));
    memset(win, 0.0, width*sizeof(double));

    int i=0;    //index for num of float
    int j=0;    //index for float array test
    int k=0;    //index for each float
    char ch;
    char temp[20];
    while(1){

        do{
            ch=fgetc(fp);
            if(ch == '\n' || ch == ' ' || ch == EOF){
                break;
            }
            temp[k++]=ch;
        }
        while(1);
        temp[k]=0;

        test[j++] = atof(temp);

        k=0;

        if(ch==EOF){
            break;
        }
    }

    for(i=0;i<j;i++){
        printf("%lf ", test[i]);
    }

    printf("\n");

    double padded[120];
    memset(padded,'0',120*sizeof(double));
    double avg;
    double sum;



    memcpy(padded+width, test, 110*sizeof(double));



    for(i=width;i<j+width;i++){

        for(k=0;k<width;k++){
            sum=sum+padded[i-k];
        }
        avg = sum/width;
        sum=0;
        printf("%lf ", avg);
    }

    return 0;
}
