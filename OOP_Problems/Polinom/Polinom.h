#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

#include <iostream>
using namespace std;

class Polinom
{
    friend ostream& operator<< (ostream&, const Polinom&);
    friend Polinom& operator*= (int, Polinom&);
    friend Polinom operator* (int, const Polinom&);
    public:

        Polinom();
        Polinom(int);
        Polinom(const int* arr, int n);
        Polinom(const Polinom&);
        Polinom& operator= (const Polinom&);
        ~Polinom();

        const int* getArr()const;
        int getN()const;

        const Polinom operator+ (const Polinom&)const;
        Polinom& operator+= (const Polinom&);
        const Polinom operator- (const Polinom&)const;
        Polinom& operator-= (const Polinom&);

        const Polinom operator* (int)const;
        Polinom& operator *= (int);

        const Polinom operator * (const Polinom&)const;
        Polinom& operator *= (const Polinom&);

        Polinom operator-- (int);
        Polinom& operator-- ();

        Polinom operator++ (int);
        Polinom& operator++ ();

        int operator() (int)const;
        int operator[] (int)const;

    private:
        void copyArr(const int*);
        void copyPolinom(const Polinom&);
        void deletePolinom();

        void setPolinom(const int*, int);
        void setArr(const int*);
        void setN(int);

        bool getSizes(int&, int&, const Polinom&)const;

        void differentiate();
        void integrate();
        void extend();

        int* arr;
        int n;
};

#endif // POLINOM_H_INCLUDED
