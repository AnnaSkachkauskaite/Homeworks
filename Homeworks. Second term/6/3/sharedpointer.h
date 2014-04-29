#pragma once
template <typename T>
class SharedPointer
{
public:
    SharedPointer() : pointer()
    {

    }

    SharedPointer(T *ptr) : pointer(new Pointer(ptr))
    {

    }

    SharedPointer(SharedPointer &ptr): pointer(ptr.pointer)
    {
        ++pointer->count;
    }
    ~SharedPointer();
    T *getPointer();
    int getCount();
    SharedPointer& operator= (SharedPointer &ptr)
    {
        if (pointer != ptr.pointer)
        {
            --pointer->count;
            pointer = ptr.pointer;
            ++pointer->count;
        }
        return *this;
    }
private:
    struct Pointer
    {
        Pointer() : ptr(nullptr), count(0) {}
        Pointer(T *point) : ptr(point), count(1) {}
        T *ptr;
        int count;
    };
    Pointer *pointer;
};

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    --pointer->count;
    if (pointer->count < 1)
        delete pointer->ptr;
}

template <typename T>
int SharedPointer<T>::getCount()
{
    return pointer->count;
}

template <typename T>
T* SharedPointer<T>::getPointer()
{
    return pointer->ptr;
}

