//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера.
//------------------------------------------------------------------------------

#include "container.h"
#include <cstdio>

//------------------------------------------------------------------------------
// Инициализация контейнера.
void Init(container &c) {
    c.len = 0;
    printf("%s","container was created\n");
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
    printf("%s","container was cleared\n");
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void In(container &c, ifstream &ifst) {
    while (!ifst.eof()) {
        if ((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        } else {
            printf("%s","reading was finished\n");
            break;
        }

    }
    printf("%s","container was filled\n");
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера.
void InRnd(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
    printf("%s","container was filled randomly\n");
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << endl;
    for (int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
    printf("%s","container was printed\n");
}

//--------------------------------------------------------------------------------
// Реализация функции прямого слияния (Straight Merge)
void Sort(double a[], int lb, int ub)
{
    int splitter;
    if (lb < ub) {
        splitter = (lb + ub)/2;
        Sort(a, lb, splitter);
        Sort(a, splitter+1, ub);
        //слияние результатов в общий массив
        Merge(a,lb,splitter, ub);
    }
}
void Merge(double *a, int lb, int split, int ub) {
    int pos1=lb;
    int pos2=split+1;
    int pos3=0;
    double *temp = new double[ub-lb+1];
    while (pos1 <= split && pos2 <= ub)
    {
        if (a[pos1] < a[pos2])
            temp[pos3++] = a[pos1++];
        else
            temp[pos3++] = a[pos2++];
    }
    while (pos2 <= ub)
        temp[pos3++] = a[pos2++];
    while (pos1 <= split)
        temp[pos3++] = a[pos1++];
    for (pos3 = 0; pos3 < ub-lb+1; pos3++)
        a[lb+pos3] = temp[pos3];
    delete[] temp;
}


// Упорядочить элементы контейнера по возрастанию используя сортировку с помощью прямого слияния.
void MergeSort(container &c, ofstream &ofst) {
    double forSort[10000];
    for (int i = 0; i < c.len; i++) {
        forSort[i] = Quotient(*(c.cont[i]));
    }
    Sort(forSort,0,c.len-1);
    for(int i = 0; i < c.len; i++){
        for(int j = 0; j < c.len; j++){
            if (forSort[i] == Quotient(*(c.cont[j]))){
                forSort[i] = 0;
                auto temp = c.cont[i];
                c.cont[i] = c.cont[j];
                c.cont[j] = temp;
                break;
            }
        }
    }
    ofst << "Container was sorted by straight merge sort and contains " << c.len << " elements." << endl;
    for (int i = 0; i < c.len; i++) {
        ofst << i <<": Quotient = " <<Quotient(*(c.cont[i])) << ": ";
        Out(*(c.cont[i]), ofst);
    }
    printf("%s","container was mergesorted\n");
}
