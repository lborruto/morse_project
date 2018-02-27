//entrée utilisateur dans la console en morse, puis écriture de la traduction en caractères dans MORSE.txt


#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "SerialPort.h"
using namespace std;

string convert(string morse, string const morseCode[]);
int writetxt1(string texte);

int decoder() //table de traduction (char) et de conversion
{
    string input = "";
    cout << "MORSE CODE: ";
    getline(cin, input);
    
    string const morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    writetxt1(convert(input, morseCode));
    return 0;
}

string convert(string morse, string const morseCode[]) //convertis le morse en caractère
{
    string output = "";
    string currentLetter = "";
    istringstream ss(morse);
    
    size_t const characters = 26;
    
    while(ss >> currentLetter)
        {
            size_t index = 0;
            while(currentLetter != morseCode[index] && index < characters)
                {
                    ++index;
                }
            output += 'A' + index;
        }
    return output;
}

int writetxt1(string texte) //écris le résultat dans MORSE.txt
{
    string const nomFichier("./MORSE.txt"); //variable du fichier txt
    remove(nomFichier.c_str()); //supprime le txt (pour le vider)
    fstream fs;
    fs.open(nomFichier.c_str(), ios::out); //recrée le fichier txt
    fs.close();
    
    fstream monFlux(nomFichier.c_str()); //initialise le stream du fichier txt
    
    if (monFlux)
        {
            monFlux << texte << endl; //écrit le texte dans le fichier txt
        }
    else
        {
            cout << "ERREUR" << endl; //si erreur, affiche ERREUR
        }
}