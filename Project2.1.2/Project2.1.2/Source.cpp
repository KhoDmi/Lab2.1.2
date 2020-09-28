#include<stdlib.h>;
#include<iostream>;
#include <limits>;

using namespace std;

#include"Exam.h"
#include"Get.h"
#include"Set.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void Get(Exam& e)
{
	cout << "Name is:" << e.name << endl;
	cout << "Mark is:" << e.mark << endl;
}

int checkId(Exam& e)
{
	return(e.id);
}

int  main()
{
	cin.clear();
	cout << "Input anything to start" << endl;
	cin.get();
	system("cls");

	cout<<"first initial data"<< endl;
	Exam firstStdCheck;
	cout <<"id"<< checkId(firstStdCheck) << endl;
	Get(firstStdCheck);
	cout << endl;

	cout << "second initial data" << endl;
	Exam secondStdCheck(1);
	cout <<"id"<<checkId(secondStdCheck) << endl;
	Get(secondStdCheck);
	cout << endl;

	Examenator setM;

	setM.setMark(firstStdCheck);
	cout << "first after assessment" << endl;
	cout << "id" << checkId(firstStdCheck) << endl;
	Get(firstStdCheck);

	setM.setMark(secondStdCheck);
	cout << "second after assessment" << endl;
	cout << "id" << checkId(secondStdCheck) << endl;
	Get(secondStdCheck);

	cout << "input anything to continue" << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	system("cls");


	int check = 0;
	int reqNumofSt = 0;
	do
	{
		cout << "input number of students" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> reqNumofSt;
	} while (cin.fail());
	
	Exam *regis = new Exam[reqNumofSt];

	for (int count = 0; count < reqNumofSt; count++)
	{
		
		do
		{
			check = 0;
			regis[count].setId();
			for (int i = 0; i < count; i++)
			{
				if (checkId(regis[count]) == checkId(regis[i]))
				{
					cout << "student with this id already exists" << endl;
					check++;
					i = count;
				}
			};
			
		} while (check != 0);
		regis[count].setName();

	}




	for (int count = 0; count < reqNumofSt; count++)
	{
		cout << "Student id" << checkId(regis[count]) << endl;
		setM.setMark(regis[count]);
	}
	check = 0;
	int chosen;
	do
	{
		cout << "do you want to know anything about any student? (y or n)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		char answer = getchar();
		if (answer == 'y')
		{
			do
			{
				cout << "input id of chosen student" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> chosen;
			} while (cin.fail());
			int count = 0;
			int checkCount = 0;
			while (count< reqNumofSt)
			{
				if (checkId(regis[count]) == chosen)
				{
					Get(regis[count]);
					count = reqNumofSt+3;
				}
				else checkCount=++count;
			}
			if (checkCount == count) cout << "there's no student with such id" << endl;
				checkCount = count = 0;
		}
		if (answer == 'n') check = -1;
	} while (check == 0);

	for (int count = 0; count < reqNumofSt; count++)
	regis[count].~Exam();
	setM.~Examenator();
	return 0;
}

