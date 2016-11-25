#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int match(char txt[],char pat[])
{
    int txt_len,pat_len,c,d,e,pos;
    txt_len=strlen(txt);
    pat_len=strlen(pat);
    if(pat_len>txt_len)
    return -1;
    for(c=0;c<=(txt_len-pat_len);c++)
    {
        pos=e=c;
        for(d=0;d<pat_len;d++)
        {
            if(pat[d]==txt[e])
            e++;
            else
            break;
        }
        if(d==pat_len)
        return (pos);
    }
    return -1;
}

int main()
{
    char a[10],b[10];
    int pos;
    printf("Text: ");
    scanf("%s",a);
    printf("Pattern: ");
    scanf("%s",b);
    pos=match(a,b);
    if(pos!=-1)
    printf("String found at location: %d",(pos+1));
    else
    printf("Not found!!");
    return 0;
}

/*Demo Input::
Text: abbbba
Pattern:ba
String foud at location 5*/