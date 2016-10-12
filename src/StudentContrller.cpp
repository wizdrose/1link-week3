#include "StudentContrller.h"
#include "StudentView.h"
#include"Student.h"
#include "StudentRepository.h"
#include<list>
#include<string.h>
#include <algorithm>
using namespace std;
StudentContrller::StudentContrller()
{
}

list<Student> StudentContrller::getStudents()
{
	StudentRepository student_repository;
	return student_repository.Read("Text.txt");
}

list<Student> StudentContrller::addStudent()
{
	list<Student> list_students;
	Student student1;
	StudentView student_view;
	StudentRepository student_repository;
	student_view.studentAddView();
	char ur_choice;
	cin >> ur_choice;
	if (ur_choice == '1')
	{
		char c;
		while (true)
		{
			int id = student_repository.lastId() + 1;
			student1 = student_view.studentsImport(id);
			list_students.push_back(student1);
			student_repository.Write(student1, "Text.txt");
			cout << "Do you want to add another record (Y/N)? ";
			cin >> c;
			if (c == 'Y' || c == 'y')
				continue;
			else
				break;
		}
	}
	if (ur_choice == '2')
	{
		string path;
		cout << "FILE'S PATH: ";
		cin >> path;
		list_students = student_repository.Read(path);
		for (list<Student>::iterator it = list_students.begin(); it != list_students.end(); ++it)
		{
			if (checkID((*it).getId()))
			{
				continue;
			}
			else
				student_repository.Write((*it), "Text.txt");
		}
	}
	return list_students;
}

struct CompareBy
{
	const string SORT_FIELD;
	CompareBy(const string& sort_field = "name")
		: SORT_FIELD(sort_field)
	{
		/* validate sort_field */
	}

