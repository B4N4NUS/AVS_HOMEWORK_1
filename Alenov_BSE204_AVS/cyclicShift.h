#ifndef __cyclicShift__
#define __cyclicShift__

//-----------------------------------------------------------------------------------
// cyclicShift.h - содержит описание шифрования циклическим сдвигом  и его интерфейса.
//-----------------------------------------------------------------------------------

#include <fstream>
using namespace std;
# include "rnd.h"

// Шифрование заменой символов.
struct cyclicShift {
    string text,encrypted;
    int n;
};

// Ввод параметров шифрования из файла.
void In(cyclicShift &cs, ifstream &ifst);

// Случайный ввод параметров шифрования.
void InRnd(cyclicShift &cs);

// Вывод параметров шифрования в форматируемый поток.
void Out(cyclicShift &cs, ofstream &ofst);

// Вычисление частного шифрования.
double Quotient(cyclicShift &cs);

#endif //__cyclicShift__
