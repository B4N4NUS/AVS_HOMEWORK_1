#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include <fstream>
#include "text.h"

using std::ifstream;
using std::ofstream;
using std::endl;

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива.
struct container {
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    text *cont[max_len];
};

// Инициализация контейнера.
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока.
void In(container &c, ifstream &ifst);

// Случайный ввод содержимого контейнера.
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток.
void Out(container &c, ofstream &ofst);

// Упорядочить элементы контейнера по возрастанию используя сортировку с помощью прямого слияния.
void MergeSort(container &c, ofstream &ofst);
void Merge(double *a, int lb, int splitter, int ub);

#endif
