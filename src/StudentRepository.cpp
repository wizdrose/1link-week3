#include "StudentRepository.h"
#include<fstream>

StudentRepository::StudentRepository()
{
}
void StudentRepository::Write(Student& student,string path)
{
	ofstream file(path, ios::app);
	file << student.getId()<<"\t";
	file << student.getName()<<"\t";
	file << student.getAddress()<<"\t";
	file << student.getSex()<<"\t" ;
	file << student.getPoint().getMath()<<"\t";
	file << student.getPoint().getPhysical()<<"\t"; 
	file << student.getPoint().getAlchemist()<<"\t";
	file << "\n";
	file.close();
}
int StudentRepository::lastId()
{
	int t=0;
	string line;
	ifstream file("Text.txt", ios::in);
	while (getline(file,line))
	{
		int position = line.find("\t");
		t = stoi(line.substr(0, position));
	}
	return t;
}
list<Student> StudentRepository::Read(string path)
{
	string line;
	ifstream file(path, ios::in);

	Student student;
	list<Student> list_students;
	while (getline(file, line))
	{
		Student student;
		Point point;
		int id;
		string name;
		string address;
		string sex;
		float math;
		float physical;
		float alchemist;
		bool flag = true;
		try
		{

			int position = line.find("\t");
			id = stoi(line.substr(0, position));
			line = line.substr(position + 1);
			position = line.find("\t");
			name = line.substr(0, position).c_str();
			line = line.substr(position + 1);
			position = line.find("\t");
			address = line.substr(0, position).c_str();
			line = line.substr(position + 1);
			position = line.find("\t");
			sex = line.substr(0, position).c_str();
			line = line.substr(position + 1);
			position = line.find("\t");
			math = stof((line.substr(0, position)).c_str());
			line = line.substr(position + 1);
			position = line.find("\t");
			physical = stof((line.substr(0, position)).c_str());
			position = line.find("\t");
			alchemist = stof((line.substr(0, position)).c_str());
			student.setId(id);
			student.setName(name);
			student.setAddress(address);
			student.setSex(sex);
			point.setMath(math);
			point.setPhysical(physical);
			point.setAlchemist(alchemist);
			student.setPoint(point);
			list_students.push_back(student);
		}
		catch (const std::exception&)
		{
			flag = false;
		}
		if (flag == false) { continue; }
	}
	file.close();
	return list_students;
}
void StudentRepository::overWrite(list<Student> list_student, string path)
{
	ofstream file(path, ios::trunc);
	for (list<Student>::iterator it = list_student.begin(); it != list_student.end(); ++it)
	{
		file << (*it).getId() << "\t";
		file << (*it).getName() << "\t";
		file << (*it).getAddress() << "\t";
		file << (*it).getSex() << "\t";
		file << (*it).getPoint().getMath() << "\t";
		file << (*it).getPoint().getPhysical() << "\t";
		file << (*it).getPoint().getAlchemist() << "\t";
		file << "\n";
	}
	file.close();
}

StudentRepository::~StudentRepository()
{
	
}
