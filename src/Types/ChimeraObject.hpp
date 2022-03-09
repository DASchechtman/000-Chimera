#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include "../Types.hpp"
#include "../DataTypes.hpp"


using namespace std;

enum COMPARE_OPERS {
    LESS_OPER, 
    LESS_EQUAL_OPER, 
    GREATER_OPER, 
    GREATER_EQUAL_OPER, 
    EQUAL_OPER
};

const string EMPTY_VAR_NAME;

const int FAIL = 1;
const int SUCCEED = 0;

// used for when a scope isn't runnable as a placeholder return value
const int NON_RUNNABLE = 2;



union ObjectData {
    string *str;
    int64 integer;
    float floating;
    long double decimal;
    char32_t character;
    bool boolean;
};

class ChimeraObject {
private:
    VAR_TYPES m_type = OBJECT_DATA_TYPE;
    VAR_TYPES m_gen_type = UNDEFINED_DATA_TYPE;
    const char* m_get_err = "Error: cannot put '%s' in %s\n";
    const char* m_set_err = "Error: cannot set %s to '%s'\n";

    bool PerformCompareOper(ChimeraObject* other, COMPARE_OPERS oper_code);

    template<class T>
    bool Compare(T a, T b, COMPARE_OPERS oper_code);

protected:
    ObjectData m_data;
    bool is_const = false;
    virtual void SetType(VAR_TYPES new_type);
    virtual void SetGeneralType(VAR_TYPES new_type);
    virtual string VarTypeToStr(VAR_TYPES type);

public:

    friend ostream &operator<<(ostream &output, ChimeraObject& obj)
    {

        switch(obj.GetType()) {
            case INT_DATA_TYPE: {
                int64 data = 0;
                obj.Get(data);
                output << data;
                break;
            }
            case FLOAT_DATA_TYPE: {
                float data = 0;
                obj.Get(data);
                output << data;
                break;
            }
            case DOUBLE_DATA_TYPE: {
                dbl128 data = 0;
                obj.Get(data); 
                output << data;
                break;
            }
            case CHAR_DATA_TYPE: {
                char32_t data = '\0';
                obj.Get(data);
                if (data < 255) {
                    output << (char)data;
                }
                else {
                    output << data;
                }
                break;
            }
            case STRING_DATA_TYPE: {
                string data;
                obj.Get(data);
                output << data;
                break;
            }
            case BOOL_DATA_TYPE: {
                bool data = false;
                obj.Get(data);
                if(data) {
                    output << "true";
                }
                else {
                    output << "false";
                }
                break;
            }
            default: {
                output << obj.ToStr();
                break;
            }
        }
        return output;
    }

    virtual ChimeraObject* operator->();

    virtual bool IsNumber();
    virtual bool IsText();
    virtual bool IsBool();

    virtual string GetTypeName();

    virtual VAR_TYPES GetType();
    virtual VAR_TYPES GetGeneralType();

    virtual int Set(int64 &data);
    virtual int Set(float &data);
    virtual int Set(long double &data);
    virtual int Set(char32_t &data);
    virtual int Set(bool &data);
    virtual int Set(string &data);
    virtual int Set(ChimeraObject *other);

    virtual int Get(int64 &data);
    virtual int Get(float &data);
    virtual int Get(long double &data);
    virtual int Get(char32_t &data);
    virtual int Get(bool &data);
    virtual int Get(string &data);

    virtual ChimeraObject* ConvertTo(string type);

    virtual bool Less(ChimeraObject* other);
    virtual bool LessEqual(ChimeraObject* other);
    virtual bool Greater(ChimeraObject* other);
    virtual bool GreaterEqual(ChimeraObject* other);
    virtual bool Equal(ChimeraObject* other);

    virtual void SetConstStatus(bool is_const);
    virtual bool GetConstStatus();

    virtual string ToStr() = 0;
    virtual int64 ToInt() = 0;
    virtual float ToFloat() = 0;
    virtual long double ToDouble() = 0;
    virtual char32_t ToChar() = 0;
    virtual bool ToBool() = 0; 

    virtual ChimeraObject* Clone() = 0;
    virtual ~ChimeraObject() {};

};

template<class T>
bool ChimeraObject::Compare(T a, T b, COMPARE_OPERS oper_code) {
    bool compare_res = false;

    if (oper_code == LESS_OPER) {
        compare_res = (a < b);
    }
    else if (oper_code == LESS_EQUAL_OPER) {
        compare_res = (a <= b);
    }
    else if (oper_code == GREATER_OPER) {
        compare_res = (a > b);
    }
    else if (oper_code == GREATER_EQUAL_OPER) {
        compare_res = (a >= b);
    }
    else if (oper_code == EQUAL_OPER) {
        compare_res = (a == b);
    }

    return compare_res;
}