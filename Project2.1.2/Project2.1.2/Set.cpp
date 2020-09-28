#include<iostream>
#include<stdlib.h>
#include<string>
#include<iomanip>
#include<limits>

using namespace std;

#include"Exam.h"
#include"Set.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


void Examenator::setMark(Exam& e)
{
	do
	{
		cout << "Input mark" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> e.mark;
	} while (cin.fail());
}

Examenator::~Examenator()
{

}