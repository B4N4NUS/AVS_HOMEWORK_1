#include "charecterToNumber.h"
#include <string>

// Ввод параметров шифрования из файла.
void In(characterToNumber &ctn, ifstream &ifst){
    string input;
    while(ifst >> input){
        if (input == ";"){
            break;
        }
        ctn.text += input +" ";
    }


    // Шифрование.
    for (int i = 0; i < ctn.text.size(); i++) {
        if (ctn.text[i] == ' ') {
            ctn.encrypted += "/ ";
        } else {
            ctn.encrypted += to_string((int)ctn.text[i])+" ";
        }
    }
}

// Случайный ввод параметров шифрования.
void InRnd(characterToNumber &ctn){
    ctn.text = Random();

    // Шифрование.
    for (int i = 0; i < ctn.text.size(); i++) {
        if (ctn.text[i] == ' ') {
            ctn.encrypted += "/ ";
        } else {
            ctn.encrypted += to_string((int)ctn.text[i])+" ";
        }
    }
}

// Вывод параметров шифрования в форматируемый поток.
void Out(characterToNumber &ctn, ofstream &ofst){
    ofst << "Text: " << ctn.text
         << "\nEncryption by replacing characters with numbers: " << ctn.encrypted << "\n";
}

// Вычисление частного шифрования.
double Quotient(characterToNumber &ctn){
    int64_t sum = 0;
    for(int i = 0; i < ctn.text.size(); i++){
        sum += ctn.text[i];
    }
    return sum*1.0/ctn.text.size();
}
