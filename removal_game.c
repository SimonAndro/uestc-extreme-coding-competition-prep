#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long getGCD(long a, long b);
long getCost(int seq[], int start,int seqLen);
int main()
{
    int total;
    char buffer[1000] = {0};
    const char s[2] = " ";

    char *token;
    gets(buffer);

    int outCount = 0;
    long outBuffer[1001] = {0};
    while(buffer[0] != '0') // last  character is 0
    {


        token = strtok(buffer, s);

        int count = atoi(token);
        const seqSize = count;
        int seqList[seqSize];

        // get numbers
        int i=0;
        token = strtok(NULL, s);
        while( token != NULL ) {
            seqList[i++] = atoi(token);
            token = strtok(NULL, s);
        }

        /*get all gcd*/
        for(int costIndex=0;costIndex<count; costIndex++)
        {
            long totalCost = 0;
            for(int num = count; num>2; num--)
            {
                 // test out seq
                /* printf("got: ");
                for(int i = 0; i<num; i++)
                {
                    printf("%d ",seqList[i]);
                }
                printf("\n");
                */

                /*
                int cost = 0;
                int costIndex = 0;
                int minCost = 5000; // any large value
                for(int i = 0; i<num; i++)
                {
                    if(i == 0)
                    {
                        cost = getGCD(seqList[i+1],seqList[num-1]);
                    }else if(i == (num-1))
                    {
                        cost = getGCD(seqList[i-1],seqList[0]);
                    }else
                    {
                        cost = getGCD(seqList[i-1],seqList[i+1]);
                    }
                    if(cost<minCost)
                    {
                        minCost = cost;
                        costIndex = i;
                    }
                    //printf("%d ",cost);
                }
                */
               // printf("\n");

                if(costIndex == 0)
                {
                    cost = getGCD(seqList[1],seqList[num-1]);
                }else if(costIndex == (num-1))
                {
                    cost = getGCD(seqList[costIndex-1],seqList[0]);
                }else
                {
                    cost = getGCD(seqList[costIndex-1],seqList[costIndex+1]);
                }

                totalCost += minCost;

                //generate new sequence
                int f =0;
                for(int i=0; i<num; i++)
                {
                    if(i != costIndex)
                    {
                        seqList[f++] = seqList[i];
                    }
                }
            }
        }

        totalCost += getGCD(seqList[0],seqList[1]);
        outBuffer[outCount++] = totalCost;

        /* get next line*/
        memset(buffer,0,sizeof(buffer));
        gets(buffer);
    }
    for(int i =0; i<outCount; i++)
    {
        printf("%ld\n",outBuffer[i]);
    }
    return 0;
}

int getCost(int seq[], int start,int num, int* costIndex)
{
    int cost = 0;
    int minCost = 5000; // any large value
    for(int i = start; i<num; i++)
    {
        if(i == 0)
        {
            cost = getGCD(seqList[i+1],seqList[num-1]);
        }else if(i == (num-1))
        {
            cost = getGCD(seqList[i-1],seqList[0]);
        }else
        {
            cost = getGCD(seqList[i-1],seqList[i+1]);
        }
        if(cost<minCost)
        {
            minCost = cost;
            *costIndex = i;
        }
    }
    return minCost;
}

int calculateTotalCost(int seqList,int seqSize,int startIndex, int runningTotal)
{
    int costTotal = runningTotal;
    if(seqSize == 2)
    {
        return costTotal + getGCD(seqList[0],seqList[1]);
    }

    // get initial cost
    if(startIndex == 0)
    {
        costTotal += getGCD(seqList[1],seqList[seqSize-1]);
    }else if(startIndex == (seqSize-1))
    {
        costTotal += getGCD(seqList[costIndex-1],seqList[0]);
    }else
    {
        costTotal += getGCD(seqList[costIndex-1],seqList[costIndex+1]);
    }

    // get cost for next line
    for(int i=0; i<seqSize; i++)
    {

    }
}

int getMinCost(int seqList[], int seqSize, int startIndex)
{
    int cost = 0;

    if(seqSize == 2)
    {
        return getGCD(seqList[0],seqList[1]);
    }
    if(startIndex == 0)
    {
        cost += getGCD(seqList[1],seqList[seqSize-1]);
    }else if(startIndex == (seqSize-1))
    {
        cost += getGCD(seqList[startIndex-1],seqList[0]);
    }else
    {
        cost += getGCD(seqList[startIndex-1],seqList[startIndex+1]);
    }

    for(int i =startIndex; i<seqSize-1; i++)
    {
        seqList[i] = seqList[i+1]
    }
    seqSize--;

    int minCost  = 5000;
    for(int i =0; i<seqSize; i++)
    {
        cost += getMinCost(seqList,seqSize,i);
        if(cost<minCost)
        {
            minCost = cost;
        }
    }
    return minCost;
}


long getGCD(long a, long b) {
   int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}
