// Function counting arithmetic mean and weighted arithmetic mean.



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#define AM "first.txt"  //file used for arithmetic mean and harmonic mean
#define WMA "second.txt" //file used for weighted arithmetic mean



char* ftoa(double number)       //function which changes double into string
{

    char* first;
    char string[50];
    char string_2[50];
    double  number_2,change;
    int  fractional,decimal;


    decimal = (int) number;     //extracting decimal part form fractional

    number_2 = (double) decimal;

    change = number - number_2;

    fractional = change*1000; //extracting fractional part and changing it into integer

    // itoa(decimal,first,10);
    // itoa(fractional,sec,10);

    sprintf(string,"%d",decimal);           //changing both parts into string
    sprintf(string_2,"%d",fractional);

    strcat(string,".");                     //adding dot between numbers
    strcat(string,string_2);
  //  strcat(string," ");
    first = string;

    return first;                           //returning final string
}





void FileEdition_1(void)
{
    int decission ;
    char sign ;
    do
    {
        sign = 'A';
        decission = 0;
        double input;
        char *string;
        printf("\nInput '1' to add new data to previous"); //sprawdzenie czy dziala
        printf("\nInput '2' to add completely new data"); //sprawdzenie czy dziala
        printf("\nInput '3' to display data"); //sprawdzenie czy dziala
        printf("\nInput '4' to go back:"); //sprawdzenie czy dziala
        scanf("%i",&decission);
        getc(stdin);
        fseek(stdin,0,SEEK_END);


        switch (decission)
        {
            case 1:
            {

                FILE *file;
                if ((file = fopen(AM,"r+"))==NULL)
                {
                    printf("File not found");
                    exit(EXIT_FAILURE);
                }

                do
                {
                  //  printf("\nPOCZATEK:%c",sign);
                    fseek(file,0,SEEK_END);
                    printf("\nInput number, remember about '0.0' format:");
                    scanf("\n%lf",&input);
                    getc(stdin);
                    fseek(stdin,0,SEEK_END);

                  //  printf("\nSRODEK:%c",sign);

                    string = ftoa(input);
                    //printf("STRING:%s",string);

                    fprintf(file,"%s",string);
                    fclose(file);
                //fflush        ~~!!!!!!!!!!!!!!!!!!!!!!!!!

                    printf("\nDo you want to add another one? Press 'q' or 'Q' to exit");
                    printf("\nor type any other sign to continue:");
                    scanf("\n%c",&sign);
                  //  printf("\nKONIEC:%c",sign);
                    fseek(stdin,0,SEEK_END);


                }while(sign != 'q' && sign !='Q');


            }









            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            return;
        }
    }
    while(1);

}



void FileEdition_2(void)
{
    printf("\nInput '1' to add new data to previous"); //sprawdzenie czy dziala
    printf("\nInput '2' to add completely new data"); //sprawdzenie czy dziala
    printf("\nInput '3' to display data"); //sprawdzenie czy dziala
    getc(stdin);
}

void FileSettings(void(*FileEdition_1)(void),void(*FileEdition_2)(void))
{
   // enum decission {a=1, b=2,c=3} my_decision;
    int my_decission=0;

    do
    {
        printf("\nInput '1' to change dates for arthmetic mean and harmonic mean");
        printf("\nInput '2' to change dates for weighted arthmetic mean");
        printf("\nPress '3' to go back:");
        scanf("%d",&my_decission);
        getc(stdin);
        fseek(stdin,0,SEEK_END);


        switch(my_decission)
        {
            case 1:
            FileEdition_1();
            my_decission=0;
            break;

            case 2:
            FileEdition_2();
            my_decission=0;
            break;

            case 3:
            return;
        }

    }
    while(1);
   // while(my_decission!=1 && my_decission!=2 && my_decission!=3);
}



void Estimate (float scores[],uint8_t *amount, void (*FileSettings)(void(*FileEdition_1)(void),void(*FileEdition_2)(void)))
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
            printf("\n Choose what kind of estimation u want to make:\n");
            printf("\n'1' for weighted arithmetic mean");
            printf("\n'2' for arithmetic mean");
            printf("\n'3' for harmonic mean");
            printf("\n'4' for exit");
            printf("\n'5' for change data in files:\n");

            scanf("%hhu",&number);
            getc(stdin);
            fseek(stdin,0,SEEK_END);

        }while(number!= 1 && number!=2 && number!=3 && number!=4 && number!=5);


        switch(number)
        {
                case 1:
                {

                    FILE *file;
                    if((file=fopen(WMA,"r"))==NULL)
                    {
                            printf("File not found");
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
                    fclose(file);

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
                number =0;
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
                    fclose(file2);

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
                number =0;
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
                number =0;
                break;

                case 4:
                break;

                case 5: //file settings
                FileSettings(FileEdition_1,FileEdition_2);
                number =0;
                break;

        }

    }

}




