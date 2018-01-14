#include "cell.hpp"

cell::cell(): x_(0), y_(0), value_('/') {}

cell::cell(int x, int y, char newValue) : x_(x), y_(y), value_(newValue)
{}

void cell::setPossibility(float newPoss)
{
	poss_=newPoss;
	
}

void cell::setValue(char newValue)
{
	value_=newValue;
}

char cell::getValue() const
{
	return value_;
}

float cell::getPossibility() const
{
	return poss_;
}
void cell::setXY(int x, int y)  {x_=x; y_=y;}
int cell::getX() const { return x_;}
int cell::getY() const { return y_;}

/*void cell::PrintInFile(ostream& f)
{
	f<< "["<< x << "][" << y << "], перспективность=" << (1-poss_);
}*/



bool cell::operator <(const cell &x) const
{
	return ( this->getPossibility() < x.getPossibility());
}

bool cell::operator <(const cell &x)
{
	return ( this->getPossibility() < x.getPossibility());
}

bool cell::operator==(const cell &other) const
{ return (value_ == other.value_
		  && poss_ == other.poss_
          && x_ == other.x_
		  && y_ == other.y_);
}

bool cell::operator==(const cell &other)
{ return (value_ == other.value_
          && poss_ == other.poss_
		  && x_ == other.x_
		  && y_ == other.y_);
}

cell::~cell(void){}
