#pragma once
#include <string>
#include <iostream>
using namespace std;

// "перемещение в прямом и обратном направлениях" - ?

// С Т Р У К Т У Р Ы
struct Bus // Двунаправленный кольцевой АВТОБУСЫ
{
    Bus* prev;
    Bus* next;

    int id; // ID автовокзала
    int id_bus; // ID автобуса
    string name; // Назв марки
};

struct Station // Двунаправленный кольцевой АВТОВОКЗАЛЫ
{
    Station* prev;
    Station* next;

    int id; // ID
    string name; // Назв автовокзала
    Bus* busHead = NULL; // Голова списка автобусов для данного вокзала
    Bus* busEnd = NULL; // Хвост списка автобусов
};

struct Driver // Водитель (линейный)
{
    Driver* next;

    string name; // ФИО
    int id; // ID водителя
};

struct Route { // Линейный (рейсы)
    Route* next;

    int id_station; // ID автовокзала
    int id_bus; // ID автобуса
    int id_driver; // ID водителя

    int route_number; // Номер рейса
    string time; // Время отправления
    int tickets; // Количество проданных билетов
    int passengers; // Количество пассажиров
    string end_route; // Место назначения
}; 

// Функции кольцевого двухсвязного для ВОКЗАЛОВ
int makeStation(int id, string name, Station*& end, Station*& head); //  Добавление нового элемента
int max_station_id(Station* head); // Найти макс id
void DeleteStation(Station*& head, Station*& end, int id); // Удаление элемента по его id
void printStation(Station* head);  // Печать всего списка
void printStationBack(Station* end); // В обратную сторону
void delListStation(Station*& head, Station*& end); // Удаление списка
Station* findElemStation(int id, Station* head); // Найти элемент по id
int find_id_station(string name, Station* head); // Найти id по названию
Station* move_in_stations(Station* curr_pos, int step); // Перемещение в прямом и обратном направлениях

// Функции кольцевого двухсвязного для АВТОБУСОВ
int makeBus(int id, int id_bus, string name, Bus*& end, Bus*& head); //  Добавление нового элемента
int max_bus_id(Bus* head); // Найти макс id
void DeleteBus(Bus*& head, Bus*& end, int index); // Удаление элемента по его индексу
void printBus(Bus* head, Station* s_head);  // Печать всего списка
void printBusBack(Bus* end); // В обратную сторону
void delListBus(Bus*& head, Bus*& end); // Удаление списка
Bus* findElemBus(int id, Bus* head); // Найти элемент в списке по id
int find_id_bus(string name, Bus* head); // Найти id по названию
Bus* move_in_buses(Bus* curr_pos, int step); // Перемещение в прямом и обратном направлениях

// Функции линейного ВОДИТЕЛЬ
int make_driver(int id, string name, Driver*& end, Driver*& head); //  Добавление нового элемента
int max_driver_id(Driver* head); // Найти макс id
void print_drivers(Driver* head);  // Печать всего списка
Driver* find_driver(int id, Driver* head); // Найти элемент в списке по id
int find_id_driver(string name, Driver* head); // Найти id по названию
void delete_driver(Driver*& head, Driver*& end, int id); // Удаление элемента по его id
void del_drivers(Driver*& head); // Удаление списка

// Функции линейного РЕЙСЫ
int make_route(Route* ptr, Route*& end, Route*& head); //  Добавление нового элемента
void print_routes(Route* head, Station* s_head, Driver* d_head);  // Печать всего списка
Route* find_route_stationID(int id_station, Route* head); // Найти элемент в списке по полю id вокзала
Route* find_route_busID(int id_bus, Route* head); // Найти элемент в списке по полю id автобуса
Route* find_route_driverID(int id_driver, Route* head); // Найти элемент в списке по полю id водителя
Route* find_route_number(int route_number, Route* head); // Найти элемент в списке по полю номера маршрута
Route* find_route_time_dep(string time_dep, Route* head);
Route* find_route_tickets(int tickets, Route* head);
Route* find_route_pass(int passengers, Route* head);
Route* find_route_end(string end_route, Route* head);
void print_stations_in_route(Route* r_head, Station* s_head); // Вывод всех вокзалов для удаления или поиска
void print_buses_in_route(Route* r_head, Station* s_head); // Вывод всех вокзалов и автобусов для удаления или поиска
void print_drivers_in_route(Route* r_head, Driver* d_head); // Вывод всех водителей для удаления или поиска
void delete_route(Route*& head, Route*& end, int route_number); // Удаление элемента по номеру маршрута
void del_routes(Route*& head); // Удаление списка