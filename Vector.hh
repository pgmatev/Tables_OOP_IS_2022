#ifndef VECTOR_HH
#define VECTOR_HH

#include <iostream>

template <class T>
class Vector
{
private:
    int size;
    int capacity;
    T* elements;

    void destroy()
    {
        delete [] elements;
    }

    void resize()
    {
        capacity *= 2;
        T* new_elements = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            new_elements[i] = elements[i];
        }
        destroy();
        elements = new_elements;
    }
public:
    Vector()
    {
        size = 0;
        capacity = 1;
        elements = new T[capacity];
    }

    // ~Vector()
    // {
    //     destroy();
    // }

    Vector& operator=(const Vector&  other)
    {
        if(this!=&other)
        {
            destroy();
            this->size = other.size;
            this->capacity = other.capacity;
            this->elements = new T[this->capacity];
            for (int i = 0; i < this->size; i++)
            {
                this->elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    void push_back(T element)
    {
        if (size == capacity)
        {
            resize();
        }
        elements[size] = element;
        size++;
    }

    void push(T element, int index)
    {
        if (index == size)
        {
            push_back(element);
        }
        else
        {
            elements[index] = element;
        }
    }

    T get(int index)
    {
        if (index < size)
        {
            return elements[index];
        }
        return 0;
    }

    void pop()
    {
        size--;
    }

    int getSize()
    {
        return size;
    }

    int getCapacity()
    {
        return capacity;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif