#include "common.h"
#include "match.h"
//#include "hidden_unit0.h"
//#include "hidden_unit1.h"
//#include "output_unit.h"

DWORD readWAV(char*, BYTE*);

void fourierTransform(char*, BYTE*);

void readDatabase(BYTE**, DWORD**);

void readFourier(char*, float*);
