#include "StrWrapper.hpp"
#include <string>

using namespace std;

struct YYSTYPE {
    StrWrapper types;
    StrWrapper id;
    StrWrapper tmp_id;
    
    StrWrapper str_val;
    unsigned char char_val;
    int int_val;
    float flo_val;
    long double dou_val;
    bool bol_val;
};