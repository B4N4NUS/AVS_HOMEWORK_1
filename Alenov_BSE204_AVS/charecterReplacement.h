#ifndef __characterReplacement__
#define __characterReplacement__

//-----------------------------------------------------------------------------------------
// charecterReplacement.h - содержит описание шифрования заменой символов и его интерфейса.
//-----------------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

// Шифрование заменой символов.
struct characterReplacement {
    string text,encrypted;
};

// Ввод параметров шифрования из файла.
void In(characterReplacement &cr, ifstream &ifst);

// Случайный ввод параметров шифрования.
void InRnd(characterReplacement &cr);

// Вывод параметров шифрования в форматируемый поток.
void Out(characterReplacement &cr, ofstream &ofst);

// Вычисление частного шифрования.
double Quotient(characterReplacement &cr);

#endif
