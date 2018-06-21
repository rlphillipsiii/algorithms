/*
 * implementation_exception.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_EXCEPTIONS_IMPLEMENTATION_EXCEPTION_H_
#define LIBRARY_EXCEPTIONS_IMPLEMENTATION_EXCEPTION_H_

#include <exception.h>

#define DSA_NOT_IMPLEMENTED throw implementation_exception(__FUNCTION__);

namespace dsa
{
	class implementation_exception : public exception
	{
	public:
		implementation_exception(const string & function)
			: exception("Functionality not implemented: "),
			  m_function(function)
		{ }

		virtual string message() const override
		{
			return (exception::m_message + m_function);
		}

	private:
		string m_function;
	};
};

#endif /* LIBRARY_EXCEPTIONS_IMPLEMENTATION_EXCEPTION_H_ */
