#include "../include/group.hpp"
#include "../include/cell.hpp"


group::group(int mines) : mines_(mines) {}

	
void group::addCell(cell& cell2)//Добавить ячейку в группу
{
	listcell.push_back(cell2);
}

int group::size()
{
	listcell.size();
}

int group::getMines()
{
	return mines_;
}

list <cell>& group::getList()
{
	return listcell;
}

void group::setProbabilities(float newPoss)
{
	for (auto it=listcell.begin(); it != listcell.end(); ++it)
	{
		it*.poss_=newPoss;
	}
}
list<float> group::getProbabilities()
{
	for (int i=0; i<listcell.size(); i++)
	{
		return cell.getPossibility();
	}
}

list<char> group::getValues()
{
	for (int i=0; i<listcell.size(); i++)
	{
		return cell.getValue();
	}
}

bool group::equal(group group2)//Экивалентность групп по ячейкам
{
	if (this->size() != group2.size()) return false;
	for (const auto& cell1 : this)
		{
		while(bool flag=false)
		for (const auto& cell2 : group2)
		if (cell1.x_ = cell2.x_ && cell1.y_ = cell2.y_)
			{flag=true;}
		if (!flag) return false;
		}
	return true;
}

bool group::contains(group group2)//group1 содержит в себе group2
{
	if (this->size() <= group2.size()) return false;
	for (const auto& cell2 : group2)
		{
		while(bool flag=false)
		for (const auto& cell1 : this)
		if (cell1.x_ = cell2.x_ && cell1.y_ = cell2.y_)
			{flag=true;}
		if (!flag) return false;
		}
	return true;
}


bool group::overlaps(group group2)//group1 пересекает group2
{
	int k=0;
	for (const auto& cell1 : this)
		{
		for (const auto& cell2 : group2)
		if (cell1.x_ = cell2.x_ && cell1.y_ = cell2.y_)
			k++;
		}
	if (k>0) return true
	else return false;
}

bool group::overlapstwice(group group2)//group1 пересекает group2 в двух местах
{
	int k=0; //то же самое что и в getOverlap
	for (const auto& cell1 : this)
		{
		for (const auto& cell2 : group2)
		if (cell1.x_ = cell2.x_ && cell1.y_ = cell2.y_)
			listcell.push_back(cell2);
		}
	group Overlap = listcell;
	for (auto it=Overlap.begin(); it != Overlap.end()-1; ++it) //Проходим по списку
	{  cell cell1=it*;
		for (auto it2=Overlap.begin()+a; it2 != Overlap.end(); ++it2)
		{	cell cell2=it2*;
			if (overlap.size()==2)//Если пересечение=2, делаем проверку
			if (abs(cell1.x_-cell2.x_)==2 || abs(cell1.y_-cell2.y_)==2) k=2;
			if (overlap.size()==4) k=4; //Если=4, то в любом случае пересекает дважды
		} 
	}
	if (k>0) return true
	else return false;
}

list <cell>& group::getOverlap(group group2)//составляем из пересекающихся ячеек новый список
{
	for (const auto& cell1 : this)
		{
		for (const auto& cell2 : group2)
		if (cell.x_ = cell2.x_ && cell1.y_ = cell2.y_)
		listcell.push_back(cell2);
		}
		group Gr = listcell;
		Gr.mines_=this.mines_-(group2.size()-Gr.size());
	return Gr;
}

void group::subtraction(group group2)//Вычитаем из текущей группы group2
{
	if (this->size() <= group2.size()) return false;
	for (const auto& cell2 : group2)
		{
		for (const auto& cell1 : this)
		if (cell1.x_ = cell2.x_ && cell1.y_ = cell2.y_)
			this.erase(cell1);
			
		}
	this.mines_-=group2.mines_;
	return true;
}


group::~group(int number)
{
}
