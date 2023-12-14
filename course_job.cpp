// course_job.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include "lists.h"
using namespace std;
// Спросить:
// Функции добавления - функций make в lists.cpp достаточно?
 // TODO: 
 // Удаление элементов во всех списках
 // Поиск по айди: функция поиска или вокзала или автобуса или водителя - как пользователь захочет
 // Поиск (по имени, а не только по айди)
 // Проверки
 // Проверка на уникальность
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

int add_stations(Station*& head, Station*& end);
int add_buses(Station* head, int id_station);
int add_drivers(Driver*& head, Driver*& end);
int add_routes(Route*& head, Route*& end, Station* head_station, Driver* head_driver);

int del_station(Station*& head, Station*& end);
int del_bus(Station* head, int id_station);
int del_driver(Driver*& head, Driver*& end);
int del_route(Route*& head, Route*& end);

void print_table(Route* head_route, Station* head_station, Driver* head_driver); // Печать таблицы (проход по списку рейсов) TODO: А МОЖЕТ РЕЙСЫ И БУДУТ КОЛЬЦЕВЫМ СПИСКОМ?
void PrintMess(int code); // Сообщение об ошибке

const char* fstations = "stations.txt";
const char* fbuses = "buses.txt";
const char* fdrivers = "drivers.txt";
const char* froutes = "routes.txt";
// Ширина столбцов для таблицы
const int table_col = 20;

int choice = NULL; // Переменная выбора действия
int loc_choice = NULL;
bool is_finished = 0; // закончили
int code = 0; // Код ошибки

int main()
{
    system("chcp 1251");

    Station* station_head = NULL;
    Station* station_end = NULL;
    Driver* driver_head = NULL;
    Driver* driver_end = NULL;
    Route* route_head = NULL;
    Route* route_end = NULL;
    Station* station_ptr = NULL; // Для прохода по вокзалам
    int id_station = 0; // id вокзала, выбираемое пользователем

    // Создание БД, с которой собираемся работать
    create_stations(fstations, station_head, station_end);
    create_buses(fbuses, station_head);
    create_drivers(fdrivers, driver_head, driver_end);
    create_routes(froutes, route_head, route_end);

    while (!is_finished)
    {
        cin.clear();
        cout << "Выберете действие: " << endl;
        cout << "0. Выход " << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Поиск элемента" << endl;
        cout << "4. Печать списков" << endl;
        cout << "5. Печать таблицы" << endl; // Предусмотреть случаи добавления/удаления элементов
        cout << "6. Перемещение в прямом и обратном направлениях" << endl;
        cout << "7. Удалить БД" << endl;
        cout << ">>"; cin >> choice; cout << endl;
        switch (choice)
        {


        case 0: // Выход
            is_finished = 1;
            break;


        case 1:
            
            cout << "Выберете элемент, который нужно добавить: \n1. Вокзал\n2. Автобус\n 3. Маршрут\n4. Водителя\n"; 
            cin >> loc_choice;
            switch (loc_choice)
            {
            case 1:
                add_stations(station_head, station_end);
                printStation(station_head);
                break;
            case 2:
                
                cout << "Введите id станции, в которую вы хотите добавить автобус: "; cin >> id_station;
                add_buses(station_head, id_station);
                printBus(findElemStation(id_station, station_head)->busHead);
                break;
            case 3:
                add_drivers(driver_head, driver_end);
                break;
            case 4:
                add_routes(route_head, route_end, station_head, driver_head);
                break;
            default:
                cout << "Введено некорректное значение!";
                break;
            } // switch 1


        case 2:
            cout << "Выберете элемент, который нужно удалить: \n1. Вокзал\n2. Автобус\n 3. Маршрут\n4. Водителя\n";
            cin >> loc_choice;
            switch (loc_choice)
            {
            case 1:
                del_station(station_head, station_end);
                printStation(station_head);
                break;
            case 2:
                
                del_bus(station_head);
                printBus(findElemStation(id_station, station_head)->busHead);
                break;
            case 3:
                del_driver(driver_head, driver_end);
                break;
            case 4:
                del_route(route_head, route_end);
                break;
            default:
                cout << "Введено некорректное значение!";
                break;
            } // switch 2


        case 4:
            cout << "Выберете список, который нужно распечатать: \n1. Вокзалов\n2. Автобусов\n 3. Маршрутов\n4. Водителей\n5. Все вышеперечисленное\n";
            cin >> loc_choice;
            switch (loc_choice)
            {
            case 1: // Вокзалов
                printStation(station_head);
                break;
            case 2: // Автобусов
                station_ptr = station_head;
                do // Проход по всем вокзалам
                {
                    printBus(station_ptr->busHead);
                } while (station_ptr != station_head);
                break;
            case 3: // Маршрутов
                print_drivers(driver_head);
                break;
            case 4: // Водителей
                print_routes(route_head);
                break;
            case 5: // Все вышеперечисленное
                printStation(station_head);
                station_ptr = station_head;
                do // Проход по всем вокзалам
                {
                    printBus(station_ptr->busHead);
                } while (station_ptr != station_head);
                print_drivers(driver_head);
                print_routes(route_head);
                break;
            default:
                cout << "Введено некорректное значение!";
                break;
            } // switch 4


        } // switch global

    } // while

    

    print_table(route_head, station_head, driver_head);

}
// Создание БД из файла
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
        do // Ищем вокзал по route_number
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
    return NULL;
}

