#ifndef __text__
#define __text__
//------------------------------------------------------------------------------
// text.h - содержит описание обобщенного текста.
//------------------------------------------------------------------------------

#include <fstream>
#include "charecterReplacement.h"
#include "charecterToNumber.h"
#include "cyclicShift.h"

using std::ifstream;
using std::ofstream;

struct text {
    text();

    enum key {CHARACTERREPLACEMENT,CYCLICSHIFT,CHARACTERTONUMBER};
    key k;
    characterReplacement cr;
    cyclicShift cs;
    characterToNumber ctn;
};

// Ввод обобщенного текста.
text *In(ifstream &ifdt);

// Случайный ввод обобщенного текста.
text *InRnd();

// Вывод обобщенного текста.
void Out(text &s, ofstream &ofst);

// Вычисление частного шифрования.
double Quotient(text &s);

#endif __text__
