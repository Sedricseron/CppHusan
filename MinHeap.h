#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include "DataStruct.h"

using namespace std;

template <class data>
class MinHeap : public DataStruct<data> {
private:
    data* arr;
    int capacity;
    int size;

    void min_heapify(int i) {
        int lt = 1 + 2 * i;
        int rt = 1 + 2 * i + 1;
        int sm = i;
        if (lt < size && arr[lt] < arr[sm]) {
            sm = lt;
        }
        if (rt < size && arr[rt] < arr[sm]) {
            sm = rt;
        }
        if (sm != i) {
            data t = arr[i];
            arr[i] = arr[sm];
            arr[sm] = t;
            min_heapify(sm);
        }
    }

public:
    MinHeap(){
        this->capacity = 16;
        this->arr = new data[capacity];
        this->size = 0;
    }

    MinHeap(vector<data> v) {
        this->capacity = v.size();
        this->arr = new data[capacity];
        this->size = 0;
        for (unsigned int i = 0; i < v.size(); i++) {
            append(v[i]);
        }
    }

    template <size_t SIZE>
    MinHeap(array<data, SIZE> v) {
        this->capacity = v.size();
        this->arr = new data[capacity];
        this->size = 0;
        for (int i = 0; i < v.size(); i++) {
            append(v[i]);
        }
    }

    MinHeap(data* v, size_t n) {
        this->capacity = n;
        this->arr = new data[capacity];
        this->size = 0;
        for (int i = 0; i < n; i++) {
            append(v[i]);
        }
    }

    MinHeap(size_t n) {
        this->capacity = n;
        this->arr = new data[capacity];
        this->size = 0;
    }

    bool append(data p) {
        if (size == capacity) {
            return false;
        }
        int i = size++;
        arr[i] = p;
        while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
            data t = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = t;
            i = (i - 1) / 2;
        }
        return true;
    }

    data pop() {
        if (size == 0) {
            return dline_minv;
        }
        data ret = arr[0];
        arr[0] = arr[--size];
        min_heapify(0);
        return ret;
    }

    bool is_empty() {
        return size == 0;
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
    }

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

        arr[i] = dline_minv;
        while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
            data t = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = t;
            i = (i - 1) / 2;
        }
        pop();

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

