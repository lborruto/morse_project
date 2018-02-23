#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "SerialPort.hpp"
#include "define.hpp"
using namespace std;

using std::cout;
using std::endl;

char *port_name = "\\\\.\\COM3";

char incomingData[MAX_DATA_LENGTH];

int serial()
{
  SerialPort arduino(port_name);
  if (arduino.isConnected()) cout << "Connection Established !" << endl;
  else cout << "ERROR, check port name";
  
  while (arduino.isConnected()){
    int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
    puts(incomingData);
    Sleep(1000);
    
    ofstream myfile;
  myfile.open ("MORSE.txt");
  myfile << incomingData;
  myfile.close();
  }
}