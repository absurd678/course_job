﻿/***********************************************************************************
*                         Программирование                                         *
************************************************************************************
*Project type :Win64 Console Application                                           *
*Project name :course_job.sln                                                      *
*File name    :course_job.cpp                                                      *
*Language     :CPP, MSVS 2022                                                      *
*Programmers  :Кожевников Артем Вадимович,  М3О-209Б-22                            *
*Modified By  :                                                                    *
*Created      :06.12.2023                                                          *
*Last revision:18.12.2023                                                          *
*Comment      :                                                                    *
***********************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include "lists.h"
using namespace std;
// TODO: 
// Добить замечания Секретарева
// Проверки (в первую очередь, уникальность значений полей)
// Блок-схему мэйн со ссылками, чтобы влезла
// 10 блок-схем
// 
// 
 // Проверки: 
 // 
 // Проверка на уникальность
// Замечания:
// Внутри одного и того же вокзала все автобусы имеют разные названия
// Абсолютно у всех автобусов должны быть разные id
// 
// формат времени
// соответствие автобусов в рейсе и в списке марок
// тоже самое для автовокзалов с автобусами


/*********************************************************************
 *              П Р О Т О Т И П Ы    Ф У Н К Ц И Й                   *
 *********************************************************************/
void create_stations(const char* fname, Station*& head, Station*& end); // Создание списка вокзалов
void create_buses(const char* fname, Station* head); // Создание списков марок к каждому вокзалу
void create_drivers(const char* fname, Driver*& head, Driver*& end); // Создание списка рейсов
int create_routes(const char* fname, Route*& head, Route*& end); // Создание списка рейсов
// ФУНКЦИИ ДОБАВЛЕНИЯ
int switch_add(Station*& s_head, Station*& s_end, Driver*& d_head, Driver*& d_end, Route*& r_head, Route*& r_end);
int add_stations(Station*& head, Station*& end);
int add_buses(Station* head, int id_station);
int add_drivers(Driver*& head, Driver*& end);
int add_routes(Route*& head, Route*& end, Station* head_station, Driver* head_driver);
// ФУНКЦИИ УДАЛЕНИЯ
int switch_del(Station*& s_head, Station*& s_end, Driver*& d_head, Driver*& d_end, Route*& r_head, Route*& r_end);
int del_station(Station*& head, Station*& end, Route*& route_head, Route*& route_end);
int del_bus(Station* head, Route*& route_head, Route*& route_end);
int del_driver(Driver*& head, Driver*& end, Route*& route_head, Route*& route_end);
int del_route(Route*& head, Route*& end);
// ФУНКЦИИ ПЕЧАТИ ТАБЛИЦЫ
void print_table(Route* head_route, Station* head_station, Driver* head_driver); // Печать таблицы (проход по списку рейсов)
void print_header(); // Печать шапки
void print_raw(Route* ptr, Station* head_station, Driver* head_driver); // Печать одной строчки
// ФУНКЦИИ ПЕЧАТИ 
void switch_print(Station*& s_head, Driver*& d_head, Route*& r_head);

// ФУНКЦИИ ПОИСКА
// Поиск по полю -> вывод в виде таблицы
int switch_search(Route* route_head, Station* st_head, Driver* dr_head);

// ФУНКЦИИ ПЕРЕМЕЩЕНИЯ В ПРЯМОМ И ОБРАТНОМ НАПРАВЛЕНИЯХ 
int switch_move(Station* s_head, Station*& curr_station, Bus*& curr_bus);


// ОСТАЛЬНЫЕ ФУНКЦИИ
void PrintMess(int code); // Сообщение об ошибке

//------ГЛОБАЛЬНЫЕ КОНСТАНТЫ------//

const char* fstations = "stations.txt";
const char* fbuses = "buses.txt";
const char* fdrivers = "drivers.txt";
const char* froutes = "routes.txt";
// Ширина столбцов для таблицы
const int table_col = 20;

//------ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ------//

int choice = NULL; // Переменная выбора действия
int loc_choice = NULL;
bool is_finished = 0; // закончили
int code = 0; // Код ошибки


/*********************************************************************
 *              Г Л А В Н А Я   П Р О Г Р А М М А                    *
 *********************************************************************/
