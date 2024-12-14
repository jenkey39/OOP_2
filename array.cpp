#include "array.h"
#include <algorithm>

Array::Array() : data(nullptr), size(0) {}

Array::Array(size_t size, number value) : size(size) {
    data = new number[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = value;
    }
}

Array::~Array() {
    delete[] data;
}

void Array::resize(size_t newSize) {
    number* newData = new number[newSize];
    size_t minSize = (newSize < size) ? newSize : size;
    for (size_t i = 0; i < minSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
}

void Array::set_value(size_t index, number value) {
    if (index < size) {
        data[index] = value;
    }
}

number Array::get_value(size_t index) const {
    if (index < size) {
        return data[index];
    }
    return number();
}

size_t Array::get_size() const {
    return size;
}

double Array::mean() const {
    double sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += data[i].modulus();
    }
    return sum / size;
}

double Array::std_dev() const {
    double mean_value = mean();
    double sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += std::pow(data[i].modulus() - mean_value, 2);
    }
    return std::sqrt(sum / size);
}

void Array::sort_ascending() {
    std::sort(data, data + size, [](const number& a, const number& b) {
        return a.modulus() < b.modulus();
    });
}

void Array::sort_descending() {
    std::sort(data, data + size, [](const number& a, const number& b) {
        return a.modulus() > b.modulus();
    });
}

std::istream& operator>>(std::istream& in, Array& arr) {
    for (size_t i = 0; i < arr.size; ++i) {
        in >> arr.data[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Array& arr) {
    for (size_t i = 0; i < arr.size; ++i) {
        out << arr.data[i] << "\n";
    }
    return out;
}
