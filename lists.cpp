#include <iostream>
#include "lists.h"
using namespace std;

/***********************************************************************
 *                � � � � � � � � � �    � � � � � � �                 *
 ***********************************************************************/

void make(float a, Elem*& end, Elem*& head) //  ���������� ������ ��������
{
    if (!findElem(a, head)) // ���� a � ������ ��� �� ����
    {
        Elem* ptr = new Elem; // ����� �������
        if (!head) head = ptr; // ���� ��� ������ �������
        else { end->next = ptr; } // � ����� ��������� �����������
        ptr->data = a;
        end = ptr; // ������ ���� ������� ���������
        ptr->next = NULL; // ��������� ��������� ������ ���
    } // if
    else cout << "������� a = " << a << " ��� ���������� � ������!" << endl;
} // make

Elem* findElem(float a, Elem* head) // ����� ������� � ������
{
    Elem* ptr = head;
    while (ptr)
    {
        if (ptr->data == a) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
} // findElem

void print(Elem* head)  // ������ ����� ������
{
    Elem* ptr = head;
    if (!ptr) cout << "������ ����";
    while (ptr)
    {
        cout << "\t" << ptr->data;  // ���������� �������
        ptr = ptr->next; // ������� � ����������
    }
    cout << endl;
} // print

int count_size(Elem* head) // ��������� ������ ������
{
    int counter = 0;
    while (head)
    {
        counter++;
        head = head->next;
    } // while
    return counter;
} // counter_size

int findMax(Elem* head) // ����� �������������
{
    Elem* ptr = head;
    int counter = -1; // ������
    float maxFound = -pow(10, 38); // ����� ��������� ��������
    while (ptr)
    {
        if (ptr->data > maxFound)
        {
            maxFound = ptr->data;
            counter++;
        } // if
        ptr = ptr->next; // ������� ������
    } // while
    cout << "���������� �������� = " << maxFound << endl;
    return counter;
} // findMax

void Insertion(float a, Elem* head, int index) { // ������� �������� � ������ �� ��������� �����
    Elem* elem = new Elem;
    elem->data = a;
    Elem* ptr = head;
    for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
    }
    elem->next = ptr->next;
    ptr->next = elem;
} // Insertion

void Delete(Elem*& head, int index) { // �������� �������� �� �������
    Elem* ptr = head;
    for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
    } // for i
    if (ptr != head)
    {
        Elem* ptr2 = ptr->next;
        ptr->next = ptr->next->next;
        delete ptr2;
    } // if
    else {
        head = ptr->next;
        delete ptr;
    } // else
} // Delete

void delList(Elem*& head) // �������� ����� ������
{
    Elem* ptr;
    while (head) // ��������, ������������ � "������"
    {
        ptr = head->next;
        delete head;
        head = ptr;
    } // while
    head = NULL;
} // delList


 // �����������
void makeRDL(float a, RingElem*& end, RingElem*& head) //  ���������� ������ ��������
{
    RingElem* ptr = new RingElem;
    ptr->data = a;
    if (!head) head = ptr;
    else
    {
        end->next = ptr;
        ptr->prev = end;
    }
    end = ptr;
    end->next = head;
    head->prev = end;
}
void DeleteRDL(RingElem*& head, RingElem*& end, int index) // �������� �������� �� ��� ������� 
{ // TODO: �������� �������
    int counter = 0;
    RingElem* ptr = head;
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
            cout << "Test: " << ptr->next->prev->data << " " << ptr->prev->next->data << endl;
            delete ptr;
            return;
        } // if
        counter++;
        ptr = ptr->next;
    } // while
} // DeleteRDL

void printRDL(RingElem* head)  // ������ ����� ������
{
    RingElem* ptr = head;
    if (ptr) cout << ptr->data;
    else
    {
        cout << "������ ����!" << endl;
        return;
    } // else
    ptr = ptr->next;
    while (ptr != head)
    {
        cout << " " << ptr->data;
        ptr = ptr->next;
    } // while
}

void printRDLBack(RingElem* end)  // ������ ����� ������ � �������� �������
{
    RingElem* ptr = end;
    if (ptr) cout << ptr->data;
    else
    {
        cout << "������ ����!" << endl;
        return;
    } // else
    ptr = ptr->prev;
    while (ptr != end)
    {
        cout << " " << ptr->data;
        ptr = ptr->prev;
    } // while
}

void delListRDL(RingElem*& head, RingElem*& end) // �������� ������
{
    RingElem* ptr = head;
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

RingElem* findElemRDL(float a, RingElem* head) // ����� ������� � ������
{
    RingElem* ptr = head;
    if (a == ptr->data) return ptr; // ���� ������ - �������
    ptr = ptr->next;
    while (ptr != head)
    {
        if (a == ptr->data) return ptr;
        ptr = ptr->next;
    } // while
    cout << "������� " << a << " �� ������" << endl;
    return nullptr;
}
//int count_sizeRDL(RingElem* head)
//{
//
//}