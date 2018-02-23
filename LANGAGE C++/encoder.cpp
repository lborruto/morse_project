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
using namespace std;

string translate(string word)
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

int encoder()
{	
	stringstream ss;
	string sentence;
	string word = "";
	
	cout << "Mot a traduire ";
	getline(cin, sentence);
	ss << sentence;
	cout << "Morse: " << endl;
	
	while(ss >> word)
		cout << translate(word) << endl;
}