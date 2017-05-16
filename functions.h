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

// ��������� �������� �������
class Functions
{
	public:
		string consoleInput();
		
		void createFile(string filename);
		void processFile(string filename);
	private:
		string currentTime(int type);	// ��������� ���� � �����. 1 - ��-��-��-��-��-��. 2 - ��:��:��-��:��:��
		
		int a = 0; 		// ���������������
		int adv = 0; 	// �������
		int advpro = 0; // ������������ �������
		int anum = 0; 	// ������������-��������������
		int apro = 0; 	// �����������-��������������
		int com = 0; 	// ����� ��������� - �������� �����
		int conj = 0; 	// ����
		int intj = 0; 	// ����������
		int num = 0; 	// ������������
		int part = 0; 	// �������
		int pr = 0; 	// �������
		int s = 0; 		// ���������������
		int spro = 0; 	// ����	�������-���������������
		int v = 0; 		// ������
		int ger  = 0;	// 	������������
		int inf = 0;	// 	���������
		int partcp = 0;	// 	���������
		int indic = 0;	//	������������� ����������
		int imper = 0;	//	������������� ����������
		int unknown = 0;// ����������� ��������
};
#endif
