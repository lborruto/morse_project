#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.hpp"
#include "SerialPort.hpp"
using namespace std;

int choix1 = 1;
int choix2 = 2;

int main()
{
    
	int choix;

	printf("Que voulez-vous faire ?\n");
	printf("Selectionnez une option :\n\n");
	printf("1 - Decoder du Morse\n");
	printf("2 - Encoder en Morse\n");
    printf("3 - LIRE SERIAL PORT\n");

	scanf("%i", &choix);
	printf("\n");
	
    while (choix == 1)
  {
	decoder();
  }
  
    while (choix == 2)
  {
	encoder();
  }
  
  while (choix == 3)
  {
	serial();
  }
}