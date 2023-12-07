#include <iostream>
#include "lists.h"
using namespace std;

/***********************************************************************
 *                Р Е А Л И З А Ц И Я    Ф У Н К Ц И Й                 *
 ***********************************************************************/

void make(float a, Elem*& end, Elem*& head) //  Добавление нового элемента
{
    if (!findElem(a, head)) // Если a в списке еще не было
    {
        Elem* ptr = new Elem; // Новый элемент
        if (!head) head = ptr; // Если это первый элемент
        else { end->next = ptr; } // У конца появилось продолжение
        ptr->data = a;
        end = ptr; // Делаем этот элемент последним
        ptr->next = NULL; // Следующих элементов списка нет
    } // if
    else cout << "Элемент a = " << a << " уже содержится в списке!" << endl;
} // make

Elem* findElem(float a, Elem* head) // Найти элемент в списке
{
    Elem* ptr = head;
    while (ptr)
    {
        if (ptr->data == a) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
} // findElem

void print(Elem* head)  // Печать всего списка
{
    Elem* ptr = head;
    if (!ptr) cout << "Список пуст";
    while (ptr)
    {
        cout << "\t" << ptr->data;  // Считывание данного
        ptr = ptr->next; // Переход к следующему
    }
    cout << endl;
} // print

int count_size(Elem* head) // Посчитать размер списка
{
    int counter = 0;
    while (head)
    {
        counter++;
        head = head->next;
    } // while
    return counter;
} // counter_size

int findMax(Elem* head) // Поиск максимального
{
    Elem* ptr = head;
    int counter = -1; // Индекс
    float maxFound = -pow(10, 38); // Очень маленькое значение
    while (ptr)
    {
        if (ptr->data > maxFound)
        {
            maxFound = ptr->data;
            counter++;
        } // if
        ptr = ptr->next; // Переход дальше
    } // while
    cout << "Наибольшее значение = " << maxFound << endl;
    return counter;
} // findMax

void Insertion(float a, Elem* head, int index) { // Вставка элемента в список на указанное место
    Elem* elem = new Elem;
    elem->data = a;
    Elem* ptr = head;
    for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
    }
    elem->next = ptr->next;
    ptr->next = elem;
} // Insertion

void Delete(Elem*& head, int index) { // Удаление элемента по индексу
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

void delList(Elem*& head) // Удаление всего списка
{
    Elem* ptr;
    while (head) // Удаление, начинающееся с "головы"
    {
        ptr = head->next;
        delete head;
        head = ptr;
    } // while
    head = NULL;
} // delList


 // ДВУХСВЯЗНЫЙ
void makeRDL(float a, RingElem*& end, RingElem*& head) //  Добавление нового элемента
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
void DeleteRDL(RingElem*& head, RingElem*& end, int index) // Удаление элемента по его индексу 
{ // TODO: проверка индекса
    int counter = 0;
    RingElem* ptr = head;
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
            cout << "Test: " << ptr->next->prev->data << " " << ptr->prev->next->data << endl;
            delete ptr;
            return;
        } // if
        counter++;
        ptr = ptr->next;
    } // while
} // DeleteRDL

void printRDL(RingElem* head)  // Печать всего списка
{
    RingElem* ptr = head;
    if (ptr) cout << ptr->data;
    else
    {
        cout << "Список пуст!" << endl;
        return;
    } // else
    ptr = ptr->next;
    while (ptr != head)
    {
        cout << " " << ptr->data;
        ptr = ptr->next;
    } // while
}

void printRDLBack(RingElem* end)  // Печать всего списка в обратном порядке
{
    RingElem* ptr = end;
    if (ptr) cout << ptr->data;
    else
    {
        cout << "Список пуст!" << endl;
        return;
    } // else
    ptr = ptr->prev;
    while (ptr != end)
    {
        cout << " " << ptr->data;
        ptr = ptr->prev;
    } // while
}

void delListRDL(RingElem*& head, RingElem*& end) // Удаление списка
{
    RingElem* ptr = head;
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

RingElem* findElemRDL(float a, RingElem* head) // Найти элемент в списке
{
    RingElem* ptr = head;
    if (a == ptr->data) return ptr; // Если голова - искомое
    ptr = ptr->next;
    while (ptr != head)
    {
        if (a == ptr->data) return ptr;
        ptr = ptr->next;
    } // while
    cout << "Элемент " << a << " не найден" << endl;
    return nullptr;
}
//int count_sizeRDL(RingElem* head)
//{
//
//}