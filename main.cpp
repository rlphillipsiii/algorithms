/*
 * main.cpp
 *
 *  Created on: Jun 7, 2018
 *      Author: Robert Phillips III
 */

#include <iostream>

#include <list.h>
#include <bst.h>
#include <arraylist.h>
#include <heap.h>
#include <dequeue.h>
#include <avltree.h>
#include <array.h>

using dsa::list;
using dsa::bst;
using dsa::array_list;
using dsa::heap;
using dsa::dequeue;
using dsa::avl_tree;
using dsa::array;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	list<int> dsa_list;
	dsa_list.push(5);
	dsa_list.push(5);
	dsa_list.push(52);

	std::cout << "List Size:  " << dsa_list.size() << "\n";
	std::cout << "    Front:  " << dsa_list.front() << "\n";
	std::cout << "\n";

	bst<int> dsa_bst;
	dsa_bst.add(3);
	dsa_bst.add(1);
	dsa_bst.add(14);
	dsa_bst.add(10);
	for (int i = 20; i < 200; i++) {
		dsa_bst.add(i);
	}

	int found = *dsa_bst.find(14);

	dsa_bst.remove(14);
	dsa_bst.remove(3);
	dsa_bst.remove(-1);

	found = *dsa_bst.find(10);

	std::cout << "BST Size:  " << dsa_bst.size() << "\n";
	std::cout << "    Found:  " << found << "\n";

	heap<int> dsa_heap;
	(void)dsa_heap;

	avl_tree<int> dsa_avl;
	(void)dsa_avl;

	array<int> dsa_array(16);
	for (uint64_t i = 0; i < dsa_array.size(); i++) {
		dsa_array[i] = i;
	}

	return 0;
}
