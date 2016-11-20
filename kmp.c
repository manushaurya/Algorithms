#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int kmp(char substr[],char str[])
{
    int n,m,i,j;
    n=strlen(str);
    m=strlen(substr);
    int *d=(int *)malloc(m*sizeof(int));
    d[0]=0;
    for(i=0,j=0;i<m;i++)
    {
        while(j>0 && substr[j]!=substr[i])
        {
            j=d[j]-1;
        }
        if(substr[j]==substr[i])
        {
            j++;
            d[i]=j;
        }
    }
    for(i=0,j=0;i<n;i++)
    {
        while(j<0 && substr[j]!=str[i])
        {
            j=d[j]-1;
        }
        if(substr[j]==str[i])
            j++;
        if(j==m)
            {free(d);
         return (i-j+1); }
    }
    free(d);
    return -1;
}

int main()
{
    char str[20],substr[20];
    int pos;
    printf("Enter the string: ");
    gets(str);
    printf("Enter the sub-string: ");
    gets(substr);
    pos=kmp(substr,str);
    if(pos!=-1)
        printf("Position starts at %d\n",(pos+1));
    else
        printf("Match not found!!!\n");
    return 0;

}
