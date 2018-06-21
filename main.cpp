/*
 * main.cpp
 *
 *  Created on: Jun 7, 2018
 *      Author: Robert Phillips III
 */

#include <iostream>
#include <string>

#include <dsa_test.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	DataStructureTest harness;

	bool status = true;

	status &= harness.run();
	status &= !DataStructureTest::leak();

	std::string message = (status) ? "Passed" : "Failed";

	std::cout << "Tests " << message << "\n";

	return (status) ? 0 : 1;
}
