#include <iostream>

using namespace std;

float chebeshev(int n = 0, int x = 1) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return x;
    }
    else {
        int polinom;
        polinom = 2 * x * chebeshev((n - 1), x) - chebeshev((n - 2), x);
        return polinom;
    }
}


int main() {
    int n, x;
    cout << "n = "; cin >> n;
    cout << "x = "; cin >> x;
    cout << chebeshev(n, x) << endl;

}