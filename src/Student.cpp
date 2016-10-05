#include "Student.h"


Student::Student()
{
}
void Student::setId(int id){
	this->id = id;
}
int Student::getId(){
	return this->id;
}
void Student::setName(string name){
	this->name = name;
}
string Student::getName(){
	return this->name;
}
void Student::setAddress(string address){
	this->address = address;
}
string Student::getAddress(){
	return this->address;
}
void Student::setSex(string sex){
	this->sex = sex;
}
string Student::getSex(){
	return this->sex;
}
void Student::setPoint(Point point){
	this->point = point;
}
Point Student::getPoint(){
	return this->point;
}
template<typename T>
struct greater
{
	bool operator()(const T &a, const T &b)
	{
		//compare a and b and return either true or false.
		return a > b;
	}
};