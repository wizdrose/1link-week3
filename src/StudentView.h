#pragma once
#include"Student.h"
#include<list>
using namespace std;
class StudentView
{
public:
	StudentView();
	Student studentsImport(int);
	void studentModifyStudent(Student&);
	void studentShow(Student);
	void studentAddView();
	void studentSearchView();
	void studentSortView();
	void studentStatisticView();
	int findID();
};
