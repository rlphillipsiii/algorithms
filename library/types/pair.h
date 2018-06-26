/*
 * pair.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_TYPES_PAIR_H_
#define LIBRARY_TYPES_PAIR_H_

namespace dsa
{
    template <typename T1, typename T2>
    class pair
    {
    public:
        pair() { }
        pair(const pair<T1, T2> & other)
        {
            first  = other.first;
            second = other.second;
        }

        pair(const T1 & f, const T2 & s)
            : first(f),
              second(s)
         { }

        ~pair() { }

        bool operator==(const pair<T1, T2> & other) const
        {
            return ((first == other.first) && (second == other.second));
        }

        T1 first;
        T2 second;
    };
};

#endif /* LIBRARY_TYPES_PAIR_H_ */
