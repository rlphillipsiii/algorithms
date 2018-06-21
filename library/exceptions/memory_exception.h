/*
 * memory_exception.h
 *
 *  Created on: Jun 20, 2018
 *      Author: Robert
 */

#ifndef LIBRARY_EXCEPTIONS_MEMORY_EXCEPTION_H_
#define LIBRARY_EXCEPTIONS_MEMORY_EXCEPTION_H_

#include "exception.h"

#define CHECK_ALLOC(type, pointer, count) if (pointer == nullptr) throw memory_exception(sizeof(type) * count);

namespace dsa
{
    class memory_exception : public exception
    {
    public:
        memory_exception(uint64_t count)
            : exception("Failed to allocate "),
              m_count(count)
        { }

        virtual string message() const override
        {
            //return (exception::m_message + m_function);
            return exception::m_message;
        }

    private:
        uint64_t m_count;
    };
};



#endif /* LIBRARY_EXCEPTIONS_MEMORY_EXCEPTION_H_ */
