/*
 * hash_table.cpp
 *
 *  Created on: Jun 21, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
hash_table<T>::hash_table(uint64_t size)
    : data_structure<T>(),
      m_storage(size)
{

}

template <typename T>
hash_table<T>::~hash_table()
{
    clear();
}

template <typename T>
uint64_t hash_table<T>::index(const T & value) const
{
    return hash<T>::make(value) % m_storage.size();
}

template <>
uint64_t hash_table<hashable>::index(const hashable & h) const
{
    return h.make() & m_storage.size();
}

template <typename T>
T *hash_table<T>::find(const T & value) const
{
    return m_storage[index(value)].find(value);
}

template <typename T>
bool hash_table<T>::remove(const T & value)
{
    bool status = false;

    try {
        status = m_storage[index(value)].remove(value);
        if (status) {
            __m_size--;
        }
    } catch (index_exception &) { }

    return status;
}

template <typename T>
void hash_table<T>::add(const T & value)
{
    m_storage[index(value)].push(value);

    __m_size++;
}

template <typename T>
void hash_table<T>::clear()
{
    for (uint64_t i = 0; i < m_storage.size(); i++) {
        m_storage[i].clear();
    }

    __m_size = 0;
}
