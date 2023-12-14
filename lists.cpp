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

void DeleteBus(Bus*& head, Bus*& end, int id) // Удаление элемента по его id
{ // TODO: проверка индекса
    int counter = 0;
    Bus* ptr = head;
    do
    {
        if (id == ptr->id_bus)
        {
            if (counter == 0) // Удаляется голова
            {
                ptr->prev->next = ptr->next; // Лево на право
                ptr->next->prev = ptr->prev;  // Право на лево
                head = ptr->next; // Голову на второй
                delete ptr;
                return;
            }// if
            else // Из промежутка или конца
            {
                ptr->prev->next = ptr->next; // Лево на право
                ptr->next->prev = ptr->prev;  // Право на лево
                delete ptr;
                return;
            } // if
        }
        counter++;
        ptr = ptr->next;
    } while (ptr != head);
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

void printBusBack(Bus* end) // В обратную сторону
{
    Bus* ptr = end;
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
} // printBusBack

void delListBus(Bus*& head, Bus*& end) // Удаление списка
{
    Bus* ptr = head;
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
} // delListBus

Bus* findElemBus(int id, Bus* head) // Найти элемент по id
{
    Bus* ptr = head;
    do // Поиск по полю id
    {
        if (ptr->id_bus == id) return ptr;
        ptr = ptr->next;
    } while (ptr != head);
    return NULL;
} // findElemStation

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
void DeleteStation(Station*& head, Station*& end, int id) // Удаление элемента по его id
{ 
    int counter = 0;
    Station* ptr = head;
    do
    {
        if (id == ptr->id)
        {
            if (counter == 0) // Удаляется голова
            {
                ptr->prev->next = ptr->next; // Лево на право
                ptr->next->prev = ptr->prev;  // Право на лево
                head = ptr->next; // Голову на второй
                delete ptr;
                return;
            }// if
            else // Из промежутка или конца
            {
                ptr->prev->next = ptr->next; // Лево на право
                ptr->next->prev = ptr->prev;  // Право на лево
                delete ptr;
                return;
            } // if
        }
        counter++;
        ptr = ptr->next;
    } while (ptr != head);
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

Station* findElemStation(int id, Station* head) // Найти элемент по id
{
    Station* ptr = head;
    do // Поиск по полю id
    {
        if (ptr->id == id) return ptr;
        ptr = ptr->next;
    } while (ptr != head);
    return NULL;
} // findElemStation

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

Driver* find_driver(int id, Driver* head) // Найти элемент по id
{
    Driver* ptr = head;
    while (ptr)
    {
        if (ptr->id == id) return ptr;
        ptr = ptr->next;
    }
    return NULL;
} // findElemStation

void delete_driver(Driver*& head, Driver*& end, int id) { // Удаление элемента по id
    Driver* ptr = head;

    if (ptr->id == id) // Удаление головы
    {
        head = ptr->next;
        delete ptr;
    } // if
    while(ptr->next->id != id) ptr = ptr->next; // Ищем предшественника удаляемого элемента

    Driver* ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    if (ptr2 == end) end = ptr;
    delete ptr2;
} // delete_driver

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
//
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
void make_route(Route* ptr, Route*& end, Route*& head) //  Добавление нового элемента
{
    if (!head) head = ptr; // Если это первый элемент
    else { end->next = ptr; } // У конца появилось продолжение

    end = ptr; // Делаем этот элемент последним
    ptr->next = NULL; // Следующих элементов списка нет
} // make

Route* find_route(int route_number, Route* head) // Найти элемент по номеру маршрута
{
    Route* ptr = head;
    while (ptr)
    {
        if (ptr->route_number == route_number) return ptr;
        ptr = ptr->next;
    }
    return NULL;
} // find_route

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

void delete_route(Route*& head, Route*& end, int route_number) { // Удаление элемента по номеру маршрута
    Route* ptr = head;

    if (ptr->route_number == route_number) // Удаление головы
    {
        head = ptr->next;
        delete ptr;
    } // if
    while (ptr->next->route_number != route_number) ptr = ptr->next; // Ищем предшественника удаляемого элемента

    Route* ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    if (ptr2 == end) end = ptr;
    delete ptr2;
} // Delete