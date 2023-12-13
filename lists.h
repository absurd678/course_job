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
void DeleteStation(Station*& head, Station*& end, int index); // �������� �������� �� ��� �������
void printStation(Station* head);  // ������ ����� ������
void printStationBack(Station* end); // � �������� �������
void delListStation(Station*& head, Station*& end); // �������� ������
Station* findElemStation(int id, Station* head); // ����� ������� �� id
//int count_sizeRDL(RingElem* head); // ��������� ����� ������

// ������� ���������� ������������ ��� ���������
void makeBus(int id, int id_bus, string name, Bus*& end, Bus*& head); //  ���������� ������ ��������
void DeleteBus(Bus*& head, Bus*& end, int index); // �������� �������� �� ��� �������
void printBus(Bus* head);  // ������ ����� ������
void printBusBack(Bus* end); // � �������� �������
void delListBus(Bus*& head, Bus*& end); // �������� ������
Bus* findElemBus(int id, Bus* head); // ����� ������� � ������ �� id

// ������� ��������� ��������
void make_driver(int id, string name, Driver*& end, Driver*& head); //  ���������� ������ ��������
void print_drivers(Driver* head);  // ������ ����� ������
Driver* find_driver(int id, Driver* head); // ����� ������� � ������ �� id
//void del_drivers(Driver*& head); // �������� ������
//void Insertion(float a, List* head, int index); // ���������� ��������
//void Delete(List*& head, int index); // �������� �������� �� ��� �������
//int count_size(List* head); // ��������� ����� ������

// ������� ��������� �����
void make_route(Route* ptr, Route*& end, Route*& head); //  ���������� ������ ��������
void print_routes(Route* head);  // ������ ����� ������
//void del_routes(Route*& head); // �������� ������
//Route* find_route(float a, Route* head); // ����� ������� � ������ TODO
//void Insertion(float a, List* head, int index); // ���������� ��������
//void Delete(List*& head, int index); // �������� �������� �� ��� �������
//int count_size(List* head); // ��������� ����� ������