#include <iostream>
#include <string>
#include "lists.h"
using namespace std;

/***********************************************************************
 *                Р Е А Л И З А Ц И Я    Ф У Н К Ц И Й                 *
 ***********************************************************************/

// Функции кольцевого двухсвязного для марок
void makeBus(int id, int id_bus, string name, Bus*& end, Bus*& head) //  Добавление нового элемента
{
    Bus* ptr = new Bus;

    if (!head) head = ptr;
    else
    {
        end->next = ptr;
        ptr->prev = end;
    }
    // Заполнение инф полей
    ptr->id = id;
    ptr -> id_bus = id_bus;
    ptr->name = name;

    end = ptr;
    end->next = head;
    head->prev = end;
} // makeBus

void DeleteBus(Bus*& head, Bus*& end, int index) // Удаление элемента по его индексу
{ // TODO: проверка индекса
    int counter = 0;
    Bus* ptr = head;
    if (index == 0) // Удаляется голова
    {
        ptr->prev->next = ptr->next; // Лево на право
        ptr->next->prev = ptr->prev;  // Право на лево
        head = ptr->next; // Голову на второй
        delete ptr;
        return;
    }
    ptr = ptr->next; counter++;
    while (ptr != head)
    {
        if (index == counter)
        {
            ptr->prev->next = ptr->next; // Лево на право
            ptr->next->prev = ptr->prev;  // Право на лево
            delete ptr;
            return;
        } // if
        counter++;
        ptr = ptr->next;
    } // while
} // DeleteBus

void printBus(Bus* head)  // Печать всего списка
{
    Bus* ptr = head;
    if (ptr) cout << ptr->id << " " << ptr->name << endl;
    else
    {
        cout << "Список пуст!" << endl;
        return;
    } // else
    ptr = ptr->next;
    while (ptr != head)
    {
        cout << ptr->id << " " << ptr->name << endl;
        ptr = ptr->next;
    } // while
} // printBus

//void printBusBack(Bus* end) // В обратную сторону
//{
//    Bus* ptr = end;
//    if (ptr) cout << ptr->id << " " << ptr->name << endl;
//    else
//    {
//        cout << "Список пуст!" << endl;
//        return;
//    } // else
//    ptr = ptr->prev;
//    while (ptr != end)
//    {
//        cout << ptr->id << " " << ptr->name << endl;
//        ptr = ptr->prev;
//    } // while
//} // printBusBack

//void delListBus(Bus*& head, Bus*& end) // Удаление списка
//{
//    Bus* ptr = head;
//    while (head != end)
//    {
//        ptr = head;
//        ptr->prev->next = ptr->next; // Лево на право
//        ptr->next->prev = ptr->prev;  // Право на лево
//        head = ptr->next;
//        delete ptr;
//    }
//    delete head; // Удаляем конец
//    head = NULL; end = NULL;
//} // delListBus
//Bus* findElemBus(float a, Bus* head); // Найти элемент в списке

// Функции двухсвязного списка для вокзалов
void makeStation(int id, string name, Station*& end, Station*& head) //  Добавление нового элемента
{
    Station* ptr = new Station;
    
    if (!head) head = ptr;
    else
    {
        end->next = ptr;
        ptr->prev = end;
    }
    // Заполнение инф полей
    ptr->id = id;
    ptr->name = name;

    end = ptr;
    end->next = head;
    head->prev = end;
}
void DeleteStation(Station*& head, Station*& end, int index) // Удаление элемента по его индексу 
{ // TODO: проверка индекса
    int counter = 0;
    Station* ptr = head;
    if (index == 0) // Удаляется голова
    {
        ptr->prev->next = ptr->next; // Лево на право
        ptr->next->prev = ptr->prev;  // Право на лево
        head = ptr->next; // Голову на второй
        delete ptr;
        return;
    }
    ptr = ptr->next; counter++;
    while (ptr != head)
    {
        if (index == counter)
        {
            ptr->prev->next = ptr->next; // Лево на право
            ptr->next->prev = ptr->prev;  // Право на лево
            delete ptr;
            return;
        } // if
        counter++;
        ptr = ptr->next;
    } // while
} // DeleteStation

void printStation(Station* head)  // Печать всего списка
{
    Station* ptr = head;
    if (ptr) cout << ptr->id << " " << ptr->name << endl;
    else
    {
        cout << "Список пуст!" << endl;
        return;
    } // else
    ptr = ptr->next;
    while (ptr != head)
    {
        cout << ptr->id << " " << ptr->name << endl;
        ptr = ptr->next;
    } // while
}

void printStationBack(Station* end)  // Печать всего списка в обратном порядке
{
    Station* ptr = end;
    if (ptr) cout << ptr->id << " " << ptr->name << endl;
    else
    {
        cout << "Список пуст!" << endl;
        return;
    } // else
    ptr = ptr->prev;
    while (ptr != end)
    {
        cout << ptr->id << " " << ptr->name << endl;
        ptr = ptr->prev;
    } // while
}

