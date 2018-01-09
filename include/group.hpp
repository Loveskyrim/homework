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
    explicit group(int mines_);
	
	void addCell(cell& cell2);
	unsigned long size() const;
	int getMines() const;
    void setMines(int newmines);
	list <cell>& getList() const;
	list<float> getProbabilities() const;
	bool equal(group group2);
	bool contains (group group2);
	bool overlaps(group group2);
	bool overlapstwice(group group2);
	group getOverlap(group group2);
	void subtraction(group group2);
	~group();
};

#endif
