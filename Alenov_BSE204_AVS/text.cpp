//------------------------------------------------------------------------------
// text.cpp - содержит процедуры связанные с обработкой обобщенного текста
// и создания произвольной текста.
//------------------------------------------------------------------------------

#include "text.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного текста из файла.
text* In(ifstream &ifst) {
    text *sp;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            sp = new text;
            sp->k = text::CHARACTERREPLACEMENT;
            In(sp->cr, ifst);
            return sp;
        case 2:
            sp = new text;
            sp->k = text::CYCLICSHIFT;
            In(sp->cs, ifst);
            return sp;
        case 3:
            sp = new text;
            sp->k = text::CHARACTERTONUMBER;
            In(sp->ctn, ifst);
            return sp;
        default:
            return 0;
    }
}

// Случайный ввод обобщенного текста.
text *InRnd() {
    text *sp;
    auto k = rand() % 3 + 1;
    switch(k) {
        case 1:
            sp = new text;
            sp->k = text::CHARACTERREPLACEMENT;
            InRnd(sp->cr);
            return sp;
        case 2:
            sp = new text;
            sp->k = text::CYCLICSHIFT;
            InRnd(sp->cs);
            return sp;
        case 3:
            sp = new text;
            sp->k = text::CHARACTERTONUMBER;
            InRnd(sp->ctn);
            return sp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего текста в поток.
void Out(text &s, ofstream &ofst) {
    switch(s.k) {
        case text::CHARACTERREPLACEMENT:
            Out(s.cr, ofst);
            break;
        case text::CYCLICSHIFT:
            Out(s.cs, ofst);
            break;
        case text::CHARACTERTONUMBER:
            Out(s.ctn, ofst);
            break;
        default:
            ofst << "Incorrect text!" << endl;
    }
}

//-----------------------------------------------------------------------------------------------------
// Нахождение частного от делеления суммы кодов незашифрованной строки на число символов в этой строке.
double Quotient(text &s) {
    switch(s.k) {
        case text::CHARACTERREPLACEMENT:
            return Quotient(s.cr);
            break;
        case text::CYCLICSHIFT:
            return Quotient(s.cs);
            break;
        case text::CHARACTERTONUMBER:
            return Quotient(s.ctn);
            break;
        default:
            return 0.0;
    }
}

text::text() {
}

