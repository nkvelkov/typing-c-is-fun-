#include <iostream>
#include "Cell.h"
#include "Cell.cpp"
#include "Field.h"
#include "Field.cpp"

using namespace std;

int main()
{
    cout << "Console MineSweeper ... " <<endl;
    /*излищни неща...
    Cell c(3), b(1);

    Field m;

    cout << m.cells[0][0].getStatus();

    m.flagCell(4,5);
    //c.open();
    int n;

    cin >> n;

    int* a = new int(1);

    int* arr = new int[3];

    int** arr1 = new int*[n];

    for(int i=0; i<n; ++i)
    {
        arr1[i] = new int[n];
    }

    Cell** cells = new Cell*[n];

    for(int i=0; i<n; ++i)
    {
        cells[i] = new Cell[n];
    }

    //destruct!

    delete [] a;

    delete [] arr;

    for(int i=0; i<n; ++i)
    {
        delete arr1[i];
    }

    delete [] arr1;
    cells[0][0].flag();
    cout << cells[0][0].getStatus() << endl;



    for(int i=0; i<n; ++i)
    {
        delete cells[i];
    }

    delete [] cells;


    cout << boolalpha << areStatusesEqual(c.getStatus(), b.getStatus() ) << endl;
    cout << c.getStatus() << endl;

    c.open();

    cout << c.getStatus() <<endl;*/
    return 0;
}
