#include "cyclicShift.h"
#include <iostream>
#include <string>

// Ввод параметров шифрования из файла.
void In(cyclicShift &cs, ifstream &ifst){
    ifst >> cs.n;
    string input;
    while(ifst >> input){
        if (input == ";"){
            break;
        }
        cs.text += input +" ";
    }
    //cout << "cr.text         " <<cs.text <<endl;
    //cout << "cyclicShift created" << endl;


    // Шифрование.
    for (int i = 0; i < cs.text.size(); i++) {
        if (cs.text[i] == ' ') {
            cs.encrypted += ' ';
        } else {
            cs.encrypted += (char) ((int) cs.text[i] + cs.n);
        }
    }
}

// Случайный ввод параметров шифрования.
void InRnd(cyclicShift &cs){
    cs.text = Random();

    // Шифрование.
    int n = rand()%10+1;
    cs.encrypted += "(n = "+ to_string(n)+") ";
    for (int i = 0; i < cs.text.size(); i++) {
        if (cs.text[i] == ' ') {
            cs.encrypted += ' ';
        } else {
            cs.encrypted += (char) ((int) cs.text[i] + n);
        }
    }
}

// Вывод параметров шифрования в форматируемый поток.
void Out(cyclicShift &cs, ofstream &ofst){
    ofst << "Text: " << cs.text
         << "\nEncryption by cyclically shifting the code of each character by "<<cs.n<<": " << cs.encrypted << "\n";
}

// Вычисление частного шифрования.
double Quotient(cyclicShift &cs){
    int64_t sum = 0;
    for(int i = 0; i < cs.text.size(); i++){
        sum += cs.text[i];
    }
    return sum*1.0/cs.text.size();
}