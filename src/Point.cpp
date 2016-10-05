#include "Point.h"

Point::Point(){}
int Point::getID()
{
	return this->id;
}
void Point::setID(int id){
	this-> id = id;
}
float Point::getMath()
{
	return this->math;
}
void Point::setMath(float math){
	this->math = math;
}
float Point::getPhysical()
{
	return this->physical;
}
void Point::setPhysical(float physical){
	this->physical = physical;
}
float Point::getAlchemist()
{
	return this->alchemist;
}
void Point::setAlchemist(float alchemist){
	this->alchemist = alchemist;
}
