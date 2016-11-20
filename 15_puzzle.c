#include <stdio.h>
#include <stdlib.h>

int table[20][20],i,j,temp;
void movedown()
{
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(table[i][j]==0 && i!=0)
            {
                temp=table[i-1][j];
                table[i-1][j]=0;
                table[i][j]=temp;
            }
        }
    }
}

void moveright()
{
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(table[i][j]==0 && j!=0)
            {
                temp=table[i][j-1];
                table[i][j-1]=0;
                table[i][j]=temp;
            }
        }
    }
}

void moveleft()
{
    for(i=3;i>=0;i--)
    {
        for(j=3;j>=0;j--)
        {
            if(table[i][j]==0 && j!=3)
            {
                temp=table[i][j+1];
                table[i][j+1]=0;
                table[i][j]=temp;
            }
        }
    }
}

void moveup()
{
    for(i=3;i>=0;i--)
    {
        for(j=3;j>=0;j--)
        {
            if(table[i][j]==0 && i!=3)
            {
                temp=table[i+1][j];
                table[i+1][j]=0;
                table[i][j]=temp;
            }
        }
    }
}

int checkforfinish()
{
    int result=0;
    temp=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(table[i][j]==temp)
            temp=temp+1;
        }
    }
    if(temp==16)
    result=1;

    return result;
}

void displaytable()
{
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(table[i][j]==0)
                printf(" ");
            else
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

}

void movenumbers()
{
    char key;
    int s;
    do
    {
        printf("Enter the key:\n\tMoveup-->u\n\tMovedown-->d\n\tMoveleft-->l\n\tMoveright-->r\n\tCheckForFinish-->c\n\tExit-->e\n");
        scanf("%s",&key);
        switch(key)
        {
            case 'l':moveleft();
            displaytable();
            break;

            case 'r' :moveright();
            displaytable();
            break;

            case 'u' :moveup();
            displaytable();
            break;

            case 'd' :movedown();
            displaytable();
            break;

            case 'c' : s=checkforfinish();
            if(s==1)
            printf("Game completed successfully.\n");
            else
            printf("Continue with move...");
            movenumbers();
            break;

            case 'e' :exit(1);
        }
    } while(1);
}

void ownsetup()
{
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&table[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
        movenumbers();
    }
    for(j=0;j<4;j++)
        {
         displaytable();
        }
}

int main()
{
    ownsetup();
    return 0;
}
/*inputs*/
/*
1 2  3 4
5 6 7 0
9 10 11 8
13 14 15 12
l->u->u*/
