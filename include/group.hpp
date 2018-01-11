#ifndef GROUP_HPP
#define GROUP_HPP

#include <list>
using namespace std;

class cell;

class group
{
private:
    int mines_;
	list <cell> listcell;

public:
    group(int mines_);
	
	void addCell(cell& cell2);
	unsigned long size() const;
	int getMines() const;
    void setMines(int newmines);
	list <cell>& getList();
    const list <cell>& getList() const;
    list<float> getProbabilities();
	bool equal(group group2) const;
	bool contains (group group2);
	bool overlaps(group group2) const;
	bool overlapstwice(group group2);
	group getOverlap(group group2);
	void subtraction(group group2);
    bool operator==(const group &other) const;
    bool operator<(const group &other) const;
    bool operator<(const group &other);
	~group();
};

#endif
