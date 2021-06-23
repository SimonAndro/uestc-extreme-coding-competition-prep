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

    int playersTotal = 0;
    scanf("%d",&playersTotal);
    const int pT = playersTotal;
    char* playerList[pT];

    char nameBuffer[1024] ={0};
    getchar(); // left by scanf
    gets(nameBuffer);

    const char s[2] = " ";
    char *token;
    token = strtok(nameBuffer, s);

    int i=0;
    while( token != NULL ) {
        playerList[i++] = token;
        token = strtok(NULL, s);
    }

    char gameBuffer[1024] ={0};
    gets(gameBuffer);
    int gameLength = strlen(gameBuffer);



    // test input
    /*for(i=0; i<playersTotal; i++)
    {
        printf("%s ",playerList[i]);
    }
    printf("game length is %d",gameLength);
*/
    const int snapT = gameLength;
    TEAM inSnapShot[snapT];

    TEAM black = {0};
    TEAM white = {0};

    white.offenseId = 0;
    black.offenseId = 1;
    white.defenseId = 2;
    black.defenseId = 3;

    white.firstcome =   white.offenseId;
    black.firstcome =   black.offenseId;

    white.score = 0;
    black.score  = 0;

    const int waitT = snapT+playersTotal-4;
    int waitList[waitT];
    memset(waitList,0,sizeof(int)*waitT);
    int nextPlayer = 0;
    int nextPlayerAdd = 0;
    for(i = 4;i<playersTotal;i++)
    {
        waitList[nextPlayerAdd++] = i;
    }

    // take snapshot
    int currentSnap = 0;
    if(gameBuffer[0] == 'W')
    {
        memcpy(&inSnapShot[currentSnap++],&white,sizeof(TEAM));
    }else{
        memcpy(&inSnapShot[currentSnap++],&black,sizeof(TEAM));
    }

    int temp;
    for(i = 0; i<gameLength; i++)
    {

        switch(gameBuffer[i])
        {
        case 'W':
            {
                // white winning
                white.score++;

                temp = white.defenseId; // swap defence, offense
                white.defenseId = white.offenseId;
                white.offenseId = temp;

                // black losing
                waitList[nextPlayerAdd++] = black.defenseId; // defense to wait list
                black.defenseId = black.offenseId;

                black.firstcome = black.offenseId;

                black.offenseId = waitList[nextPlayer++];


                inSnapShot[currentSnap-1].score = black.score; // update snapshot before clear score
                black.score = 0;
            }
            break;
        case 'B':
            {
                // black winning
                black.score++;

                temp = black.defenseId; // swap defence, offense
                black.defenseId = black.offenseId;
                black.offenseId = temp;

                // white losing
                waitList[nextPlayerAdd++] = white.defenseId; // defense to wait list
                white.defenseId = white.offenseId;

                white.firstcome = white.offenseId;

                white.offenseId = waitList[nextPlayer++];

                inSnapShot[currentSnap-1].score = white.score; // update snapshot before clear score
                white.score = 0;
            }
            break;
        }
        if(i!=0)
        {
            if(gameBuffer[i]!=gameBuffer[i-1])
            {
                switch(gameBuffer[i])
                {
                case 'W':
                    {
                         memcpy(&inSnapShot[currentSnap++],&white,sizeof(TEAM));

                    }
                    break;
                case 'B':
                    {
                        memcpy(&inSnapShot[currentSnap++],&black,sizeof(TEAM));

                    }
                    break;
                }
            }else if(i == gameLength-1 )
            {
                switch(gameBuffer[i])
                {
                case 'W':
                    {
                        inSnapShot[currentSnap-1].score = white.score; // update snapshot before finish

                    }
                    break;
                case 'B':
                    {
                        inSnapShot[currentSnap-1].score = black.score; // update snapshot before finish

                    }
                    break;
                }
            }
        }
    }

    // getting highest score
    int highestScore = inSnapShot[0].score;
    TEAM* winner = NULL;
    winner = &inSnapShot[0];
    winner->winnerNxt = NULL;

    TEAM *hold = winner;


    for(i = 1; i<currentSnap; i++)
    {
        if(inSnapShot[i].score > highestScore)
        {
            highestScore = inSnapShot[i].score;
            winner = &inSnapShot[i];
            winner->winnerNxt = NULL;

            hold = winner;
        }
        else if(inSnapShot[i].score == highestScore)
        {
            winner->winnerNxt = &inSnapShot[i];
            winner = winner->winnerNxt;
        }
    }

    while(hold != NULL)
    {
        //printf("score: %d, offense %d, defence %d\n", hold->score, hold->offenseId,hold->defenseId);
        printf("%s %s\n",playerList[hold->firstcome],playerList[(hold->firstcome==hold->defenseId)?hold->offenseId:hold->defenseId]);
        fflush(stdout);
        hold = hold->winnerNxt;
    }

    return 0;
}







