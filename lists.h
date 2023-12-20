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
int makeStation(int id, string name, Station*& end, Station*& head); //  ���������� ������ ��������
int max_station_id(Station* head); // ����� ���� id
void DeleteStation(Station*& head, Station*& end, int id); // �������� �������� �� ��� id
void printStation(Station* head);  // ������ ����� ������
void printStationBack(Station* end); // � �������� �������
void delListStation(Station*& head, Station*& end); // �������� ������
Station* findElemStation(int id, Station* head); // ����� ������� �� id
int find_id_station(string name, Station* head); // ����� id �� ��������
Station* move_in_stations(Station* curr_pos, int step); // ����������� � ������ � �������� ������������

// ������� ���������� ������������ ��� ���������
int makeBus(int id, int id_bus, string name, Bus*& end, Bus*& head); //  ���������� ������ ��������
int max_bus_id(Bus* head); // ����� ���� id
void DeleteBus(Bus*& head, Bus*& end, int index); // �������� �������� �� ��� �������
void printBus(Bus* head, Station* s_head);  // ������ ����� ������
void printBusBack(Bus* end); // � �������� �������
void delListBus(Bus*& head, Bus*& end); // �������� ������
Bus* findElemBus(int id, Bus* head); // ����� ������� � ������ �� id
int find_id_bus(string name, Bus* head); // ����� id �� ��������
Bus* move_in_buses(Bus* curr_pos, int step); // ����������� � ������ � �������� ������������

// ������� ��������� ��������
int make_driver(int id, string name, Driver*& end, Driver*& head); //  ���������� ������ ��������
int max_driver_id(Driver* head); // ����� ���� id
void print_drivers(Driver* head);  // ������ ����� ������
Driver* find_driver(int id, Driver* head); // ����� ������� � ������ �� id
int find_id_driver(string name, Driver* head); // ����� id �� ��������
void delete_driver(Driver*& head, Driver*& end, int id); // �������� �������� �� ��� id
void del_drivers(Driver*& head); // �������� ������

// ������� ��������� �����
int make_route(Route* ptr, Route*& end, Route*& head); //  ���������� ������ ��������
void print_routes(Route* head, Station* s_head, Driver* d_head);  // ������ ����� ������
Route* find_route_stationID(int id_station, Route* head); // ����� ������� � ������ �� ���� id �������
Route* find_route_busID(int id_bus, Route* head); // ����� ������� � ������ �� ���� id ��������
Route* find_route_driverID(int id_driver, Route* head); // ����� ������� � ������ �� ���� id ��������
Route* find_route_number(int route_number, Route* head); // ����� ������� � ������ �� ���� ������ ��������
Route* find_route_time_dep(string time_dep, Route* head);
Route* find_route_tickets(int tickets, Route* head);
Route* find_route_pass(int passengers, Route* head);
Route* find_route_end(string end_route, Route* head);
void print_stations_in_route(Route* r_head, Station* s_head); // ����� ���� �������� ��� �������� ��� ������
void print_buses_in_route(Route* r_head, Station* s_head); // ����� ���� �������� � ��������� ��� �������� ��� ������
void print_drivers_in_route(Route* r_head, Driver* d_head); // ����� ���� ��������� ��� �������� ��� ������
void delete_route(Route*& head, Route*& end, int route_number); // �������� �������� �� ������ ��������
void del_routes(Route*& head); // �������� ������