#pragma once
//#include <string>

// "����������� � ������ � �������� ������������" - ?

// � � � � � � � � �
struct Route { // �������� (�����)
    Route* next;

    int id; // ID
    string bus; // ���� ����� (����� ��������, � ������ �������� ��������, � �� ������ �������)
    string driver; // ��� ��������
    int route_number; // ����� �����
    string time; // ����� �����������
    int tickets; // ���������� ��������� �������
    int passengers; // ���������� ����������
    string end_route; // ����� ����������
}; 

struct Bus // ��������������� ��������� (�����)
{
    Bus* prev;
    Bus* next;

    int id; // ID
    string name; // ���� ����������� ��� �����
    Route* routeHead; // ������ ������ ������ ��� ������ �����
    Route* routeEnd; // ����� ������ ������ ��� ������ �����
};

struct Station // ��������������� ��������� (�����������)
{
    Station* prev;
    Station* next;

    int id; // ID
    string name; // ���� �����������
    Bus* busHead; // ������ ������ ����� ��� ������� �������
    Bus* busEnd; // ����� ������ �����
};



// ������� ���������
void make(int id, string bus, string driver, int route_number, string time, int tickets, int passengers, string end_route, Route*& end, Route*& head); //  ���������� ������ ��������
void print(Route* head);  // ������ ����� ������
void delList(Route*& head); // �������� ������
Route* findElem(float a, Route* head); // ����� ������� � ������ TODO
//int findMax(List* head); // ����� ������������� �������� � ��������� ��� ������
//void Insertion(float a, List* head, int index); // ���������� ��������
//void Delete(List*& head, int index); // �������� �������� �� ��� �������
//int count_size(List* head); // ��������� ����� ������

// ������� ���������� ������������ ��� �����
void makeBus(int id, string name, Station*& end, Station*& head); //  ���������� ������ ��������
void DeleteBus(Bus*& head, Bus*& end, int index); // �������� �������� �� ��� �������
void printBus(Bus* head);  // ������ ����� ������
void printBusBack(Bus* end); // � �������� �������
void delListBus(Bus*& head, Bus*& end); // �������� ������
//Bus* findElemBus(float a, Bus* head); // ����� ������� � ������


// ������� ���������� ������������ ��� ��������
//int createRDL(List*& head, List*& end, const char* fileName); // �������� ������
void makeStation(int id, string name, Station*& end, Station*& head); //  ���������� ������ ��������
void DeleteStation(Station*& head, Station*& end, int index); // �������� �������� �� ��� �������
void printStation(Station* head);  // ������ ����� ������
void printStationBack(Station* end); // � �������� �������
void delListStation(Station*& head, Station*& end); // �������� ������
//Station* findElemStation(float a, Station* head); // ����� ������� � ������
//int count_sizeRDL(RingElem* head); // ��������� ����� ������