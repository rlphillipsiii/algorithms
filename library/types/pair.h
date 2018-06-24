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
        pair(const T1 & f, const T2 & s)
            : first(f)
              second(s)
         { }

        ~pair() { }

        T1 first;
        T2 second;
    };
};

#endif /* LIBRARY_TYPES_PAIR_H_ */
