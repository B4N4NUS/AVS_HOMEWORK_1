//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование.
//------------------------------------------------------------------------------

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

// Для использования более точного таймера.
/*#include <chrono>
using namespace std::chrono;
 */

#include "container.h"

//------------------------------------------------------------------------------
// Выводит сообщение о некорректном вводе.
void errMessage1() {
    printf("%s","incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -r number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
// Выводит сообщение о некорректном вводе метода заполнения.
void errMessage2() {
    printf("%s","incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}
//------------------------------------------------------------------------------
// Точка входа.
int main(int argc, char *argv[]) {
    // Старт таймера.
    //auto start = high_resolution_clock::now();

    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("%s","Start\n");
    container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        if (ifst){
            In(c, ifst);
        } else {
            printf("%s","Incorrect path or file");
        }

    } else if (!strcmp(argv[1], "-r")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("%s","incorrect number of words = ");
            printf("%d",size);
            printf("%s",". Set 0 < number <= 10000\n");
            return 3;
        }
        // системные часы в качестве инициализатора.
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел.
        InRnd(c, size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл.
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);

    // Вторая часть задания (функция)
    ofstream ofst2(argv[4]);
    MergeSort(c,ofst2);
    //ofst2 << "Quotient sum = " << to_string(MergeSort(c)) <<"\n";

    Clear(c);
    printf("Stop\n");

    // Конец таймера и вывод времени работы в консоль.
    /*
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printf("%s","EXECUTION TIME - ");
    printf("%d",duration.count());
    printf("%s"," microseconds\n");
     */
    return 0;
}
