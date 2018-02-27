//lis le port série de l'arduino puis affiche et écris les impulsions en lettres dans MORSE.txt

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "SerialPort.h"
using namespace std;
using std::cout;
using std::endl;

/*Portname must contain these backslashes, and remember to
replace the following com port*/
char *port_name = "\\\\.\\COM3";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];

int read() //lis le port série de l'arduino
{
    string const nomFichier("./MORSE.txt"); //variable du fichier txt
    remove(nomFichier.c_str()); //supprime le txt (pour le vider)
    fstream fs;
    fs.open(nomFichier.c_str(), ios::out); //recrée le fichier txt
    fs.close();
    
    fstream monFlux(nomFichier.c_str()); //initialise le stream du fichier txt
    
    SerialPort arduino(port_name); //check le port COM3 de l'arduino
    if (arduino.isConnected()) cout << "Connection Established" << endl; //si la connexion est établie..
    else cout << "ERROR, check port name"; //...sinon ERROR
  
    while (arduino.isConnected()) //tant que l'arduino est connecté...
    {
        int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH); //check si les donnée sont lues ou non
        if (strlen(incomingData)!=0) //si incomingData n'est pas vide (!) ...
            {
                monFlux << incomingData << endl; //écrire dans le fichier
                cout << incomingData; //affiche dans la console
                *incomingData = 0; //vide la variable
            }
    }
}

