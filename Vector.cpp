/**
 * @file Vector.cpp
 * @author Garritt Baker
 * @date 2024-09-27
 * @brief cpp file of the Vector class in Vector.h
 * 
 * 
 */





#include "Vector.h"
#include <iostream>


Vector::Vector() : vec_ptr(nullptr), vec_size(0), vec_capacity(0) {}

Vector::Vector(const Vector &other) : vec_size(other.vec_size), vec_capacity(other.vec_capacity) {
    vec_ptr = new int[vec_capacity];
    for (int i = 0; i < vec_size; ++i) {
        vec_ptr[i] = other.vec_ptr[i];
    }
}

Vector::~Vector() {
    delete[] vec_ptr;
}

Vector& Vector::operator=(const Vector &other) {
    if (this != &other) {
        delete[] vec_ptr;
        vec_size = other.vec_size;
        vec_capacity = other.vec_capacity;
        vec_ptr = new int[vec_capacity];
        for (int i = 0; i < vec_size; ++i) {
            vec_ptr[i] = other.vec_ptr[i];
        }
    }
    return *this;
}

int Vector::size() const {
    return vec_size;
}

int Vector::capacity() const {
    return vec_capacity;
}

void Vector::push_back(int element) {
    if (vec_size == vec_capacity) {
        reserve(vec_capacity == 0 ? 1 : 2 * vec_capacity);
    }
    vec_ptr[vec_size++] = element;
}

void Vector::reserve(int n) {
    if (n > vec_capacity) {
        int *new_ptr = new int[n];
        for (int i = 0; i < vec_size; ++i) {
            new_ptr[i] = vec_ptr[i];
        }
        delete[] vec_ptr;
        vec_ptr = new_ptr;
        vec_capacity = n;
    }
}

int& Vector::operator[](unsigned int index) {
    return vec_ptr[index];
}
