#include <iostream>
#include <string>
#include "lists.h"
using namespace std;

/***********************************************************************
 *                � � � � � � � � � �    � � � � � � �                 *
 ***********************************************************************/

// ������� ���������� ������������ ��� �����
int makeBus(int id, int id_bus, string name, Bus*& end, Bus*& head) //  ���������� ������ ��������
{
    if (find_id_bus(name, head)) return 6;
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
    return 0;
} // makeBus

int max_bus_id(Bus* head) // ����� ���� id
{
    Bus* ptr = head;
    int max_id = 0;
    do {
        if (max_id < ptr->id_bus) max_id = ptr->id_bus;
        ptr = ptr->next;
    } while (ptr != head);
    return max_id;
}

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

void printBus(Bus* head, Station* s_head)  // ������ ����� ������
{
    Bus* ptr = head;
    if (ptr) cout <<" "<<findElemStation(ptr->id, s_head)->name << " " << ptr->name << endl;
    else
    {
        cout << "������ ����!" << endl;
        return;
    } // else
    ptr = ptr->next;
    while (ptr != head)
    {
        cout << " " << findElemStation(ptr->id, s_head)->name << " " << ptr->name << endl;
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
    if (!ptr) return NULL; // ���� ������ ���� - �������

    do // ����� �� ���� id
    {
        if (ptr->id_bus == id) return ptr;
        ptr = ptr->next;
    } while (ptr != head);
    return NULL;
} // findElemStation

int find_id_bus(string name, Bus* head) // ����� id �� ��������
{
    Bus* ptr = head;
    if (!ptr) return -1; // ���� ������ ���� - �������

    do // ����� �� ���� id
    {
        if (ptr->name == name) return ptr->id_bus;
        ptr = ptr->next;
    } while (ptr != head);
    return -1;
}

Bus* move_in_buses(Bus* curr_pos, int step) // ����������� � ������ � �������� ������������
{
    if (step >= 0) // ������
    {
        for (int counter = 0; counter < step; counter++)
            curr_pos = curr_pos->next;
    }
    else // ��� ������������� => �����!
    {
        for (int counter = 0; counter < step * (-1); counter++)
            curr_pos = curr_pos->prev;
    } 
    return curr_pos;
}


//Bus* findElemBus(float a, Bus* head); // ����� ������� � ������

// ������� ������������ ������ ��� ��������
int makeStation(int id, string name, Station*& end, Station*& head) //  ���������� ������ ��������
{
    if (find_id_station(name, head)) return 6; // ������ �������
    else if (findElemStation(id, head)->id == id) return 3; // ������ id
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
    return 0;
}

int max_station_id(Station* head) // ����� ���� id
{
    Station* ptr = head;
    int max_id = 0;
    do {
        if (max_id < ptr->id) max_id = ptr->id;
        ptr = ptr->next;
    } while (ptr != head);
    return max_id;
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
    if (ptr) cout << ptr->name << endl;
    else
    {
        cout << "������ ����!" << endl;
        return;
    } // else
    ptr = ptr->next;
    while (ptr != head)
    {
        cout <<" " << ptr->name << endl;
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

int find_id_station(string name, Station* head)
{
    Station* ptr = head;
    do // ����� �� ���� id
    {
        if (ptr->name == name) return ptr->id;
        ptr = ptr->next;
    } while (ptr != head);
    return NULL;
} // find_id_station

Station* move_in_stations(Station* curr_pos, int step) // ����������� � ������ � �������� ������������
{
    if(step>=0) // ������
    { 
        for (int counter = 0; counter < step; counter++) 
            curr_pos = curr_pos->next;
    }
    else // ��� ������������� => �����!
        for (int counter = 0; counter < step*(-1); counter++) 
            curr_pos = curr_pos->prev;
    return curr_pos;
}

// ������� ��������� ��������
int make_driver(int id, string name, Driver*& end, Driver*& head) //  ���������� ������ ��������
{
    if (find_driver(id, head)) return 3;
    else if (find_id_driver(name, head)) return 6;
    Driver* ptr = new Driver; // ����� �������
    if (!head) head = ptr; // ���� ��� ������ �������
    else { end->next = ptr; } // � ����� ��������� �����������

    // ���������� ������ �����
    ptr->id = id;
    ptr->name = name;

    end = ptr; // ������ ���� ������� ���������
    ptr->next = NULL; // ��������� ��������� ������ ���
} // make

int max_driver_id(Driver* head) // ����� ���� id
{
    Driver* ptr = head;
    int max_id = 0;
    while(ptr)
    {
        if (max_id < ptr->id) max_id = ptr->id;
        ptr = ptr->next;
    } 
    return max_id;
}

void print_drivers(Driver* head)  // ������ ����� ������
{
    Driver* ptr = head;
    if (!ptr) cout << "������ ����" << endl;
    while (ptr)
    {
        cout << " " << ptr->name << endl;  // ���������� �������
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

int find_id_driver(string name, Driver* head) // ����� id �� ��������
{
    Driver* ptr = head;
    while (ptr)
    {
        if (ptr->name == name) return ptr->id;
        ptr = ptr->next;
    }
    return NULL;
}

void delete_driver(Driver*& head, Driver*& end, int id) { // �������� �������� �� id
    Driver* ptr = head;

    if (ptr->id == id) // �������� ������
    {
        head = ptr->next;
        delete ptr;
        return;
    } // if
    while(ptr->next->id != id) ptr = ptr->next; // ���� ��������������� ���������� ��������

    Driver* ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    if (ptr2 == end) end = ptr;
    delete ptr2;
} // delete_driver

void del_drivers(Driver*& head) // �������� ����� ������
{
    Driver* ptr;
    while (head) // ��������, ������������ � "������"
    {
        ptr = head->next;
        delete head;
        head = ptr;
    } // while
    head = NULL;
} // delList

// ������� ��������� �����
int make_route(Route* ptr, Route*& end, Route*& head) //  ���������� ������ ��������
{
    if (find_route_number(ptr->route_number, head)) return 5;
    if (!head) head = ptr; // ���� ��� ������ �������
    else { end->next = ptr; } // � ����� ��������� �����������

    end = ptr; // ������ ���� ������� ���������
    ptr->next = NULL; // ��������� ��������� ������ ���
} // make

// ����� �� ������ �����

Route* find_route_stationID(int id_station, Route* head) // ����� ������� � ������ �� ���� id �������
{
    Route* ptr = head;
    while (ptr)
    {
        if (ptr->id_station == id_station) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Route* find_route_busID(int id_bus, Route* head) // ����� ������� � ������ �� ���� id ��������
{
    Route* ptr = head;
    if (id_bus == -1) return NULL;
    while (ptr)
    {
        if (ptr->id_bus == id_bus) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Route* find_route_driverID(int id_driver, Route* head) // ����� ������� � ������ �� ���� id ��������
{
    Route* ptr = head;
    while (ptr)
    {
        if (ptr->id_driver == id_driver) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Route* find_route_number(int route_number, Route* head) // ����� ������� �� ������ ��������
{
    Route* ptr = head;
    while (ptr)
    {
        if (ptr->route_number == route_number) return ptr;
        ptr = ptr->next;
    }
    return NULL;
} // find_route_number

Route* find_route_time_dep(string time_dep, Route* head) // �� �������
{
    Route* ptr = head;
    while (ptr)
    {
        if (ptr->time == time_dep) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Route* find_route_tickets(int tickets, Route* head) // �� �������
{
    Route* ptr = head;
    while (ptr)
    {
        if (ptr->tickets == tickets) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Route* find_route_pass(int passengers, Route* head) // �� ����������
{
    Route* ptr = head;
    while (ptr)
    {
        if (ptr->passengers == passengers) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Route* find_route_end(string end_route, Route* head) // �� ������
{
    Route* ptr = head;
    while (ptr)
    {
        if (ptr->end_route == end_route) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

// ������
void print_routes(Route* head, Station* s_head, Driver* d_head)  // ������ ����� ������
{
    Route* ptr = head;
    Station* s_ptr; // ������ �� ��������
    if (!ptr) cout << "������ ����" << endl;
    while (ptr)
    {
        s_ptr = findElemStation(ptr->id_station, s_head);
        cout << "\t" << s_ptr->name << " " << findElemBus(ptr->id_bus, s_ptr->busHead)->name << " " 
            << find_driver(ptr->id_driver, d_head)->name << " " << ptr->route_number << " " << ptr->time << " "
            << ptr->tickets << " " << ptr->passengers << " " << ptr->end_route << endl;  // ���������� �������
        ptr = ptr->next; // ������� � ����������
    }
    cout << endl;
} // print

// ��������
void delete_route(Route*& head, Route*& end, int route_number) { // �������� �������� �� ������ ��������
    Route* ptr = head;

    if (ptr->route_number == route_number) // �������� ������
    {
        head = ptr->next;
        delete ptr;
        return;
    } // if
    while (ptr->next->route_number != route_number) ptr = ptr->next; // ���� ��������������� ���������� ��������

    Route* ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    if (ptr2 == end) end = ptr;
    delete ptr2;
} // Delete

void del_routes(Route*& head) // �������� ����� ������
{
    Route* ptr;
    while (head) // ��������, ������������ � "������"
    {
        ptr = head->next;
        delete head;
        head = ptr;
    } // while
    head = NULL;
} // delList

void print_stations_in_route(Route* r_head, Station* s_head)
{
    Station* s_ptr = s_head;
    cout << "��� ������� � ������� (�������� ������): " << endl;
    do
    {
        if (find_route_stationID(s_ptr->id, r_head))
            cout << s_ptr->id << " " << s_ptr->name << endl;
        s_ptr = s_ptr->next;
    } while (s_ptr != s_head);
}

void print_buses_in_route(Route* r_head, Station* s_head)
{
    Route* r_ptr = r_head;
    Station* temp;
    cout << "��� ������� � �������� � ������� (�������� ������): " << endl;
    while (r_ptr)
    {
        temp = findElemStation(r_ptr->id_station, s_head);
        cout << r_ptr->id_station << " (" << temp->name << ") "
            << r_ptr->id_bus << " (" << findElemBus(r_ptr->id_bus, temp->busHead)->name << ")" << endl;
        r_ptr = r_ptr->next;
    }
}

void print_drivers_in_route(Route* r_head, Driver* d_head)
{
    Driver* d_ptr = d_head;
    cout << "��� �������� � ������� (�������� ������): " << endl;
    while (d_ptr)
    {
        if (find_route_driverID(d_ptr->id, r_head))
            cout << d_ptr->id << " " << d_ptr->name << endl;
        d_ptr = d_ptr->next;
    }
}