#include "functions.h"

string Functions::currentTime(int type)
{
    time_t now = time(NULL);
    struct tm tstruct;
    char buf[40];
    tstruct = *localtime(&now);
    if (type == 1) {
    	strftime(buf, sizeof(buf), "%d-%m-%Y-%H-%M-%S", &tstruct);
	} else if (type == 2) {
		strftime(buf, sizeof(buf), "%d:%m:%Y-%H:%M:%S", &tstruct);
	}
    return buf;
}

void Functions::createFile(string filename)
{
	Functions useful;
	cout << "Creating file\n";
	if (filename == "") {
		filename = Functions::currentTime(1) + ".txt";
	} else {
		filename = filename + ".txt";
	}
	ofstream yafile (filename, fstream::app);
	
	yafile << "Текущее дата и время: " + Functions::currentTime(2);
	yafile << "\n";
	yafile << "";
	yafile << "\n";
	yafile << "Прилагательных ";
	yafile << Functions::a;
	yafile << "\n";
	yafile << "Наречий ";
	yafile << Functions::adv;
	yafile << "\n";
	yafile << "Местоименных наречий ";
	yafile << Functions::advpro;
	yafile << "\n";
	yafile << "Числительных-прилагательных ";
	yafile << Functions::anum;
	yafile << "\n";
	yafile << "Местоимений-прилагательных ";
	yafile << Functions::apro;
	yafile << "\n";
	yafile << "Частей композитов - сложных слов ";
	yafile << Functions::com;
	yafile << "\n";
	yafile << "Союзов ";
	yafile << Functions::conj;
	yafile << "\n";
	yafile << "Междометий ";
	yafile << Functions::intj;
	yafile << "\n";
	yafile << "Числительных ";
	yafile << Functions::num;
	yafile << "\n";
	yafile << "Частиц ";
	yafile << Functions::part;
	yafile << "\n";
	yafile << "Предлогов ";
	yafile << Functions::pr;
	yafile << "\n";
	yafile << "Существительных ";
	yafile << Functions::s;
	yafile << "\n";
	yafile << "Местоимений-существительных ";
	yafile << Functions::spro;
	yafile << "\n";
	yafile << "Глаголов ";
	yafile << Functions::v;
	yafile << "\n";
	yafile << "Из них:";
	yafile << "\n";
	yafile << " Деепричастий ";
	yafile << Functions::ger;
	yafile << "\n";
	yafile << " Инфинитивов ";
	yafile << Functions::inf;
	yafile << "\n";
	yafile << " Причастий ";
	yafile << Functions::partcp;
	yafile << "\n";
	yafile << " Изьявительных наклонений ";
	yafile << Functions::indic;
	yafile << "\n";
	yafile << " Повелительных наклонений ";
	yafile << Functions::imper;
	yafile << "\n";
	
	yafile.close();
}

void Functions::processFile(string filename)
{
	string narrow_string(filename);
	wstring wide_string = wstring(narrow_string.begin(), narrow_string.end());
	const wchar_t* filenameW = wide_string.c_str();
	
	Functions useful;
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filenameW);
	
	if (result)
	{
	    cout << "File parsed without errors\n";
	}
	else
	{
	    cout << "File parsed with errors\n";
	    cout << "Error description: " << result.description() << "\n";
	    exit(1);
	}

	pugi::xml_node bodyNode = doc.child("html").child("body");
	string tempString;
	
	ofstream logfile ("log.txt", fstream::app);
	
	for (pugi::xml_node tool = bodyNode.child("se"); tool; tool = tool.next_sibling("se"))
	{
		for (pugi::xml_node tool1 = tool.child("w"); tool1; tool1 = tool1.next_sibling("w"))
		{
			pugi::xml_node tool2 = tool1.child("ana");
			tempString = tool2.attribute("gr").value();

			string outputString = tempString.substr(0, tempString.find(","));
			string outputString1 = outputString.substr(0, outputString.find("="));

			if (outputString1 == "") {
				useful.unknown++;	
			} else if (outputString1 == "A") {
		    	Functions::a++;
			} else if (outputString1 == "ADV") {
				Functions::adv++;
			} else if (outputString1 == "ADVPRO") {
				Functions::advpro++;
			} else if (outputString1 == "ANUM") {
				Functions::anum++;
			} else if (outputString1 == "APRO") {
				Functions::apro++;
			} else if (outputString1 == "COM") {
				Functions::com++;
			} else if (outputString1 == "CONJ") {
				Functions::conj++;
			} else if (outputString1 == "INTJ") {
				Functions::intj++;
			} else if (outputString1 == "NUM") {
				Functions::num++;
			} else if (outputString1 == "PART") {
				Functions::part++;
			} else if (outputString1 == "PR") {
				Functions::pr++;
			} else if (outputString1 == "S") {
				Functions::s++;
			} else if (outputString1 == "SPRO") {
				Functions::spro++;
			} else if (outputString1 == "V") {
				Functions::v++;
				string diffverbs = tool2.attribute("gr").value();
			 	
			 	if (diffverbs.find("ger") != string::npos) {
				    Functions::ger++;
				}
			 	if (diffverbs.find("inf") != string::npos) {
				    Functions::inf++;
				}
			 	if (diffverbs.find("partcp") != string::npos) {
				    Functions::partcp++;
				}
			 	if (diffverbs.find("indic") != string::npos) {
				    Functions::indic++;
				}
			 	if (diffverbs.find("imper") != string::npos) {
				    Functions::imper++;
				}
			}
		}
	}
}

string Functions::consoleInput()
{
	string temp;
	getline(cin, temp);
	
	if (temp.empty()) {
		temp = "";
	}
	
	return temp;
}
