#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream input("txt1.txt");
    float ch;
    int Count = 0;
    while (input >> ch) Count++;
    input.close();

    float* mass = new float[Count];
    ifstream file("txt1.txt");
    for (int i = 0; i < Count; i++) {
        file >> mass[i];
        if ((mass[i] - (int)mass[i]) == 0) {
            cout << "error!";
            return 0;
        }
        cout << mass[i] << endl;
    }
    float maximal = mass[0];
    for (int i = 0; i < Count; i++) {
        if (mass[i] > maximal) maximal = mass[i];
    }
    cout << "Maximal = " << maximal << endl;
    delete[]  mass;
    system("pause");
    return 0;
}