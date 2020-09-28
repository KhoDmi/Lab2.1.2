#include<string>
#include<limits>
#ifndef EXAM_H
#define EXAM_H

using std::string;

class Exam
{
public:
	friend int checkId(Exam& e);
	friend void Get(Exam &e);
	friend class Examenator;
	Exam();
	Exam(int a);
	void setId();
	void setName();
	int checkId();
	~Exam();
private:
	int id;
	string name;
	double mark;
};

#endif EXAM_H
