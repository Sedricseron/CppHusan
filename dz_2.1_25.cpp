#include <iostream>

using namespace std;
// поворот на 270 градусів у додатньому напрямку це те саме, що поворот на 90 градусів за годинниковою стрілкою
int main() {
    int n;
    cin >> n;
    int** x = new int* [n];
    for (int i = 0; i < n; i++)
        x[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> x[i][j];
    cout << endl;
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--)
            cout << x[i][j] << " ";
        cout << endl;
    }
    return 0;
}