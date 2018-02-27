//lis le contenu du MORSE.TXT (en caractères) puis le traduit en morse et l'affiche dans la console

#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "SerialPort.h"
using namespace std;

string translate(string word) //table de traduction (char) et de conversion
{
    string morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", 
    "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", 
    ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
    "-.--", "--.."};
    char ch;
    string morseWord = "";

    for(unsigned int i=0; i < word.length(); i++)
        {
            if(isalpha(word[i]))
                {
                    ch = word[i];
                    ch = toupper(ch);
                    morseWord += morseCode[ch - 'A'];
                    morseWord += " ";
                }
        }
        
    return morseWord;
}

int encoder() //écriture de la traduction (et affichage) dans le fichier txt
{
    stringstream ss;
    string sentence;
    string word = "";
    string const nomFichier("./MORSE.txt");
    ifstream monFlux(nomFichier.c_str());
    
    if (monFlux)
        {
            getline(monFlux, sentence); //interaction avec l'utilisateur
            cout << "MOT A TRADUIRE: ";
            cout << sentence << endl; //récupère le txt a traduire en morse
            ss << sentence;
            cout << "MORSE: ";

            while(ss >> word)
                cout << translate(word) << endl; //traduction et affichage du morse
        
            monFlux.close();
            main();
        }
    else
        {
            cout << "ERREUR ENCODE" << endl; //si erreur....
            Sleep(100000);
        }
}