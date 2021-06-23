#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int userTotal=0,userLinks=0,patientZeroIndex=0,minutes=0;
    scanf("%d %d %d %d",&userTotal,&userLinks,&patientZeroIndex,&minutes);

    int const userT = userTotal;
    int const linkT = userLinks;
    int userGraph[userT][linkT];

    int userLinkTotal[userT][1];
    memset(userLinkTotal,0,sizeof(int)*userT);

    int node1, node2;
    for(int i=0; i<userLinks; i++)
    {
        scanf("%d %d",&node1,&node2);
        userGraph[node1][userLinkTotal[node1][0]++] = node2;
        userGraph[node2][userLinkTotal[node2][0]++] = node1;
    }


    // test input
    /*
    for(int i=0; i<userTotal; i++)
    {
        printf("user index: %d->links: ",i);
        for(int j=0;j<userLinkTotal[i][0];j++)
        {
            printf("%d ",userGraph[i][j]);
        }
        printf("\n");
    }
    */

    long long unsigned int sqwarkShot[userT][2]; // first col send, second col receive
    memset(sqwarkShot,0,sizeof(long long unsigned int)*userT*2);
    sqwarkShot[patientZeroIndex][0] = 1;

    for(int i = 0; i<minutes; i++)
    {
        for(int user = 0; user<userTotal; user++) //// inject sqwark shots
        {
            for(int j = 0; j<userLinkTotal[user][0]; j++)
            {
                sqwarkShot[userGraph[user][j]][1] += sqwarkShot[user][0]; // inject sqwark shots
            }
        }
        // update shots to give in next minute
        for(int k =0; k<userTotal; k++)
        {
            sqwarkShot[k][0] = sqwarkShot[k][1];
            sqwarkShot[k][1] = 0;
        }
    }

    long long unsigned int total = 0;
    // calculate total squarks
    for(int k =0; k<userTotal; k++)
    {
        total+=sqwarkShot[k][0];
    }

    //printf("total squarks at time %d is %d\n",minutes,total);
    printf("%llu\n",total);
    fflush(stdout);

    return 0;
}