int main()
{
    system("chcp 1251");

    Station* station_head = NULL;
    Station* station_end = NULL;
    Driver* driver_head = NULL;
    Driver* driver_end = NULL;
    Route* route_head = NULL;
    Route* route_end = NULL;
    Station* curr_station = NULL; // Для перемещения в прямом и обратном направлениях (вокзал)
    Bus* curr_bus = NULL; // Для перемещения в прямом и обратном направлениях (автобус)
    Station* ptr_station; // Для удаления БД

    // Создание БД, с которой собираемся работать
    create_stations(fstations, station_head, station_end); 
    curr_station = station_head; // Текущий вокзал - самый первый
    create_buses(fbuses, station_head);
    curr_bus = station_head->busHead; // Текущий автобус - самый первый в списке у первого вокзала
    create_drivers(fdrivers, driver_head, driver_end);
    create_routes(froutes, route_head, route_end);

    cout << "~Система учета автобусов для автовокзала~" << endl;
    while (!is_finished)
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера

        cout << "Выберете действие: " << endl;
        cout << "0. Выход " << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Настроить фильтр в таблице (поиск)" << endl;
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
            
            cout << "Выберете элемент, который нужно добавить: \n1. Вокзал\n2. Автобус\n 3. Водителя\n4. Маршрут\n"; 
            cin >> loc_choice;
            code = switch_add(station_head, station_end, driver_head, driver_end, route_head, route_end);
            if (code) // Ошибка
            {
                PrintMess(code);
                is_finished = 1;
            }
            break;

        case 2:

            cout << "Выберете элемент, который нужно удалить: \n1. Вокзал\n2. Автобус\n 3. Водителя\n4. Маршрут\n";
            cin >> loc_choice;
            code = switch_del(station_head, station_end, driver_head, driver_end, route_head, route_end);
            if (code) // Ошибка
            {
                PrintMess(code);
                is_finished = 1;
            }
            break;
        case 3:
            cout << "Выберете элемент, по которому поставить фильтр: \n1. Вокзал\n2. Автобус\n3. Водитель\n4. Номер маршрута\n5. Время отправления\n6. Количество билетов\n7. Количество пассажиров\n8. Пункт назначения\n";
            cin >> loc_choice;
            code = switch_search(route_head, station_head, driver_head);
            if (code) // Ошибка
            {
                PrintMess(code);
                is_finished = 1;
            }
            break;
        case 4:
            cout << "Выберете список, который нужно распечатать: \n1. Вокзалов\n2. Автобусов\n 3. Водителей\n4. Маршрутов\n5. Все вышеперечисленное\n";
            cin >> loc_choice;
            switch_print(station_head, driver_head, route_head);
            break;

        case 5:
            print_table(route_head, station_head, driver_head);
            break;
        case 6: // TODO Проверка на случай, если в вокзале вообще нет автобусов
            cout << "Выберете список, по которому нужно пройти: \n1. Вокзалов\n2. Автобусов\n>>";
            cin >> loc_choice;
            code = switch_move(station_head, curr_station, curr_bus);
            if (code) // Ошибка
            {
                PrintMess(code);
                is_finished = 1;
            }
            break;
        case 7:
            ptr_station = station_head;
            // Удаление автобусов из всех вокзалов
            do
            {
                delListBus(ptr_station->busHead, ptr_station->busEnd);
                ptr_station = ptr_station->next;
            } while (ptr_station != station_head);
            delListStation(station_head, station_end); // Удаление всех вокзалов 
            del_drivers(driver_head);
            del_routes(route_head);
            is_finished = 1; // Выход из программы
        } // switch global

    } // while

}

/***********************************************************************
 *                Р Е А Л И З А Ц И Я    Ф У Н К Ц И Й                 *
 ***********************************************************************/
 
 //------Создание БД из файла------//

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
        do // Ищем вокзал
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

//------Добавление элементов------//

int switch_add(Station*& s_head, Station*& s_end, Driver*& d_head, Driver*& d_end, Route*& r_head, Route*& r_end)
{
    int id_station; // id вокзала, выбираемого пользователем
    int mistake_code = 0; // Код ошибки
    switch (::loc_choice) // ГЛОБАЛЬНАЯ ПЕРЕМЕННАЯ
    {
    case 1:
        mistake_code = add_stations(s_head, s_end);
        break;
    case 2:
        cout << "Введите id станции, в которую вы хотите добавить автобус: "; cin >> id_station;
        mistake_code = add_buses(s_head, id_station);
        break;
    case 3:
        mistake_code = add_drivers(d_head, d_end);
        break;
    case 4:
        mistake_code = add_routes(r_head, r_end, s_head, d_head);
        break;
    default:
        cout << "Введено некорректное значение!";
        break;
    } // switch
    return mistake_code;
} // switch_add

