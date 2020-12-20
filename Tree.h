#pragma once

#include <array>
#include <cmath>
#include <climits>
#include "DataStruct.h"

using namespace std;

template <typename data>
class Tree : public DataStruct<data> {
private:
    data* arr;
    int capacity;
    int size;

public:
    Tree() {
        this->capacity = 16;
        this->arr = new data[capacity];
        this->size = 0;
    }

    Tree(vector<data> v) {
        this->capacity = v.size();
        this->arr = new data[capacity];
        this->size = 0;
        for (unsigned int i = 0; i < v.size(); i++) {
            append(v[i]);
        }
    }

    template <size_t SIZE>
    Tree(array<data, SIZE> v) {
        this->capacity = v.size();
        this->arr = new data[capacity];
        this->size = 0;
        for (int i = 0; i < v.size(); i++) {
            append(v[i]);
        }
    }

    Tree(data* v, size_t n) {
        this->capacity = n;
        this->arr = new data[capacity];
        this->size = 0;
        for (int i = 0; i < n; i++) {
            append(v[i]);
        }
    }

    Tree(size_t n) {
        this->capacity = n;
        this->arr = new data[capacity];
        this->size = 0;
    }

    bool append(data p) {
        if (size == capacity) {
            return false;
        }
        arr[size++] = p;
        return true;
    }

    data pop() {
        if (size == 0) {
            return dline_minv;
        }
        return arr[--size];
    }

    bool is_empty() {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool is_present(data p) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == p) {
                return true;
            }
        }
        return false;
    }

    size_t find(data p) {
        size_t ret = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == p) {
                ret += 1;
            }
        }
        return ret;
    } // кількість елементів р

    bool remove(data p) {
        int i = -1;
        for (int j = 0; j < size; j++) {
            if (arr[j] == p) {
                i = j;
                break;
            }
        }

        if (i == -1) {
            return false;
        }

        arr[i] = arr[--size];

        return true;
    }

    vector<data> find_all(data p1, data p2) {
        vector<data> ret;
        for (int i = 0; i < size; i++) {
            if ((arr[i] > p1 && arr[i] < p2)
                || arr[i] == p1
                || arr[i] == p2) {
                ret.push_back(arr[i]);
            }
        }
        return ret;
    }
};
