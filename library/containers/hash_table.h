/*
 * hash_table.h
 *
 *  Created on: Jun 20, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_HASH_TABLE_H_
#define LIBRARY_HASH_TABLE_H_

#include <datastructure.h>
#include <hashable.h>
#include <hash.h>
#include <array.h>
#include <list.h>

#define __HASH_TABLE_DEFAULT_SIZE 8192

namespace dsa
{
    template <typename T>
    class hash_table : public data_structure<T>
    {
    public:
        hash_table(uint64_t size = __HASH_TABLE_DEFAULT_SIZE);
        virtual ~hash_table();

        T *find(const T & value) const override;
        bool remove(const T & value) override;
        virtual void add(const T & value) override;
        void clear() override;

    private:
        array<list<T>> m_storage;

        uint64_t index(const T & value) const;
    };

#include "hash_table.cpp"
};

#endif /* LIBRARY_HASH_TABLE_H_ */
