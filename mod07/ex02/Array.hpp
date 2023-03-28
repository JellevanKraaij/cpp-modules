#pragma once

template <typename T>
class Array {
   public:
    Array() : _data(nullptr), _size(0) {}
    Array(unsigned int length) : _data(new T[length]()), _size(length) {}
    Array(const Array &other) { *this = other; }
    ~Array() { delete[] _data; }

    Array &operator=(const Array &other) {
        if (this == &other)
            return (*this);

        if (_size != other._size) {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
        }

        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
        return (*this);
    }

    unsigned int size() const { return (_size); }

    T &operator[](unsigned int i) {
        if (i >= _size)
            throw std::out_of_range("Array index is out of bounds");
        return (_data[i]);
    }

   private:
    T *_data;
    unsigned int _size;
};
