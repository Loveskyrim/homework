//Обозначим пустые открытые клетки одной из цифр 0-5 каждую, пусть '/' обозначает закрытую простую клетку.
#include "cell.hpp"
#include <fstream>
#include <cmath>
#include <set>
#include <iterator>
using namespace std;

group setGroup(cell field2[], int i2, int j2, int height2, int width2)
{
	group pGroup_(field2[i2*width2+j2].getValue()-'0');//Проверяем все окружающие ячейки
	if (i2==0 && j2==0)
    {
        for (int iGr=0; iGr<2; iGr++)
        {
            for (int jGr=0; jGr<2; jGr++)
            {
                if (field2[iGr*width2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    cell pCell_(iGr, jGr, 'x');
                    pGroup_.addCell(field2[iGr*width2+jGr]); //Включаем ячейку в группу
                }
            }
        }return pGroup_;
    }

else    if (i2==0 && j2>0 && j2<width2)
    {
        for (int iGr=0; iGr<2; iGr++)
        {
            for (int jGr=j2-1; jGr<j2+2; jGr++)
            {
                if (field2[iGr*width2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    cell pCell_(iGr, jGr, 'x');
                    pGroup_.addCell(field2[iGr*width2+jGr]); //Включаем ячейку в группу
                }
            }
        }return pGroup_;
    }

    else    if (i2==height2-1 && j2>0 && j2<width2)
    {
        for (int iGr=height2-1; iGr<height2+1; iGr++)
        {
            for (int jGr=j2-1; jGr<j2+2; jGr++)
            {
                if (field2[iGr*width2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    cell pCell_(iGr, jGr, 'x');
                    pGroup_.addCell(field2[iGr*width2+jGr]); //Включаем ячейку в группу
                }
            }
        }return pGroup_;
    }
    else    if (i2>0 && i2<height2-1 && j2==0)
    {
        for (int iGr=i2-1; iGr<i2+2; iGr++)
        {
            for (int jGr=0; jGr<2; jGr++)
            {
                if (field2[iGr*width2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    cell pCell_(iGr, jGr, 'x');
                    pGroup_.addCell(field2[iGr*width2+jGr]); //Включаем ячейку в группу
                }
            }
        }return pGroup_;
    }

    else    if (i2>0 && i2<height2-1 && j2==width2-1)
    {
        for (int iGr=i2-1; iGr<i2+2; iGr++)
        {
            for (int jGr=width2-1; jGr<width2+1; jGr++)
            {
                if (field2[iGr*width2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    cell pCell_(iGr, jGr, 'x');
                    pGroup_.addCell(field2[iGr*width2+jGr]); //Включаем ячейку в группу
                }
            }
        }return pGroup_;
    }

    else    if (i2==0 && j2==width2-1)
    {
        for (int iGr=0; iGr<2; iGr++)
        {
            for (int jGr=width2-2; jGr<width2; jGr++)
            {
                if (field2[iGr*width2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    cell pCell_(iGr, jGr, 'x');
                    pGroup_.addCell(field2[iGr*width2+jGr]); //Включаем ячейку в группу
                }
            }
        }return pGroup_;
    }

    else    if (i2==height2-1 && j2==0)
    {
        for (int iGr=height2-2; iGr<height2; iGr++)
        {
            for (int jGr=0; jGr<2; jGr++)
            {
                if (field2[iGr*width2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    cell pCell_(iGr, jGr, 'x');
                    pGroup_.addCell(field2[iGr*width2+jGr]); //Включаем ячейку в группу
                }
            }
        }return pGroup_;
    }

    else    if (i2==height2-1 && j2==width2-1)
    {
        for (int iGr=height2-2; iGr<height2; iGr++)
        {
            for (int jGr=width2-2; jGr<width2; jGr++)
            {
                if (field2[iGr*width2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    cell pCell_(iGr, jGr, 'x');
                    pGroup_.addCell(field2[iGr*width2+jGr]); //Включаем ячейку в группу
                }
            }
        }return pGroup_;
    }
    else
    if (i2>0 && i2<height2-1 && j2>0 && j2<width2-1)
    {
        for (int iGr = i2 - 1; iGr < i2 + 2; iGr++)
        {
            for (int jGr = j2 - 1; jGr < j2 + 2; jGr++)
            {
                if (field2[iGr * width2 + jGr].getValue() == 'x')//Если клетка не открыта
                {
                    cell pCell_(iGr, jGr, 'x');
                    pGroup_.addCell(field2[iGr * width2 + jGr]); //Включаем ячейку в группу
                }
            }
        }
    }
	return pGroup_;
};

void probCorrect(group &GroupCor, int minesCor)
{
    float sum=0.0;
    for (float elem : GroupCor.getProbabilities()) sum+=elem;//Вычисляем сумму вероятностей
        for (auto& Cell: GroupCor.getList())
        {
            Cell.setPossibility(Cell.getPossibility()*minesCor/sum);
        }
};

//===============================================================================================================
int main()
{
	ifstream ifs; //Файл для чтения
	std::set<group> groupSet; //Set состоящий из групп
	list<cell> finalCells;//Список для вывода в поток или файл

    try {
        ifs.open("/root/Рабочий стол/homework/examples/example01.txt");
        if (!ifs.is_open()) throw 1;
    }catch (int Err){cerr << "Возникло исключение: "<< Err << "-Файл не найден" << endl;};


    if (ifs.is_open())
    {
        int closedCells_=0;//количество закрытых ячеек
        int height;
        int width;
        char temp; //Временная переменная

        ifs >>height>>width;
        int fieldSize_ = height * width;//количество ячеек в массиве "Поле"

        cell field[height][width];
        do{
            ifs.get(temp);
        } while (temp!='\n');


            for (int k = 0; k < height; k++) {
                for (int l = 0; l < width; l++) {
                    ifs.get(temp);
                    if (temp == '\f') break;//Пока не конец файла
                    if (temp == '\n') ifs.get(temp);
                    if (temp != ' ' && temp != '\n') field[k][l].setValue(temp);
                    if (field[k][l].getValue()=='x') closedCells_++;
                    field[k][l].setXY(k, l);
                }
            }

        for (int i = 0; i < height; i++)//Выводим массив полученных значений в поток
        {
            for (int j = 0; j < width; j++) {

                cout << field[i][j].getValue() << "\t";
            }
            cout << "\n";
        }

        int setMines;
        cout<<"Ввод количества мин:"<<endl;
        cin >> setMines;

        if (setMines <= fieldSize_) //Если число мин не больше числа ячеек
        {
            if (setMines < closedCells_)//Если число мин меньше числа закрытых ячеек
            {
                for (int i2 = 0; i2 < height; i2++)//Проходим по полю
                {
                    for (int j2 = 0; j2 < width; j2++) {
                        if (field[i2][j2].getValue() != 'x' &&
                            field[i2][j2].getValue() != '0'){//Если ячейка открыта, создаем новую группу
                            try
                            {
                                if (setGroup(reinterpret_cast<cell*>(field), i2, j2, height, width).size()< field[i2][j2].getValue()-'0') throw 2;
                                else  setGroup(reinterpret_cast<cell*>(field), i2, j2, height, width);
                            }catch (int Err) {
                                cerr<<"Возникло исключение:"<<Err<<"Значение в ячейке больше числа закрытых ячеек вокруг нее"<<endl;}

                        groupSet.insert(setGroup(reinterpret_cast<cell*>(field), i2, j2, height, width));}
                    }
                }
//-----------------------------------------------------------------------------------------------------------------//
                bool repeat1;
                do {
                    repeat1 = false;

                    for (auto it=groupSet.begin(); it!=groupSet.end(); ++it) // проходим по списку групп
                    {
                        group GroupI = *it;
                        for (auto it2=groupSet.begin(); it2!=groupSet.end(); ++it2) // сравниваем ее с остальными меньшими группами
                        {
                            group GroupJ = *it2;
                            if (it != it2 && it2 !=groupSet.begin()) {
                            if (GroupI.equal(GroupJ))                  // удаляем одинаковые группы
                            {
                                groupSet.erase(GroupJ);
                                break;
                            }
                        }
                            group parent(0);                               // большая группа
                            group child(0);                                // меньшая группа

                            if (GroupI.size() >
                                GroupJ.size())            // определяем большую и меньшую группы по кол-ву ячеек
                            {
                                parent = GroupI;
                                child = GroupJ;
                            } else {
                                child = GroupI;
                                parent = GroupJ;
                            }

                            if (parent.contains(child)) // если большая содержит меньшую
                            {
                                parent.subtraction(child);              //  то вычитаем меньшую из большей
                                repeat1 = true;                            //  фиксируем факт изменения групп
                            } else if (GroupI.overlaps(GroupJ) > 0) // иначе если группы пересекаются
                            {
                                if (GroupI.getMines() > GroupJ.getMines())// определяем большую и меньшую группы по кол-ву мин
                                {
                                    parent = GroupI;
                                    child = GroupJ;
                                } else {
                                    child = GroupI;
                                    parent = GroupJ;
                                }

                                group overlap = parent.getOverlap(child);// то берем результат пересечения
                                if (overlap.getMines() != 0)    //  !!!!!!!!!!!!и если он имеет смысл (в результате пересечения выявились ячейки с 0% или 100%)
                                {
                                    if (!parent.overlapstwice(child))//Если не пересекает дважды
                                    {
                                        groupSet.insert(overlap);//то вносим соответствующие коррективы в список
                                        parent.subtraction(overlap);
                                        child.subtraction(overlap);
                                        repeat1 = true;
                                    } else//Если пересекает дважды
                                    {
//--------------------------------------------------------------------------------------------------------------------//
                                        set<cell> cells; // цикл устанавливает единое значение вероятности в каждой ячейке, учитывая различные значения вероятностей в ячейке от разных групп
                                        for (group Group : groupSet) {
                                            for (auto &Cell: Group.getList()) {
                                                if (cells.count(Cell) == 0) // если ячейка еще не в мапе
                                                {
                                                    cells.insert(Cell);// то добавляем ее со значением из группы
                                                    Cell.setPossibility(Group.getMines() / Group.size());
                                                } else     //если она уже в мапе, то редачим ее
                                                {
                                                    Cell.setPossibility(1 - (1 - (Group.getMines() / Group.size()) *
                                                                                 (1 - Cell.getPossibility())));
                                                }
                                            }
                                        }
                                        // цикл корректирует значения с учетом того, что сумма вероятностей в группе должна быть равна количеству мин в группе
                                        bool repeat2;
                                        do {
                                            repeat2 = false;
                                            for (group Group : groupSet)    // для каждой группы
                                            {
                                                //  берем список вероятностей всех ячеек в группе
                                                float sum = 0.0;
                                                for (float elem : Group.getProbabilities()) sum += elem;//Вычисляем ее сумму
                                                int mines = Group.getMines();//Получаем количество мин в группе
                                                if (abs(sum - mines) >
                                                    0.01)//Если разница между ними велика, то проводим корректировку
                                                {
                                                    repeat2 = true;   //фиксируем факт корректировки
                                                    probCorrect(Group, mines); // Корректируем список
                                                }
                                            }
                                        } while (repeat2);

                                        for (cell NewCell: cells) {  // перестраховка
                                            if (NewCell.getPossibility() > 99) NewCell.setPossibility(99);
                                            if (NewCell.getPossibility() < 0) NewCell.setPossibility(0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                } while (repeat1);

                for (int i3 = 0; i3 < height; i3++)//Проходим по полю
                    for (int j3 = 0; j3 < width; j3++) {
                        if (field[i3][j3].getValue() == 'x')//Если ячейка закрыта
                            finalCells.push_back(field[i3][j3]);//Добавляем ячейки
                    }
                finalCells.sort();


                for (const auto &it: finalCells) {
                    std::cout << 1 - (it.getPossibility()) << "-possibility x[" << it.getX() << "] y[" << it.getY()
                              << "]";
                    std::cout << std::endl;
                }


            } else if (setMines == closedCells_)
                std::cout << "Every cell already has a mine";//Надо переделать (присвоить нулевое значение вероятности каждой ячейке и вывести)
        } else std::cout << "Too many mines for this field:" << setMines << " mines for" << fieldSize_ << " cells";

        ifs.close();
    }

    getchar();
    return 0;
};