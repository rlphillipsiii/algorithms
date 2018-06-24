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

#define __MAP_DEFAULT_SIZE 8192

namespace dsa
{
    template <typename K, typename V>
    class map : public data_structure<V>
    {
    public:
        map(uint64_t size = __MAP_DEFAULT_SIZE);
        ~map();

        bool hasKey(const K & key);

        T *find(const T & value) const override;
        bool remove(const T & value) override;
        void add(const T & value) override;
        void clear() override;

    private:
        list<K> m_keys;
        array<list<pair<K, V>>> m_storage;

        uint64_t index(const K & key);
    };

#include "map.cpp"
};

#endif /* LIBRARY_CONTAINERS_MAP_H_ */
