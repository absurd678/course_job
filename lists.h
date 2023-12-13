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
//int createRDL(List*& head, List*& end, const char* fileName); // Создание списка
void makeStation(int id, string name, Station*& end, Station*& head); //  Добавление нового элемента
void DeleteStation(Station*& head, Station*& end, int index); // Удаление элемента по его индексу
void printStation(Station* head);  // Печать всего списка
void printStationBack(Station* end); // В обратную сторону
void delListStation(Station*& head, Station*& end); // Удаление списка
Station* findElemStation(int id, Station* head); // Найти элемент по id
//int count_sizeRDL(RingElem* head); // Посчитать длину списка

// Функции кольцевого двухсвязного для АВТОБУСОВ
void makeBus(int id, int id_bus, string name, Bus*& end, Bus*& head); //  Добавление нового элемента
void DeleteBus(Bus*& head, Bus*& end, int index); // Удаление элемента по его индексу
void printBus(Bus* head);  // Печать всего списка
void printBusBack(Bus* end); // В обратную сторону
void delListBus(Bus*& head, Bus*& end); // Удаление списка
Bus* findElemBus(int id, Bus* head); // Найти элемент в списке по id

// Функции линейного ВОДИТЕЛЬ
void make_driver(int id, string name, Driver*& end, Driver*& head); //  Добавление нового элемента
void print_drivers(Driver* head);  // Печать всего списка
Driver* find_driver(int id, Driver* head); // Найти элемент в списке по id
//void del_drivers(Driver*& head); // Удаление списка
//void Insertion(float a, List* head, int index); // добавлений элемента
//void Delete(List*& head, int index); // Удаление элемента по его индексу
//int count_size(List* head); // Посчитать длину списка

// Функции линейного РЕЙСЫ
void make_route(Route* ptr, Route*& end, Route*& head); //  Добавление нового элемента
void print_routes(Route* head);  // Печать всего списка
//void del_routes(Route*& head); // Удаление списка
//Route* find_route(float a, Route* head); // Найти элемент в списке TODO
//void Insertion(float a, List* head, int index); // добавлений элемента
//void Delete(List*& head, int index); // Удаление элемента по его индексу
//int count_size(List* head); // Посчитать длину списка