#include "Text.hpp"
#include <iostream>

using namespace std;

Text::Text() {
    SetGeneralType(TEXT_DATA_TYPE);
}

int Text::Add(Text &other) {
    cout << "Error: 'Add' on baseclass Text not implemented yet\n";
    return FAIL;
}

int Text::Subtract(Text &other) {
    cout << "Error: 'Subtract' on baseclass Text not implemented yet\n";
    return FAIL;
}