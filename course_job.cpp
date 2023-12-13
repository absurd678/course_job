// course_job.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include "lists.h"
using namespace std;
 // TODO: Проверки
 // Поиск
 // Проверка на уникальность
 // Таблица
// соответствие автобусов в рейсе и в списке марок
// тоже самое для автовокзалов с автобусами
// поля целых чисел, даты
// 


/*********************************************************************
 *              П Р О Т О Т И П Ы    Ф У Н К Ц И Й                   *
 *********************************************************************/
void create_stations(const char* fname, Station*& head, Station*& end); // Создание списка вокзалов
void create_buses(const char* fname, Station* head); // Создание списков марок к каждому вокзалу
void create_drivers(const char* fname, Driver*& head, Driver*& end); // Создание списка рейсов
int create_routes(const char* fname, Route*& head, Route*& end); // Создание списка рейсов
void print_table(Route* head); // Печать таблицы (проход по списку рейсов) TODO: А МОЖЕТ РЕЙСЫ И БУДУТ КОЛЬЦЕВЫМ СПИСКОМ?
void PrintMess(int code); // Сообщение об ошибке

const char* fstations = "stations.txt";
const char* fbuses = "buses.txt";
const char* fdrivers = "drivers.txt";
const char* froutes = "routes.txt";

int main()
{
    setlocale(LC_ALL, "Russian");

    Station* station_head = NULL;
    Station* station_end = NULL;
    Driver* driver_head = NULL;
    Driver* driver_end = NULL;
    Route* route_head = NULL;
    Route* route_end = NULL;

    create_stations(fstations, station_head, station_end);
    printStation(station_head);
    create_buses(fbuses, station_head);
    create_drivers(fdrivers, driver_head, driver_end);
    print_drivers(driver_head);
    create_routes(froutes, route_head, route_end);
    print_routes(route_head);


}

void create_stations(const char* fname, Station*& head, Station*& end)
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
    int id; // айди вокзала
    int id_bus; // айди автобуса
    string name; // Название марки
    Station* ptr = head;

    while (!fin.eof())
    {
        fin >> id;
        if (fin.fail())
        {
            cout << "Некорректный id автовокзала!" << endl;
            continue;
        } // if

        fin >> id_bus;
        if (fin.fail())
        {
            cout << "Некорректный id автобуса!" << endl;
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

        Bus* bus_loc_head = ptr->busHead; Bus* bus_loc_end = ptr->busEnd;

        makeBus(id, id_bus, name, bus_loc_end, bus_loc_head); // Добавляем автобус в вокзал
         if (!ptr->busHead) ptr->busHead = bus_loc_head; // Добавление головы в поле
        ptr->busEnd = bus_loc_end; // Изменение поля конца списка

    } // while
    fin.close();
} // create_bus

void create_drivers(const char* fname, Driver*& head, Driver*& end) // Создание списка рейсов
{
    ifstream fin(fname);
    int id;
    string full_name; string name; string father_name; // ФИО

    while (!fin.eof())
    {
        
        fin >> id;
        if (fin.fail())
        {
            cout << "Некорректный id водителя!" << endl;
            continue;
        } // if

        fin >> full_name;
        if (fin.fail())
        {
            cout << "Некорректное ФИО водителя!" << endl;
            continue;
        } // if
        fin >> name;
        if (fin.fail())
        {
            cout << "Некорректное ФИО водителя!" << endl;
            continue;
        } // if
        fin >> father_name;
        if (fin.fail())
        {
            cout << "Некорректное ФИО водителя!" << endl;
            continue;
        } // if
        full_name = full_name + " " + name + " " + father_name; // ФИО

        make_driver(id, full_name, end, head); // Добавить в список
    } // while
    fin.close();
}

int create_routes(const char* fname, Route*& head, Route*& end)
{
    ifstream fin(fname);
    
    while (!fin.eof())
    {
        Route* RouteLoc = new Route;
        fin >> RouteLoc->id_station;
        if (fin.fail())
        {
            cout << "Некорректный id вокзала!" << endl;
            return 0;
        } // if
        
        fin >> RouteLoc->id_bus;
        if (fin.fail())
        {
            cout << "Некорректный id автобуса!" << endl;
            return 1;
        } // if
        
        fin >> RouteLoc->id_driver;
        if (fin.fail())
        {
            cout << "Некорректный id водителя!" << endl;
            return 2;
        } // if

        fin >> RouteLoc->route_number;
        if (fin.fail())
        {
            cout << "Некорректный № рейса!" << endl;
            return 3;
        } // if

        fin >> RouteLoc->time; // TODO: проверка формата
        if (fin.fail())
        {
            cout << "Некорректная запись времени!" << endl;
            return 4;
        } // if

        fin >> RouteLoc->tickets;
        if (fin.fail())
        {
            cout << "Некорректное число билетов!" << endl;
            return 5;
        } // if

        fin >> RouteLoc->passengers;
        if (fin.fail())
        {
            cout << "Некорректное число пассажиров!" << endl;
            return 6;
        } // if

        fin >> RouteLoc->end_route;
        if (fin.fail())
        {
            cout << "Некорректный пункт назначения!" << endl;
            return 7;
        } // if

        make_route(RouteLoc, end, head);

    } // while
    fin.close();
}

