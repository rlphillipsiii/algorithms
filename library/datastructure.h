/*
 * datastructure.h
 *
 *  Created on: Jun 8, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_DATASTRUCTURE_H_
#define LIBRARY_DATASTRUCTURE_H_

#include <cstdint>
#include <index_exception.h>

#define __m_size     data_structure<T>::m_size
#define __check(...) data_structure<T>::check(__VA_ARGS__)

namespace dsa
{
	template <typename T>
	class data_structure
	{
	public:
		data_structure() : m_size(0) { }
		virtual ~data_structure() { }

		virtual T *find(const T & value) const = 0;
		virtual bool remove(const T & value) = 0;

		virtual bool contains(const T & value)
		{
			return (find(value) != nullptr);
		}

		virtual inline uint64_t size() const { return m_size; }

	protected:
		uint64_t m_size;

		void check(uint64_t index = 0) const
		{
			uint64_t count = size();
			if ((count == 0) || (index < 0) || (index >= count)) {
				throw dsa::index_exception(index);
			}
		}

		struct Container {
		public:
			Container()          { m_refs++; }
			virtual ~Container() { m_refs--; }

			inline static uint64_t count() { return m_refs; }

		private:
			static uint64_t m_refs;
		};
	};

	template <typename T>
	uint64_t data_structure<T>::Container::m_refs = 0;
};

#endif /* LIBRARY_DATASTRUCTURE_H_ */
