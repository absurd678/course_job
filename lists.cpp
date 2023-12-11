#include <iostream>
#include <string>
#include "lists.h"
using namespace std;

/***********************************************************************
 *                � � � � � � � � � �    � � � � � � �                 *
 ***********************************************************************/

// ������� ���������� ������������ ��� �����
void makeBus(int id, int id_bus, string name, Bus*& end, Bus*& head) //  ���������� ������ ��������
{
    Bus* ptr = new Bus;

    if (!head) head = ptr;
    else
    {
        end->next = ptr;
        ptr->prev = end;
    }
    // ���������� ��� �����
    ptr->id = id;
    ptr -> id_bus = id_bus;
    ptr->name = name;

    end = ptr;
    end->next = head;
    head->prev = end;
} // makeBus

void DeleteBus(Bus*& head, Bus*& end, int index) // �������� �������� �� ��� �������
{ // TODO: �������� �������
    int counter = 0;
    Bus* ptr = head;
    if (index == 0) // ��������� ������
    {
        ptr->prev->next = ptr->next; // ���� �� �����
        ptr->next->prev = ptr->prev;  // ����� �� ����
        head = ptr->next; // ������ �� ������
        delete ptr;
        return;
    }
    ptr = ptr->next; counter++;
    while (ptr != head)
    {
        if (index == counter)
        {
            ptr->prev->next = ptr->next; // ���� �� �����
            ptr->next->prev = ptr->prev;  // ����� �� ����
            delete ptr;
            return;
        } // if
        counter++;
        ptr = ptr->next;
    } // while
} // DeleteBus

void printBus(Bus* head)  // ������ ����� ������
{
    Bus* ptr = head;
    if (ptr) cout << ptr->id << " " << ptr->name << endl;
    else
    {
        cout << "������ ����!" << endl;
        return;
    } // else
    ptr = ptr->next;
    while (ptr != head)
    {
        cout << ptr->id << " " << ptr->name << endl;
        ptr = ptr->next;
    } // while
} // printBus

//void printBusBack(Bus* end) // � �������� �������
//{
//    Bus* ptr = end;
//    if (ptr) cout << ptr->id << " " << ptr->name << endl;
//    else
//    {
//        cout << "������ ����!" << endl;
//        return;
//    } // else
//    ptr = ptr->prev;
//    while (ptr != end)
//    {
//        cout << ptr->id << " " << ptr->name << endl;
//        ptr = ptr->prev;
//    } // while
//} // printBusBack

//void delListBus(Bus*& head, Bus*& end) // �������� ������
//{
//    Bus* ptr = head;
//    while (head != end)
//    {
//        ptr = head;
//        ptr->prev->next = ptr->next; // ���� �� �����
//        ptr->next->prev = ptr->prev;  // ����� �� ����
//        head = ptr->next;
//        delete ptr;
//    }
//    delete head; // ������� �����
//    head = NULL; end = NULL;
//} // delListBus
//Bus* findElemBus(float a, Bus* head); // ����� ������� � ������

// ������� ������������ ������ ��� ��������
void makeStation(int id, string name, Station*& end, Station*& head) //  ���������� ������ ��������
{
    Station* ptr = new Station;
    
    if (!head) head = ptr;
    else
    {
        end->next = ptr;
        ptr->prev = end;
    }
    // ���������� ��� �����
    ptr->id = id;
    ptr->name = name;

    end = ptr;
    end->next = head;
    head->prev = end;
}
void DeleteStation(Station*& head, Station*& end, int index) // �������� �������� �� ��� ������� 
{ // TODO: �������� �������
    int counter = 0;
    Station* ptr = head;
    if (index == 0) // ��������� ������
    {
        ptr->prev->next = ptr->next; // ���� �� �����
        ptr->next->prev = ptr->prev;  // ����� �� ����
        head = ptr->next; // ������ �� ������
        delete ptr;
        return;
    }
    ptr = ptr->next; counter++;
    while (ptr != head)
    {
        if (index == counter)
        {
            ptr->prev->next = ptr->next; // ���� �� �����
            ptr->next->prev = ptr->prev;  // ����� �� ����
            delete ptr;
            return;
        } // if
        counter++;
        ptr = ptr->next;
    } // while
} // DeleteStation

void printStation(Station* head)  // ������ ����� ������
{
    Station* ptr = head;
    if (ptr) cout << ptr->id << " " << ptr->name << endl;
    else
    {
        cout << "������ ����!" << endl;
        return;
    } // else
    ptr = ptr->next;
    while (ptr != head)
    {
        cout << ptr->id << " " << ptr->name << endl;
        ptr = ptr->next;
    } // while
}

