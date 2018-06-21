/*
 * hash.cpp
 *
 *  Created on: Jun 20, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
uint64_t hash<T>::make(const T & object)
{
    const uint8_t *temp = reinterpret_cast<const uint8_t*>(&object);

    uint64_t length = sizeof(object);
    return make(temp, length);
}

template <typename T>
uint64_t hash<T>::make(const uint8_t *str, uint64_t length)
{
    uint64_t hash = 5381;
    for (uint64_t i = 0; i < length; i++) {
        hash = ((hash << 5) + hash) + str[i];
    }

    return hash;
}
