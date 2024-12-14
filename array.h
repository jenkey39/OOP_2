#ifndef ARRAY_H
#define ARRAY_H

#include "number.h"
#include <iostream>
#include <cmath>

class Array {
private:
    number* data;
    size_t size;

public:
    Array();
    Array(size_t size, number value = number());
    ~Array();

    void resize(size_t newSize);
    void set_value(size_t index, number value);
    number get_value(size_t index) const;
    size_t get_size() const;

    double mean() const;
    double std_dev() const;

    void sort_ascending();
    void sort_descending();

    friend std::istream& operator>>(std::istream& in, Array& arr);
    friend std::ostream& operator<<(std::ostream& out, const Array& arr);
};

#endif
