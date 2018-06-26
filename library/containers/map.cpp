/*
 * map.cpp
 *
 *  Created on: Jun 21, 2018
 *      Author: Robert Phillips III
 */

template <typename K, typename T>
map<K, T>::map(uint64_t size)
    : m_storage(size)
{

}

template <typename K, typename V>
map<K, V>::~map()
{
    clear();
}

template <typename K, typename T>
uint64_t map<K, T>::index(const K & key) const
{
#if 0
    const hashable *h = dynamic_cast<const hashable*>(&key);

    uint64_t raw = (h) ? h->make() : hash<K>::make(key);

    return raw % m_storage.size();
#endif

    return hash<K>::make(key) & m_storage.size();
}

template <typename K, typename T>
void map<K, T>::add(const K & key, const T & value)
{
    (*this)[key] = value;
}

template <typename K, typename T>
bool map<K, T>::remove(const K & key)
{
    list<pair<K, T>> & kvp = m_storage[index(key)];

    auto it = kvp.begin();
    while (it.hasNext()) {
        const pair<K, T> & entry = it.next();
        if (entry.first == key) {
            break;
        }
    }

    return kvp.remove(it);
}

template <typename K, typename T>
T *map<K, T>::find(const K & key) const
{
    auto it = m_storage[index(key)].begin();

    while (it.hasNext()) {
        pair<K, T> & entry = it.next();
        if (entry.first == key) {
            return &entry.second;
        }
    }

    return nullptr;
}

template <typename K, typename T>
T & map<K, T>::operator[](const K & key)
{
    list<pair<K, T>> entries = m_storage[index(key)];

    auto it = entries.begin();
    while (it.hasNext()) {
        pair<K, T> & entry = it.next();
        if (entry.first == key) {
            return entry.second;
        }
    }

    __m_size++;

    m_keys.add(key);

    entries.push(pair<K, T>());
    return entries.front();
}

template <typename K, typename T>
const T & map<K, T>::at(const K & key) const
{
    const list<pair<K, T>> entries = m_storage.at(index(key));

    const T *found = nullptr;

    auto it = entries.begin();
    while (it.hasNext()) {
        const pair<K, T> & entry = it.next();
        if (entry.first == key) {
            found = &entry.second;
            break;
        }
    }

    if (found == nullptr) {
        throw index_exception(it.index());
    }

    return *found;
}

template <typename K, typename T>
void map<K, T>::clear()
{
    for (uint64_t i = 0; i < m_storage.size(); i++) {
        m_storage[i].clear();
    }
}
