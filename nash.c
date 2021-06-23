#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LLInt long long int
int main()
{
    LLInt N=0, M=0;

    scanf("%lld %lld",&N,&M);

    LLInt const seqSize = N;
    LLInt seq[seqSize];
    for(LLInt i =0; i<seqSize; i++)
    {
        scanf("%lld",&seq[i]);
    }

    LLInt const outSize = M;
    LLInt out[outSize];
    LLInt outCount = 0;
    for(LLInt m =0; m<M;m++)
    {
        int operation = 0;
        LLInt U,V,C;
        scanf("%d",&operation);
        if(operation == 1)
        {
            scanf("%lld %lld %lld",&U,&V,&C);
            //printf("%lld %lld %lld\n",U,V,C);
            for(LLInt k = U-1; k<V;k++)
            {
                seq[k] = C;
            }

        }else if(operation == 2)
        {
            scanf("%lld %lld %lld",&U,&V,&C);
            //printf("%lld %lld %lld\n",U,V,C);
            for(LLInt k = U-1; k<V;k++)
            {
                if((seq[k]+C)>0)
                {
                    seq[k] = seq[k]+C;
                }else{
                    seq[k] = 0;
                }
            }

        }else if(operation == 3)
        {
            scanf("%lld %lld",&U,&V);
            //printf("%lld %lld %lld\n",U,V);
            LLInt count = 0;
            for(LLInt k = U-1; k<V;k++)
            {
                if(seq[k]==0)
                {
                    count++;
                }
            }
            //printf("%lld\n",count);
            out[outCount++] = count;
        }
    }

    for(LLInt i =0; i<outCount; i++)
    {
        printf("%lld\n",out[i]);
    }
    /*
    for(LLInt i =0; i<seqSize; i++)
    {
        printf("%d",seq[i]);
    }*/

    return 0;
}
