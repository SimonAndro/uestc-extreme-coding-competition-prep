#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct GLASS{
    int x;
    int y;
    int z;

    int r;
    int v;
}GLASS;


int main()
{
    int glassTotal = 0;
    scanf("%d",&glassTotal);

    int const glassArraySize = glassTotal;
    GLASS glassArray[glassArraySize];
    int x,y,z,r,v;
    for(int i=0; i<glassTotal;i++)
    {
        scanf("%d %d %d %d %d",&x,&y,&z,&r,&v);
        glassArray[i].x = x;
        glassArray[i].y = y;
        glassArray[i].z = z;
        glassArray[i].r = r;
        glassArray[i].v = v;
    }

    // test input
    /*
    printf("got glasses \n");
    for(int i=0; i<glassTotal;i++)
    {
        printf("x:%d y:%d z:%d r:%d v:%d\n",
            glassArray[i].x,
            glassArray[i].y,
            glassArray[i].z,
            glassArray[i].r,
            glassArray[i].v
        );
    }
    */

    double rate = 100;
    for(int i=0; i<glassTotal; i++)
    {
        GLASS glass = glassArray[i];
        for(int j=0; j<glassTotal; j++)
        {

        }
    }

    return 0;
}
