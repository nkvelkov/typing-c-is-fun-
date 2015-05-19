#include <iostream>
#include "Field.h"
//#include "Cell.h"
//#include "Cell.cpp"

Field::Field(int width, int height)
{
    this->width = width;

    this->height = height;

    makeNew();
}

void Field::deleteField()
{
    for(int i=0; i<height; ++i)
    {
        delete cells[i]; // trqbva li da e delete [width] cells[i]~~~ ??? ~~~
    }

    delete [] cells;
}

void Field::makeNew()
{
    cells = new Cell*[height];

    for(int i=0; i<height; ++i)
    {
        cells[i] = new Cell[width];
    }
}

void Field::copyField(const Field& other)
{

    width = other.width;

    height = other.height;

    makeNew();

    for(int i=0; i<height; ++i)
    {
        for(int j=0; j<width; ++j)
        {
            cells[i][j] = other.cells[i][j];
        }
    }
}

Field::Field(const Field& other)
{
    copyField(other);

}

Field& Field::operator = (const Field& other)
{
    if(this != &other)
    {
        deleteField();

        copyField(other);
    }

    return *this;
}

Field::~Field()
{
    deleteField();
}

void Field::openCell(int x, int y)
{
    cells[x][y].open();

    if(x >= height || y >= width || y < 0 || x < 0)
        return;

    if(cells[x+1][y+1].getValue() == -1||
       cells[x-1][y-1].getValue() == -1||
       cells[x+1][y-1].getValue() == -1||
       cells[x-1][y+1].getValue() == -1||
       cells[x][y+1].getValue() == -1||
       cells[x][y-1].getValue() == -1||
       cells[x+1][y].getValue() == -1||
       cells[x-1][y].getValue() == -1)
        return;

    openCell(x+1, y+1);
    openCell(x+1, y-1);

    openCell(x-1, y+1);
    openCell(x-1, y-1);

    openCell(x, y+1);
    openCell(x, y-1);

    openCell(x+1, y);
    openCell(x-1, y);
}
/* тази функция я направих и булева, защото не знам как точно ще се реализира играта
и предполагам, че за някои реализации трябва да е булева
bool Field::openCell(int x, int y)
{
    cells[x][y].open();

    if(x >= height || y >= width || y < 0 || x < 0)
        return true;

    if(cells[x][y].getValue() == -1)
        return false;

    if(cells[x+1][y+1].getValue() == -1||
       cells[x-1][y-1].getValue() == -1||
       cells[x+1][y-1].getValue() == -1||
       cells[x-1][y+1].getValue() == -1||
       cells[x][y+1].getValue() == -1||
       cells[x][y-1].getValue() == -1||
       cells[x+1][y].getValue() == -1||
       cells[x-1][y].getValue() == -1)
        return true;


    openCell(x+1, y+1);
    openCell(x+1, y-1);

    openCell(x-1, y+1);
    openCell(x-1, y-1);

    openCell(x, y+1);
    openCell(x, y-1);

    openCell(x+1, y);
    openCell(x-1, y);

    return true;
}*/


void Field::flagCell(int x, int y)
{
    cells[x][y].flag();
}

void Field::unflagCell(int x, int y)
{
    cells[x][y].unflag();
}

// help function used in the next one
bool areStatusesEqual(CELL_STATUS b, CELL_STATUS a)
{
    return (int)a == (int)b;
}

bool Field::isSolved()const
{
    bool b = true;

    for(int i=0; i<height && b; ++i)
    {
        for(int j=0; j<width && b; ++j)
        {
            if(cells[i][j].getValue() == -1)
            {
                //if((int)cells[i][j].getStatus() != || (int)cells[i][j].getStatus != 2)
                if(areStatusesEqual(cells[i][j].getStatus(), CLOSED) || areStatusesEqual(cells[i][j].getStatus(),FLAGGED) )
                {
                    b = false;
                }
            }else{
                if(cells[i][j].getStatus() != OPEN)
                {
                    b = false;
                }
            }
        }
    }

    return b;
}
