#ifndef CELL_HPP
#define CELL_HPP

#include <string>
#include <iostream>

class cell
{
	private:
		char value_;
		float poss_;
		int x_;
		int y_;
		group *pGroup_;
	public:
		cell(int x, int y);
		void setPossibility(double newPoss);
		void getPossibility();
		void setValue(char newValue);
		void getValue();
		void PrintInFile(ostream& f);
		cell(int x, int y, char value);
		cell(int x, int y, char value, group *pGr);
		~cell(int x, int y);
};

#endif
