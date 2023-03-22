#include "ScalarHolder.hpp"

template <typename T>
ScalarHolder<T>::ScalarHolder() : _variable(), _isValid(true) {}

template <typename T>
ScalarHolder<T>::ScalarHolder(const T& var) : _variable(var), _isValid(true) {}

template <typename T>
ScalarHolder<T>::ScalarHolder(bool valid) : _variable(), _isValid(false) {
    (void)valid;
}

template <typename T>
ScalarHolder<T>::ScalarHolder(const ScalarHolder<T>& other) {
    *this = other;
}

template <typename T>
ScalarHolder<T>& ScalarHolder<T>::operator=(const ScalarHolder<T>& other) {
    if (this == &other)
        return (*this);
    _variable = other._variable;
    _isValid = other._isValid;
    return (*this);
}

template <typename T>
bool ScalarHolder<T>::isValid() const {
    return _isValid;
}

template <typename T>
T ScalarHolder<T>::getVariable() const {
    return _variable;
}

template <typename T>
ScalarHolder<T>::operator bool() const {
    return _isValid;
}

template <typename T>
ScalarHolder<T>::operator T() const {
    return _variable;
}

template class ScalarHolder<char>;
template class ScalarHolder<int>;
template class ScalarHolder<float>;
template class ScalarHolder<double>;