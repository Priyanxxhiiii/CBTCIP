#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=0,words=0,newline=0,characters=0;
    char str[1000];
    FILE *fp=NULL,*fp1=NULL;
    fp=fopen("Word.txt","w");
    if(fp==NULL)
    {
        printf("File not created.");
    }
    else
    {
        printf("Enter a string of upto 1000 character and press '~' and hit enter to subbmit!\n");
        scanf("%[^~]",&str);
        while(str[i]!='\0')
        {
            fputc(str[i],fp);
            i++;
        }
        fclose(fp);
    }
    fp1=fopen("Word.txt","r");
    if(fp1==NULL)
    {
        printf("File not created.");
    }
    else
    {
        do
        {
            str[i]=fgetc(fp1);
            if(str[i]== ' ')
            {
                words++;
            }
            else if(str[i]=='\n')
            {
                newline++;
                words++;
            }
            else if(str[i]!=' '&&str[i]!='\n')
            {
                characters++;
            }
         }
        while (str[i]!=EOF);
        if(characters>0)
        {
            words++;
            newline++;
        }
        printf("\nTotal number of words:%d\n",words);
        printf("Total number of lines:%d\n",newline);
        printf("Total number of characters:%d\n",characters);
    }
    fclose(fp1);
    return 0;
}