void printStationBack(Station* end)  // ������ ����� ������ � �������� �������
{
    Station* ptr = end;
    if (ptr) cout << ptr->id << " " << ptr->name << endl;
    else
    {
        cout << "������ ����!" << endl;
        return;
    } // else
    ptr = ptr->prev;
    while (ptr != end)
    {
        cout << ptr->id << " " << ptr->name << endl;
        ptr = ptr->prev;
    } // while
}

void delListStation(Station*& head, Station*& end) // �������� ������
{
    Station* ptr = head;
    while (head != end)
    {
        ptr = head;
        ptr->prev->next = ptr->next; // ���� �� �����
        ptr->next->prev = ptr->prev;  // ����� �� ����
        head = ptr->next;
        delete ptr;
    }
    delete head; // ������� �����
    head = NULL; end = NULL;
} // delListRDL

//Bus_Station* findElemRDL(float a, Bus_Station* head) // ����� ������� � ������
//{
//    Bus_Station* ptr = head;
//    if (a == ptr->data) return ptr; // ���� ������ - �������
//    ptr = ptr->next;
//    while (ptr != head)
//    {
//        if (a == ptr->data) return ptr;
//        ptr = ptr->next;
//    } // while
//    cout << "������� " << a << " �� ������" << endl;
//    return nullptr;
//}
//int count_sizeRDL(RingElem* head)
//{
//
//}

// ������� ��������� ��������
void make_driver(int id, string name, Driver*& end, Driver*& head) //  ���������� ������ ��������
{
    Driver* ptr = new Driver; // ����� �������
    if (!head) head = ptr; // ���� ��� ������ �������
    else { end->next = ptr; } // � ����� ��������� �����������

    // ���������� ������ �����
    ptr->id = id;
    ptr->name = name;

    end = ptr; // ������ ���� ������� ���������
    ptr->next = NULL; // ��������� ��������� ������ ���
} // make

//Route* findElem(float a, Route* head) // ����� ������� � ������
//{
//    Route* ptr = head;
//    while (ptr)
//    {
//        if (ptr->data == a) return ptr;
//        ptr = ptr->next;
//    }
//    return nullptr;
//} // findElem

void print_drivers(Driver* head)  // ������ ����� ������
{
    Driver* ptr = head;
    if (!ptr) cout << "������ ����" << endl;
    while (ptr)
    {
        cout << "\t" << ptr->id << " " << ptr->name << endl;  // ���������� �������
        ptr = ptr->next; // ������� � ����������
    }
    cout << endl;
} // print

//int count_size(Route* head) // ��������� ������ ������
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
//void Delete(Route*& head, int index) { // �������� �������� �� �������
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
//void delList(Route*& head) // �������� ����� ������
//{
//    Route* ptr;
//    while (head) // ��������, ������������ � "������"
//    {
//        ptr = head->next;
//        delete head;
//        head = ptr;
//    } // while
//    head = NULL;
//} // delList

// ������� ��������� �����
void make_route(int id_station, int id_bus, int id_driver, int route_number, string time, int tickets, int passengers, string end_route, Route*& end, Route*& head) //  ���������� ������ ��������
{
    Route* ptr = new Route; // ����� �������
    if (!head) head = ptr; // ���� ��� ������ �������
    else { end->next = ptr; } // � ����� ��������� �����������

    // ���������� ������ �����
    ptr->id_station = id_station; // ID �����������
    ptr->id_bus = id_bus; // ID ��������
    ptr->id_driver = id_driver; // ID ��������
    ptr->route_number = route_number; // ����� �����
    ptr->time = time; // ����� �����������
    ptr->tickets = tickets; // ���������� ��������� �������
    ptr->passengers = passengers; // ���������� ����������
    ptr->end_route = end_route; // ����� ����������

    end = ptr; // ������ ���� ������� ���������
    ptr->next = NULL; // ��������� ��������� ������ ���
} // make

//Route* findElem(float a, Route* head) // ����� ������� � ������
//{
//    Route* ptr = head;
//    while (ptr)
//    {
//        if (ptr->data == a) return ptr;
//        ptr = ptr->next;
//    }
//    return nullptr;
//} // findElem

void print_routes(Route* head)  // ������ ����� ������
{
    Route* ptr = head;
    if (!ptr) cout << "������ ����" << endl;
    while (ptr)
    {
        cout << "\t" << ptr->id_station << " " << ptr->id_bus << " " << ptr->id_driver << " " << ptr->route_number << " " << ptr->time << " "
            << ptr->tickets << " " << ptr->passengers << " " << ptr->end_route << endl;  // ���������� �������
        ptr = ptr->next; // ������� � ����������
    }
    cout << endl;
} // print