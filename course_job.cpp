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
 // TODO: 
 // Поиск по айди: функция поиска или вокзала или автобуса или водителя - как пользователь захочет
 // 
 // Поиск (по имени, а не только по айди)
 // Проверки (ищи TODO!)
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
// ФУНКЦИИ ПЕЧАТИ 
void switch_print(Station*& s_head, Driver*& d_head, Route*& r_head);

// ФУНКЦИИ ПОИСКА
// Поиск по полю -> вывод в виде таблицы
int switch_search();

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

    // Создание БД, с которой собираемся работать
    create_stations(fstations, station_head, station_end); 
    curr_station = station_head; // Текущий вокзал - самый первый
    create_buses(fbuses, station_head);
    curr_bus = station_head->busHead; // Текущий автобус - самый первый в списке у первого вокзала
    create_drivers(fdrivers, driver_head, driver_end);
    create_routes(froutes, route_head, route_end);

    while (!is_finished)
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера

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
            
            cout << "Выберете элемент, который нужно добавить: \n1. Вокзал\n2. Автобус\n 3. Водителя\n4. Маршрут\n"; 
            cin >> loc_choice;
            code = switch_add(station_head, station_end, driver_head, driver_end, route_head, route_end);
            if (code) return 666; // PrintMess
            break;

        case 2:

            cout << "Выберете элемент, который нужно удалить: \n1. Вокзал\n2. Автобус\n 3. Водителя\n4. Маршрут\n";
            cin >> loc_choice;
            code = switch_del(station_head, station_end, driver_head, driver_end, route_head, route_end);
            if (code) return 666; // PrintMess
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
            if (code) return 666; // PrintMess
            break;

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
    int id; 
    string name;
    Station* station_ptr = findElemStation(id_station, head); // Вокзал, к которому будет относиться автобус
    cout << "Введите id марки автобуса: "; cin >> id;
    if (cin.fail()) {
        return 1; // Некорректный id
    }
    else if (!station_ptr) return 4; // Не найдена станция
    cout << "Введите название марки: "; cin >> name;
    if (cin.fail()) {
        return 2; // Некорректное имя
    }

    Bus* bus_end = station_ptr->busEnd;
    makeBus(station_ptr->id, id, name, bus_end, station_ptr->busHead);
    station_ptr->busEnd = bus_end;

    return 0;
}

int add_drivers(Driver*& head, Driver*& end)
{
    int id; 
    string name;
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
        mistake_code = del_station(s_head, s_end, r_head, r_end);
        break;
    case 2:

        mistake_code = del_bus(s_head, r_head, r_end);
        break;
    case 3:
        mistake_code = del_driver(d_head, d_end, r_head, r_end);
        break;
    case 4:
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
    ptr = find_route(route_number, head);
    if (!ptr) return 4; // Если такого нет
    delete_route(head, end, route_number);
    return 0;
}


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