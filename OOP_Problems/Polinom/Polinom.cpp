#include <iostream>
#include "Polinom.h"

Polinom:: Polinom() : arr(NULL)
{
    arr = new int[1];
    setN(1);
    arr[0] = -2;
}

Polinom:: Polinom(int n) : arr(NULL)
{
    setN(n+1);
    arr = new int[this->n];
}

Polinom:: Polinom(const int* arr, int n) : arr(NULL)
{
    setPolinom(arr, n+1);
}

Polinom:: Polinom(const Polinom& other) : arr(NULL)
{
    copyPolinom(other);
}

Polinom& Polinom:: operator= (const Polinom& other)
{
    if(this != &other)
    {
        deletePolinom();
        copyPolinom(other);
    }
    return *this;
}

Polinom:: ~Polinom()
{
    deletePolinom();
}

void Polinom:: copyPolinom(const Polinom& other)
{
    setPolinom(other.arr, other.n);
}

void Polinom:: setPolinom(const int* arr, int n)
{
    setN(n);
    setArr(arr);
}

void Polinom:: deletePolinom()
{
    delete [] arr;
}

void Polinom:: setN(int n)
{
    this->n = n;
}

void Polinom:: setArr(const int* arr)
{
    this-> arr = new int[n];

    copyArr(arr);
}

void Polinom:: copyArr(const int* arr)
{
    for(int i=0; i<n; ++i)
    {
        this->arr[i] = arr[i];
    }
}

int Polinom:: getN()const
{
    return this->n;
}

const int* Polinom:: getArr()const
{
    return arr;
}

ostream& operator << (ostream& out, const Polinom& polinom)
{
    for(int i=polinom.n-1; i>=1; --i)
    {
        if(polinom.arr[i] != 0)
        {
            out << polinom.arr[i] << ".x^"<< i;

            if(polinom.arr[i-1] > 0)
                out << " +";
            else if(polinom.arr[i-1] < 0)
                out << " ";

        }else{
            if(polinom.arr[i-1] != 0)
            {
                if(polinom.arr[i-1] > 0)
                    out << " +";
                else if(polinom.arr[i-1] < 0)
                    out << " ";
            }
        }
    }
    if(polinom.arr[0] != 0)
        out << polinom.arr[0];
    return out;
}

int Polinom:: operator() (int x)const
{
    int s = 0;
    s += arr[0];
    for(int i=1; i<n; ++i)
    {
        s += arr[i]* x;
        x *= x;
    }
    return s;
}

int Polinom:: operator[] (int index)const
{
    return arr[index];
}

const Polinom Polinom:: operator+ (const Polinom& right)const
{
    int minn, maxn;
    bool b = getSizes(minn, maxn, right);

    Polinom p(maxn);

    for(int i=0; i<minn; ++i)
    {
        p.arr[i] = this->arr[i] + right.arr[i];
    }

    for(int i=minn; i<maxn; ++i)
    {
        if(b)
            p.arr[i] = this->arr[i];
        else
            p.arr[i] = right.arr[i];
    }

    return p;
}

Polinom& Polinom:: operator+= (const Polinom& right)
{
    *this = *this + right;
    return *this;
}

bool Polinom:: getSizes(int& minn, int& maxn, const Polinom& right)const
{
    bool b;
    if(this->n < right.n)
    {
        minn = this->n;
        maxn = right.n;
        b = false;
    }else{
        maxn = this->n;
        minn = right.n;
        b = true;
    }

    return b;
}
const Polinom Polinom:: operator- (const Polinom& right)const
{
    int minn, maxn;
    bool b = getSizes(minn, maxn, right);

    Polinom p(maxn);

    for(int i=0; i<minn; ++i)
    {
        p.arr[i] = this->arr[i] - right.arr[i];
    }

    for(int i=minn; i<maxn; ++i)
    {
        if(b)
            p.arr[i] = this->arr[i];
        else
            p.arr[i] = right.arr[i];
    }

    return p;
}

Polinom& Polinom:: operator -= (const Polinom& right)
{
    *this = *this - right;
    return *this;
}

const Polinom Polinom:: operator * (int number)const
{
    Polinom p(*this);

    for(int i=0; i<p.n; ++i)
    {
        p.arr[i] *= number;
    }

    return p;
}

Polinom& Polinom:: operator *= (int number)
{
    *this = (*this) * number;

    return *this;
}

Polinom& operator *= (int number, Polinom& right)
{
    return right *= number;
}

Polinom operator * (int number, const Polinom& right)
{
    return right * number;
}

const Polinom Polinom:: operator * (const Polinom& right)const
{
    int length = this->n + right.n;

    Polinom p(length-1);

    for(int i=0; i<length; ++i)
    {
        p.arr[i] = 0;
    }

    for(int i=0; i<this->n; ++i)
    {
        for(int j=0; j<right.n; ++j)
        {
            p.arr[i+j] += this->arr[i] * right.arr[j];
        }
    }

    return p;
}

Polinom& Polinom:: operator *= (const Polinom& right)
{
    (*this) = (*this) * right;
    return (*this);
}

Polinom Polinom:: operator-- (int)
{
    Polinom temp = *this;

    differentiate();

    return temp;
}

Polinom& Polinom:: operator-- ()
{
    differentiate();

    return *this;
}

void Polinom:: differentiate()
{
    for(int i=1; i<n; ++i)
    {
        this->arr[i-1] = this->arr[i] * i;
    }
    this->n--;
}

Polinom Polinom:: operator++ (int)
{
    Polinom temp;

    extend();

    integrate();

    return temp;
}

Polinom& Polinom:: operator++ ()
{
    extend();

    integrate();

    return *this;
}

void Polinom:: integrate()
{

    for(int i=n-1; i>=1; --i)
    {
        this->arr[i] = this->arr[i-1] * (1.0/i);
    }
    this->arr[0] = 1; // ili druga stoinost, tova e konstantata ot integriraneto
}

void Polinom:: extend ()
{
    int* narr = new int[this->n+1];

    for(int i=0; i<n; ++i)
    {
        narr[i] = this->arr[i];
    }

    this->n++;

    delete [] arr;

    arr = narr;
}