int add_stations(Station*& head, Station*& end)
{
    int id; 
    string name;
    id = max_station_id(head) + 1; // генерируем новый id
    cout << "Введите название вокзала: "; cin>>name;
    if (cin.fail()) {
        return 2; // Некорректное имя
    }
    makeStation(id, name, end, head);

    return 0;
}

int add_buses(Station* head, int id_station)
{
    int new_id = 0; int max_id = 0;
    string name;
    Station* ptr = head;
    Station* station_ptr = findElemStation(id_station, head); // Вокзал, к которому будет относиться автобус
    if (!station_ptr) return 4; // Не найдена станция

    // Определение нового id
    do
    {
        max_id = max_bus_id(ptr->busHead);
        if (new_id < max_id) new_id = max_id;
    } while (ptr != head);
    
    cout << "Введите название марки: "; cin >> name;
    if (cin.fail()) {
        return 2; // Некорректное имя
    }

    Bus* bus_end = station_ptr->busEnd;
    makeBus(station_ptr->id, new_id, name, bus_end, station_ptr->busHead);
    station_ptr->busEnd = bus_end;

    return 0;
}

int add_drivers(Driver*& head, Driver*& end)
{
    int id; 
    string name;
    id = max_driver_id(head);
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
    Station* station_ptr;

    cout << "Введите id существующего вокзала: "; cin >> ptr_route->id_station;
    if (cin.fail()) {
        return 1; // Несоответствие типов данных!
    }
    station_ptr = findElemStation(ptr_route->id_station, head_station);
    if (!station_ptr) return 4; // Не найден элемент

    cout << "Введите id существующего автобуса: "; cin >> ptr_route->id_bus;
    if (cin.fail()) {
        return 1; // Некорректный route_number
    }
    else if (!findElemBus(ptr_route->id_bus, station_ptr->busHead)) return 4; // Не найден элемент

    cout << "Введите id существующего водителя: "; cin >> ptr_route->id_driver;
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
    make_route(ptr_route, end, head);

    return 0;
}

//------Удаление элементов------//

int switch_del(Station*& s_head, Station*& s_end, Driver*& d_head, Driver*& d_end, Route*& r_head, Route*& r_end)
{

    int mistake_code = 0;
    switch (::loc_choice)
    {
    case 1:
        print_stations_in_route(r_head, s_head); // Вывод всех вокзалов с рейсами
        mistake_code = del_station(s_head, s_end, r_head, r_end);
        break;
    case 2:
        print_buses_in_route(r_head, s_head); // Вывод всех вокзалов и автобусов с рейсами
        mistake_code = del_bus(s_head, r_head, r_end);
        break;
    case 3:
        print_drivers_in_route(r_head, d_head); // Вывод всех водителей с рейсами
        mistake_code = del_driver(d_head, d_end, r_head, r_end);
        break;
    case 4:
        cout << "Все рейсы: " << endl;
        print_routes(r_head, s_head, d_head);
        mistake_code = del_route(r_head, r_end);
        break;
    default:
        cout << "Введено некорректное значение!";
        break;
    } // switch
    return mistake_code;
} // switch_del

int del_station(Station*& head, Station*& end, Route*& route_head, Route*& route_end)
{
    int id; 
    Station* ptr;
    Route* route_ptr;

    cout << "Введите id вокзала: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный id
    }
    ptr = findElemStation(id, head);
    if (!ptr) return 4; // Если такого вокзала нет

    // Удаляем рейсы с таким вокзалом
    route_ptr = find_route_stationID(id, route_head);
    do
    {
        delete_route(route_head, route_end, route_ptr->route_number); // Удаляем по номеру маршрута
        route_ptr = find_route_stationID(id, route_head); // Ищем еще
    } while (route_ptr); // Удаляем все рейсы

    delListBus(ptr->busHead, ptr->busEnd); // Удаляем автобусы из вокзала
    DeleteStation(head, end, id); // Удалить вокзал
    return 0;
}

