#include "StrWrapper.hpp"
#include <string.h>


using namespace std;
    


void StrWrapper::operator=(string const &data) {
    m_primary_data = data;
}

void StrWrapper::operator=(const char *data) {
    m_primary_data = data;
}

string StrWrapper::operator[](unsigned int i) {
    return m_extra_data[i];
}

void StrWrapper::SetFinalResult(string data) {
    m_primary_data = data;
}

void StrWrapper::SetFinalResult(char data) {
    m_primary_data = data;
}

void StrWrapper::SetWithOmittedEnds(const char* data) {
    m_primary_data = "";
    size_t len = strlen(data)-1;
    size_t i = 1;
    while (i < len) {
        m_primary_data += data[i];
        i++;
    }
}


string StrWrapper::GetFinalResult() {
    return m_primary_data;
}


void StrWrapper::AddPending(string data) {
    m_extra_data.push_back(data);
}

size_t StrWrapper::PendingDataSize() {
    return m_extra_data.size();
}

bool StrWrapper::HasPendingData() {
    return m_extra_data.size() > 0;
}

string StrWrapper::GetPending(unsigned int i) {
    return m_extra_data[i];
}

void StrWrapper::SetPending(unsigned int i, string data) {
    m_extra_data[i] = data;
}

string StrWrapper::RemoveFromPending(unsigned int i) {
    string tmp = m_extra_data[i];
    m_extra_data.erase(m_extra_data.begin() + i);
    return tmp;
}