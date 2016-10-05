#pragma once
#include<list>
#include"Student.h"
class StudentRepository
{
public:
	list<Student> Read(string);
	void Write(Student&, string );
	int lastId();
	void overWrite(list<Student> , string);
	StudentRepository();
	~StudentRepository();
};

