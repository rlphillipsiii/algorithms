/*
 * hashable.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_HASHABLE_H_
#define LIBRARY_HASHABLE_H_

namespace dsa
{
    class hashable {
    public:
        virtual uint64_t make() const = 0;
    };
};


#endif /* LIBRARY_HASHABLE_H_ */
