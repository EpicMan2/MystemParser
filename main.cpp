#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <locale.h>

#include "functions.h"

using namespace std;

const string version = "1.0.0.0";

int main()
{	
	setlocale(LC_ALL, "rus");
	Functions useful;
	cout << "Program loaded v" + version + "\n";
	cout << "Input file name: ";

	string inputName = useful.consoleInput();
	inputName = inputName + ".xml";	
	useful.processFile(inputName);

	cout << "\nOr just press Enter for date/time name";
    cout << "\nOutput file name: ";
    string outputName = useful.consoleInput();
    useful.createFile(outputName);
    
    cout << "\nFinished successfully";
    return 0;
}
