#include "charecterReplacement.h"

void In(characterReplacement &cr, ifstream &ifst) {
    string input;
    while(ifst >> input){
        if (input == ";"){
            break;
        }
        cr.text += input +" ";
    }

    // Шифрование.
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string encryptCode = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    for (int i = 0; i < cr.text.size(); i++) {
        if (cr.text[i] == ' ') {
            cr.encrypted += " ";
        } else {
            if (alphabet.find(cr.text[i]) != std::string::npos){
                cr.encrypted += encryptCode[alphabet.find(cr.text[i])];
            } else {
                cr.encrypted += cr.text[i];
            }
        }
    }
}

// Случайный ввод параметров шифрования.
void InRnd(characterReplacement &cr) {
    cr.text = Random();

    // Шифрование.
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string encryptCode = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    for (int i = 0; i < cr.text.size(); i++) {
        if (cr.text[i] == ' ') {
            cr.encrypted += " ";
        } else {
            if (alphabet.find(cr.text[i]) != std::string::npos){
                cr.encrypted += encryptCode[alphabet.find(cr.text[i])];
            } else {
                cr.encrypted += cr.text[i];
            }
        }
    }
}

// Вывод параметров шифрования в форматируемый поток.
void Out(characterReplacement &cr, ofstream &ofst) {
    ofst << "Text: " << cr.text
         << "\nEncryption by substitution of characters: " << cr.encrypted << "\n";
}

// Вычисление частного шифрования.
double Quotient(characterReplacement &cr) {
    int64_t sum = 0;
    for(int i = 0; i < cr.text.size(); i++){
        sum += cr.text[i];
    }
    return sum*1.0/cr.text.size();
}
