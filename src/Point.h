#pragma once
class Point
{
protected:
	int id;
	float math;
	float physical;
	float alchemist;
public:
	int getID();
	void setID(int);
	float getMath();
	void setMath(float);
	float getPhysical();
	void setPhysical(float);
	float getAlchemist();
	void setAlchemist(float);
	Point();

};

