#pragma once
//#include <string>

// "перемещение в прямом и обратном направлениях" - ?

// С Т Р У К Т У Р Ы
struct Route { // Линейный (рейсы)
    Route* next;

    int id; // ID
    string bus; // Назв марки (чтобы понимать, к какому автобусу относить, а не только вокзалу)
    string driver; // ФИО водителя
    int route_number; // Номер рейса
    string time; // Время отправления
    int tickets; // Количество проданных билетов
    int passengers; // Количество пассажиров
    string end_route; // Место назначения
}; 

struct Bus // Двунаправленный кольцевой (марки)
{
    Bus* prev;
    Bus* next;

    int id; // ID
    string name; // Назв автовокзала или марки
    Route* routeHead; // Голова списка рейсов для данной марки
    Route* routeEnd; // Хвост списка рейсов для данной марки
};

struct Station // Двунаправленный кольцевой (автовокзалы)
{
    Station* prev;
    Station* next;

    int id; // ID
    string name; // Назв автовокзала
    Bus* busHead; // Голова списка марок для данного вокзала
    Bus* busEnd; // Хвост списка марок
};



// Функции линейного
void make(int id, string bus, string driver, int route_number, string time, int tickets, int passengers, string end_route, Route*& end, Route*& head); //  Добавление нового элемента
void print(Route* head);  // Печать всего списка
void delList(Route*& head); // Удаление списка
Route* findElem(float a, Route* head); // Найти элемент в списке TODO
//int findMax(List* head); // Поиск максимального элемента с возвратом его номера
//void Insertion(float a, List* head, int index); // добавлений элемента
//void Delete(List*& head, int index); // Удаление элемента по его индексу
//int count_size(List* head); // Посчитать длину списка

// Функции кольцевого двухсвязного для марок
void makeBus(int id, string name, Station*& end, Station*& head); //  Добавление нового элемента
void DeleteBus(Bus*& head, Bus*& end, int index); // Удаление элемента по его индексу
void printBus(Bus* head);  // Печать всего списка
void printBusBack(Bus* end); // В обратную сторону
void delListBus(Bus*& head, Bus*& end); // Удаление списка
//Bus* findElemBus(float a, Bus* head); // Найти элемент в списке


// Функции кольцевого двухсвязного для вокзалов
//int createRDL(List*& head, List*& end, const char* fileName); // Создание списка
void makeStation(int id, string name, Station*& end, Station*& head); //  Добавление нового элемента
void DeleteStation(Station*& head, Station*& end, int index); // Удаление элемента по его индексу
void printStation(Station* head);  // Печать всего списка
void printStationBack(Station* end); // В обратную сторону
void delListStation(Station*& head, Station*& end); // Удаление списка
//Station* findElemStation(float a, Station* head); // Найти элемент в списке
//int count_sizeRDL(RingElem* head); // Посчитать длину списка