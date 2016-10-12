#pragma once

#include "Student.h"
#include "StudentView.h"
#include<list>
#include"StudentRepository.h"
#include <iostream>
using namespace std;
class StudentContrller
{

public:
	StudentRepository student_repository;
	StudentView student_view;
	list<Student> getStudents();
	list<Student> addStudent();
	void deleteStudent();
	void modifyStudent();
	void searchStudent(list<Student>&);
	void sortStudent();
	void statisticStudent();
	void listStudent(list<Student>);
	bool checkID(int);
	StudentContrller();
	~StudentContrller();
};

