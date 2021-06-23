#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PEG
{
    int disks[50];
    int diskTotal;
} PEG;

int main()
{
    PEG firstPeg = {0};
    PEG secongPeg = {0};
    PEG thirdPeg = {0};


    int count;
    for(int i=0; i<3; i++)
    {
        scanf("%d",&count);
        switch(i)
        {
        case 0:
            firstPeg.diskTotal = count;
            break;
        case 1:
            secongPeg.diskTotal = count;
            break;
        case 2:
            thirdPeg.diskTotal = count;
            break;
        }
        for(int j=0; j<count; j++)
        {
            switch(i)
            {
            case 0:
                scanf("%d",&firstPeg.disks[j]);
                break;
            case 1:
                scanf("%d",&secongPeg.disks[j]);
                break;
            case 2:
                scanf("%d",&thirdPeg.disks[j]);
                break;
            }

        }
    }

    //test output
    for(int i=0; i<3; i++)
    {
        switch(i)
        {
        case 0:
            printf("first peg: ");
            for(int j=0; j<firstPeg.diskTotal; j++)
            {
                printf("%d ",firstPeg.disks[j]);
            }
            break;
        case 1:
            printf("second peg: ");
             for(int j=0; j<secongPeg.diskTotal; j++)
            {
                printf("%d ",secongPeg.disks[j]);
            }
            break;
        case 2:
            printf("third peg: ");
            for(int j=0; j<thirdPeg.diskTotal; j++)
            {
                printf("%d ",thirdPeg.disks[j]);
            }
            break;
        }
        printf("\n");

    }
    return 0;
}
