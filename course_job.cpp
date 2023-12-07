// course_job.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "lists.cpp"
using namespace std;
 // TODO: Проверки
 // Поиск
 // Проверка на уникальность
 // Таблица
// соответствие марок в рейсе и в списке марок
// тоже самое для автовокзалов с марками
// поля целых чисел, даты
// 


/*********************************************************************
 *              П Р О Т О Т И П Ы    Ф У Н К Ц И Й                   *
 *********************************************************************/
void create_stations(const char* fname, Station* head, Station* end); // Создание списка вокзалов
void create_buses(const char* fname, Station* head); // Создание списков марок к каждому вокзалу
void create_routes(const char* fname, Station* head); // Создание списка рейсов к каждой марке у каждого вокзала



const char* fstations = "stations.txt";
const char* fbuses = "buses.txt";
const char* froutes = "routes.txt";

int main()
{
    setlocale(LC_ALL, "Russian");

    Station* station_head = NULL;
    Station* station_end = NULL;
    
}

void create_stations(const char* fname, Station* head, Station* end)
{
    ifstream fin(fname);
    int id;
    string name; // Название вокзала
    while (!fin.eof())
    {
        fin >> id; 
        if (fin.fail()) 
        { 
            cout << "Некорректный id!" << endl;  
            continue; 
        } // if
        fin >> name; 
        if (fin.fail())
        {
            cout << "Некорректное название вокзала!" << endl;
            continue;
        } // if
        makeStation(id, name, end, head);
    } // while
    fin.close();
} // create_stations

void create_buses(const char* fname, Station* head)
{
    ifstream fin(fname);
    int id;
    string name; // Название марки
    Station* ptr = head;
    while (!fin.eof())
    {
        fin >> id;
        if (fin.fail())
        {
            cout << "Некорректный id!" << endl;
            continue;
        } // if
        fin >> name;
        if (fin.fail())
        {
            cout << "Некорректное название марки!" << endl;
            continue;
        } // if

        ptr = head;
        do // Ищем вокзал по id
        {
            if (id == ptr->id) break;
            ptr = ptr->next;
        } while (ptr != head);
        makeBus(id, name, ptr->busEnd, ptr->busHead); // Добавляем марку в вокзал

    } // while
    fin.close();
}

void create_routes(const char* fname, Station* head) // TODO: добить - см блок-схему (как считывать ФИО?)
{
    ifstream fin(fname);
    int id;
    string bus; // Название марки
    string driver; // ФИО водителя
    int route_number; // Номер рейса
    string time; // Время отправления
    int tickets; // Количество проданных билетов
    int passengers; // Количество пассажиров
    string end_route; // Место назначения

    Station* ptr = head;
    while (!fin.eof())
    {
        fin >> id;
        if (fin.fail())
        {
            cout << "Некорректный id!" << endl;
            continue;
        } // if
        fin >> bus;
        if (fin.fail())
        {
            cout << "Некорректное название марки!" << endl;
            continue;
        } // if

        ptr = head;
        do // Ищем вокзал по id
        {
            if (id == ptr->id) break;
            ptr = ptr->next;
        } while (ptr != head);
        


    } // while
    fin.close();
}

