/*
 * set.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_SET_H_
#define LIBRARY_SET_H_

#include <hash_table.h>

namespace dsa
{
    template <typename T>
    class set : public hash_table<T>
    {
    public:
        set(uint64_t size = __HASH_TABLE_DEFAULT_SIZE);
        ~set();

        virtual bool add(const T & value) override;
    private:
    };

#include "set.cpp"
};

#endif /* LIBRARY_SET_H_ */