// Добавление элементов из командной строки
int add_stations(Station*& head, Station*& end)
{
    int id; string name;
    cout << "Введите id вокзала: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный route_number
    }
    cout << "Введите название вокзала: "; cin>>name;
    if (cin.fail()) {
        return 2; // Некорректное имя
    }
    makeStation(id, name, end, head);

    return 0;
}

int add_buses(Station* head, int id_station)
{
    int id; string name;
    Station* station_ptr = findElemStation(id_station, head);
    cout << "Введите id марки автобуса: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный route_number
    }
    else if (!station_ptr) return 4; // Не найдена станция
    cout << "Введите название марки: "; cin >> name;
    if (cin.fail()) {
        return 2; // Некорректное имя
    }
    makeBus(station_ptr->id, id, name, station_ptr->busEnd, station_ptr->busHead);

    return 0;
}

int add_drivers(Driver*& head, Driver*& end)
{
    int id; string name;
    cout << "Введите id водителя: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный route_number
    }
    cout << "Введите ФИО водителя: "; cin >> name;
    if (cin.fail()) {
        return 2; // Некорректное имя
    }
    make_driver(id, name, end, head);

    return 0;
}

int add_routes(Route*& head, Route*& end, Station* head_station, Driver* head_driver)
{
    Route* ptr_route = new Route;
    cout << "Введите id вокзала: "; cin >> ptr_route->id_station;
    if (cin.fail()) {
        return 1; // Несоответствие типов данных!
    }
    else if (!findElemStation(ptr_route->id_station, head_station)) return 4; // Не найден элемент

    cout << "Введите id автобуса: "; cin >> ptr_route->id_bus;
    if (cin.fail()) {
        return 1; // Некорректный route_number
    }
    else if (!findElemBus(ptr_route->id_station, head_station->busHead)) return 4; // Не найден элемент

    cout << "Введите id водителя: "; cin >> ptr_route->id_driver;
    if (cin.fail()) {
        return 1; // Некорректный route_number
    }
    else if (!find_driver(ptr_route->id_driver, head_driver)) return 4; // Не найден элемент

    cout << "Введите номер рейса: "; cin >> ptr_route->route_number;
    if (cin.fail()) {
        return 1; // Несоответствие типов данных!
    }
    cout << "Введите время отправления: "; cin >> ptr_route->time;
    if (cin.fail()) {
        return 1; // Несоответствие типов данных!
    }
    cout << "Введите количество проданных билетов: "; cin >> ptr_route->tickets;
    if (cin.fail()) {
        return 1; // Несоответствие типов данных!
    }
    cout << "Введите количество пассажиров: "; cin >> ptr_route->passengers;
    if (cin.fail()) {
        return 1; // Несоответствие типов данных!
    }
    cout << "Введите место назначения: "; cin >> ptr_route->end_route;
    if (cin.fail()) {
        return 1; // Несоответствие типов данных!
    }

    return 0;
}