void delListStation(Station*& head, Station*& end) // Удаление списка
{
    Station* ptr = head;
    while (head != end)
    {
        ptr = head;
        ptr->prev->next = ptr->next; // Лево на право
        ptr->next->prev = ptr->prev;  // Право на лево
        head = ptr->next;
        delete ptr;
    }
    delete head; // Удаляем конец
    head = NULL; end = NULL;
} // delListRDL

//Bus_Station* findElemRDL(float a, Bus_Station* head) // Найти элемент в списке
//{
//    Bus_Station* ptr = head;
//    if (a == ptr->data) return ptr; // Если голова - искомое
//    ptr = ptr->next;
//    while (ptr != head)
//    {
//        if (a == ptr->data) return ptr;
//        ptr = ptr->next;
//    } // while
//    cout << "Элемент " << a << " не найден" << endl;
//    return nullptr;
//}
//int count_sizeRDL(RingElem* head)
//{
//
//}

// Функции линейного ВОДИТЕЛЬ
void make_driver(int id, string name, Driver*& end, Driver*& head) //  Добавление нового элемента
{
    Driver* ptr = new Driver; // Новый элемент
    if (!head) head = ptr; // Если это первый элемент
    else { end->next = ptr; } // У конца появилось продолжение

    // Заполнение информ полей
    ptr->id = id;
    ptr->name = name;

    end = ptr; // Делаем этот элемент последним
    ptr->next = NULL; // Следующих элементов списка нет
} // make

//Route* findElem(float a, Route* head) // Найти элемент в списке
//{
//    Route* ptr = head;
//    while (ptr)
//    {
//        if (ptr->data == a) return ptr;
//        ptr = ptr->next;
//    }
//    return nullptr;
//} // findElem

void print_drivers(Driver* head)  // Печать всего списка
{
    Driver* ptr = head;
    if (!ptr) cout << "Список пуст" << endl;
    while (ptr)
    {
        cout << "\t" << ptr->id << " " << ptr->name << endl;  // Считывание данного
        ptr = ptr->next; // Переход к следующему
    }
    cout << endl;
} // print

//int count_size(Route* head) // Посчитать размер списка
//{
//    int counter = 0;
//    while (head)
//    {
//        counter++;
//        head = head->next;
//    } // while
//    return counter;
//} // counter_size
//
//void Delete(Route*& head, int index) { // Удаление элемента по индексу
//    Route* ptr = head;
//    for (int i = 0; i < index - 1; i++) {
//        ptr = ptr->next;
//    } // for i
//    if (ptr != head)
//    {
//        Route* ptr2 = ptr->next;
//        ptr->next = ptr->next->next;
//        delete ptr2;
//    } // if
//    else {
//        head = ptr->next;
//        delete ptr;
//    } // else
//} // Delete
//
//void delList(Route*& head) // Удаление всего списка
//{
//    Route* ptr;
//    while (head) // Удаление, начинающееся с "головы"
//    {
//        ptr = head->next;
//        delete head;
//        head = ptr;
//    } // while
//    head = NULL;
//} // delList

// Функции линейного РЕЙСЫ
void make_route(int id_station, int id_bus, int id_driver, int route_number, string time, int tickets, int passengers, string end_route, Route*& end, Route*& head) //  Добавление нового элемента
{
    Route* ptr = new Route; // Новый элемент
    if (!head) head = ptr; // Если это первый элемент
    else { end->next = ptr; } // У конца появилось продолжение

    // Заполнение информ полей
    ptr->id_station = id_station; // ID автовокзала
    ptr->id_bus = id_bus; // ID автобуса
    ptr->id_driver = id_driver; // ID водителя
    ptr->route_number = route_number; // Номер рейса
    ptr->time = time; // Время отправления
    ptr->tickets = tickets; // Количество проданных билетов
    ptr->passengers = passengers; // Количество пассажиров
    ptr->end_route = end_route; // Место назначения

    end = ptr; // Делаем этот элемент последним
    ptr->next = NULL; // Следующих элементов списка нет
} // make

//Route* findElem(float a, Route* head) // Найти элемент в списке
//{
//    Route* ptr = head;
//    while (ptr)
//    {
//        if (ptr->data == a) return ptr;
//        ptr = ptr->next;
//    }
//    return nullptr;
//} // findElem

void print_routes(Route* head)  // Печать всего списка
{
    Route* ptr = head;
    if (!ptr) cout << "Список пуст" << endl;
    while (ptr)
    {
        cout << "\t" << ptr->id_station << " " << ptr->id_bus << " " << ptr->id_driver << " " << ptr->route_number << " " << ptr->time << " "
            << ptr->tickets << " " << ptr->passengers << " " << ptr->end_route << endl;  // Считывание данного
        ptr = ptr->next; // Переход к следующему
    }
    cout << endl;
} // print