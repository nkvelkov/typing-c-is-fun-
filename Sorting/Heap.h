#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

template <typename T>
class Heap
{
public:

    Heap();
    Heap(int);
    Heap(const Heap&);
    Heap& operator = (const Heap&);
    ~Heap();

    bool isEmpty()const;
    int peek(T&)const;

    int insert(const T&);
    bool pop(T&, int&);


private:

    int leftChild(int x);
    int rightChild(int x);
    int parent(int x);
    int swapElems(int, int);
    bool exist(int x);

    void extend();
    void shrink();
    void copyHeap(const Heap&);
    void deleteHeap();

    int sink(int);
    int bubble(int);

    T* arr;
    int n;
    int capacity;

};

template <typename T>
Heap<T>:: Heap()
{
    this->n = 0;
    this->capacity = 1;
    this->arr = new T[1];
}

template <typename T>
Heap<T>:: Heap(int n)
{
    this->n = 0;
    this->capacity = n;
    this->arr = new T[n];
}

template <typename T>
Heap<T>:: Heap(const Heap& heap)
{
    copyHeap(heap);
}

template <typename T>
Heap<T>& Heap<T>:: operator = (const Heap<T>& heap)
{
    if(this != &heap)
    {
        deleteHeap();
        copyHeap(heap);
    }

    return *this;
}

template <typename T>
Heap<T>:: ~Heap()
{
    deleteHeap();
}
template <typename T>
void Heap<T>:: deleteHeap()
{
    delete [] arr;
}

template <typename T>
void Heap<T>:: copyHeap(const Heap& heap)
{
    this->n = heap.n;
    this->capacity = heap.capacity;
    this->arr = new T[heap.capacity];

    for(int i=0; i<n; ++i)
    {
        this->arr[i] = heap.arr[i];
    }
}

template <typename T>
int Heap<T>:: leftChild(int x)
{
    return x*2 + 1;
}

template <typename T>
int Heap<T>:: rightChild(int x)
{
    return x*2 + 2;
}

template <typename T>
int Heap<T>:: parent(int x)
{
    return (x-1)/2;
}

template <typename T>
bool Heap<T>:: isEmpty()const
{
    return n == 0;
}
void printArr2(const int* arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        cout << arr[i] << " ";
    }cout << endl;
}
template <typename T>
int Heap<T>:: insert(const T& elem)
{
    if(n >= capacity)
    {
        capacity *= 2;
        extend();
    }
    arr[n++] = elem;

    bubble(n-1);
}

template <typename T>
int Heap<T>:: bubble(int x)
{
    int ctr = 0;
    while(x != 0)
    {
        int p = parent(x);

        if(arr[p] > arr[x])
        {
            ctr += swapElems(p, x);
            x = p;
        }else
        {
            x = 0;
        }
    }
    return ctr;
}

template <typename T>
bool Heap<T>:: pop(T& elem, int& numOperations)
{
    if(isEmpty()) return false;

    elem = arr[0];
    swapElems(0, n-1);
    --n;

    numOperations = sink( 0 );

    if(capacity > 10*n)
    {
        shrink();
    }
    return true;
}

template <typename T>
int Heap<T>:: sink(int x)
{
    int ctr = 0;

    while(x < n)
    {
        int l = leftChild(x), r = rightChild(x);

        if(exist(l) && exist(r) && arr[x] > arr[l] && arr[x] > arr[r])
        {
            if(arr[l] < arr[r])
            {
                swapElems(x, l);
                x = l;
            }else
            {
                swapElems(x, r);
                x = r;
            }
            ++ctr;
        }else if(exist(r) && arr[x] > arr[r])
        {
            swapElems(x, r);
            x = r;
            ++ctr;
        }else if(exist(l) && arr[x] > arr[l])
        {
            swapElems(l, x);
            x = l;
            ++ctr;
        }else
        {
            break;
            //x = n;
        }
    }
    return ctr;
}
template <typename T>
int Heap<T>:: swapElems(int ind1, int ind2)
{
    T temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;

    return 1;
}

template <typename T>
int Heap<T>:: peek(T& elem)const
{
    int index = 0;
    elem = arr[index];

    return index;
}

template <typename T>
bool Heap<T>:: exist(int x)
{
    return x < n;
}

template <typename T>
void Heap<T>:: shrink()
{
    this->capacity = capacity / 2;
    T * narr = new T[capacity];
    for(int i=0; i<n; ++i)
    {
        narr[i] = arr[i];
    }

    delete [] arr;

    arr = narr;
}

template <typename T>
void Heap<T>:: extend()
{
    T* narr = new T[capacity];

    for(int i=0; i<n; ++i)
    {
        narr[i] = arr[i];
    }

    delete [] arr;

    this->arr = narr;
}
#endif // HEAP_H_INCLUDED
