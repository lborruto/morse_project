#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "define.hpp"
using namespace std;

std::string convert(std::string morse, std::string const morseCode[]);

int decoder()
{
    std::string input = "";
    std::cout << "MORSE CODE: ";
    std::getline(std::cin, input);
    
    std::string const morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    std::cout << convert(input, morseCode) << std::endl;
    return 0;
}

std::string convert(std::string morse, std::string const morseCode[])
{
    std::string output = "";
    std::string currentLetter = "";
    std::istringstream ss(morse);
    
    std::size_t const characters = 26;
    
    while(ss >> currentLetter)
    {
        std::size_t index = 0;
        while(currentLetter != morseCode[index] && index < characters)
        {
            ++index;
        }
        output += 'A' + index;
    }
    return output;
}