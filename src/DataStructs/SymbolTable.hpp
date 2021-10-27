#include <map>
#include <string>
#include "../Types/ChimeraObject.hpp"


using namespace std;

struct TableItem {
    ChimeraObject* item;
    bool is_temp;
};

class SymbolTable {
private:
    map<string, TableItem> m_table;
    unsigned long long m_cur_reg = 0;
    unsigned long long m_reg = 0;

    void UpdateCurReg();
protected:


public:

    SymbolTable();
    SymbolTable (const SymbolTable &old);
    ~SymbolTable();

    bool Has(string var_id);
    string AddEntry(string var_id, ChimeraObject *object);
    ChimeraObject* GetEntry(string var_id);
    void RemoveEntry(string var_id);
    void FreeMemory();

};