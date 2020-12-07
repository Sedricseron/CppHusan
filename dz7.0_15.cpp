#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string str, wrd, tmp;
    std::cout << "String: ";
    std::getline(std::cin, str);
    std::cout << "Word: ";
    std::cin >> wrd;

    std::istringstream ist(str);
    size_t cnt = 0;
    while (ist >> tmp)
        if (tmp == wrd)
            ++cnt;
    std::cout << "meet " << cnt << " times." << std::endl;

    return 0;
}
