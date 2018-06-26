/*
 * dsa_test.cpp
 *
 *  Created on: Jun 10, 2018
 *      Author: Robert Phillips III
 */

#include "dsa_test.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <array.h>
#include <arraylist.h>
#include <list.h>
#include <bst.h>
#include <heap.h>
#include <dequeue.h>
#include <hash_table.h>
#include <map.h>

using namespace dsa;

#define assertEquals(status, expected, actual) if (expected != actual) { \
    status &= false; \
    std::cout << __FILE__ << ":" <<  __LINE__ << " - Excepted = " << expected << " | Actual = " << actual << "\n"; \
}

static const int MAX_DATA_STRUCTURE_SIZE = 100000;

bool DataStructureTest::TestableHelper::s_error = false;

const int DataStructureTest::TEST_OBJECT_COUNT = MAX_DATA_STRUCTURE_SIZE;

#define TESTABLE(name, structure, runDefault, function, ...) \
    { name, new structure<ObjectContainer>(__VA_ARGS__), runDefault, &DataStructureTest::function }

DataStructureTest::DataStructureTest()
    : m_containers({
          TESTABLE("Array Test", array, false, noop, MAX_DATA_STRUCTURE_SIZE),
          TESTABLE("Array List Test", array_list, true, testArrayList, MAX_DATA_STRUCTURE_SIZE),
          TESTABLE("Linked List Test", list, true, noop),
          TESTABLE("BST Test", bst, true, noop),
          TESTABLE("Heap Test", heap, true, noop),
          TESTABLE("Dequeue Test", dequeue, true, noop),
          TESTABLE("Hash Table Test", hash_table, true, noop),
          { "Map Test", new map<ObjectContainer, ObjectContainer>(), false, &DataStructureTest::noop }
      })
{
    m_objects = new ObjectContainer[TEST_OBJECT_COUNT];
    for (int i = 0; i < TEST_OBJECT_COUNT; i++) {
        m_objects[i].value = std::rand();
    }
}

DataStructureTest::~DataStructureTest()
{
    delete [] m_objects;
}

int DataStructureTest::indexOfNextUnique(int index)
{
    int value = m_objects[index].value;

    while (++index < MAX_DATA_STRUCTURE_SIZE) {
        int next = m_objects[index].value;

        if (next != value) {
            return index;
        }
    }

    return -1;
}

bool DataStructureTest::run()
{
    uint64_t seconds = std::time(nullptr);
    std::cout << "Using seed:  " << seconds << "\n";

    std::srand(seconds);

    bool status = true;
    for (const struct Testable & testable : m_containers) {
        status &= run(testable);
    }

    return status;
}

bool DataStructureTest::run(const struct Testable & testable)
{
    std::cout << testable.name << "\n";

    bool status = true;

    TestableHelper helper(testable);

    auto *container = testable.container;
    if (testable.runDefault) {
        container->clear();

        container->add(m_objects[0]);
        assertEquals(status, 1, container->size());

        bool removed = container->remove(m_objects[indexOfNextUnique(0)]);
        assertEquals(status, false, removed);
        assertEquals(status, 1, container->size());

        removed = container->remove(m_objects[0]);
        assertEquals(status, true, removed);
        assertEquals(status, 0, container->size());

        for (int i = 0; i < MAX_DATA_STRUCTURE_SIZE; i++) {
            container->add(m_objects[i]);
        }

        container->clear();
        assertEquals(status, 0, container->size());
        container->clear();
    }

    if (testable.test != nullptr) {
        status &= (this->*testable.test)(container);
    }

    return status;
}

bool DataStructureTest::testArrayList(data_structure<ObjectContainer> *container)
{
    bool status = true;

    auto *structure = dynamic_cast<array_list<ObjectContainer>*>(container);
    if (!structure) {
        return false;
    }

    return status;
}
