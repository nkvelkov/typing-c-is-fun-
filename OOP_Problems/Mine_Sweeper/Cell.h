#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

enum CELL_STATUS{OPEN, CLOSED, FLAGGED};

class Cell
{
private:

    int value;

    CELL_STATUS status;

public:

    Cell(int =0);

    CELL_STATUS getStatus()const;

    void open();

    void flag();

    void unflag();

    int getValue()const;
};

#endif // CELL_H_INCLUDED
