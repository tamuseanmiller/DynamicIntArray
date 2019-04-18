#ifndef DYNAMICINTARRAY_H
#define DYNAMICINTARRAY_H

#include <iostream>
#include <string>

using namespace std;

class DynamicIntArray {
    int *A;
    unsigned int capacity;
    unsigned int len;

    void grow() {
//        Double Capacity
        capacity *= 2;
//        Allocate New Array
        int *newA = new int[capacity];
//        Copy old data over
        for (unsigned int i = 0; i < len; i++) {
            newA[i] = A[i];
            A[i] = 0;
        }
//        Zero out rest of array
        for (unsigned int i = len; i < capacity; i++) {
            newA[i] = 0;
        }
//        Deallocate old array
        delete[] A;
//        "return" new array
        A = newA;
    };

public:
    DynamicIntArray() : A(new int[1]), capacity(1), len(0) {};

    DynamicIntArray(const DynamicIntArray &other) {
        A = new int[other.capacity];
        for (unsigned int i = 0; i < other.len; i++) {
            A[i] = other[i];
        }
        for (unsigned int i = len; i < other.capacity; i++) {
            A[i] = 0;
        }
        len = other.len;
        capacity = other.capacity;
    };

    ~DynamicIntArray() {
        for (unsigned int i = 0; i < capacity; i++) {
            A[i] = 0;
        }
        delete[] A;
        capacity = 0;
        len = 0;
    };

    unsigned int length() {
        return len;
    };

    void push_back(int elem) {
        if (len == capacity) {
            grow();
        }
        A[len++] = elem;
    };

    int pop_back() {
        if (len == 0) {
            throw "Array is Empty";
        }
        int val = A[--len];
        A[len + 1] = 0;
        return val;
    };

    int &operator[](unsigned int num) {
        if (num < 0 || num >= len) {
            throw "Index out of bounds: " + std::to_string(num);
        }
        return A[num];
    };

    const int &operator[](const unsigned int num) const {
        if (num < 0 || num >= len) {
            throw "Index out of bounds: " + std::to_string(num);
        }
        return A[num];
    };

    DynamicIntArray &operator=(DynamicIntArray &arr) {
        for (unsigned int i = 0; i < len; i++) {
            arr[i] = A[i];
        }
        return arr;
    };
};

#endif