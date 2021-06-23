#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI acos(-1.0)

#define sinX(x) (sin(x*PI/180.0))

int main()
{
    int total =0;

    scanf("%d",&total);

    float degree,distance;
    double difference =0;

    //printf("%f",sinX(8));
    for(int i =0; i<total; i++)
    {
        scanf("%f %f",&degree,&distance);
        //printf("degree: %d, distance %d\n", degree,distance);

        difference += distance*sinX(degree);
    }
    //printf("disfference : ");
    printf("%0.2f",difference);
}
