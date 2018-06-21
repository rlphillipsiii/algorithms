/*
 * hash.h
 *
 *  Created on: Jun 20, 2018
 *      Author: Robert
 */

#ifndef HASH_H_
#define HASH_H_

#include <cstdint>

namespace dsa
{
    template <typename T>
    class hash
    {
    public:
        static uint64_t make(const T & object);

    private:
        static uint64_t make(const uint8_t *str, uint64_t length);

    };

#include "hash.cpp"
};

#endif /* HASH_H_ */
