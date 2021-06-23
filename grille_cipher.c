#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int grilleSize = 0;
    scanf("%d",&grilleSize);

    const int size = grilleSize;
    char grille[size][size];

    char grilleCpy[size][size];
    for(int i =0; i<grilleSize; i++)
    {
        scanf("%s",grille[i]);
    }

    const int stringLength = size*size;
    char encrypted[stringLength];
    //scanf("%s",encrypted);
    //getchar(); // left by scanf
    getchar();
    gets(encrypted);

    //test input
    /*printf("grille\n");
    for(int i =0; i<grilleSize; i++)
    {
        printf("%s\n",grille[i]);
    }
    printf("encrypted\n");
    printf("%s\n",encrypted);
    */

    // check grille validity
    char msgDecrypt[stringLength];
    memset(msgDecrypt,'$',sizeof(msgDecrypt));
    //msgDecrypt[stringLength] = 0;
    int characterTracker = 0;

    for(int p=0; p<grilleSize; p++) // initial hole punching
    {
        for(int q =0; q<grilleSize; q++)
        {
            if(grille[p][q]=='.')
            {
                /*if(characterTracker>grilleSize*grilleSize-1)
                {
                    printf("invalid grille\n");
                    fflush(stdout);
                    return 0;
                }*/
                msgDecrypt[(p*4)+q] = encrypted[characterTracker++];
            }
        }
    }

    for(int i=0; i<3; i++)
    {
        // rotate grille, first row becomes last column
        memcpy(grilleCpy,grille,sizeof(grille));
        for(int j =0; j<grilleSize; j++)
        {
            for(int k=0,t=grilleSize-1; k<grilleSize; k++,t--)
            {
                grille[j][k] = grilleCpy[t][j];
            }
        }
        /*printf("grille rotation\n");
        for(int i =0; i<grilleSize; i++)
        {
            printf("%s\n",grille[i]);
        }*/

        for(int p=0; p<grilleSize; p++) // punch holes after rotation, while trying to recover message
        {
            for(int q =0; q<grilleSize; q++)
            {
                if(grille[p][q]=='.')
                {
                    if(characterTracker>grilleSize*grilleSize-1)
                    {
                        printf("invalid grille\n");
                        fflush(stdout);
                        return 0;
                    }
                    msgDecrypt[(p*4)+q] = encrypted[characterTracker++];
                }
            }
        }

    }

    // printf("punched string %s\n",tempEnc);
    for(int i =0; i<stringLength;i++)
    {
        //if(tempEnc[i]!='$')
        if(msgDecrypt[i]=='$')
        {
            printf("invalid grille");
            fflush(stdout);
            return 0;
        }
    }

    for(int i =0; i<stringLength;i++)
    {
        printf("%c",msgDecrypt[i]);
    }
    printf("\n");
    fflush(stdout);

    return 0;
}
