/*
 * dsa_test.h
 *
 *  Created on: Jun 10, 2018
 *      Author: Robert
 */

#ifndef LIBRARY_DSA_TEST_H_
#define LIBRARY_DSA_TEST_H_

#include <datastructure.h>
#include <iostream>
#include <cstdint>

#define TESTABLE_COUNT 8

class DataStructureTest
{
public:
    DataStructureTest();
    ~DataStructureTest();

    bool run();

    static bool leak() { return TestableHelper::error(); }

private:
    class ObjectContainer {
    public:
        int value;

        bool operator==(const ObjectContainer & other) const { return (value == other.value); }
        bool operator>(const ObjectContainer & other)  const { return (value > other.value);  }
        bool operator<(const ObjectContainer & other)  const { return (value < other.value);  }
        bool operator>=(const ObjectContainer & other) const { return (value >= other.value); }
        bool operator<=(const ObjectContainer & other) const { return (value <= other.value); }
    };

    static uint64_t nodes() { return dsa::data_structure<ObjectContainer>::nodes(); }

    typedef bool (DataStructureTest::*TestableTest)(dsa::data_structure<ObjectContainer>*);

    struct Testable {
        Testable(const char *n,
                dsa::data_structure<ObjectContainer> *c,
                bool r,
                TestableTest t)
            : name(n),
              container(c),
              runDefault(r),
              test(t)
        { }

        const char *name;
        dsa::data_structure<ObjectContainer> *container;
        bool runDefault;
        TestableTest test;
    };

    class TestableHelper
    {
    public:
        TestableHelper(const struct Testable & testable)
            : m_testable(testable)
        { }

        ~TestableHelper()
        {
            delete m_testable.container;

            if (DataStructureTest::nodes() != 0) {
                std::cout << m_testable.name << ": Memory leak detected\n";

                s_error = true;
            }
        }

        static bool error() { return s_error; }
    private:
        const struct Testable & m_testable;

        static bool s_error;
    };

    ObjectContainer *m_objects;

    bool run(const struct Testable & testable);
    int indexOfNextUnique(int index);

    bool noop(dsa::data_structure<ObjectContainer>*) { return true; }

    static const int TEST_OBJECT_COUNT;

    const struct Testable m_containers[TESTABLE_COUNT];

    // Data structure tests
    bool testArrayList(dsa::data_structure<ObjectContainer> *container);

};

#endif /* LIBRARY_DSA_TEST_H_ */
