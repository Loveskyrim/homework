#include "../include/cell.hpp"

cell::cell(int x, int y) : x_(x), y_(y)
{}

void cell::setPossibility(float newPoss)
{
	poss_=newPoss;
	
}

void cell::getPossibility()
{
	return poss_;	
}

void cell::setValue(char newValue)
{
	value_=newValue;
}

void cell::getValue()
{
	return value_;
}

void cell::PrintInFile(ostream& f)
{
	f<< "["<< x << "][" << y << "], перспективность=" << (1-poss);
}

cell::cell(int x, int y, char value)//Вызов ячейки без добавления в группу
{
	x_=x;
	y_=y;
	value_=value;
}


cell::cell(int x, int y, char value, group *pGr)//Включаем ячейку в группу
{
	x_=x;
	y_=y;
	value_=value;
	pGroup_=pGr;
	pGroup->listcell.push_back(*this);
	
}

cell::~cell(int x, int y){}
