#pragma once

#include <string>
#include <iostream>

using namespace std;

enum VAR_TYPES {
    UNDEFINED_DATA_TYPE, 
    OBJECT_DATA_TYPE, 
    NUMBER_DATA_TYPE, 
    TEXT_DATA_TYPE, 
    INT_DATA_TYPE, 
    DOUBLE_DATA_TYPE, 
    FLOAT_DATA_TYPE, 
    CHAR_DATA_TYPE, 
    STRING_DATA_TYPE, 
    BOOL_DATA_TYPE
};

const string INT_TYPE_NAME = "int";
const string FLOAT_TYPE_NAME = "float";
const string DOUBLE_TYPE_NAME = "double";
const string CHAR_TYPE_NAME = "char";
const string STRING_TYPE_NAME = "string";
const string BOOL_TYPE_NAME = "bool";
const string OBJECT_TYPE_NAME = "object";
const string UNDEFINED_TYPE_NAME = "undefined";
const string TEXT_TYPE_NAME = "text";
const string NUMBER_TYPE_NAME = "number";

union ObjectData {
    string *str;
    int integer;
    float floating;
    long double decimal;
    unsigned char character;
    bool boolean;
};

class ChimeraObject {
private:
    VAR_TYPES m_type = OBJECT_DATA_TYPE;
    const char* m_get_err = "Error: cannot put '%s' in %s\n";
    const char* m_set_err = "Error: cannot set %s to '%s'\n";

    bool IsNumber(ChimeraObject* other);
    bool IsText(ChimeraObject* other);
    bool IsBool(ChimeraObject* other);

protected:
    ObjectData m_data;
    virtual void SetType(VAR_TYPES new_type);

public:

    friend ostream &operator<<(ostream &output, const ChimeraObject& obj)
    {
        switch(obj.m_type) {
            case INT_DATA_TYPE: {
                output << obj.m_data.integer;
                break;
            }
            case FLOAT_DATA_TYPE: {
                output << obj.m_data.floating;
                break;
            }
            case DOUBLE_DATA_TYPE: {
                output << obj.m_data.decimal;
                break;
            }
            case CHAR_DATA_TYPE: {
                output << obj.m_data.character;
                break;
            }
            case STRING_DATA_TYPE: {
                output << obj.m_data.str->c_str();
                break;
            }
            case BOOL_DATA_TYPE: {
                if(obj.m_data.boolean) {
                    output << "true";
                }
                else {
                    output << "false";
                }
                break;
            }
            default: {
                output << "Error: trying to output unrecognized type" << '\n';
                break;
            }
        }
        return output;
    }

    virtual bool IsNumber();
    virtual bool IsText();
    virtual bool IsBool();

    virtual string GetTypeName();

    virtual VAR_TYPES GetType();

    virtual int Set(int &data);
    virtual int Set(float &data);
    virtual int Set(long double &data);
    virtual int Set(unsigned char &data);
    virtual int Set(bool &data);
    virtual int Set(string &data);

    virtual int Get(int &data);
    virtual int Get(float &data);
    virtual int Get(long double &data);
    virtual int Get(unsigned char &data);
    virtual int Get(bool &data);
    virtual int Get(string &data);

    virtual ChimeraObject* ConvertTo(string type);

    virtual bool Less(ChimeraObject* other);
    virtual bool LessEqual(ChimeraObject* other);
    virtual bool Greater(ChimeraObject* other);
    virtual bool GreaterEqual(ChimeraObject* other);
    virtual bool Equal(ChimeraObject* other);

    virtual string ToStr() = 0;
    virtual int ToInt() = 0;
    virtual float ToFloat() = 0;
    virtual long double ToDouble() = 0;
    virtual unsigned char ToChar() = 0;
    virtual bool ToBool() = 0; 

    virtual ChimeraObject* Clone() = 0;

};