// DataStruct.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include "DLine.h"
#include "MinHeap.h"
#include "DataStruct.h"
#include "Tree.h"
#include <Windows.h>

using namespace std;


void test_tree() {

    vector<DLine> tmp = {
      DLine(1, 2, 3),
      DLine(9, 9, 9),
      DLine(5, 6, 7),
      DLine(4, 5, 6),
      DLine(1, 1, 1),
    };
    DataStruct<DLine>* tree = new Tree<DLine>(tmp);
    cout << "Видалення елемента (9,9,9) з дерева" << endl;
    tree->remove(DLine(9, 9, 9));
    cout << "Додавання елемента (9,8,7) до дерева" << endl;
    tree->append(DLine(9, 8, 7));
    cout << endl;
    cout << "Дана функція знаходить всі вектори дерева, які більші за p1 та менші за p2 " << endl;

    vector<DLine> qwer = tree->find_all(DLine(1, 1, 1), DLine(7, 7, 7));
    for (int i = 0; i < qwer.size(); i++) {
        cout << qwer[i] << endl;
    }
    cout << "Tree:" << endl;
    while (!tree->is_empty()) {
        cout << tree->pop() << endl;
    }


}

void test_MinHeap() {

    vector<DLine> tmp = {
      DLine(1, 2, 3),
      DLine(9, 9, 9),
      DLine(5, 6, 7),
      DLine(4, 5, 6),
      DLine(1, 1, 1),
    };
    DataStruct<DLine>* minheap = new MinHeap<DLine>(tmp);
    cout << "Видалення елемента (9,9,9) з кучі" << endl;
    minheap->remove(DLine(9, 9, 9));
    cout << "Додавання елемента (9,8,7) до кучі" << endl;
    minheap->append(DLine(9, 8, 7));
    cout << endl;
    cout << "Дана функція знаходить всі вектори кучі, які більші за p1 та менші за p2 " << endl;

    vector<DLine> qwer = minheap->find_all(DLine(1, 1, 1), DLine(7, 7, 7));
    for (int i = 0; i < qwer.size(); i++) {
        cout << qwer[i] << endl;
    }
    cout << "MinHeap:" << endl;
    while (!minheap->is_empty()) {
        cout << minheap->pop() << endl;
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    test_tree();
    test_MinHeap();
}