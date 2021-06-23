

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RATE{
    char* name;
    char* to;
    long long int value;
}RATE;

int main()
{
    long long int value =0;
    int unitNames = 0;
    scanf("%d",&unitNames);

    char conversionBuffer[2048] = {0};
    getchar(); // left by scanf
    gets(conversionBuffer);


    scanf("%lld",&value);

    int const rateSize = unitNames;
    RATE rateArray[rateSize];

    const char s[2] = " ";
    char *token;
    token = strtok(conversionBuffer, s);

    int i=0;
    rateArray[0].name = token;
    token = strtok(NULL, s);

    char *p;
    while( token != NULL ) {
        rateArray[i].value = strtoll(token,&p,10);
        token = strtok(NULL, s);
        rateArray[i].to = token;

        i++;
        rateArray[i].name = token;
        token = strtok(NULL, s);
    }

    // test print
    /*printf("%d\n",unitNames);
    printf("%s\n",conversionBuffer);
    printf("%ld\n",value);

    for(int i =0; i<unitNames-1;i++)
    {
        printf("1 %s is %d %s\n",rateArray[i].name,rateArray[i].value,rateArray[i].to);
    }*/

    double closest = value;
    for(int i =0; i<unitNames-1;i++)
    {
        closest/=(double)rateArray[i].value;
    }

    //printf("closest: ");
    printf("%.0lf %s\n",closest,rateArray[0].name);


    //printf("precise\n");

    long long int whole1 = closest;
    double whole2 = (closest-whole1)*rateArray[0].value;
    printf("%lld %s %.0lf %s\n",whole1,rateArray[0].name,whole2,rateArray[0].to);


    return 0;
}
