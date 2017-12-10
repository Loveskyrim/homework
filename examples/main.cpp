#include <iostream>
#include "cell.hpp"
#include "group.hpp"
#include <fstream>
#include <cmath>
using namespace std;

void setGroup(cell field[i][j])
{	
	
}


void main()
{
	group *pGroup_;
	cell  *pCell_;
	int number_;
	int mines_;
	float poss_;
	ofstream *ofs; //Файл для записи
	ifstream *ifs; //Файл для чтения
	unordered_map<group, int> groupMap; //Map состоящий из групп

	int n=0, m=0;	
	cell field[n][m];
	int fieldSize_;//количество ячеек в массиве "Поле"
	int closedCells_;//количество закрытых ячеек
	cell Cell_;
	
	while(!ifs.eof())
	{
		
	ifs>>Cell_;
		if(strcmp(Cell_,'\n') == 0) j++;
		field[i][j] = Cell_;
	}


	int groupCount=0; //Количество групп

	int setMines;
	cin >> setMines;
	if (setMines<=fieldSize_) //Если число мин не больше числа ячеек
	{
		if (setMines<closedCells_)//Если число мин меньше числа закрытых ячеек
		{
			for (int i=0; i<n; i++)//Проходим по полю 
			{
				for (int j=0; j<m; j++)
				{
					if ((field[i][j].getValue()<>'/') || (field[i][j].getValue()<>'x'))//Если ячейка открыта, создаем новую группу
					{pGroup=new group(number);
					for (int iGr=i-1; iGr<i+2; iGr++)
						{
							for (int jGr=j-1; jGr<j+2; jGr++)
							{
								if ((field[iGr][jGr]<>NULL) && ((field[iGr][jGr].getValue()=='/') || (field[iGr][jGr].getValue()=='x')))
								{
								pCell_=new cell(iGr, jGr, value);
								pGroup_.addCell(field[i][j]); //Включаем ячейку в группу
								}
							}
						}++groupCount;
					}
					groupMap.insert(groupCount, *pGroup);
				}
			}
//-----------------------------------------------------------------------------------------------------------------//		
		bool repeat;
       		do{
          	repeat=false;

            	for(auto it=groupMap.begin(); it != groupMap.end()-1; ++it) // проходим по списку групп
		{
			group GroupI = it*;
			for (auto it2=groupMap.begin()+a; it2 != groupMap.end(); ++it2) // сравниваем ее с остальными меньшими группами
			{	group GroupJ = it2*;
				if (groupI.equal(groupJ))                  // удаляем одинаковые группы
                        	{
					groups.erase(groupI);break;
				}
				group parent;                               // большая группа
				group child;                                // меньшая группа
			
				if (groupI.size()>groupJ.size())            // определяем большую и меньшую группы по кол-ву ячеек
                        	{
					parent=groupI;child=groupJ;
				}
				else {child=groupI;parent=groupJ;}
                    
				if (parent.contains(child)) // если большая содержит меньшую
				{               
	                	        parent.subtraction(child);              //  то вычитаем меньшую из большей
	                	        repeat=true;                            //  фиксируем факт изменения групп
				}
				else if (groupI.overlaps(groupJ) > 0) // иначе если группы пересекаются
				{
					if (groupI.getMines()>groupJ.getMines())// определяем большую и меньшую группы по кол-ву мин
					{
						parent=groupI;child=groupJ;
					}
                        	else {child=groupI;parent=groupJ;}
				
				group overlap = parent.getOverlap(child);// то берем результат пересечения
                        	if (overlap != NULL) 	//  и если он имеет смысл (в результате пересечения выявились ячейки с 0% или 100%)
				{
					if ((!parent.overlapstwice(child)) || (overlap.size()>2))
					{
						groupMap.insert(overlap);//то вносим соответствующие коррективы в список
                        			parent.subtraction(overlap);
                        			child.subtraction(overlap);
                        			repeat=true;	
					}
					else
					{
//--------------------------------------------------------------------------------------------------------------------//					
					unordered_map<cell, float>* cells= new unordered_map<>(); // цикл устанавливает единое значение вероятности в каждой ячейке, учитывая различные значения вероятностей в ячейке от разных групп
        			for (group Group : groupMap)
				{
            				for (cell Cell: group.getList())
					{
						float value;
					if (find(Cell)==null) // если ячейка еще не в мапе
                   				{
						cells.insert(Cell,(Group.getMines()/ Group.size()));// то добавляем ее со значением из группы
						Cell.setPossibility(Group.getMines()/ Group.size());
						}
                			else     //если она уже в мапе, то редачим ее
						{
						cells.emplace_hint(Cell,1-(1-(Group.getMines()/ Group.size())*(1-Cell.getPossibility));
            					Cell.setPossibility(1-(1-(Group.getMines()/ Group.size())*(1-Cell.getPossibility));
						}
					}
        			}
        // цикл корректирует значения с учетом того, что сумма вероятностей в группе должна быть равна количеству мин в группе
        bool repeat;
       
	do{
            repeat=false;
            for (group Group : groupMap){                      // для каждой группы
                list<float> prob = Group.getProbabilities()*100; //  берем список вероятностей всех ячеек в группе в процентах
                float sum=0.0;
                for (float elem : prob) sum+=elem;             //  вычисляем ее сумму
                int mines= Group.getMines()*100;             //  умножаем количество мин в группе на сто (из-за процентов)
                if (abs(sum-mines)>1){                  //  если разница между ними велика, то проводим корректировку
                    repeat=true;                             //   фиксируем факт корректировки
                              //   корректируем список
                    for (int i=0;i< Group.size();i++){       //   заносим откорректированные значения из списка в ячейки
			group GrPoss = Group.getList();
                        float value= (Group.getMines()/sum);
                        setPossibility(value);
                    }
                }
            }
        }
        while (repeat);
        for (Cell cell:cells.keySet()){  // перестраховка
            if (cell.getPossibility()>99)cell.setPossibility(99);
            if (cell.getPossibility()<0)cell.setPossibility(0);
        }
    }
					}


                        		
				}
			}	
		}
	}
}
        while(repeat);





		}
		else if (setMines==closedCells_) goto bestSituation;//Надо переделать (присвоить нулевое значение вероятности каждой ячейке и вывести)
	}
	else throw "Too many mines for this field:"+setMines+" mines for"+fieldSize_+" cells";
	};
