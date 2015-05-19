#include <iostream>
#include "Cell.h"

Cell::Cell(int value)
{
    this->value = value;

    status = CLOSED;
}

CELL_STATUS Cell::getStatus()const
{
    return this->status;
}


void Cell::open()
{
    if(this->getStatus() == CLOSED)
        status = OPEN;
}

void Cell::flag()
{
    if(getStatus() == CLOSED)
        status = FLAGGED;
}

void Cell::unflag()
{
    if(getStatus() == FLAGGED)
        status = CLOSED;
}

int Cell::getValue()const
{
    return value;
}
