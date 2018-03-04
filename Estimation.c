// Function counting arithmetic mean and weighted arithmetic mean.



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define AM "first"  //file used for arithmetic mean and harmonic mean
#define WMA "second" //file used for weighted arithmetic mean




void Estimate (float scores[],uint8_t *amount)
{
    struct
    {

        float val[100];
        float quant[100]; // add this adjustments to github

    }wam;


    uint8_t number = 0;
    uint8_t k;
    uint8_t i;

    char array [100];
    char *first_number;
    char *second_number;
    float outcome = 0;
    float quantity = 0;


    while(number!=4)
    {
        do
        {
            printf("\nChoose what kind of estimation u want to make:\n");
            printf("\n'1' for weighted arithmetic mean");
            printf("\n'2' for arithmetic mean");
            printf("\n'3' for harmonic mean");
            printf("\n'4' for exit\n");

            scanf("%hhu",&number);
            getc(stdin);

            fseek(stdin,0,SEEK_END);

        }while(number!= 1 && number!=2 && number!=3 && number!=4);


        if(number == 1 || number == 2 || number == 3)
        {
            switch(number)
            {
                case 1:
                {

                    FILE *file;
                    if((file=fopen(WMA,"r"))==NULL)
                        {
                            printf("Error");
                            exit(EXIT_FAILURE);
                        }

                    k=0;

                    while (fgets(array,100,file)!=NULL)
                    {

                        first_number=strtok(array,"|");
                        second_number=strtok(NULL,"\n");

                        wam.val[k] = atof(first_number);
                        wam.quant[k] = atof(second_number);
                        k++;

                    }

                    for (i=0;i<k;i++)
                    {

                        outcome +=wam.val[i]*wam.quant[i];
                        quantity +=wam.quant[i];

                    }

                    outcome =outcome/quantity;
                    printf ("\nWeighted arithmetic mean equals :%f\n",outcome);
                    scores[*amount]=outcome;
                    *amount+=1;
                    outcome=0;
                    quantity=0;

                }
                break;

                case 2:
                {
                    FILE *file2;
                    if((file2=fopen(AM,"r"))==NULL)
                    {
                        printf("File not found");
                        exit(EXIT_FAILURE);
                    }

                    k=0;
                    while(fgets(array,100,file2)!=NULL)
                    {
                        wam.val[k]=atof(array);
                        k++;
                    }
                    for(i=0;i<k;i++)
                    {
                        outcome +=wam.val[i];
                    }
                    outcome=outcome/i;
                    scores[*amount]=outcome;
                    printf ("\nArithmetic mean equals :%f\n",scores[*amount]);
                    *amount+=1;
                    outcome=0;
                    i=0;

                }
                break;

                case 3:
                {
                    FILE *file2;
                    if((file2=fopen(AM,"r"))==NULL)
                    {
                        printf("File not found");
                        exit(EXIT_FAILURE);
                    }

                    k=0;
                    while(fgets(array,100,file2)!=NULL)
                    {
                        wam.val[k]=atof(array);
                        k++;
                    }
                    for(i=0;i<k;i++)
                    {
                        outcome +=(1/wam.val[i]);
                    }
                    outcome=i/outcome;
                    scores[*amount]=outcome;
                    printf ("\nArithmetic mean equals :%f\n",scores[*amount]);
                    *amount+=1;
                    outcome=0;
                    i=0;
                }
                break;

                default:
                break;
            }
        }
        else if(number==4)
        break;
    }

}




