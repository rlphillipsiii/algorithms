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
		index_exception(int index)
			: exception("Index Out of Bounds"),
			  m_index(index)
		{ }

		inline int index() { return m_index; }

	private:
		int m_index;
	};
};

#endif /* INDEX_EXCEPTION_H_ */
