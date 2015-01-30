#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hasRepeat(char *word, int size);

int main(int argc, char * argv[])
{
    printf("getting here\n");
    FILE * fp;

    fp = fopen(argv[1],"r");
    int i=0;
    int j=0;
    int k=0;
    char ch;

    char temp[20];
    char wordList[100][20];
    int wordCount[100];
    memset(wordCount,0,100*sizeof(int));

    while (1)
    {
        do
        {
            ch=fgetc(fp);
            if(ch=='\n'||ch==' '||ch==EOF)
            {
                break;
            }
            temp[k++]=ch;
        }
        while(1);
        temp[k]=0;

        if(hasRepeat(temp, strlen(temp))==0)
        {
            k=0;
            if(ch==EOF)
                break;
            continue;
        }

        if(i==0)
        {
            strcpy(wordList[i],temp);
            wordCount[i]++;
            i++;
        }
        else
        {
            for(j=0; j<i; j++)
            {
                if(strcmp(wordList[j],temp)==0)
                {
                    wordCount[j]++;
                    break;
                }
            }
            if(j==i)
            {
                strcpy(wordList[i],temp);
                wordCount[i]++;
                i++;
            }
        }

        k=0;

        if(ch==EOF)
            break;
    }

    int l=0;

    while (l<i)
    {
        if(wordCount[l]!=0)
        {
            printf("%s : %d\n", wordList[l],wordCount[l]);
        }
        l++;
    }

    return 0;
}

int hasRepeat(char *word, int size)
{
    char temp[2]=" ";
    for(int i=0; i<size-1; i++)
    {
        temp[0]=word[i];
        if(strstr(word+i+1,temp))
        {
            return 1;
        }
    }

    return 0;


}
