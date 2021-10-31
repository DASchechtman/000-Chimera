#include "ChimeraObject.hpp"
#include "Text/Derived/String.hpp"
#include "Number/Derived/Int.hpp"
#include "Number/Derived/Float.hpp"
#include "Number/Derived/Double.hpp"
#include "Number/Derived/Char.hpp"
#include "Bool/Bool.hpp"
#include <stdio.h>

using namespace std;

//PRIVATE METHOD BELOW ------------------------------------------------------------------------------------------------------------------------------

bool ChimeraObject::IsNumber(ChimeraObject *other) {
    return (
        other->GetType() == INT_DATA_TYPE
        || other->GetType() == FLOAT_DATA_TYPE
        || other->GetType() == DOUBLE_DATA_TYPE
        || other->GetType() == CHAR_DATA_TYPE
    );
}

bool ChimeraObject::IsText(ChimeraObject *other) {
    return other->GetType() == STRING_DATA_TYPE;
}

bool ChimeraObject::IsBool(ChimeraObject *other) {
    return other->GetType() == BOOL_DATA_TYPE;
}

//PRIVATE METHODS ABOVE -----------------------------------------------------------------------------------------------------------------------------



//PROTECTED METHODS BELOW ---------------------------------------------------------------------------------------------------------------------------

void ChimeraObject::SetType(VAR_TYPES new_type) {
    m_type = new_type;
}


//PROTECTED METHODS ABOVE ---------------------------------------------------------------------------------------------------------------------------




//PUBLIC METHODS BELOW ------------------------------------------------------------------------------------------------------------------------------

bool ChimeraObject::IsNumber() {
    return IsNumber(this);
}

bool ChimeraObject::IsText() {
    return IsText(this);
}

bool ChimeraObject::IsBool() {
    return IsBool(this);
}

string ChimeraObject::GetTypeName() {
    string type_name = UNDEFINED_TYPE_NAME;

    if (m_type == OBJECT_DATA_TYPE) {
        type_name = OBJECT_TYPE_NAME;
    }
    else if (m_type == NUMBER_DATA_TYPE) {
        type_name = NUMBER_TYPE_NAME;
    }
    else if (m_type == TEXT_DATA_TYPE) {
        type_name = TEXT_TYPE_NAME;
    }
    else if (m_type == INT_DATA_TYPE) {
        type_name = INT_TYPE_NAME;
    }
    else if (m_type == FLOAT_DATA_TYPE) {
        type_name = FLOAT_TYPE_NAME;
    }
    else if (m_type == DOUBLE_DATA_TYPE) {
        type_name = DOUBLE_TYPE_NAME;
    }
    else if (m_type == CHAR_DATA_TYPE) {
        type_name = CHAR_TYPE_NAME;
    }
    else if (m_type == STRING_DATA_TYPE) {
        type_name = STRING_TYPE_NAME;
    }
    else if (m_type == BOOL_DATA_TYPE) {
        type_name = BOOL_TYPE_NAME;
    }

    return type_name;
}

VAR_TYPES ChimeraObject::GetType() {
    return m_type;
}

// SET OVERRIDES BELOW ------------------------------------------------------------------------------------------------------------------------------------
int ChimeraObject::Set(int &data) {
    printf(m_set_err, GetTypeName().c_str(), "int\0");
    return 1;
}

int ChimeraObject::Set(float &data) {
    printf(m_set_err, GetTypeName().c_str(), "float\0");
    return 1;
}

int ChimeraObject::Set(long double &data) {
    printf(m_set_err, GetTypeName().c_str(), "double\0");
    return 1;
}

int ChimeraObject::Set(unsigned char &data) {
    printf(m_set_err, GetTypeName().c_str(), "char\0");
    return 1;
}

int ChimeraObject::Set(bool &data) {
    printf(m_set_err, GetTypeName().c_str(), "bool\0");
    return 1;
}

int ChimeraObject::Set(string &data) {
    printf(m_set_err, GetTypeName().c_str(), "string\0");
    return 1;
}
//SET OVERRIDES ABOVE ----------------------------------------------------------------------------------------------------------------------------------------

//GET OVERRIDES BELOW -----------------------------------------------------------------------------------------------------------------------------------------
int ChimeraObject::Get(int &data) {
    printf(m_get_err, "int\0", GetTypeName().c_str());
    return 1;
}

int ChimeraObject::Get(float &data) {
    printf(m_get_err, "float\0", GetTypeName().c_str());
    return 1;
}

int ChimeraObject::Get(long double &data) {
    printf(m_get_err, "double\0", GetTypeName().c_str());
    return 1;
}

int ChimeraObject::Get(unsigned char &data) {
    printf(m_get_err, "char\0", GetTypeName().c_str());
    return 1;
}


int ChimeraObject::Get(string &data) {
    printf(m_get_err, "string\0", GetTypeName().c_str());
    return 1;
}

