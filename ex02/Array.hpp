#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
private:
    T *_elements;
    unsigned int _size;

public:
    // Default constructor - creates empty array
    Array() : _elements(NULL), _size(0) {}

    // Parameterized constructor - creates array of n elements initialized by default
    Array(unsigned int n) : _elements(NULL), _size(n)
    {
        if (n > 0)
        {
            _elements = new T[n]();
        }
    }

    // Copy constructor - deep copy
    Array(const Array &other) : _elements(NULL), _size(other._size)
    {
        if (_size > 0)
        {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
            {
                _elements[i] = other._elements[i];
            }
        }
    }

    // Assignment operator - deep copy
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            // Clean up existing memory
            delete[] _elements;

            // Copy size and allocate new memory
            _size = other._size;
            if (_size > 0)
            {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                {
                    _elements[i] = other._elements[i];
                }
            }
            else
            {
                _elements = NULL;
            }
        }
        return *this;
    }

    // Destructor
    ~Array()
    {
        delete[] _elements;
    }

    // Subscript operator with bounds checking
    T &operator[](unsigned int index)
    {
        if (index >= _size)
        {
            throw std::exception();
        }
        return _elements[index];
    }

    // Const version of subscript operator
    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
        {
            throw std::exception();
        }
        return _elements[index];
    }

    // Size function - returns number of elements
    unsigned int size() const
    {
        return _size;
    }
};

#endif
