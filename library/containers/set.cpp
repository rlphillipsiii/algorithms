/*
 * set.cpp
 *
 *  Created on: Jun 21, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
set<T>::set(uint64_t size)
    : hash_table<T>(size)
{

}

template <typename T>
set<T>::~set()
{

}

template <typename T>
void set<T>::add(const T & value)
{
    if (!data_structure<T>::contains(value)) {
        hash_table<T>::add(value);
    }
}
