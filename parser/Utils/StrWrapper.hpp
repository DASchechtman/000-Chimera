#pragma once

#include <string>
#include <vector>

using namespace std;

class StrWrapper
{
private:
    string m_primary_data;
    vector<string> m_extra_data;

public:
    void operator=(string const &data);
    void operator=(const char *data);
    string operator[](unsigned int index);

    friend ostream &operator<<(ostream &output, const StrWrapper &str)
    {
        output << str.m_primary_data;
        return output;
    }

    operator string()
    {
        return m_primary_data;
    }

    void SetFinalResult(string data);
    void SetFinalResult(char data);
    void SetWithOmittedEnds(const char *data);
    string GetFinalResult();

    void AddPending(string data);
    void ClearPending();
    size_t PendingDataSize();
    bool HasPendingData();
    string GetPending(unsigned int i);
    void SetPending(unsigned int i, string data);
    string RemoveFromPending(unsigned int i);
};
