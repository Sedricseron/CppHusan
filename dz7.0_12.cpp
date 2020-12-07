#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream f1;
    f1.open("txt1.txt");
    string data;
    string s = "";
    while (getline(f1, data)) {
        s += data;
    }
    f1.close();
    int i = 0;
    char a;
    cin >> a;
    cout << "String:\n";

    while (s[i])
    {
        if (s[i] == a) { s.erase(i, 1); i--; }
        i++;
    }

    cout << s << "\n";

    system("pause");
    return 0;
}