int del_bus(Station* head, Route*& route_head, Route*& route_end)
{
    int id_station; // ID вокзала
    int id; // ID автобуса
    Station* ptr; //  указатель на вокзал с этим автобусом 

    cout << "Введите id станции, из которой удалить автобус: "; cin >> id_station;

    ptr = findElemStation(id_station, head);
    if (!ptr) return 4; // Если такого вокзала нет

    cout << "Введите id марки: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный id
    }
    else if (!findElemBus(id, ptr->busHead)) return 4; // Такого автобуса нет

    // Удаляем рейс, найдя указатель функцией поиска по полю id автобуса, по полю route_number
    delete_route(route_head, route_end, find_route_busID(id, route_head)->route_number);

    // Удаляем, не забывая изменить поля
    Bus* bus_head = ptr->busHead;
    Bus* end = ptr->busEnd;
    DeleteBus(bus_head, end, id);
    ptr->busHead = bus_head;
    ptr->busEnd = end;
    return 0;
}
int del_driver(Driver*& head, Driver*& end, Route*& route_head, Route*& route_end)
{
    int id; Driver* ptr;
    cout << "Введите id водителя: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный id
    }
    
    if (!find_driver(id, head)) return 4; // Если такого нет

    // Удаляем рейс, найдя указатель функцией поиска по полю id водителя, по полю route_number
    delete_route(route_head, route_end, find_route_driverID(id, route_head)->route_number);
    // Удаляем из списка водителей
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
    ptr = find_route_number(route_number, head);
    if (!ptr) return 4; // Если такого нет
    delete_route(head, end, route_number);
    return 0;
}

//------Поиск элемента------//

