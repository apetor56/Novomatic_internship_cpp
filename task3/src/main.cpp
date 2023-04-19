#include <iostream>
#include <algorithm>
#include <iterator>

int main() {
    std::string tmp;
    std::getline(std::cin, tmp);
    char input = tmp[0];

    auto pred = [input] (char character) -> bool {
        return character == input;
    };

    std::string str;
    std::getline(std::cin, str);

    str.erase(str.begin(), std::find_if_not(str.begin(), str.end(), pred));
    
    while(str[str.size() - 1] == input) {
        str.erase(--str.end());
    }

    std::cout << str << '\n';
}