#pragma once
// � � � � � � � � �
struct Elem { // ��������
    float data;
    Elem* next;
}; 

struct RingElem // ��������������� ���������
{
    RingElem* prev;
    float data;
    RingElem* next;
};
// ������� ���������
void make(float a, Elem*& end, Elem*& head); //  ���������� ������ ��������
void print(Elem* head);  // ������ ����� ������
void delList(Elem*& head); // �������� ������
Elem* findElem(float a, Elem* head); // ����� ������� � ������
//int findMax(List* head); // ����� ������������� �������� � ��������� ��� ������
//void Insertion(float a, List* head, int index); // ���������� ��������
//void Delete(List*& head, int index); // �������� �������� �� ��� �������
//int count_size(List* head); // ��������� ����� ������

// ������� ���������� ������������
//int createRDL(List*& head, List*& end, const char* fileName); // �������� ������
void makeRDL(float a, RingElem*& end, RingElem*& head); //  ���������� ������ ��������
void DeleteRDL(RingElem*& head, RingElem*& end, int index); // �������� �������� �� ��� �������
void printRDL(RingElem* head);  // ������ ����� ������
void printRDLBack(RingElem* end); // � �������� �������
void delListRDL(RingElem*& head, RingElem*& end); // �������� ������
RingElem* findElemRDL(float a, RingElem* head); // ����� ������� � ������
//int count_sizeRDL(RingElem* head); // ��������� ����� ������