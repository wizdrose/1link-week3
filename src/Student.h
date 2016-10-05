#pragma once
#include<string>
#include<ostream>
#include"Point.h"
using namespace std;
class Student
{
private:
	int id;
	string name;
	string address;
	string sex;
	Point point;
public:
	void setId(int);
	int getId();
	void setName(string);
	string getName();
	void setAddress(string);
	string getAddress();
	void setSex(string);
	string getSex();
	void setPoint(Point point);
	Point getPoint();
	
	Student();

};

