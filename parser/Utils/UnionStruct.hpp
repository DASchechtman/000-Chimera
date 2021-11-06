#include "StrWrapper.hpp"
#include <string>

using namespace std;

/*
used to replace the default union structure bison provides because a union can't hold object types.
best it can store is a pointer to an object, and since a union can only hold one peice of data at a time
I found a union too restrictive
*/
struct YYSTYPE {
    // internal values used by the parser to pass data
    // around
    StrWrapper types;
    StrWrapper id;
    StrWrapper tmp_id;
    
    // representations of data types in Chimera
    StrWrapper str_val;
    char32_t char_val;
    long long int int_val;
    float flo_val;
    long double dou_val;
    bool bol_val;
};