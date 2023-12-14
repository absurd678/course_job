#pragma once
#include <string>
#include <iostream>
using namespace std;

// "����������� � ������ � �������� ������������" - ?

// � � � � � � � � �
struct Bus // ��������������� ��������� ��������
{
    Bus* prev;
    Bus* next;

    int id; // ID �����������
    int id_bus; // ID ��������
    string name; // ���� �����
};

struct Station // ��������������� ��������� �����������
{
    Station* prev;
    Station* next;

    int id; // ID
    string name; // ���� �����������
    Bus* busHead = NULL; // ������ ������ ��������� ��� ������� �������
    Bus* busEnd = NULL; // ����� ������ ���������
};

struct Driver // �������� (��������)
{
    Driver* next;

    string name; // ���
    int id; // ID ��������
};

struct Route { // �������� (�����)
    Route* next;

    int id_station; // ID �����������
    int id_bus; // ID ��������
    int id_driver; // ID ��������

    int route_number; // ����� �����
    string time; // ����� �����������
    int tickets; // ���������� ��������� �������
    int passengers; // ���������� ����������
    string end_route; // ����� ����������
}; 

// ������� ���������� ������������ ��� ��������
//int createRDL(List*& head, List*& end, const char* fileName); // �������� ������
void makeStation(int id, string name, Station*& end, Station*& head); //  ���������� ������ ��������
void DeleteStation(Station*& head, Station*& end, int id); // �������� �������� �� ��� id
void printStation(Station* head);  // ������ ����� ������
void printStationBack(Station* end); // � �������� �������
void delListStation(Station*& head, Station*& end); // �������� ������
Station* findElemStation(int id, Station* head); // ����� ������� �� id
Station* move_in_stations(Station* curr_pos, int step); // ����������� � ������ � �������� ������������
//int count_sizeRDL(RingElem* head); // ��������� ����� ������

// ������� ���������� ������������ ��� ���������
void makeBus(int id, int id_bus, string name, Bus*& end, Bus*& head); //  ���������� ������ ��������
void DeleteBus(Bus*& head, Bus*& end, int index); // �������� �������� �� ��� �������
void printBus(Bus* head);  // ������ ����� ������
void printBusBack(Bus* end); // � �������� �������
void delListBus(Bus*& head, Bus*& end); // �������� ������
Bus* findElemBus(int id, Bus* head); // ����� ������� � ������ �� id
Bus* move_in_buses(Bus* curr_pos, int step); // ����������� � ������ � �������� ������������

// ������� ��������� ��������
void make_driver(int id, string name, Driver*& end, Driver*& head); //  ���������� ������ ��������
void print_drivers(Driver* head);  // ������ ����� ������
Driver* find_driver(int id, Driver* head); // ����� ������� � ������ �� id
void delete_driver(Driver*& head, Driver*& end, int id); // �������� �������� �� ��� id
//void del_drivers(Driver*& head); // �������� ������
//void Insertion(float a, List* head, int index); // ���������� ��������

//int count_size(List* head); // ��������� ����� ������

// ������� ��������� �����
void make_route(Route* ptr, Route*& end, Route*& head); //  ���������� ������ ��������
void print_routes(Route* head);  // ������ ����� ������
Route* find_route(int route_number, Route* head); // ����� ������� � ������ �� ���� ������ ��������
Route* find_route_stationID(int id_station, Route* head); // ����� ������� � ������ �� ���� id �������
Route* find_route_busID(int id_bus, Route* head); // ����� ������� � ������ �� ���� id ��������
Route* find_route_driverID(int id_driver, Route* head); // ����� ������� � ������ �� ���� id ��������
void delete_route(Route*& head, Route*& end, int route_number); // �������� �������� �� ������ ��������
//void del_routes(Route*& head); // �������� ������
//void Insertion(float a, List* head, int index); // ���������� ��������
//void Delete(List*& head, int index); // �������� �������� �� ��� �������
//int count_size(List* head); // ��������� ����� ������