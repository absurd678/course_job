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

void DeleteBus(Bus*& head, Bus*& end, int id) // �������� �������� �� ��� id
{ // TODO: �������� �������
    int counter = 0;
    Bus* ptr = head;
    do
    {
        if (id == ptr->id_bus)
        {
            if (counter == 0) // ��������� ������
            {
                ptr->prev->next = ptr->next; // ���� �� �����
                ptr->next->prev = ptr->prev;  // ����� �� ����
                head = ptr->next; // ������ �� ������
                delete ptr;
                return;
            }// if
            else // �� ���������� ��� �����
            {
                ptr->prev->next = ptr->next; // ���� �� �����
                ptr->next->prev = ptr->prev;  // ����� �� ����
                delete ptr;
                return;
            } // if
        }
        counter++;
        ptr = ptr->next;
    } while (ptr != head);
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

void printBusBack(Bus* end) // � �������� �������
{
    Bus* ptr = end;
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
} // printBusBack

void delListBus(Bus*& head, Bus*& end) // �������� ������
{
    Bus* ptr = head;
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
} // delListBus

Bus* findElemBus(int id, Bus* head) // ����� ������� �� id
{
    Bus* ptr = head;
    do // ����� �� ���� id
    {
        if (ptr->id_bus == id) return ptr;
        ptr = ptr->next;
    } while (ptr != head);
    return NULL;
} // findElemStation

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
void DeleteStation(Station*& head, Station*& end, int id) // �������� �������� �� ��� id
{ 
    int counter = 0;
    Station* ptr = head;
    do
    {
        if (id == ptr->id)
        {
            if (counter == 0) // ��������� ������
            {
                ptr->prev->next = ptr->next; // ���� �� �����
                ptr->next->prev = ptr->prev;  // ����� �� ����
                head = ptr->next; // ������ �� ������
                delete ptr;
                return;
            }// if
            else // �� ���������� ��� �����
            {
                ptr->prev->next = ptr->next; // ���� �� �����
                ptr->next->prev = ptr->prev;  // ����� �� ����
                delete ptr;
                return;
            } // if
        }
        counter++;
        ptr = ptr->next;
    } while (ptr != head);
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

Station* findElemStation(int id, Station* head) // ����� ������� �� id
{
    Station* ptr = head;
    do // ����� �� ���� id
    {
        if (ptr->id == id) return ptr;
        ptr = ptr->next;
    } while (ptr != head);
    return NULL;
} // findElemStation

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

Driver* find_driver(int id, Driver* head) // ����� ������� �� id
{
    Driver* ptr = head;
    while (ptr)
    {
        if (ptr->id == id) return ptr;
        ptr = ptr->next;
    }
    return NULL;
} // findElemStation

void delete_driver(Driver*& head, Driver*& end, int id) { // �������� �������� �� id
    Driver* ptr = head;

    if (ptr->id == id) // �������� ������
    {
        head = ptr->next;
        delete ptr;
    } // if
    while(ptr->next->id != id) ptr = ptr->next; // ���� ��������������� ���������� ��������

    Driver* ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    if (ptr2 == end) end = ptr;
    delete ptr2;
} // delete_driver

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
//
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
void make_route(Route* ptr, Route*& end, Route*& head) //  ���������� ������ ��������
{
    if (!head) head = ptr; // ���� ��� ������ �������
    else { end->next = ptr; } // � ����� ��������� �����������

    end = ptr; // ������ ���� ������� ���������
    ptr->next = NULL; // ��������� ��������� ������ ���
} // make

Route* find_route(int route_number, Route* head) // ����� ������� �� ������ ��������
{
    Route* ptr = head;
    while (ptr)
    {
        if (ptr->route_number == route_number) return ptr;
        ptr = ptr->next;
    }
    return NULL;
} // find_route

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

void delete_route(Route*& head, Route*& end, int route_number) { // �������� �������� �� ������ ��������
    Route* ptr = head;

    if (ptr->route_number == route_number) // �������� ������
    {
        head = ptr->next;
        delete ptr;
    } // if
    while (ptr->next->route_number != route_number) ptr = ptr->next; // ���� ��������������� ���������� ��������

    Route* ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    if (ptr2 == end) end = ptr;
    delete ptr2;
} // Delete