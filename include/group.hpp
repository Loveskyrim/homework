#ifndef GROUP_HPP
#define GROUP_HPP

#include <list>
using namespace std;

class cell;

class group
{
	int mines_;
	list <cell> listcell;

public:
	group(int mines_);
	
	void addCell(cell& cell2);
	int size();
	int getMines();
	list <cell>& getList();
	void setProbabilities(float newPoss);
	list<float> getProbabilities();
	list<char> getValues();
	bool equal(group group2);
	bool contains (group group2);
	bool overlaps(group group2);
	bool overlapstwice(group group2);
	list <cell>& getOverlap(group group2);
	void subtraction(group group2);
	~group(int number);
};

#endif
