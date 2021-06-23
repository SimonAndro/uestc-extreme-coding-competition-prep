#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMinCost(int seqList[], int seqSize, int startIndex);
long getGCD(long a, long b) ;


int main()
{
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
        int const seqSize = count;
        int seqList[seqSize];

         get numbers
        int i=0;
        token = strtok(NULL, s);
        while( token != NULL ) {
            seqList[i++] = atoi(token);
            token = strtok(NULL, s);
        }

        /*
         sequence out
        for(int i =0; i<count;i++)
        {
            printf("%d ",seqList[i]);
        }
         printf("\n");
        */

        int minCost = 0;
        for(int i =0; i<count;i++)
        {
            int cost = getMinCost(seqList,count,i);
            if(i == 0)
            {
                minCost = cost;
            }else{
                if(cost<minCost)
                    minCost = cost;
            }
        }

        outBuffer[outCount++] = minCost;

         get next line
        memset(buffer,0,sizeof(buffer));
        gets(buffer);
    }
    for(int i =0; i<outCount; i++)
    {
         printf("%ld\n",outBuffer[i]);
    }

    return 0;
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

     if(cost == 1)
     {
         return cost;
     }

     int const newSeqSize = seqSize-1;
     int newSeq[newSeqSize];
     int f=0;
     for(int i =0; i<seqSize; i++)
     {
         if(i != startIndex)
         {
             newSeq[f++] = seqList[i];
         }

     }

     int minCost  = 0;
     for(int i =0; i<newSeqSize; i++)
     {
         int totalCost = cost + getMinCost(newSeq,newSeqSize,i);
         if(i==0)
         {
             minCost = totalCost;
         }else{
             if(totalCost<minCost)
             {
                 minCost = totalCost;
             }
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
