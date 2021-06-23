 int getMinCost(int seqList[], int seqSize, int startIndex);
 long getGCD(long a, long b) ;


 int main()
 {
     ///int seqList[] = {2, 3, 4,5};
     ///int seqList[] = {14, 2, 4 ,6, 8};

   int seqList[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,
                   75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
    //int seqList[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int listSize = sizeof(seqList)/sizeof(int);
    printf("size %d\n",listSize);
    for(int i =0; i<listSize;i++)
    {
        int cost = getMinCost(seqList,listSize,i);
        printf("final cost is %d\n", cost);
    }

     return 0;
 }
 int getMinCost(int seqList[], int seqSize, int startIndex)
 {
     int cost = 0;

     if(startIndex >= seqSize)
     {
         return;
     }

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


    if(cost == 1)
    {
        return cost+getMinCost(newSeq,newSeqSize,startIndex);
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
