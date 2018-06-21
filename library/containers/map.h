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

#define __MAP_DEFAULT_SIZE 8192

namespace dsa
{
    template <typename K, typename V>
    class map : public data_structure<V>
    {
    public:
        map(uint64_t size = __MAP_DEFAULT_SIZE);
        ~map();

    private:
    };

#include "map.cpp"
};

#endif /* LIBRARY_CONTAINERS_MAP_H_ */
