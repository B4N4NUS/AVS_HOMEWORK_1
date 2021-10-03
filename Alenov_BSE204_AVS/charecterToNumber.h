#ifndef __characterToNumber__
#define __characterToNumber__

//-----------------------------------------------------------------------------------------------
// charecterToNumber.h - содержит описание шифрования заменой символов на цифры  и его интерфейса.
//-----------------------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

// Шифрование заменой символов.
struct characterToNumber {
    string text,encrypted;
};

// Ввод параметров шифрования из файла.
void In(characterToNumber &ctn, ifstream &ifst);

// Случайный ввод параметров шифрования.
void InRnd(characterToNumber &ctn);

// Вывод параметров шифрования в форматируемый поток.
void Out(characterToNumber &ctn, ofstream &ofst);

// Вычисление частного шифрования.
double Quotient(characterToNumber &ctn);

#endif //__characterToNumber__
