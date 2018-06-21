/*
 * strings.cpp
 *
 *  Created on: Jun 20, 2018
 *      Author: Robert Phillips III
 */

#include <strings.h>

using namespace dsa;

string::string()
    : m_capacity(16),
      m_length(0)
{
    m_string = new char[m_capacity];
}

string::string(const string & str)
    : string()
{
    for (int i = 0; i < str.length(); i++) {
        append(str.at(i));
    }
}

string::string(const char *str)
    : string()
{
    for (int i = 0; str[i] != '\0'; i++) {
        append(str[i]);
    }
}

string::string(const char *str, int length)
    : string()
{
    for (int i = 0; i < length; i++) {
        append(str[i]);
    }
}

string::~string()
{
    delete [] m_string;
}

void string::append(char c)
{
    if (m_length == m_capacity) {
        m_capacity *= 2;

        char *temp = m_string;

        m_string = new char[m_capacity];

        for (int i = 0; i < m_length; i++) {
            m_string[i] = temp[i];
        }

        delete [] temp;
    }

    m_string[m_length++] = c;
}

const char *string::cstring() const
{
    char *str = new char[m_length + 1];

    for (int i = 0; i < m_length; i++) {
        str[i] = m_string[i];
    }

    str[m_length] = 0;
    return str;
}

char string::at(uint64_t index) const
{
    return m_string[index];
}

char & string::operator[](uint64_t index)
{
    return m_string[index];
}

string string::operator+(const string & other) const
{
    string temp(*this);

    for (int i = 0; i < other.m_length; i++) {
        temp.append(other.m_string[i]);
    }

    return temp;
}

string string::operator+(const char *str) const
{
    string temp(*this);

    for (int i = 0; str[i] != '\0'; i++) {
        temp.append(str[i]);
    }

    return temp;
}

bool string::operator==(const string & other) const
{
    int len = length();
    if (len != other.length()) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (m_string[i] != other.m_string[i]) {
            return false;
        }
    }

    return true;
}
