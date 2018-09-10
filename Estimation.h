#ifndef _ESTIMATION_
#define _ESTIMATION_

#define OUTCOMES 100    //number of OUTCOMES
#define NUMBER_OF_DATA_1 100    //number of date in first file (number of rows)
#define NUMBER_OF_DATA_2 100    //number of date in second file (number of rows)


void Estimate (float scores[],uint8_t *amount, void (*FileSettings)(void(*FileEdition_1)(void),void(*FileEdition_2)(void))); //program function
void FileSettings(void(*FileEdition_1)(void),void(*FileEdition_2)(void)); //edit file settings
void FileEdition_1(void);     // file data edition for arthmetic mean and harmonic mean
void FileEdition_2(void);    // file data edition for arthmetic mean and harmonic mean weighted arthmetic mean
#endif

