#include <map>
#include <string>
#include "../Types/ChimeraObject.hpp"


using namespace std;

struct TableItem {
    ChimeraObject* item;
    bool is_temp;
    string created_from;
};

const string REF_SIGNLE = "a-ref";

class SymbolTable {
private:
    map<string, TableItem> m_table;
    map<ChimeraObject*, uint32_t> m_ref_counter;
    unsigned long long m_cur_reg = 0;
    unsigned long long m_reg = 0;

    void UpdateCurReg();
    void DecreaseRefCount(ChimeraObject *object);
protected:


public:

    SymbolTable();
    SymbolTable (const SymbolTable &old);
    ~SymbolTable();

    bool Has(string var_id);
    bool IsTemp(string var_id);
    void SetParent(string var_id, string parent_id);
    string GetParent(string var_id);
    string AddEntry(string var_id, ChimeraObject *object);
    string AddOrUpdateRef(string var_id, ChimeraObject *object);
    ChimeraObject* GetEntry(string var_id);
    void RemoveEntry(string var_id);
    void FreeTempItems();
};