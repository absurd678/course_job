// course_job.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "lists.cpp"
using namespace std;



/*********************************************************************
 *              П Р О Т О Т И П Ы    Ф У Н К Ц И Й                   *
 *********************************************************************/





float A[] = { 0, 1, 2, 6 };
int main()
{
    setlocale(LC_ALL, "Russian");

    RingElem* headRE = NULL;
    RingElem* endRE = NULL;
    for (int i = 0; i < 4; i++)
    {
        makeRDL(A[i], endRE, headRE);
    }
    printRDL(headRE); cout << endl;

    DeleteRDL(headRE, endRE, 0);
    printRDL(headRE); cout << endl;

    printRDLBack(endRE); cout << endl;
    findElemRDL(1, headRE);
    delListRDL(headRE, endRE);
    printRDLBack(endRE); cout << endl;
}


