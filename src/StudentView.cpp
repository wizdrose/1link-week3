#include "StudentView.h"
#include <iostream>
#include<list>
using namespace std;

StudentView::StudentView()
{
}

Student StudentView::studentsImport(int id)
{
	int valid;
	Student tempStudent;
	string name;
	string address;
	string sex;
	float math;
	float physical;
	float alchemist;
	bool flag = true;
	char t_math[20],t_physical[20],t_alchemist[20];
	cout << "ID: " << id;
	tempStudent.setId(id);
	getline(cin, name);
	cout << "\nNAME ";
	getline(cin, name);
	tempStudent.setName(name);
	cout << "\nADDRESS ";
	fflush(stdin);
	getline(cin, address); tempStudent.setAddress(address);
	cout << "\nSEX: ";
	getline(cin, sex); tempStudent.setSex(sex);
	Point point;
	cout << "\nMATH GRADE: ";
	do
	{
		gets_s(t_math);
		math = atof(t_math);
		if (math == 0)
		{
			cout << "\nWRONG INPUT, PLEASE FILL AGAIN MATH GRADE: ";
		}
	} while (math==0);
	point.setMath(math);
	fflush(stdin);
	cout << "\nPHYSICAL GRADE: ";
	do
	{
		gets_s(t_physical);
		physical = atof(t_physical);
		if (physical == 0)
		{
			cout << "\nWRONG INPUT, PLEASE FILL AGAIN PHYSICAL GRADE: ";
		}
	} while (physical == 0);
	point.setPhysical(physical);
	fflush(stdin);
	cout << "\nALCHEMIST GRADE: ";
	do
	{
		gets_s(t_alchemist);
		alchemist = atof(t_alchemist);
		if (alchemist == 0)
		{
			cout << "\nWRONG INPUT, PLEASE FILL AGAIN ALCHEMIST GRADE: ";
		}
	} while (alchemist == 0); 
	point.setAlchemist(alchemist);
	fflush(stdin);
	tempStudent.setPoint(point);
	return tempStudent;
}
void StudentView::studentShow(Student student)
{
	cout << student.getId() << "\t" << student.getName() << "\t" << student.getAddress() << "\t" << student.getSex() << "\t" << student.getPoint().getMath() << "\t" << student.getPoint().getPhysical() << "\t\t" << student.getPoint().getAlchemist() << endl;
}
void StudentView::studentAddView()
{
	cout << "1.ADD FROM KEYBOARD: " << endl;
	cout << "2.ADD FROM FILE: " << endl;
}
void StudentView::studentSearchView()
{
	cout << "1.SEARCH BY NAME" << endl;
	cout << "2.SEARCH BY ID" << endl;
	cout << "3.SEARCH BY MATH POINT" << endl;
	cout << "4.SEARCH BY PHYSICAL POINT" << endl;
	cout << "5.SEARCH BY ALCHEMIST POINT" << endl;
	cout << "6.SEARCH BY TOTAL POINT" << endl;
}
void StudentView::studentModifyStudent(Student &student1)
{
	string name;
	string address;
	string sex;
	float math;
	float physical;
	float alchemist;
	int valid;
	char t_math[10], t_physical[10], t_alchemist[10];
	Point point;
	cout << "MODIFY STUDENT HAVE ID: " << student1.getId();
	getline(cin, name);
	cout << "NAME: ";
	getline(cin, name);
	student1.setName(name);
	cout << "ADDRESS: ";
	getline(cin, address);
	student1.setAddress(address);
	cout << "SEX: ";
	getline(cin, sex);
	student1.setSex(sex);
	cout << "\nMATH GRADE: ";
	do
	{
		gets_s(t_math);
		math = atof(t_math);
		if (math == 0)
		{
			cout << "\nWRONG INPUT, PLEASE FILL AGAIN MATH GRADE: ";
		}
	} while (math == 0);
	point.setMath(math);
	fflush(stdin);
	cout << "\nPHYSICAL GRADE: ";
	do
	{
		gets_s(t_physical);
		physical = atof(t_physical);
		if (physical == 0)
		{
			cout << "\nWRONG INPUT, PLEASE FILL AGAIN PHYSICAL GRADE: ";
		}
	} while (physical == 0);
	point.setPhysical(physical);
	fflush(stdin);
	cout << "\nALCHEMIST GRADE: ";
	do
	{
		gets_s(t_alchemist);
		alchemist = atof(t_alchemist);
		if (alchemist == 0)
		{
			cout << "\nWRONG INPUT, PLEASE FILL AGAIN ALCHEMIST GRADE: ";
		}
	} while (alchemist == 0);
	point.setAlchemist(alchemist);
	student1.setPoint(point);
}
void StudentView::studentSortView()
{
	cout << "1.SORT BY NAME: " << endl;
	cout << "2.SORT BY TOTAL POINT: " << endl;
}
void StudentView::studentStatisticView()
{
	cout << "1.BY POINT" << endl;
	cout << "2.TOTAL STUDENTS" << endl;
}
int StudentView::findID()
{
	int id;
	cout << "ENTER STUDENT'S ID: ";
	cin >> id;
	return id;
}