// Удаление элементов
int del_station(Station*& head, Station*& end)
{
    int id; Station* ptr;
    cout << "Введите id вокзала: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный id
    }
    ptr = findElemStation(id, head);
    if (!ptr) return 4; // Если такого вокзала нет
    delListBus(ptr->busHead, ptr->busEnd); // Удаляем автобусы из вокзала
    DeleteStation(head, end, id); // Удалить вокзал
    return 0;
}
int del_bus(Station* head)
{
    int id_station; // ID вокзала
    int id; Station* ptr; // ID автобуса и указатель на вокзал с этим автобусом 
    cout << "Введите id станции, из которой удалить автобус: "; cin >> id_station;
    ptr = findElemStation(id_station, head);
    if (!ptr) return 4; // Если такого вокзала нет

    cout << "Введите id марки: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный id
    }
    else if (!findElemBus(id, ptr->busHead)) return 4; // Такого автобуса нет
    // Зря ругается
    Bus* end = ptr->busEnd;
    Bus* head = ptr->busHead;
    DeleteBus(head, end, id);
    ptr->busHead = head;
    ptr->busEnd = end;
    return 0;
}
int del_driver(Driver*& head, Driver*& end)
{
    int id; Driver* ptr;
    cout << "Введите id водителя: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный id
    }
    ptr = find_driver(id, head);
    if (!ptr) return 4; // Если такого нет
    delete_driver(head, end, id);
    return 0;
}
int del_route(Route*& head, Route*& end)
{
    int route_number; Route* ptr;
    cout << "Введите номер удаляемого маршрута: "; cin >> route_number;
    if (cin.fail()) {
        return 1; // Некорректный route_number
    }
    ptr = find_route(route_number, head);
    if (!ptr) return 4; // Если такого нет
    delete_route(head, end, route_number);
    return 0;
}

// Таблица
void print_table(Route* head_route, Station* head_station, Driver* head_driver)
{
    Station* station_ptr = NULL;
    Bus* bus_ptr;
    Driver* driver_ptr;

    // ШАПКА
    cout << '_' << setfill('_') << setw(table_col * 8) << '_' << endl;
    cout << '|' << "Вокзалы" << setfill(' ') << setw(table_col - 7)
        << '|' << "Автобус" << setfill(' ') << setw(table_col - 7)
        << '|' << "Водитель" << setfill(' ') << setw(table_col - 8)
        << '|' << "Номер рейса" << setfill(' ') << setw(table_col - 11)
        << '|' << "Время отправления" << setfill(' ') << setw(table_col - 17)
        << '|' << "Проданных билетов" << setfill(' ') << setw(table_col - 17)
        << '|' << "Пассажиров" << setfill(' ') << setw(table_col - 10)
        << '|' << "Место назначения" << setfill(' ') << setw(table_col - 16)
        << '|' << endl;
    // Проход по списку рейсов
    Route* route_ptr = head_route;
    while (route_ptr)
    {
        station_ptr = findElemStation(route_ptr->id_station, head_station);
        bus_ptr = findElemBus(route_ptr->id_bus, station_ptr->busHead); // Проверка соответствия Автобуса с вокзалом  TODO
        driver_ptr = find_driver(route_ptr->id_driver, head_driver);
        // Строка
        cout << '|' << setfill('_') << setw(table_col * 8) << '|' << endl;
        cout << '|' << station_ptr->name << setfill(' ') << setw(table_col - (station_ptr->name).size())
            << '|' << bus_ptr->name << setfill(' ') << setw(table_col - (bus_ptr->name).size())
            << '|' << driver_ptr->name << setfill(' ') << setw(table_col - (driver_ptr->name).size())
            << '|' << route_ptr->route_number << setfill(' ') << setw(table_col - (int)log10(route_ptr->route_number)-1)
            << '|' << route_ptr->time << setfill(' ') << setw(table_col - route_ptr->time.size())
            << '|' << route_ptr->tickets << setfill(' ') << setw(table_col - (int)log10(route_ptr->tickets)-1)
            << '|' << route_ptr->passengers << setfill(' ') << setw(table_col - (int)log10(route_ptr->passengers)-1)
            << '|' << route_ptr->end_route << setfill(' ') << setw(table_col - route_ptr->end_route.size())
            << '|' << endl;

        route_ptr = route_ptr->next;
    }
    // Подчеркиваем
    cout << '|' << setfill('_') << setw(table_col * 8) << '|' << endl;
}