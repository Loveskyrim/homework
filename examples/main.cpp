//Обозначим пустые открытые клетки одной из цифр 0-5 каждую, пусть '/' обозначает закрытую простую клетку.
#include "cell.hpp"
#include <fstream>
#include <cmath>
#include <set>
#include <iterator>
using namespace std;

group setGroup(cell field2[], int i2, int j2, int height2, int width2)
{
	group pGroup_(field2[i2*height2+j2].getValue()-'0');//Проверяем все окружающие ячейки
	if (i2==0 && j2==0)
    {
        for (int iGr=0; iGr<2; iGr++)
        {
            for (int jGr=0; jGr<2; jGr++)
            {
                if (field2[iGr*height2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    pGroup_.addCell(field2[iGr*height2+jGr]); //Включаем ячейку в группу
                }
            }
        }
        for (auto& it: pGroup_.getList())
        {
            it.setPossibility((float)pGroup_.getMines()/pGroup_.size());
        }
        list<float> listPoss;
        pGroup_.getProbabilities(listPoss);
        for (float elem : listPoss) cout<<elem<<endl;//Правильно выводит лист вероятностей
    }

     if (i2==0 && j2>0 && j2<width2)
    {
        for (int iGr=0; iGr<2; iGr++)
        {
            for (int jGr=j2-1; jGr<j2+2; jGr++)
            {
                if (field2[iGr*height2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    pGroup_.addCell(field2[iGr*height2+jGr]); //Включаем ячейку в группу
                }
            }
        }
        for (auto& it: pGroup_.getList())
        {
            it.setPossibility((float)pGroup_.getMines()/pGroup_.size());
        }
        list<float> listPoss;
        pGroup_.getProbabilities(listPoss);
        for (float elem : listPoss) cout<<elem<<endl;//Правильно выводит лист вероятностей
    }

     if (i2==height2-1 && j2>0 && j2<width2)
    {
        for (int iGr=height2-1; iGr<height2+1; iGr++)
        {
            for (int jGr=j2-1; jGr<j2+2; jGr++)
            {
                if (field2[iGr*height2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    pGroup_.addCell(field2[iGr*height2+jGr]); //Включаем ячейку в группу
                }
            }
        }
        for (auto& it: pGroup_.getList())
        {
            it.setPossibility((float)pGroup_.getMines()/pGroup_.size());
        }
        list<float> listPoss;
        pGroup_.getProbabilities(listPoss);
        for (float elem : listPoss) cout<<elem<<endl;//Правильно выводит лист вероятностей
    }
    if (i2 > 0 && i2 < height2 - 1 && j2 == 0)
    {
        for (int iGr=i2-1; iGr<i2+2; iGr++)
        {
            for (int jGr=0; jGr<2; jGr++)
            {
                if (field2[iGr*height2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    pGroup_.addCell(field2[iGr*height2+jGr]); //Включаем ячейку в группу
                }
            }
        }
        for (auto& it: pGroup_.getList())
        {
            it.setPossibility((float)pGroup_.getMines()/pGroup_.size());
        }
        list<float> listPoss;
        pGroup_.getProbabilities(listPoss);
        for (float elem : listPoss) cout<<elem<<endl;//Правильно выводит лист вероятностей
    }

    if (i2>0 && i2<height2-1 && j2==width2-1)
    {
        for (int iGr=i2-1; iGr<i2+2; iGr++)
        {
            for (int jGr=width2-1; jGr<width2+1; jGr++)
            {
                if (field2[iGr*height2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    pGroup_.addCell(field2[iGr*height2+jGr]); //Включаем ячейку в группу
                }
            }
        }
        for (auto& it: pGroup_.getList())
        {
            it.setPossibility((float)pGroup_.getMines()/pGroup_.size());
        }
        list<float> listPoss;
        pGroup_.getProbabilities(listPoss);
        for (float elem : listPoss) cout<<elem<<endl;//Правильно выводит лист вероятностей
    }

    if (i2==0 && j2==width2-1)
    {
        for (int iGr=0; iGr<2; iGr++)
        {
            for (int jGr=width2-2; jGr<width2; jGr++)
            {
                if (field2[iGr*height2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    pGroup_.addCell(field2[iGr*height2+jGr]); //Включаем ячейку в группу
                }
            }
        }
        for (auto& it: pGroup_.getList())
        {
            it.setPossibility((float)pGroup_.getMines()/pGroup_.size());
        }
        list<float> listPoss;
        pGroup_.getProbabilities(listPoss);
        for (float elem : listPoss) cout<<elem<<endl;//Правильно выводит лист вероятностей
    }
    if (i2==height2-1 && j2==0)
    {
        for (int iGr=height2-2; iGr<height2; iGr++)
        {
            for (int jGr=0; jGr<2; jGr++)
            {
                if (field2[iGr*height2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    pGroup_.addCell(field2[iGr*height2+jGr]); //Включаем ячейку в группу
                }
            }
        }
        for (auto& it: pGroup_.getList())
        {
            it.setPossibility((float)pGroup_.getMines()/pGroup_.size());
        }
        list<float> listPoss;
        pGroup_.getProbabilities(listPoss);
        for (float elem : listPoss) cout<<elem<<endl;//Правильно выводит лист вероятностей
    }

    if (i2==height2-1 && j2==width2-1)
    {
        for (int iGr=height2-2; iGr<height2; iGr++)
        {
            for (int jGr=width2-2; jGr<width2; jGr++)
            {
                if (field2[iGr*height2+jGr].getValue()=='x')//Если клетка не открыта
                {
                    pGroup_.addCell(field2[iGr*height2+jGr]); //Включаем ячейку в группу
                }
            }
        }
        for (auto& it: pGroup_.getList())
        {
            it.setPossibility((float)pGroup_.getMines()/pGroup_.size());
        }
        list<float> listPoss;
        pGroup_.getProbabilities(listPoss);
        for (float elem : listPoss) cout<<elem<<endl;//Правильно выводит лист вероятностей
    }

    if (i2>0 && i2<height2-1 && j2>0 && j2<width2-1)
    {
        for (int iGr = i2 - 1; iGr < i2 + 2; iGr++)
        {
            for (int jGr = j2 - 1; jGr < j2 + 2; jGr++)
            {
                if (field2[iGr*height2+jGr].getValue() == 'x')//Если клетка не открыта
                {
                    pGroup_.addCell(field2[iGr*height2+jGr]); //Включаем ячейку в группу
                }
            }
        }

        for (auto& it: pGroup_.getList())
        {
            it.setPossibility((float)pGroup_.getMines() / pGroup_.size());
            cout<<it.getPossibility();//Выводит вероятности правильно
        }
        list<float> listPoss;
        pGroup_.getProbabilities(listPoss);
        for (float elem : listPoss) cout<<elem<<endl;//Правильно выводит лист вероятностей

    }
    return pGroup_;
};

void probCorrect(group &GroupCor, int minesCor)
{
    list<float> listPoss;
    GroupCor.getProbabilities(listPoss);
    float sum=0.0;
    for (float elem : listPoss) sum+=elem;//Вычисляем сумму вероятностей
        for (auto& Cell: GroupCor.getList())
        {
            Cell.setPossibility(Cell.getPossibility()*(float)minesCor/sum);
            cout<<Cell.getPossibility()<<'/'<<endl;//Не выводится, хотя по идее функция в main вызывается
        }
};

//===============================================================================================================
int main()
{
	
	ifstream ifs; //Файл для чтения
    ofstream *ofs; //Файл для записи
    string file, file2;
	std::list<group> groupSet; //Set состоящий из групп
	list<cell> finalCells;//Список для вывода в поток или файл
    cout<<"The file to read:"<<endl;
    cout<<"Example:/root/Рабочий_стол/homework/examples/example01.txt"<<endl;
    cin>>file; cout<<endl;
    cout<<"The file to write in"<<endl;
    cout<<"Example:/root/Рабочий_стол/homework/examples/example01_1.txt"<<endl;
    cin>>file2; cout<<endl;
        ifs.open(file);
        if (!ifs.is_open()) throw std::invalid_argument("Cannot open the file"+file);



    if (ifs.is_open())
    {
        int closedCells_=0;//количество закрытых ячеек
        int height;
        int width;
        char temp; //Временная переменная

        ifs >>height>>width;
        int fieldSize_ = height * width;//количество ячеек в массиве "Поле"

      //  cell field[height][width];
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
     //   cout<<"Ввод количества мин (11111):";
		cout << "SetMines=";
        cin >> setMines;
      //  setMines=4;
        cout<<"setMines="<<setMines;

        if (setMines <= fieldSize_) //Если число мин не больше числа ячеек
        {
            if (setMines < closedCells_)//Если число мин меньше числа закрытых ячеек
            {
                groupSet.clear();
                for (int i2 = 0; i2 < height; i2++)//Проходим по полю
                {
                    for (int j2 = 0; j2 < width; j2++)
                    {
                        if (field[i2][j2].getValue() != 'x' &&
                            field[i2][j2].getValue() != '0')
                        {//Если ячейка открыта, создаем новую группу

                                group newGroup=setGroup(reinterpret_cast<cell*>(field), i2, j2, height, width);
                                if (newGroup.size()< field[i2][j2].getValue()-'0') throw std::invalid_argument("Cell value is bigger than closed cells around:"+ (field[i2][j2].getValue()-'0'));


                                    list<float> listPoss;
                                    newGroup.getProbabilities(listPoss);
                                    for (auto it: listPoss)
                                cout<< "Создана группа с вероятностями ячеек:"<< it<<endl;
                                    groupSet.push_back(newGroup);



                        }
                    }
                }
                if (groupSet.size()>1)
                    for (auto& Group: groupSet)
                    if (Group.getMines()==setMines) throw std::invalid_argument(" Bombs are only in group " + Group.getMines());
//-----------------------------------------------------------------------------------------------------------------//
                bool repeat1;
                do {
                    repeat1 = false;

                    for (auto it=groupSet.begin(); it!=groupSet.end();it++) // проходим по списку групп
                    {
                        group GroupI = *it;
                        for (auto it2 = groupSet.begin()++;
                             it2 != groupSet.end(); ++it2) // сравниваем ее с остальными меньшими группами
                        {
                            group GroupJ = *it2;
                            if (it != it2)
                            {
                                if (GroupI.equal(GroupJ))                  // удаляем одинаковые группы
                                {
                                    groupSet.erase(it2);
                                    break;
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
                               list<group>grCompare;
                                grCompare.push_back(child);
                                grCompare.push_back(parent);
//--------------------------------------------------------------------------------------------------------------------//
                            if (parent.overlapstwice(child)) {

                                list<cell> cells; // цикл устанавливает единое значение вероятности в каждой ячейке, учитывая различные значения вероятностей в ячейке от разных групп
                                for (auto &Group : grCompare) {
                                    for (auto &Cell: Group.getList()) {
                                        if (cells.empty()) // если лист еще пуст
                                        {
                                            cells.push_back(Cell);// то добавляем ячейку со значением из группы
                                            cout<<Cell.getPossibility()<<"pushed first to list"<<endl;
                                        } else
                                        {
                                            int k=0;
                                            for(auto &searchCell: cells) //если ячейка уже в листе, то редачим ее
                                            {

                                                if (searchCell.getX()==Cell.getX() && searchCell.getY()==Cell.getY() && searchCell.getPossibility()!=Cell.getPossibility())
                                                {
                                                    searchCell.setPossibility(1 - (1 - ((float) Group.getMines() / Group.size())) *
                                                                                  (1 - searchCell.getPossibility()));
                                                    cout<<endl<<searchCell.getPossibility()<<"differPoss"<<endl;
                                                    cout<<Cell.getPossibility()<<"differPoss2"<<endl;
                                                    k=0; break;
                                                } else
                                                {
                                                    k=1;
                                                }
                                            }
                                            if (k==1) {
                                                cells.push_back(Cell);
                                                cout<<Cell.getPossibility()<<"pushed to list"<<endl;
                                            }
                                        }
                                    }
                                }

                                for (auto& Group: grCompare)//Делаем вероятности ячеек в группах такими же как в сете
                                {
                                    for (auto& Cell: Group.getList())
                                    {
                                        for (auto &searchCell: cells)
                                        {
                                            if (searchCell.getX()==Cell.getX() && searchCell.getY()==Cell.getY() && searchCell.getPossibility()!=Cell.getPossibility())
                                            {
                                                cout<<endl<<"trying"<<Cell.getPossibility();
                                                Cell.setPossibility(searchCell.getPossibility());

                                                cout<<endl<<"changed"<< Cell.getPossibility()<<endl;
                                            }
                                        }
                                    }
                                }
                                // цикл корректирует значения с учетом того, что сумма вероятностей в группе должна быть равна количеству мин в группе
                                bool repeat2;
                                do {
                                    repeat2 = false;
                                    for (auto& Group : grCompare)    // для каждой группы
                                    {

                                        //  берем список вероятностей всех ячеек в группе
                                        float sum = 0.0;
                                        list<float> listPoss;
                                        Group.getProbabilities(listPoss);
                                        for (auto Poss: listPoss) cout<<Poss<<endl;
                                        for (float elem : listPoss) sum += elem;//Вычисляем ее сумму
                                        cout<<endl<<sum<<endl;
                                        int mines = Group.getMines();//Получаем количество мин в группе
                                        if (fabs(sum - mines) > 0.01)//Если разница между ними велика, то проводим корректировку
                                        {
                                            repeat2 = true;   //фиксируем факт корректировки
                                            probCorrect(Group, mines); // Корректируем список
                                            if (Group==grCompare.front())
                                            {
                                                for (auto& Cell: Group.getList())
                                                {
                                                    for (auto& Cell1: grCompare.back().getList())
                                                    {
                                                        if (Cell.getX()==Cell1.getX() && Cell.getY()==Cell1.getY())
                                                        {
                                                            Cell1.setPossibility(Cell.getPossibility());
                                                            cout<<"new poss success"<<Cell1.getPossibility()<<endl;
                                                        }
                                                    }
                                                }
                                            }else
                                            {
                                                for (auto& Cell: Group.getList())
                                                {
                                                    for (auto& Cell1: grCompare.front().getList())
                                                    {
                                                        if (Cell.getX()==Cell1.getX() && Cell.getY()==Cell1.getY())
                                                        {
                                                            Cell1.setPossibility(Cell.getPossibility());
                                                            cout<<"new poss success"<<Cell1.getPossibility()<<endl;
                                                        }
                                                    }
                                                }
                                            }

                                        }else {break;}

                                    }

                                } while (repeat2);

                                for (auto& NewCell: cells) {  // перестраховка
                                    if (NewCell.getPossibility() > 0.99) NewCell.setPossibility(0.99);
                                    if (NewCell.getPossibility() < 0) NewCell.setPossibility(0);
                                }
                                groupSet.erase(it);
                                groupSet.erase(it2);
                                for (auto& it3: grCompare)
                                    groupSet.push_back(it3);
                            }
//----------------------------------------------------------------------------------------------------------------------
                            else {
                                if (parent.contains(child)) // если большая содержит меньшую
                                {
                                    parent.subtraction(child);              //  то вычитаем меньшую из большей
                                    repeat1 = true;                            //  фиксируем факт изменения групп
                                } else if (GroupI.overlaps(GroupJ) > 0) // иначе если группы пересекаются
                                {
                                    if (GroupI.getMines() >
                                        GroupJ.getMines())// определяем большую и меньшую группы по кол-ву мин
                                    {
                                        parent = GroupI;
                                        child = GroupJ;
                                    } else {
                                        child = GroupI;
                                        parent = GroupJ;
                                    }

                                    group overlap = parent.getOverlap(child);// то берем результат пересечения
                                    if (overlap.getMines() != 0 && overlap.getMines() !=
                                                                   child.getMines())    //  !!!!!!!!!!!!и если он имеет смысл (в результате пересечения выявились ячейки с 0% или 100%)
                                    { break; }
                                    else if (overlap.getMines() == 0 || overlap.getMines() == child.getMines()) {

                                        groupSet.push_back(overlap);//то вносим соответствующие коррективы в список
                                        parent.subtraction(overlap);
                                        child.subtraction(overlap);
                                        repeat1 = true;
                                    }
                                }
                            }
                        }
                    }
                    }


                } while (repeat1);




                for (auto& Group: groupSet)
                    for (auto &Cell: Group.getList()) {
                        if (finalCells.empty()) {
                            finalCells.push_back(Cell);
                            cout << "inserted to finalCells with poss" << Cell.getPossibility() << "x" << Cell.getX()
                                 << "y" << Cell.getY() << endl;
                        } else {
                            int k = 0;
                            for (auto iter = finalCells.begin();
                                 iter != finalCells.end(); ++iter) //проверка, если уже ячейка в finalCells
                            {
                                cell searchCell = *iter;
                                if (searchCell.getX() == Cell.getX() && searchCell.getY() == Cell.getY()) {
                                    cout << endl << "ERROR!!!!!!!!!!!!!!!!" << endl;
                                    cout << Cell.getPossibility() << "/" << searchCell.getPossibility() << endl;
                                    k = 0;
                                    break;
                                } else {
                                    k = 1;
                                }
                            }
                            if (k == 1) {
                                finalCells.push_back(Cell);
                                cout << "inserted to finalCells with poss" << Cell.getPossibility() << "x"
                                     << Cell.getX() << "y" << Cell.getY() << endl;
                            }
                        }
                    }

                finalCells.sort();

                ofs = new ofstream(file2);

                for (const auto &it: finalCells) {
                    *ofs << 1 - (it.getPossibility()) << "-possibility x[" << it.getX() << "] y[" << it.getY()
                              << "]"<<endl;//Неправильно выводится итоговая вероятность
                }
                ofs->close();
                delete ofs;

            } else if (setMines == closedCells_)
                std::cout << "Every cell already has a mine";//Надо переделать (присвоить нулевое значение вероятности каждой ячейке и вывести)
        } else throw std::invalid_argument ("Too many mines for this field:" + setMines);

        ifs.close();
    }

    getchar();
    return 0;
};