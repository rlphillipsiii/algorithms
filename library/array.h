/*
 * array.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_ARRAY_H_
#define LIBRARY_ARRAY_H_

#include "implementation_exception.h"

namespace dsa
{
	template <typename T>
	class array : public data_structure<T>
	{
	public:
		array(uint64_t capacity);
		~array();

		T *data() const;

		T & operator[](uint64_t index);

		const T & at(uint64_t index) const;
		T get(uint64_t index) const;
		T & lookup(uint64_t index) const;

		T *find(const T & value) const;
		bool remove(const T & value);

	private:
		T *m_storage;
	};

#include "array.cpp"
};


#endif /* LIBRARY_ARRAY_H_ */
