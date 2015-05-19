#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED


class Field
{
private:

    int width;

    int height;

    Cell** cells;

    void deleteField();

    void copyField(const Field&);

    void makeNew();

public:

    Field(int =0, int =0);

    Field(const Field&);

    Field& operator = (const Field&);

    ~Field();

    void openCell(int, int);

    void flagCell(int, int);

    void unflagCell(int, int);

    bool isSolved()const;


};

#endif // FIELD_H_INCLUDED
