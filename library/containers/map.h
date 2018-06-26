/*
 * map.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_CONTAINERS_MAP_H_
#define LIBRARY_CONTAINERS_MAP_H_

#include <datastructure.h>
#include <array.h>
#include <list.h>
#include <pair.h>
#include <hash.h>
#include <set.h>
#include <hashable.h>

#define __MAP_DEFAULT_SIZE 8192

namespace dsa
{
    template <typename K, typename T>
    class map : public data_structure<T>
    {
    public:
        map(uint64_t size = __MAP_DEFAULT_SIZE);
        ~map();

        inline bool hasKey(const K & key) const { return m_keys.contains(key); }

        T *find(const K & value) const override;
        bool remove(const K & value) override;
        void clear() override;
        void add(const K & value) override      { DSA_NOT_IMPLEMENTED }

        void add(const K & key, const T & value);

        T & operator[](const K & key);
        const T & at(const K & key) const;

    private:
        set<K> m_keys;
        array<list<pair<K, T>>> m_storage;

        uint64_t index(const K & key) const;
    };

#include "map.cpp"
};

#endif /* LIBRARY_CONTAINERS_MAP_H_ */
