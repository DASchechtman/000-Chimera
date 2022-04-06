#include "StringOper.hpp"

string GetChar(string str_name, string index_name, Memory &mem) {
    bool right_types = (
        mem.GetDataType(str_name) == STRING_DATA_TYPE
        && mem.GetDataType(index_name) == INT_DATA_TYPE
    );

    if (!right_types) {
        return EMPTY_VAR_NAME;
    }

    String *str = (String*)mem.GetData(ORIGINAL, str_name);
    Int *index = (Int*)mem.GetData(ORIGINAL, index_name);

    chmr_int index_val = 0;
    index->Get(index_val);

    string str_val = str->ToStr();

    if (index_val < 0) {
        index_val = (index_val * -1) % str_val.length();
        index_val = str_val.length() - index_val;
    }

    chmr_char char_at = str_val[index_val % str_val.length()];
    string empty = EMPTY_VAR_NAME;
    
    string char_val_name = mem.CreateData(empty, CHAR_DATA_TYPE);
    mem.InitData(char_at, char_val_name);
    return char_val_name;
}

string GetStrLen(string str_name, Memory &mem) {
    bool right_type = mem.GetDataType(str_name) == STRING_DATA_TYPE;
    if (!right_type) {
        return EMPTY_VAR_NAME;
    }

    String *str = dynamic_cast<String*>(mem.GetData(ORIGINAL, str_name));
    string empty = EMPTY_VAR_NAME;
    string len_name = mem.CreateData(empty, INT_DATA_TYPE);
    mem.InitData(static_cast<chmr_int>(str->ToStr().length()), len_name);
    return len_name;
}