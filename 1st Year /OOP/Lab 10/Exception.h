#include <iostream>
#include <exception>

using namespace std;

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

class IndexOutOfRange : public exception //
{
public:
    const char* what() const throw() //
    {
        return "Index out of range";
    }
};

class Inexistent : public exception
{
public:
    const char* what() const throw()
    {
        return "Element inexistent";
    }
};

template<class T>
class ArrayIterator
{
private:
    int Current;
    T* Element;
    int Size;
public:
    ArrayIterator()
    {
        Current = 0;
        Element = nullptr;
        Size = 0;
    }
    ArrayIterator& operator ++ ()
    {
        if (Current < Size)
        {
            Current++;
            Element++;
        }
        return *this;
    }
    ArrayIterator& operator -- ()
    {
        if (Current > 0)
        {
            Current--;
            Element--;
        }
        return *this;
    }
    bool operator= (ArrayIterator<T> &)
    {
        if (this->Element == Element)
            return true;
        return false;
    }
    /*pentru atribuire:
    ArrayIterator& operator= (ArrayIterator<T> &it)
    {
        this->Current = it.Current;
        this->Element = it.Element;
        this->Size = it.Size;
        return *this;
    }*/
    bool operator!=(ArrayIterator<T> &)
    {
        if (this->Element != Element)
            return true;
        return false;
    }
    T* GetElement()
    {
        return Element;
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array()
    {
        List = nullptr;
        Capacity = 0;
        Size = 0;
    }
    ~Array()
    {
        if (List != nullptr)
        {
            for (int i = 0; i < Size; i++)
                delete List[i];
            delete[] List;
        }

    }
    Array(int capacity)
    {
        List = new T*[capacity];
        Capacity = capacity;
        Size = 0;
    }
    Array(const Array<T> &otherArray)
    {
        List = new T*[otherArray.Capacity];
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        for (int i = 0; i < Size; i++)
            List[i] = new T(*otherArray.List[i]);
    }
    T& operator[] (int index)
    {
        if (index < Size)
            return *List[index];
        else
            throw IndexOutOfRange();
    }
    const Array<T>& operator+=(const T &newElem)
    {
        if (Size < Capacity)
        {
            List[Size] = new T(newElem);
            Size++;
        }
        else
            throw IndexOutOfRange();
        return *this;
    }
    const Array<T>& Insert(int index, const T &newElem)
    {
        if (index < Size)
        {
            if (Size < Capacity)
            {
                for (int i = Size; i > index; i--)
                    List[i] = List[i - 1];
                List[index] = new T(newElem);
                Size++;
            }
            else
                throw IndexOutOfRange();
        }
        else
            throw IndexOutOfRange();
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (index < Size)
        {
            if (Size + otherArray.Size <= Capacity)
            {
                for (int i = Size - 1; i >= index; i--)
                    List[i + otherArray.Size] = List[i];
                for (int i = 0; i < otherArray.Size; i++)
                    List[index + i] = new T(*otherArray.List[i]);
                Size += otherArray.Size;
            }
            else
                throw IndexOutOfRange();
        }
        else
            throw IndexOutOfRange();
        return *this;
    }
    const Array<T>& Delete(int index)
    {
        if (index < Size)
        {
            delete List[index];
            for (int i = index; i < Size - 1; i++)
                List[i] = List[i + 1];
            Size--;
        }
        else
            throw IndexOutOfRange();
        return *this;
    }
    bool operator=(const Array<T> &otherArray)
    {
        if (this->List == otherArray.List)
            return true;
        return false;
    }
    void Sort()
    {
        T aux;
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                {
                    aux = *List[i];
                    *List[i] = *List[j];
                    *List[j] = aux;
                }
    }
    void Sort(int(*compare)(const T&, const T&))
    {
        T aux;
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) == 1)
                {
                    aux = *List[i];
                    *List[i] = *List[j];
                    *List[j] = aux;
                }
    }
    void Sort(Compare *comparator)
    {
        T aux;
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) == 1)
                {
                    aux = *List[i];
                    *List[i] = *List[j];
                    *List[j] = aux;
                }
    }
    int BinarySearch(const T& elem)
    {
        int stg = 0, drp = Size - 1, mij;
        while (stg <= drp)
        {
            mij = (stg + drp) / 2;
            if (*List[mij] == elem)
                return mij;
            if (*List[mij] < elem)
                stg = mij + 1;
            else
                drp = mij - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int stg = 0, drp = Size - 1, mij;
        while (stg <= drp)
        {
            mij = (stg + drp) / 2;
            if (compare(*List[mij], elem) == 0)
                return mij;
            if (compare(*List[mij], elem) == -1)
                stg = mij + 1;
            else
                drp = mij - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare *comparator)
    {
        int stg = 0, drp = Size - 1, mij;
        while (stg <= drp)
        {
            mij = (stg + drp) / 2;
            if (comparator->CompareElements(List[mij], &elem) == 0)
                return mij;
            if (comparator->CompareElements(List[mij], &elem) == -1)
                stg = mij + 1;
            else
                drp = mij - 1;
        }
        return -1;
    }
    int Find(const T& elem)
    {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
        throw Inexistent();
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0)
                return i;
        throw Inexistent();
    }
    int Find(const T& elem, Compare *comparator)
    {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], &elem) == 0)
                return i;
        throw Inexistent();
    }
    int GetSize()
    {
        return Size;
    }
    int GetCapacity()
    {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        ArrayIterator<T> it;
        it.Current = 0;
        it.Element = List[0];
        it.Size = Size;
        return it;
    }
    ArrayIterator<T> GetEndIterator()
    {
        ArrayIterator<T> it;
        it.Current = Size - 1;
        it.Element = List[Size - 1];
        it.Size = Size;
        return it;
    }
};
