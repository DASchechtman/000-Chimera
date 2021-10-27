#include "Number.hpp"
#include <iostream>

using namespace std;


long double Number::GetOtherNumber(Number &other) {
    long double data = 0;

    if (other.GetType() == INT_DATA_TYPE) {
        int tmp_data = 0;
        other.Get(tmp_data);
        data = tmp_data;
    }
    else if (other.GetType() == FLOAT_DATA_TYPE) {
        float tmp_data = 0;
        other.Get(tmp_data);
        data = tmp_data;
    }
    else if (other.GetType() == DOUBLE_DATA_TYPE) {
        other.Get(data);
    }
    else if (other.GetType() == CHAR_DATA_TYPE) {
        unsigned char tmp_data = 0;
        other.Get(tmp_data);
        data = tmp_data;
    }
    else {
        throw "Error: trying to add a non-number type\n";
    }

    return data;
}

long double Number::DivideByZeroGuard(Number &other) {
    long double data = 0;
    bool execption_thrown = false;

    try {
        data = GetOtherNumber(other);
    }
    catch (const char *msg) {
        cout << msg;
        execption_thrown = true;
    }

    if (data == 0) {
        if (!execption_thrown) {
            throw "Error: illegal division by zero\n";
        }
        else {
            throw 0;
        }
    }

    return data;
}

int Number::Add(Number &other) {
    cout << "Error: 'Add' on baseclass Number isn't implemented yet\n";
    return 1;
}

int Number::Subtract(Number &other) {
    cout << "Error: 'Subtract' on baseclass Number isn't implemented yet\n";
    return 1;
}

int Number::Multiply(Number &other) {
    cout << "Error: 'Multiply' on baseclass Number isn't implemented yet\n";
    return 1;
}

int Number::Divide(Number &other) {
    cout << "Error: 'Divide' on baseclass Number isn't implemented yet\n";
    return 1; 
}