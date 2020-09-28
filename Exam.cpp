#include<iostream>
#include<string>
#include<iomanip>
#include<limits>


#include"Exam.h"
#include"Get.h"
using namespace::std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

Exam::Exam()
{
	id=0;
	name = "noname";
	mark = 0.0;
}

Exam::Exam(int a) :id(a) 
{
	name = "noname";
	mark = 0.0;
}


void Exam::setName()
{
	cout << "Input name" << endl;
	cin >> name;
}

void Exam::setId()
{
	do
	{
		cout << "Input id" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	} while (cin.fail());
}



Exam::~Exam()
{
	
}