// Function counting arithmetic mean, weighted arithmetic mean and harmonic mean.

#include <stdio.h>
#include <inttypes.h>
#include "Estimation.h"


//void Estimate (float scores[],uint8_t *amount);

int main (void)
{
    float outcomes[100];     //space for outcomes
    uint8_t amount = 0;      // space for number of outcomes
    uint8_t i;
    Estimate(outcomes,&amount);
    for(i=0;i<amount;i++)
    {
        printf("\nScores you have:%f\n",outcomes[i]);
    }
    return 0;
}

