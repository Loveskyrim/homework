//Обозначим пустые открытые клетки одной из цифр 0-5 каждую, пусть '/' обозначает закрытую простую клетку.
#include "cell.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <iterator>
using namespace std;

group setGroup(cell** field2, int i2, int j2)
{	
	group pGroup_(field2[i2][j2].getValue()-'0');//Проверяем все окружающие ячейки
	for (int iGr=i2-1; iGr<i2+2; iGr++)
	{
		for (int jGr=j2-1; jGr<j2+2; jGr++)
		{
			if (field2[iGr][jGr].getValue()=='/')//Если клетка не открыта
			{
				cell pCell_(iGr, jGr, '/');
				pGroup_.addCell(field2[i2][j2]); //Включаем ячейку в группу
			}
		}
	}
	return pGroup_;
}

void probCorrect(const group &GroupCor, int minesCor)
{
    float sum=0.0;
    for (float elem : GroupCor.getProbabilities()) sum+=elem;//Вычисляем сумму вероятностей
        for (auto& Cell: GroupCor.getList())
        {
            Cell.setPossibility(Cell.getPossibility()*minesCor/sum);
        }
}


int main()
{
	ifstream ifs; //Файл для чтения
	unordered_set<group> groupSet; //Map состоящий из групп
	list<cell> finalCells;//Список для вывода в поток или файл
	int closedCells_=0;//количество закрытых ячеек
	
	ifs.open("example01.txt");
    if (!ifs.is_open())
        cerr << "File not found";
    else {
        int count = 0; //Создаем счетчик ячеек в файле

        char temp; //Временная переменная
        while (!ifs.eof())
        {
            ifs.get(temp);//Считываем в пустоту
            if (temp != ' ')
                count++;//Если не пробел, увеличиваем счетчик числа ячеек
        }
        ifs.seekg(0, ios::beg);//Переходим в начало файла
        ifs.clear();
        int count_space = 0;//Создаем счетчик пробелов в строке

        while (!ifs.eof())
        {
            ifs.get(temp);//Считываем в пустоту
            if (temp == ' ') count_space++;//Если пробел, увеличиваем счетчик числа пробелов в строке
            if (temp == '\n') break;//Если конец строки, прекращаем счет
        }
        ifs.seekg(0, ios::beg);//Переходим в начало файла
        ifs.clear();
        int height = count / (count_space + 1);
        int width = count_space + 1;
        int fieldSize_ = height * width;//количество ячеек в массиве "Поле"
        cell **field;
        field = new cell *[height];
        for (int row = 0; row < height; row++) field[row] = new cell[width];
        int k = 0;
        while (!ifs.eof()) {
            ifs.get(temp);//Пока не конец файла
            if ((temp != ' ') && (k < height)) {
                for (int j = 0; j < width; j++) {
                    field[k][j].setValue(temp);
                    field[k][j].setXY(k, j);
                }
                k++;
            }
        }

        for (int i = 0; i < height; i++)//Выводим массив полученных значений в поток
        {
            for (int j = 0; j < width; j++) {
                if (field[i][j].getValue() == '/') closedCells_++;
                cout << field[i][j].getValue() << "\t";
            }
            cout << "\n";
        }

        int setMines;
        cin >> setMines;

        if (setMines <= fieldSize_) //Если число мин не больше числа ячеек
        {
            if (setMines < closedCells_)//Если число мин меньше числа закрытых ячеек
            {
                for (int i2 = 0; i2 < height; i2++)//Проходим по полю
                {
                    for (int j2 = 0; j2 < width; j2++) {
                        if (field[i2][j2].getValue() != '/' &&
                            field[i2][j2].getValue() != '0')//Если ячейка открыта, создаем новую группу
                            setGroup(field, i2, j2);
                        groupSet.insert(setGroup(field, i2, j2));
                    }
                }
//-----------------------------------------------------------------------------------------------------------------//
                bool repeat1;
                do {
                    repeat1 = false;

                    for (group it: groupSet) // проходим по списку групп
                    {
                        group GroupI = it;
                        for (group it2: groupSet) // сравниваем ее с остальными меньшими группами
                        {
                            group GroupJ = it2;
                            if (it.equal(it2))                  // удаляем одинаковые группы
                            {
                                groupSet.erase(it);
                                break;
                            }
                            group parent(0);                               // большая группа
                            group child(0);                                // меньшая группа

                            if (it.size() >
                                it2.size())            // определяем большую и меньшую группы по кол-ву ячеек
                            {
                                parent = it;
                                child = it2;
                            } else {
                                child = it;
                                parent = it2;
                            }

                            if (parent.contains(child)) // если большая содержит меньшую
                            {
                                parent.subtraction(child);              //  то вычитаем меньшую из большей
                                repeat1 = true;                            //  фиксируем факт изменения групп
                            } else if (it.overlaps(it2) > 0) // иначе если группы пересекаются
                            {
                                if (it.getMines() > it2.getMines())// определяем большую и меньшую группы по кол-ву мин
                                {
                                    parent = it;
                                    child = it2;
                                } else {
                                    child = it;
                                    parent = it2;
                                }

                                group overlap = parent.getOverlap(child);// то берем результат пересечения
                                if (overlap.getMines() !=
                                    nullptr)    //  !!!!!!!!!!!!и если он имеет смысл (в результате пересечения выявились ячейки с 0% или 100%)
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
                                        unordered_set<cell> cells; // цикл устанавливает единое значение вероятности в каждой ячейке, учитывая различные значения вероятностей в ячейке от разных групп
                                        for (const auto &Group : groupSet) {
                                            for (auto &Cell: Group.getList()) {
                                                if (cells.count(Cell) == NULL) // если ячейка еще не в мапе
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
                                            for (auto &Group : groupSet)    // для каждой группы
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
                        if (field[i3][j3].getValue() == '/')//Если ячейка закрыта
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
    system("pause");
    getchar();
};