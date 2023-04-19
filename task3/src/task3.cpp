#include <algorithm>
#include <iostream>
#include "task3.hpp"

std::string function(char input1, std::string input2) {
    auto pred = [input1] (char character) -> bool {
        return character == input1;
    };

    input2.erase(input2.begin(), std::find_if_not(input2.begin(), input2.end(), pred));
    
    while(input2[input2.size() - 1] == input1) {
        input2.erase(--input2.end());
    }

    return input2;
}