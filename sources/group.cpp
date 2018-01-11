#include "group.hpp"
#include "cell.hpp"


group::group(int mines) : mines_(mines) {}

	
void group::addCell(cell& cell2)//Добавить ячейку в группу
{
	listcell.push_back(cell2);
}

unsigned long group::size() const
{
    return listcell.size();
}

int group::getMines() const
{
	return mines_;
}

void group::setMines(int newmines)
{
    mines_=newmines;
}

list <cell>& group::getList()
{
	return listcell;
}

const list <cell>& group::getList() const
{
    return listcell;
}

list<float> group::getProbabilities()
{
    list<float> listPoss;
	for (auto& it: listcell)
	{
		listPoss.push_back(it.getPossibility());
	}
    return listPoss;
}

bool group::equal(group group2) const//Экивалентность групп по ячейкам
{
	if (this->size() != group2.size()) return false;
	bool flag=false;
    for (auto& cell1 : this->getList())
		{
                    for (auto& cell2 : group2.getList())
		                if (cell1.getX() == cell2.getX() && cell1.getY() == cell2.getY())
			                flag=true;
            if (flag) flag = false;
            else return false;
		}
	return true;
}

bool group::contains(group group2)//group1 содержит в себе group2
{
	if (this->size() <= group2.size()) return false;
	bool flag=false;
    for (auto& cell2 : group2.getList())
		{
                    for (auto& cell1 : this->getList())
                        if (cell1.getX() == cell2.getX() && cell1.getY() == cell2.getY())
                            flag = true;
            if (flag) flag = false;
            else return false;
        }
	return true;
}


bool group::overlaps(group group2) const//group1 пересекает group2
{
	int k=0;
	for (auto& cell1 : this->getList())
		{
		for (auto& cell2 : group2.getList())
		if (cell1.getX() == cell2.getX() && cell1.getY() == cell2.getY())
			k++;
		}
    return k > 0;
}

bool group::overlapstwice(group group2)//group1 пересекает group2 в двух местах
{
	list<cell> Overlap;
	for (auto& cell1 : this->getList())
		{
		for (auto& cell2 : group2.getList())
		if (cell1.getX() == cell2.getX() && cell1.getY() == cell2.getY())
			Overlap.push_back(cell2);
		}

	for (const auto& it: Overlap) //Проходим по списку
	{
		for (const auto& it2: Overlap)
		{
			if (Overlap.size()>=2)//Если пересечение, делаем проверку
			    if ((it.getX()-it2.getX())==2 || abs(it.getY()-it2.getY())==2) return true;
		} 
	}
	return false;
}

group group::getOverlap(group group2)//составляем из пересекающихся ячеек новый список
{
    group Gr(0);
    for (auto& cell1 : this->getList())
    {
        for (auto& cell2 : group2.getList())
            if (cell1.getX() == cell2.getX() && cell1.getY() == cell2.getY())
                Gr.addCell(cell2);
    }
    Gr.setMines(static_cast<int>(this->getMines() - (group2.size() - Gr.size())));
	return Gr;
}

void group::subtraction(group group2)//Вычитаем из текущей группы group2
{

    if (this->size() <= group2.size())
        return;
	for (const auto& cell2 : group2.getList())
		{
		for (auto cell1=this->getList().begin(); cell1!=this->getList().end(); ++cell1)
		if (cell1->getX() == cell2.getX() && cell1->getY() == cell2.getY())
			this->getList().erase(cell1);
		}
	this->setMines(this->getMines()-group2.getMines());
}

bool group::operator==(const group &other) const
{ return (mines_ == other.mines_
          && this->equal(other));
}

bool group::operator<(const group &other) const
{
    return (mines_<other.mines_);
}

bool group::operator<(const group &other)
{
    return (mines_<other.mines_);
}

group::~group(void) {}
