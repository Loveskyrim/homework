#ifndef CELL_HPP
#define CELL_HPP

#include <string>
#include <iostream>
#include <list>
#include <cstring>
#include "group.hpp"
class cell
{
private:
		char value_;//1 byte
		float poss_;//4 byte
		int x_;//4 byte
		int y_;//4 byte
public:
		cell();
		cell(int x, int y, char newValue);
		void setPossibility(float newPoss);
		void setValue(char newValue);
		char getValue() const;
		float getPossibility() const;
		void setXY(int x, int y);
		int getX() const;
		int getY() const;
		//void PrintInFile(ostream& f);
		bool operator <(const cell &x) const;
        bool operator <(const cell &x);
        bool operator==(const cell &other) const;
        bool operator==(const cell &other);
		~cell();
};

#endif
