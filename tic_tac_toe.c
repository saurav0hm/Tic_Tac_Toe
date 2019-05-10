#include <stdio.h>
#include<stdlib.h>
struct deepak
{   int i;
    char ch;
};
void display(char sym[9])
{
    printf("\t\t\t\t\t Tic Tac Toe");
    printf("\nplayer 1:X");
    printf("\nplayer 2:O");
    printf("\n\t\t\t    |    |    ");
    printf("\n\t\t\t %c  | %c  | %c   ",sym[0],sym[1],sym[2]);
    printf("\n\t\t\t----|----|----");
    printf("\n\t\t\t %c  | %c  | %c   ",sym[3],sym[4],sym[5]);
    printf("\n\t\t\t----|----|----");
    printf("\n\t\t\t %c  | %c  | %c   ",sym[6],sym[7],sym[8]);
    printf("\n\t\t\t    |    |    ");
}
struct deepak inputvalue(char sym[9],int count)
{   int i;
    char value;
    struct deepak info;
    again:
    if(count%2==0)
    {
        printf("enter your choice'X':");
    }else{printf("enter your choice'O':");
        }
        scanf("%s",&value);
        for(i=0;i<9;i++)
        {
        if(value==sym[i])
        {
            info.i=i;
            if(count%2==0)

                info.ch='X';
            else

                info.ch='O';
            break;
        }else{
       info.i=-1;
       info.ch=' ';
               }
        }
               if(info.i==-1)
               {
                   printf("you enter a invalid charecter\n");
                   goto again;
               }

return info;
}
int check(char sym[9],char ch,int count)
{
    int i;
    for(i=0;i<=6;i+=3)
    {if(sym[i]==sym[i+1]&&sym[i+1]==sym[i+2])
    {
        printf("winner is %c",ch);return 1;
    }
    }
  for(i=0;i<3;i++)
   {
       if(sym[i]==sym[i+3]&&sym[i+3]==sym[i+6])
       {
           printf("winner is %c",ch);return 1;
       }
   }
   if(sym[0]==sym[4]&&sym[4]==sym[8])
   {
       printf("winner is %c",ch);return 1;
   }

    else if(sym[2]==sym[4]&&sym[4]==sym[6])
       {
           printf("winner is %c",ch);return 1;
       }
       else if(count==8){
        printf("The GAME is draw");return 1;
       }else return 0;
}
void run()
{int count=0;
struct deepak info;
    char symbol[9]={'1','2','3','4','5','6','7','8','9'};
    display(symbol);
    fan:
    info=inputvalue(symbol,count);
    symbol[info.i]=info.ch;
    system("cls");
    display(symbol);
    if(check(symbol,info.ch,count)==1);
    else{
    count++;
    goto fan;
    }

}

int main()
{char restart;
    New:
    run();
    printf("\nIf you want to play again press 1:\nElse any :");
    scanf("%s",&restart);
    if(restart=='1')
    {
        system("cls");
        goto New;
    }else
    exit(0);
    return 0;
}

