/*
 * strings.h
 *
 *  Created on: Jun 20, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_TYPES_STRINGS_H_
#define LIBRARY_TYPES_STRINGS_H_

#include <cstdint>

namespace dsa
{
    class string
    {
    public:
        string();
        string(const char *str);
        string(const char *str, int length);
        string(const string & str);

        ~string();

        const char *cstring(bool copy = false) const;

        void append(char c);

        string operator+(const string & other) const;
        string operator+(const char *str) const;

        bool operator==(const string & other) const;
        char & operator[](uint64_t index);

        char at(uint64_t index) const;

        inline int length() const { return m_length; }

    private:
        string(int capacity);

        char *m_string;

        int m_capacity;
        int m_length;
    };
};

#endif /* LIBRARY_TYPES_STRINGS_H_ */
