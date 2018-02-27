#include <stdio.h>
#include <fstream>
#include "SerialPort.h"

int main()
{
    int choix;

    printf("\n\n\nQue voulez-vous faire ?\n");
    printf("Selectionnez une option :\n\n");
    printf("1 - DECODER DU MORSE (ENTREE UTILISATEUR)\n");
    printf("2 - ENCODER EN MORSE DEPUIS UN FICHIER .TXT\n");
    printf("3 - LIRE SERIAL PORT\n\n");

    scanf("%i", &choix);
    printf("\n");
    

    while (choix == 1)
        {
            decoder(); //entrée utilisateur dans la console en morse, puis écriture de la traduction en caractères dans MORSE.txt
        }
  
    while (choix == 2)
        {
            encoder(); //lis le contenu du MORSE.TXT (en caractères) puis le traduit en morse et l'affiche dans la console
        }
  
    while (choix == 3)
        {
            read(); //lis le port série de l'arduino puis affiche et écris les impulsions en lettres dans MORSE.txt
        }
}