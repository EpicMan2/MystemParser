#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <chrono>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

#include "pugixml.hpp"
#include "pugiconfig.hpp"

using namespace std;

// Различные полезные функции
class Functions
{
	public:
		string consoleInput();
		
		void createFile(string filename);
		void processFile(string filename);
	private:
		string currentTime(int type);	// Системные дата и время. 1 - дд-мм-ГГ-ЧЧ-ММ-СС. 2 - дд:мм:ГГ-ЧЧ:ММ:СС
		
		int a = 0; 		// Существительное
		int adv = 0; 	// Наречие
		int advpro = 0; // Местоименное наречие
		int anum = 0; 	// Числительное-прилагательное
		int apro = 0; 	// Местоимение-прилагательное
		int com = 0; 	// Часть композита - сложного слова
		int conj = 0; 	// Союз
		int intj = 0; 	// Междометие
		int num = 0; 	// Числительное
		int part = 0; 	// Частица
		int pr = 0; 	// Предлог
		int s = 0; 		// Существительное
		int spro = 0; 	// Мест	оимение-существительное
		int v = 0; 		// Глагол
		int ger  = 0;	// 	Деепричастие
		int inf = 0;	// 	Инфинитив
		int partcp = 0;	// 	Причастие
		int indic = 0;	//	Изъявительное наклонение
		int imper = 0;	//	Повелительное наклонение
		int unknown = 0;// Неизвестное значение
};
#endif