	bool operator()(Student& a, Student& b)
	{
		if (SORT_FIELD == "name")
			return a.getName() < b.getName();
		else if (SORT_FIELD == "total")
			return a.getPoint().getMath() + a.getPoint().getPhysical() + a.getPoint().getAlchemist() < b.getPoint().getMath() + b.getPoint().getPhysical() + b.getPoint().getAlchemist();
		else if (SORT_FIELD == "idnum")
			return a.getId() < b.getId();
		/* throw exception or something */
	}
};
void StudentContrller::listStudent(list<Student> list_student)
{
	StudentView student_view;
	list<Student>::iterator it;
	StudentRepository student_repository;
	cout << "LIST OF STUDENT" << endl;
	cout << "ID\t" << "NAME\t" << "ADDRESS\t" << "SEX\t" << "MATH\t" << "PHYSICAL\t" << "ALCHEMIST\t" << endl;
	list_student = student_repository.Read("Text.txt");
	list_student.sort(CompareBy("idnum"));
	for (it = list_student.begin(); it != list_student.end(); ++it)
	{
		student_view.studentShow(*it);
		cout << "\n";
	}
}
void StudentContrller::deleteStudent()
{
	StudentRepository student_repository;
	list<Student> list_student = student_repository.Read("Text.txt");
	StudentView student_view;
	int id;
	id = student_view.findID();
	list<Student>::iterator it;
	for (it = list_student.begin(); it != list_student.end(); ++it)
	{
		if ((*it).getId() == id)
		{
			cout << "YOU HAVE DELETED STUDENT:" << (*it).getName() << endl;
			it = list_student.erase(it); //"list.erase()" will change the iterator!!!
			if (it == list_student.end()) break;
		}
	}
	student_repository.overWrite(list_student, "Text.txt");
}
void StudentContrller::modifyStudent()
{
	StudentRepository student_repository;
	list<Student> list_student = student_repository.Read("Text.txt");
	StudentView student_view;
	int id;
	id = student_view.findID();
	list<Student>::iterator it;
	for (it = list_student.begin(); it != list_student.end(); ++it)
	{
		if ((*it).getId() == id)
		{
			student_view.studentModifyStudent((*it));
		}
	}
	student_repository.overWrite(list_student, "Text.txt");
}
void StudentContrller::searchStudent(list<Student>& list_student)
{
	int id;
	string name;
	float math;
	float physical;
	float alchemist;
	float total;
	list<Student>::iterator it;
	StudentRepository student_repository;
	StudentView student_view;
	student_view.studentSearchView();
	char ur_choice;
	fflush(stdin);
	cin >> ur_choice;
	switch (ur_choice)
	{
	case '1':
		getline(cin, name);
		cout << "ENTER STUDENT'S NAME: ";
		getline(cin, name);
		for (it = list_student.begin(); it != list_student.end(); ++it)
		{
			if ((*it).getName().compare(name) == 0)
			{
				student_repository.Write(*it, "searchname.txt");
				student_view.studentShow(*it);
			}
		}
		break;
	case '2':
		cout << "ENTER STUDENT'S ID: ";
		cin >> id;
		for (it = list_student.begin(); it != list_student.end(); ++it)
		{
			if ((*it).getId() == id)
			{
				student_repository.Write(*it, "searchid.txt");
				student_view.studentShow(*it);
			}
		}
		break;
	case '3':
		cout << "ENTER MATH POINT: ";
		cin >> math;
		for (it = list_student.begin(); it != list_student.end(); ++it)
		{
			if ((*it).getPoint().getMath() == math)
			{
				student_repository.Write(*it, "searchmath.txt");
				student_view.studentShow(*it);
			}
		}
		break;
	case '4':
		cout << "ENTER PHYSICAL POINT: ";
		cin >> physical;
		for (it = list_student.begin(); it != list_student.end(); ++it)
		{
			if ((*it).getPoint().getPhysical() == physical)
			{
				student_repository.Write(*it, "searchphysic.txt");
				student_view.studentShow(*it);
			}

		}
		break;
	case '5':
		cout << "ENTER ALCHEMIST POINT: ";
		cin >> alchemist;
		for (it = list_student.begin(); it != list_student.end(); ++it)
		{
			if ((*it).getPoint().getAlchemist() == alchemist)
			{
				student_repository.Write(*it, "searchalchemist.txt");
				student_view.studentShow(*it);
			}

		}
	case '6':
		cout << "ENTER TOTAL POINT: ";
		cin >> total;
		for (it = list_student.begin(); it != list_student.end(); ++it)
		{
			float total_it = (*it).getPoint().getMath() + (*it).getPoint().getPhysical() + (*it).getPoint().getAlchemist();
			if (total_it == total)
			{
				student_repository.Write(*it, "searchtotal.txt");
				student_view.studentShow(*it);
			}

		}
		break;
	default:
		break;
	}
}
void StudentContrller::sortStudent()
{
	StudentRepository student_repository;
	list<Student> list_student = student_repository.Read("Text.txt");
	student_view.studentSortView();
	char ur_choice;
	cin >> ur_choice;
	StudentContrller std_contrl;
	list<Student>::iterator it;
	switch (ur_choice)
	{
	case '1':
		list_student.sort(CompareBy("name"));
		for (it = list_student.begin(); it != list_student.end(); ++it)
		{
			student_view.studentShow(*it);
			cout << "\n";
		}
		break;

	case '2':
		list_student.sort(CompareBy("total"));
		for (it = list_student.begin(); it != list_student.end(); ++it)
		{
			student_view.studentShow(*it);
			cout << "\n";
		}
	default:
		break;
	}
}
void StudentContrller::statisticStudent()
{
	StudentRepository student_repository;
	list<Student> list_student = student_repository.Read("Text.txt");
	student_view.studentStatisticView();
	char selection;
	cin >> selection;
	int i = 0;
	if (selection == '1') 
	{
		int a=0, b=0;
		cout << "POINT FROM: ";
		cin >> a;
		cout << " TO: ";
		cin >> b;
		for (list<Student>::iterator it = list_student.begin(); it != list_student.end(); ++it)
			{
				int total = (*it).getPoint().getMath() + (*it).getPoint().getPhysical() + (*it).getPoint().getAlchemist();
				if (a <= total && total <= b)
				{
					i++;
				}
			}
			cout << "NUMBER OF STUDENTS: ";
			cout << i << endl;
	}
	if (selection == '2')
	{
		for (list<Student>::iterator it = list_student.begin(); it != list_student.end(); ++it)
		{
			i++;
		}
		cout << "NUMBER OF STUDENTS: ";
		cout << i << endl;
	}
}
bool StudentContrller::checkID(int id)
{
	list<Student> list_student;
	list_student = student_repository.Read("Text.txt");
	for (list<Student>::iterator it = list_student.begin(); it != list_student.end(); it++)
	{
		if ((*it).getId() == id)
		{
			return true;
		}
		else
			return false;
	}
}
StudentContrller::~StudentContrller()
{
}
