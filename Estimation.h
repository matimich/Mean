#ifndef _ESTIMATION_
#define _ESTIMATION_


void Estimate (float scores[],uint8_t *amount, void (*FileSettings)(void(*FileEdition)(void))); //program function
void FileSettings(void(*FileEdition)(void)); //edit file settings
void FileEdition_1(void);     // file data edition for arthmetic mean and harmonic mean
void FileEdition_2(void);    // file data edition for arthmetic mean and harmonic mean weighted arthmetic mean
#endif

