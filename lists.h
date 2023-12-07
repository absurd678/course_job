#pragma once
// С Т Р У К Т У Р Ы
struct Elem { // Линейный
    float data;
    Elem* next;
}; 

struct RingElem // Двунаправленный кольцевой
{
    RingElem* prev;
    float data;
    RingElem* next;
};
// Функции линейного
void make(float a, Elem*& end, Elem*& head); //  Добавление нового элемента
void print(Elem* head);  // Печать всего списка
void delList(Elem*& head); // Удаление списка
Elem* findElem(float a, Elem* head); // Найти элемент в списке
//int findMax(List* head); // Поиск максимального элемента с возвратом его номера
//void Insertion(float a, List* head, int index); // добавлений элемента
//void Delete(List*& head, int index); // Удаление элемента по его индексу
//int count_size(List* head); // Посчитать длину списка

// Функции кольцевого двухсвязного
//int createRDL(List*& head, List*& end, const char* fileName); // Создание списка
void makeRDL(float a, RingElem*& end, RingElem*& head); //  Добавление нового элемента
void DeleteRDL(RingElem*& head, RingElem*& end, int index); // Удаление элемента по его индексу
void printRDL(RingElem* head);  // Печать всего списка
void printRDLBack(RingElem* end); // В обратную сторону
void delListRDL(RingElem*& head, RingElem*& end); // Удаление списка
RingElem* findElemRDL(float a, RingElem* head); // Найти элемент в списке
//int count_sizeRDL(RingElem* head); // Посчитать длину списка