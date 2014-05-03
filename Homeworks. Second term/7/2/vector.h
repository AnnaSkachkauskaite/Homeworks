#pragma once

///Class for using vectors
template <typename T, int size>
class Vector
{
public:
    Vector();
    Vector(int *coord);
    Vector(const Vector &vector);
    ~Vector();

    Vector<T, size> operator +(Vector &vector);
    Vector<T, size> operator - (Vector &vector);
    ///Scalar product of vectors
    T operator * (Vector &vector);
    ///Compare two vectors
    bool areEqual(Vector &vector);
    bool isZeroVector();

private:
    T *coordinates;
};

template <typename T, int size>
Vector<T, size>::Vector()
{
    coordinates = new T[size];
    for (int i = 0; i < size; ++i)
        coordinates[i] = 0;
}

template <typename T, int size>
Vector<T, size>::Vector(int *coord)
{
    coordinates = new T[size];
    for (int i = 0; i < size; ++i)
        coordinates[i] = coord[i];
}

template <typename T, int size>
Vector<T, size>::Vector(const Vector &vector)
{
    coordinates = new T[size];
    for (int i = 0; i < size; ++i)
        coordinates[i] = vector.coordinates[i];
}

template <typename T, int size>
Vector<T, size>::~Vector()
{
    delete[] coordinates;
}

template <typename T, int size>
Vector<T, size> Vector<T, size>::operator +(Vector &vector)
{
    Vector result;
    for (int i = 0; i < size; ++i)
        result.coordinates[i] = coordinates[i] + vector.coordinates[i];
    return result;
}

template <typename T, int size>
Vector<T, size> Vector<T, size>::operator -(Vector &vector)
{
    Vector result;
    for (int i = 0; i < size; ++i)
        result.coordinates[i] = coordinates[i] - vector.coordinates[i];
    return result;
}

template <typename T, int size>
T Vector<T, size>::operator *(Vector &vector)
{
    T result = 0;
    for (int i = 0; i < size; ++i)
        result += coordinates[i] * vector.coordinates[i];
    return result;
}

template <typename T, int size>
bool Vector<T, size>::areEqual(Vector &vector)
{
    for (int i = 0; i < size; ++i)
        if (coordinates[i] != vector.coordinates[i])
            return false;
    return true;
}

template <typename T, int size>
bool Vector<T, size>::isZeroVector()
{
    for (int i = 0; i < size; ++i)
        if (coordinates[i] != 0)
            return false;
    return true;
}