int switch_search(Route* route_head, Station* st_head, Driver* dr_head)
{
    Route* found; // Элемент, найденный по фильтру
    Station* st_ptr = st_head; // Проход для автобусов
    string str_filter;
    int int_filter;
    int id; // Найденный id
    bool found_flag = 0; // Флаг: найден ли элемент

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
    switch (::loc_choice)
    {
    case 1: // По вокзалам
        print_stations_in_route(route_head, st_head); // Вывод всех вокзалов с рейсами
        cout << "Введите название вокзала, рейсы которых нужно вывести: "; cin >> str_filter;
        if (cin.fail()) return 1;
        else if (!find_id_station(str_filter, st_head)) return 4; // Если такого вокзала просто нет

        id = find_id_station(str_filter, st_head); // id ищем по списку вокзалов
        found = find_route_stationID(id, route_head); // ищем рейс с таким вокзалом
        print_header(); 

        while (found) // Идем до конца
        {
            print_raw(found, st_head, dr_head);
            found = find_route_stationID(id, found->next); // Продвигаемся по списку РЕЙСОВ и ищем еще
        } // while
        break;

    case 2: // По автобусам
        print_buses_in_route(route_head, st_head); // Все автобусы в рейсах
        cout << "Введите название автобуса, рейсы с которым нужно вывести: "; cin >> str_filter;
        if (cin.fail()) return 1;
        
        print_header();
        do  // Ищем по каждому вокзалу
        { // Ищем автобус в вокзале st_ptr
            found = route_head;
            id = find_id_bus(str_filter, st_ptr->busHead); // Вернет -1, если автобус в данном вокзале не найден
            found = find_route_busID(id, route_head); // Ищем автобус такого вокзала в списке рейсов
            while (found && id != -1) // Идем до конца
            {
                found_flag = 1;
                print_raw(found, st_head, dr_head);
                found = find_route_busID(id, found->next); // Продвигаемся по списку и ищем еще
            } // while
            st_ptr = st_ptr->next;

        } while (st_ptr!=st_head); 
        
        if (!found_flag) return 4; // Такого автобуса просто нет

        break;
    
    case 3:
        print_drivers_in_route(route_head, dr_head); // Все водители в рейсах
        cout << "Введите ФИО водителя, рейсы которого нужно вывести: "; cin >> str_filter;
        if (cin.fail()) return 1;
        else if (!find_id_driver(str_filter, dr_head)) return 4; // Если такого вокзала просто нет

        id = find_id_driver(str_filter, dr_head);
        found = find_route_driverID(id, route_head);
        print_header();
        while (found) // Идем до конца
        {
            print_raw(found, st_head, dr_head);
            found = find_route_driverID(id, found->next); // Продвигаемся по списку и ищем еще
        } // while
        break;

    case 4: // number
        print_routes(route_head, st_head, dr_head); // Все рейсы
        cout << "Введите номер рейса который нужно вывести: "; cin >> int_filter;
        if (cin.fail()) return 1;

        found = find_route_number(int_filter, route_head);

        if (!found) return 4; // Если такого вокзала просто нет
        print_header();
        print_raw(found, st_head, dr_head);

        break;
    case 5: // time_dep
        print_table(route_head, st_head, dr_head); // Все существующие рейсы
        cout << "Введите время рейсов для вывода: "; cin >> str_filter;
        if (cin.fail()) return 1;
        else if (!find_route_time_dep(str_filter, route_head)) return 4; // Если такого времени просто нет

        found = find_route_time_dep(str_filter, route_head);
        print_header();
        while (found) // Идем до конца
        {
            print_raw(found, st_head, dr_head);
            found = find_route_time_dep(str_filter, found->next); // Продвигаемся по списку и ищем еще
        } // while
        
        break;
    case 6: // tickets
        print_table(route_head, st_head, dr_head); // Все существующие рейсы
        cout << "Введите количество билетов в рейсе для вывода: "; cin >> int_filter;
        if (cin.fail()) return 1;
        else if (!find_route_tickets(int_filter, route_head)) return 4; // Если такого времени просто нет

        found = find_route_tickets(int_filter, route_head);
        print_header();
        while (found) // Идем до конца
        {
            print_raw(found, st_head, dr_head);
            found = find_route_tickets(int_filter, found->next); // Продвигаемся по списку и ищем еще
        } // while
        break;
    case 7: // pass
        print_table(route_head, st_head, dr_head); // Все существующие рейсы
        print_routes(route_head, st_head, dr_head); // Все рейсы
        cout << "Введите количество пассажиров в рейсе для вывода: "; cin >> int_filter;
        if (cin.fail()) return 1;
        else if (!find_route_pass(int_filter, route_head)) return 4; // Если такого времени просто нет

        found = find_route_pass(int_filter, route_head);
        print_header();
        while (found) // Идем до конца
        {
            print_raw(found, st_head, dr_head);
            found = find_route_pass(int_filter, found->next); // Продвигаемся по списку и ищем еще
        } // while
        break;
    case 8: // end
        print_table(route_head, st_head, dr_head); // Все существующие рейсы
        cout << "Введите пункт назначения рейсов для вывода: "; cin >> str_filter;
        if (cin.fail()) return 1;
        else if (!find_route_end(str_filter, route_head)) return 4; // Если такого времени просто нет

        found = find_route_end(str_filter, route_head);
        print_header();
        while (found) // Идем до конца
        {
            print_raw(found, st_head, dr_head);
            found = find_route_end(str_filter, found->next); // Продвигаемся по списку и ищем еще
        } // while
        break;
    default:
        cout << "Введено некорректное значение!" << endl;
        break;
    } // switch
    return 0;
} // 

//------Печать списков------//
void switch_print(Station*& s_head, Driver*& d_head, Route*& r_head)
{
    Station* station_ptr = NULL; // указатель для прохода по вокзалам

    switch (::loc_choice)
    {
    case 1: // Вокзалов
        cout << "\nСПИСОК ВОКЗАЛОВ: " << endl;
        printStation(s_head);
        break;
    case 2: // Автобусов
        cout << "\nСПИСОК АВТОБУСОВ: " << endl;
        station_ptr = s_head;
        do // Проход по всем вокзалам
        {
            printBus(station_ptr->busHead, s_head);
            station_ptr = station_ptr->next;
        } while (station_ptr != s_head);
        break;
    case 3: // Водителей
        cout << "\nСПИСОК ВОДИТЕЛЕЙ: " << endl;
        print_drivers(d_head);
        break;
    case 4: // Маршрутов
        cout << "\nСПИСОК МАРШРУТОВ: " << endl;
        print_routes(r_head, s_head, d_head);
        break;
    case 5: // Все вышеперечисленное
        cout << "\nСПИСОК ВОКЗАЛОВ: " << endl;
        printStation(s_head);
        station_ptr = s_head;
        cout << "\nСПИСОК АВТОБУСОВ: " << endl;
        do // Проход по всем вокзалам
        {
            printBus(station_ptr->busHead, s_head);
        } while (station_ptr != s_head);
        cout << "\nСПИСОК ВОДИТЕЛЕЙ: " << endl;
        print_drivers(d_head);
        cout << "\nСПИСОК МАРШРУТОВ: " << endl;
        print_routes(r_head, s_head, d_head);
        break;
    default:
        cout << "Введено некорректное значение!"<<endl;
        break;
    } // switch 4
}