int ChimeraObject::Get(bool &data) {
    printf(m_get_err, "bool\0", GetTypeName().c_str());
    return 1;
}
//GETTER METHODS ABOVE ------------------------------------------------------------------------------------------------------------------------------------------


ChimeraObject* ChimeraObject::ConvertTo(string type ) {
    if (type == INT_TYPE_NAME) {
        return new Int(ToInt());
    }
    else if (type == FLOAT_TYPE_NAME) {
        return new Float(ToFloat());
    }
    else if (type == DOUBLE_TYPE_NAME) {
        return new Double(ToDouble());
    }
    else if (type == CHAR_TYPE_NAME) {
        return new Char(ToChar());
    }
    else if (type == STRING_TYPE_NAME) {
        return new String(ToStr());
    }
    else if (type == BOOL_TYPE_NAME) {
        return new Bool(ToBool());
    }
    else {
        cout << "Error: invalid conversion to type " << type << '\n';
        return nullptr;
    }
}

bool ChimeraObject::Less(ChimeraObject *other) {
    bool other_is_num = IsNumber(other);
    bool self_is_num = IsNumber(this);
    bool other_is_text = IsText(other);
    bool self_is_text = IsText(this);
    
    bool ret = false;

    if (other_is_num && self_is_num) {
        auto self_val = ((Number*)other)->GetOtherNumber(*(Number*)this);
        auto other_val = ((Number*)this)->GetOtherNumber(*(Number*)other);
        ret = self_val < other_val;
    }
    else if (other_is_text && self_is_text) {
        auto self_text = ((Text*)this)->GetText();
        auto other_text = ((Text*)other)->GetText();
        ret = self_text < other_text;
    }

    return ret;
}

bool ChimeraObject::LessEqual(ChimeraObject *other) {
    bool other_is_num = IsNumber(other);
    bool self_is_num = IsNumber(this);
    bool other_is_text = IsText(other);
    bool self_is_text = IsText(this);
    
    bool ret = false;

    if (other_is_num && self_is_num) {
        auto self_val = ((Number*)other)->GetOtherNumber(*(Number*)this);
        auto other_val = ((Number*)this)->GetOtherNumber(*(Number*)other);
        ret = self_val <= other_val;
    }
    else if (other_is_text && self_is_text) {
        auto self_text = ((Text*)this)->GetText();
        auto other_text = ((Text*)other)->GetText();
        ret = self_text <= other_text;
    }

    return ret;
}

bool ChimeraObject::Greater(ChimeraObject *other) {
    bool other_is_num = IsNumber(other);
    bool self_is_num = IsNumber(this);
    bool other_is_text = IsText(other);
    bool self_is_text = IsText(this);
    
    bool ret = false;

    if (other_is_num && self_is_num) {
        auto self_val = ((Number*)other)->GetOtherNumber(*(Number*)this);
        auto other_val = ((Number*)this)->GetOtherNumber(*(Number*)other);
        ret = self_val > other_val;
    }
    else if (other_is_text && self_is_text) {
        auto self_text = ((Text*)this)->GetText();
        auto other_text = ((Text*)other)->GetText();
        ret = self_text > other_text;
    }

    return ret;
}

bool ChimeraObject::GreaterEqual(ChimeraObject *other) {
    bool other_is_num = IsNumber(other);
    bool self_is_num = IsNumber(this);
    bool other_is_text = IsText(other);
    bool self_is_text = IsText(this);
    
    bool ret = false;

    if (other_is_num && self_is_num) {
        auto self_val = ((Number*)other)->GetOtherNumber(*(Number*)this);
        auto other_val = ((Number*)this)->GetOtherNumber(*(Number*)other);
        ret = self_val >= other_val;
    }
    else if (other_is_text && self_is_text) {
        auto self_text = ((Text*)this)->GetText();
        auto other_text = ((Text*)other)->GetText();
        ret = self_text >= other_text;
    }

    return ret;
}

bool ChimeraObject::Equal(ChimeraObject *other) {
    bool other_is_num = IsNumber(other);
    bool self_is_num = IsNumber(this);
    bool other_is_text = IsText(other);
    bool self_is_text = IsText(this);
    bool other_is_bool = IsBool(other);
    bool self_is_bool = IsBool(this);
    
    bool ret = false;

    if (other_is_num && self_is_num) {
        auto self_val = ((Number*)other)->GetOtherNumber(*(Number*)this);
        auto other_val = ((Number*)this)->GetOtherNumber(*(Number*)other);
        ret = self_val == other_val;
    }
    else if (other_is_text && self_is_text) {
        auto self_text = ((Text*)this)->GetText();
        auto other_text = ((Text*)other)->GetText();
        ret = self_text == other_text;
    }
    else if (other_is_bool && self_is_bool) {
        bool data_1 = false;
        bool data_2 = false;

        this->Get(data_1);
        other->Get(data_2);

        ret = (data_1 == data_2);
    }

    return ret;
}

//PUBLIC METHODS ABOVE ------------------------------------------------------------------------------------------------------------------------------