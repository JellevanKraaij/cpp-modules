#pragma once

template <typename T>
class ScalarHolder {
   public:
    ScalarHolder();
    ScalarHolder(const T& var);
    ScalarHolder(bool valid);

    ScalarHolder(const ScalarHolder<T>& other);
    ~ScalarHolder() {}

    ScalarHolder& operator=(const ScalarHolder<T>& other);

    bool isValid() const;

    T getVariable() const;

    operator bool() const;
    operator T() const;

   private:
    T _variable;
    bool _isValid;
};