//------Таблица------//

void print_table(Route* head_route, Station* head_station, Driver* head_driver)
{
    Station* station_ptr = NULL;
    Bus* bus_ptr;
    Driver* driver_ptr;

    // ШАПКА
    print_header();
    // Проход по списку рейсов
    Route* route_ptr = head_route;
    while (route_ptr)
    {
        print_raw(route_ptr, head_station, head_driver);
        route_ptr = route_ptr->next;
    }
    // Подчеркиваем
    cout << '|' << setfill('_') << setw(table_col * 8) << '|' << endl;
}

void print_header() // ШАПКА
{
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
} // print_header

void print_raw(Route* ptr, Station* head_station, Driver* head_driver) // Одна строчка
{
    Station* station_ptr = findElemStation(ptr->id_station, head_station);
    Bus* bus_ptr = findElemBus(ptr->id_bus, station_ptr->busHead); // Проверка соответствия Автобуса с вокзалом  TODO
    Driver* driver_ptr = find_driver(ptr->id_driver, head_driver);
    // Строка
    cout << '|' << setfill('_') << setw(table_col * 8) << '|' << endl;
    cout << '|' << station_ptr->name << setfill(' ') << setw(table_col - (station_ptr->name).size())
        << '|' << bus_ptr->name << setfill(' ') << setw(table_col - (bus_ptr->name).size())
        << '|' << driver_ptr->name << setfill(' ') << setw(table_col - (driver_ptr->name).size())
        << '|' << ptr->route_number << setfill(' ') << setw(table_col - (int)log10(ptr->route_number) - 1)
        << '|' << ptr->time << setfill(' ') << setw(table_col - ptr->time.size())
        << '|' << ptr->tickets << setfill(' ') << setw(table_col - (int)log10(ptr->tickets) - 1)
        << '|' << ptr->passengers << setfill(' ') << setw(table_col - (int)log10(ptr->passengers) - 1)
        << '|' << ptr->end_route << setfill(' ') << setw(table_col - ptr->end_route.size())
        << '|' << endl;
}


//------Перемещение------//
int switch_move(Station* s_head, Station*& curr_station, Bus*& curr_bus)
{
    int step = 0; // Шаг
    int id_station; // id вокзала
    cout << "\nНа сколько нужно шагнуть? (Пример: 2 - на два элемента вперед, -2 - на два элемента назад)";
    cin >> step;
    switch (loc_choice)
    {
    case 1:
        cout << "Текущая позиция: " << curr_station->id << " " << curr_station->name << endl;
        curr_station = move_in_stations(curr_station, step);
        cout << "Измененная позиция: " << curr_station->id << " " << curr_station->name << endl;
        break;
    case 2:
        cout << "Введите id вокзала, по автобусам которого нужно перемещаться: "; cin >> id_station;
        // Проверка id
        if (cin.fail()) return 1;
        else if (!findElemStation(id_station, s_head)) return 4;
        // Если стартовать неоткуда; иначе Если мы не продолжаем движение по тому же списку автобусов, что и в прошлый раз, то стартуем от начала другого выбранного списка 
        if (!curr_bus) curr_bus = findElemStation(id_station, s_head)->busHead;
        else if (id_station != curr_bus->id) curr_bus = findElemStation(id_station, s_head)->busHead;

        cout << "Текущая позиция: " << curr_bus->id_bus << " " << curr_bus->name << endl;
        curr_bus = move_in_buses(curr_bus, step);
        cout << "Измененная позиция: " << curr_bus->id_bus << " " << curr_bus->name << endl;
        break;
    default:
        cout << "Некорректное значение!" << endl;
        break;
    } // switch
    return 0;
} // switch_move

//------ОСТАЛЬНЫЕ ФУНКЦИИ------//
void PrintMess(int code)
{
    switch (code)
    {
    case 1: 
        cout << "Неправильный тип данных!" << endl;
        break;
    case 4:
        cout << "Элемента нету в этой БД!" << endl;
        break;
    }
}