
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int trayLength = 0,holes=0;
    int depth = 3;
    int tray1Width = 1;
    int tray2Width = 2;

    //scanf("%d %d",&trayLength,&holes);

    //printf("trayLength %d, holes %d\n",trayLength,holes);

    long ways = 0;
    /*
    for(int i=1; i<=trayLength;i++)
    {
        for(int j =1; j<=3; j++)
        {
            if(i*j%tray1Width != 0)
            {
                if(i*j%tray2Width != 0)
                {
                    continue;b
                }
            }
        }
        ways+=1;
    }*/
    for(int x=0; x<=14; x++)
    {
        for(int y=0; y<=14; y++)
        {
            /*
            if((4*x + 6*y)<=14)
            {
                ways++;
            }*/
            if((x + 2*y)==12)
            {
                ways++;
            }
        }
    }

    printf("ways %ld",ways);
    return 0;
}
