/*
 * index_exception.h
 *
 *  Created on: Jun 7, 2018
 *      Author: Robert
 */

#ifndef INDEX_EXCEPTION_H_
#define INDEX_EXCEPTION_H_

#include "exception.h"

namespace dsa
{
class index_exception : public exception
	{
	public:
		index_exception(uint64_t index)
			: exception("Index Out of Bounds"),
			  m_index(index)
		{ }

		inline uint64_t index() const { return m_index; }

	private:
		uint64_t m_index;
	};
};

#endif /* INDEX_EXCEPTION_H_ */
