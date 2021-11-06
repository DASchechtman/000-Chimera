#include "Number.hpp"
#include <iostream>

using namespace std;

// PRIVATE METHODS BELOW ---------------------------------------------------------------------------------------------------------------------------------------

long double Number::GetOtherNumber(Number &other) {
    long double data = 0;

    if (other.GetType() == INT_DATA_TYPE) {
        int64 tmp_data = 0;
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
        char32_t tmp_data = 0;
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

// PRIVATE METHODS ABOVE -------------------------------------------------------------------------------------------------------------------------------------------

// PROTECTED METHODS BELOW -----------------------------------------------------------------------------------------------------------------------------------------
// PROTECTED METHODS ABOVE -----------------------------------------------------------------------------------------------------------------------------------------

// PUBLIC METHODS BELOW --------------------------------------------------------------------------------------------------------------------------------------------

Number::Number() {
    SetGeneralType(NUMBER_DATA_TYPE);
}

long double Number::GetNumber() {
   return GetOtherNumber(*this);
}

int Number::Add(Number &other) {
    cout << "Error: 'Add' on baseclass Number isn't implemented yet\n";
    return FAIL;
}

int Number::Subtract(Number &other) {
    cout << "Error: 'Subtract' on baseclass Number isn't implemented yet\n";
    return FAIL;
}

int Number::Multiply(Number &other) {
    cout << "Error: 'Multiply' on baseclass Number isn't implemented yet\n";
    return FAIL;
}

int Number::Divide(Number &other) {
    cout << "Error: 'Divide' on baseclass Number isn't implemented yet\n";
    return FAIL; 
}

int Number::Pow(Number &other) {
    cout << "Error: 'Pow' on baseclass Number isn't implemented yet\n";
    return FAIL;
}

// PUBLIC METHODS ABOVE ------------------------------------------------------------------------------------------------------------------------------------------------