
#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>

#include "classes.h"
#include "prototypes.h"
#define DEBUG
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	fstream file;
	string path = "model_program.txt";
	string main_str;
	lexvector supervector;
	polizlexvector polizvector;
	varmap idmap;
	char c;

	file.open(path, fstream::in);
	try
	{
		if (file.is_open())
			cout << "File has successfully been opened!" << endl << "Starting the checking..." << endl << endl;
		else
			throw 1;

		while (file.get(c))
			main_str += c;
		file.close();
	}
	catch (...)
	{
		error("can't open file!");
	}


#ifdef DEBUG
	cout << main_str << endl << endl;
#endif // DEBUG


	//lexem scanner
	try
	{
		supervector = LexemScan().scanner2000(main_str.c_str());
		cout << "Lexems are allright! Checking your syntax..." << endl << endl;
	}
	catch (...)
	{
		error("lexem error, sorry");
		system("pause");
		return 0;
	}
	try
	{
		//Syntax & semantic scanner?
		Syntezator3000 ProfessorDumbledore(supervector);
		polizvector = ProfessorDumbledore.defense_matrix_activated(idmap);
		cout << "Syntax seems to be allright as well! Now starting the semantic checking..." << endl << endl;
	}
	catch (int)
	{
		error("syntax error, sorry");
		system("pause");
		return 0;
		//expand?
	}


#ifdef DEBUG
	cout << endl << "Poliz:" << endl << endl;
	for (auto i = polizvector.begin(); i != polizvector.end(); ++i)
		cout << i->getname() << "_";
	cout << endl << endl;
#endif // DEBUG


	try
	{
		//Executing...
		ThePolice Palach;
		Palach.executioner_tri_topora(polizvector, idmap);
		cout << endl << "Done!" << endl << endl;
	}
	catch (int)
	{
		error("execution error, sorry");
		//expand?
	}
	
	



#ifdef DEBUG1
	cout << endl << "Lexems:" << endl;
	for (auto i = supervector.begin(); i != supervector.end(); ++i)
		i->getinfo();
	cout << endl << endl << endl;
#endif // DEBUG1


	

	system("pause");
	return 0;
}

