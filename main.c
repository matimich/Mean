// Function counting arithmetic mean, weighted arithmetic mean and harmonic mean.

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "Estimation.h"




int main (void)
{


    float outcomes[100];     //space for outcomes
    uint8_t amount = 0;      // space for number of outcomes
    uint8_t i;
    Estimate(outcomes,&amount,FileSettings);





//DZIALA!
   /*
    double input = 1.123;
        FILE *file;
        if ((file = fopen("first.txt","r+"))==NULL)
        {
            printf("File not found");
            exit(EXIT_FAILURE);
        }

        fseek(file,0,SEEK_END);

        char *string = ftoa(10.6);




        //  printf("\n'%s'",ftoa(51.5));
        //fprintf(file,"%f",input);     //musze zostawic

        // printf("\n'%s'",ftoa(51.5));


        for(int i=0; *string !='\0';i++)
        {
            fprintf(file,"%c",*string);
            string++;
            if(*string =='\0')
            {
                fprintf(file,"%c",'\n');
            }
        }
        fclose(file);
        */


    for(i=0;i<amount;i++)
    {
        printf("\nScores you have:%f\n",outcomes[i]);
    }
    return 0;
}

