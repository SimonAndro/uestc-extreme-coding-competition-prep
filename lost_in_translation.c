
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TEAM{
    int offenseId;
    int defenseId;
    int score;

    int firstcome;

    struct TEAM* winnerNxt;
}TEAM;


int main()
{
    int languages = 0, translators = 0;
    scanf("%d %d",&languages,&translators);
    const int langTotal = languages + 1;
    char* langList[langTotal];

    char english[] = {"English"};
    langList[0] = english;

    char langBuffer[2048] ={0};
    getchar(); // left by scanf
    gets(langBuffer);

    const char s[2] = " ";
    char *token;
    token = strtok(langBuffer, s);

    int i=1;
    while( token != NULL ) {
        langList[i++] = token;
        token = strtok(NULL, s);
    }

    char node1[50] ={0};
    char node2[50] ={0};
    int weight = 0;

    int const transT = translators;
    int translationGraph[transT + 1][transT];


    int transLinks[langTotal][1];
    int transLinkCost[langTotal][transT];
    memset(transLinks,0,sizeof(int)*(langTotal));

    for(int i=0; i<translators;i++)
    {
         scanf("%s %s %d",node1,node2,&weight);
         int node1Index = 0;
         int node2Index = 0;
         int node1flag = 0;
         int node2flag = 0;
         for(int j =0; j<langTotal; j++)
         {
             if(!strcmp(langList[j],node1))
             {
                 node1Index = j;
                 node1flag = 1;

             }

             if(!strcmp(langList[j],node2))
             {
                node2Index = j;
                node2flag = 1;
             }
             if(node1flag && node2flag) break;
         }
         translationGraph[node1Index][transLinks[node1Index][0]++] = node2Index;
         translationGraph[node2Index][transLinks[node2Index][0]++] = node1Index;

         transLinkCost[node1Index][transLinks[node1Index][0]-1] = weight;
         transLinkCost[node2Index][transLinks[node2Index][0]-1] = weight;

    }

    // get minimum cost
    long minCost = 0;
    int directFlag = 0;
    int noFound = 1;
    int fail = 0;
    for(int i=1; i<langTotal; i++)
    {
        directFlag = 0;
        for(int j = 0; j<transLinks[i][0];j++)
        {
             if(translationGraph[i][j] == 0) // check direct translation to english first
             {
                 minCost += transLinkCost[i][j];
                 directFlag = 1;
                 break;
             }
        }

        // continue<--
        if(!directFlag)
        {
            int direct2english_total = transLinks[0][0];
            int tempMinCost = -1;
            for(int j = 0; j<direct2english_total;j++)
            {
                int direct2english = translationGraph[0][j];
                int direct2this_total = transLinks[direct2english][0];
                int tempCost = 0;

                //tempCost = transLinkCost[direct2english][j];
                for(int k=0; k<direct2this_total;k++)
                {
                    if(translationGraph[direct2english][k] == i)
                     {
                         noFound = 0;
                         tempCost += transLinkCost[direct2english][k];
                         if(tempMinCost<0)
                         {
                             tempMinCost = tempCost;
                         }
                         else
                         {
                             if(tempCost < tempMinCost)
                             {
                                 tempMinCost = tempCost;
                             }
                         }
                     }
                }
            }
            if(noFound)
            {
                fail = 1;
                break;
            }
            minCost+=tempMinCost;
        }
    }
    //printf(" minimum cost is %ld\n",minCost);
    if(fail)
    {
        printf("Impossible");
    }
    else
        printf("%ld",minCost);

    // test input
//    for(i=0; i<langTotal; i++)
//    {
//        printf("%s ",langList[i]);
//    }
//    printf("\n");
//
//    for(int i=0; i<langTotal;i++)
//    {
//        printf("%s ->",langList[i]);
//        for(int j =0; j<transLinks[i][0];j++)
//        {
//             printf(" %s (%d)",langList[translationGraph[i][j]],transLinkCost[i][j]);
//        }
//        printf("\n");
//
//    }


    return 0;
}







