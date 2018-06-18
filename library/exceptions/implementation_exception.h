/*
 * implementation_exception.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_EXCEPTIONS_IMPLEMENTATION_EXCEPTION_H_
#define LIBRARY_EXCEPTIONS_IMPLEMENTATION_EXCEPTION_H_

#include <string>
#include "exception.h"

namespace dsa
{
	class implementation_exception : public exception
	{
	public:
		implementation_exception(const char *function)
			: exception(""),
			  m_function(function)
		{ }

		virtual const char *message() const override
		{
			std::string temp("Functionality not implemented: ");
			return (temp + m_function).c_str();
		}

	private:
		std::string m_function;
	};
};

#endif /* LIBRARY_EXCEPTIONS_IMPLEMENTATION_EXCEPTION_H_ */
