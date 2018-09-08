#ifndef _ESTIMATION_
#define _ESTIMATION_


//void Estimate (float scores[],uint8_t *amount,void (*)(void));
void Estimate (float scores[],uint8_t *amount, void (*FileSettings)(void(*FileEdition)(void)));
//void FileOpen(void(*FileEdition)(void(*funtion)(void)));
void FileSettings(void(*FileEdition)(void));
void FileEdition_1(void);
void FileEdition_2(void);
char* ftoa(double number);

#endif
