/// @file tests.cpp
/// @author Rayyan Athar
/// @date November 07, 2023

/// Provided testing file to implement framework based tests in. The examples
/// below demonstrates a basic empty test in each framework with a single
/// assertion. The version uses the supplied catch.hpp file in starter code.
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Fall 2023

// Catch 2.x - Single Include Framework Testing
#define CATCH_CONFIG_MAIN

#include "prqueue.h"
#include "catch.hpp"

using namespace std;

// This is a basic test case example with sections.
// Requires: <no oter functions>

TEST_CASE("Test 1: The Constructor Test") {
    SECTION("Test 1: Ints")
    {
        prqueue<int> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 
    }
    SECTION("Test 1: Strings")
    {
        prqueue<string> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 
    }
    SECTION("Test 1: Doubles")
    {
        prqueue<double> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 
    }
    SECTION("Test 1: Chars")
    {
        prqueue<char> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 
    }
}

TEST_CASE("Test 2: The Size Test") {
    SECTION("Test 2: Ints")
    {
        prqueue<int> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 

        pq.enqueue(5,1);
        REQUIRE((pq.size() == 1));  
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(10,2);
        REQUIRE((pq.size() == 2)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(15,3);
        pq.enqueue(20,4);
        REQUIRE((pq.size() == 4)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(25,2);
        REQUIRE((pq.size() == 5));
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(15,6);
        REQUIRE((pq.size() == 6)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(5,2);
        pq.enqueue(20,5);
        REQUIRE((pq.size() == 8)); 
        REQUIRE((pq.getRoot() != nullptr)); 
    }
    SECTION("Test 2: Strings")
    {
        prqueue<string> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 

        pq.enqueue("Apple",1);
        REQUIRE((pq.size() == 1));  
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Ball",2);
        REQUIRE((pq.size() == 2)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Cast",3);
        pq.enqueue("Door",4);
        REQUIRE((pq.size() == 4)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Enter",2);
        REQUIRE((pq.size() == 5));
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Cast",6);
        REQUIRE((pq.size() == 6)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Ball",2);
        pq.enqueue("Enter",5);
        REQUIRE((pq.size() == 8)); 
        REQUIRE((pq.getRoot() != nullptr)); 
    }
    SECTION("Test 2: Doubles")
    {
        prqueue<double> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 

        pq.enqueue(0.5,1);
        REQUIRE((pq.size() == 1));  
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.10,2);
        REQUIRE((pq.size() == 2)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.15,3);
        pq.enqueue(0.20,4);
        REQUIRE((pq.size() == 4)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.25,2);
        REQUIRE((pq.size() == 5));
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.15,6);
        REQUIRE((pq.size() == 6)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.5,2);
        pq.enqueue(0.20,5);
        REQUIRE((pq.size() == 8)); 
        REQUIRE((pq.getRoot() != nullptr)); 
    }
    SECTION("Test 2: Chars")
    {
        prqueue<char> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 

        pq.enqueue('a',1);
        REQUIRE((pq.size() == 1));  
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('b',2);
        REQUIRE((pq.size() == 2)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('c',3);
        pq.enqueue('d',4);
        REQUIRE((pq.size() == 4)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('e',2);
        REQUIRE((pq.size() == 5));
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('c',6);
        REQUIRE((pq.size() == 6)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('b',2);
        pq.enqueue('d',5);
        REQUIRE((pq.size() == 8)); 
        REQUIRE((pq.getRoot() != nullptr)); 
    }
}

TEST_CASE("Test 3: The Enqueue Test") {
    SECTION("Test 3: Ints")
    {
        prqueue<int> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 

        pq.enqueue(5,1);
        REQUIRE((pq.size() == 1));  
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(10,2);
        REQUIRE((pq.size() == 2)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(15,3);
        pq.enqueue(20,4);
        REQUIRE((pq.size() == 4)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(25,2);
        REQUIRE((pq.size() == 5));
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(15,6);
        REQUIRE((pq.size() == 6)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(5,2);
        pq.enqueue(20,5);
        REQUIRE((pq.size() == 8)); 
        REQUIRE((pq.getRoot() != nullptr)); 
    }
    SECTION("Test 3: Strings")
    {
        prqueue<string> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 

        pq.enqueue("Apple",1);
        REQUIRE((pq.size() == 1));  
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Ball",2);
        REQUIRE((pq.size() == 2)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Cast",3);
        pq.enqueue("Door",4);
        REQUIRE((pq.size() == 4)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Enter",2);
        REQUIRE((pq.size() == 5));
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Cast",6);
        REQUIRE((pq.size() == 6)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue("Ball",2);
        pq.enqueue("Enter",5);
        REQUIRE((pq.size() == 8)); 
        REQUIRE((pq.getRoot() != nullptr)); 
    }
    SECTION("Test 3: Doubles")
    {
        prqueue<double> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 

        pq.enqueue(0.5,1);
        REQUIRE((pq.size() == 1));  
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.10,2);
        REQUIRE((pq.size() == 2)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.15,3);
        pq.enqueue(0.20,4);
        REQUIRE((pq.size() == 4)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.25,2);
        REQUIRE((pq.size() == 5));
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.15,6);
        REQUIRE((pq.size() == 6)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue(0.5,2);
        pq.enqueue(0.20,5);
        REQUIRE((pq.size() == 8)); 
        REQUIRE((pq.getRoot() != nullptr)); 
    }
    SECTION("Test 3: Chars")
    {
        prqueue<char> pq;
        REQUIRE((pq.size() == 0)); 
        REQUIRE((pq.getRoot() == nullptr)); 

        pq.enqueue('a',1);
        REQUIRE((pq.size() == 1));  
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('b',2);
        REQUIRE((pq.size() == 2)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('c',3);
        pq.enqueue('d',4);
        REQUIRE((pq.size() == 4)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('e',2);
        REQUIRE((pq.size() == 5));
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('c',6);
        REQUIRE((pq.size() == 6)); 
        REQUIRE((pq.getRoot() != nullptr)); 

        pq.enqueue('b',2);
        pq.enqueue('d',5);
        REQUIRE((pq.size() == 8)); 
        REQUIRE((pq.getRoot() != nullptr)); 
    }
}

TEST_CASE("Test 4: The toString Test") {
    SECTION("Test 4: Ints") {
        prqueue<int> pq;

        pq.enqueue(0,1);
        pq.enqueue(1,2);
        pq.enqueue(2,3);
        pq.enqueue(3,4);
        pq.enqueue(4,2);
        pq.enqueue(2,6);
        pq.enqueue(1,2);
        pq.enqueue(3,5);

        string expected = "1 value: 0\n2 value: 1\n2 value: 4\n2 value: 1\n3 value: 2\n4 value: 3\n5 value: 3\n6 value: 2\n";
        REQUIRE(pq.toString() == expected);
    }
    SECTION("Test 4: Strings") {
        prqueue<string> pq;

        pq.enqueue("Dolores", 5);
        pq.enqueue("Benard", 4);
        pq.enqueue("Arnold", 8);
        pq.enqueue("Ford", 2);
        pq.enqueue("Jasmine", 6);
        pq.enqueue("Carlos", 11);
        pq.enqueue("William", 8);
        pq.enqueue("Teddy", 8);

        string expected = "2 value: Ford\n4 value: Benard\n5 value: Dolores\n6 value: Jasmine\n8 value: Arnold\n8 value: William\n8 value: Teddy\n11 value: Carlos\n";
        REQUIRE(pq.toString() == expected);

    }
    SECTION("Test 4: Doubles") {
        prqueue<double> pq;

        pq.enqueue(0.5,1);
        pq.enqueue(1.5,2);
        pq.enqueue(2.5,3);
        pq.enqueue(3.5,4);
        pq.enqueue(4.5,2);
        pq.enqueue(2.5,6);
        pq.enqueue(1.5,2);
        pq.enqueue(3.5,5);

        string expected = "1 value: 0.5\n2 value: 1.5\n2 value: 4.5\n2 value: 1.5\n3 value: 2.5\n4 value: 3.5\n5 value: 3.5\n6 value: 2.5\n";
        REQUIRE(pq.toString() == expected);
    }
    SECTION("Test 4: Chars") {
        prqueue<char> pq;

        pq.enqueue('a',1);
        pq.enqueue('b',2);
        pq.enqueue('c',3);
        pq.enqueue('d',4);
        pq.enqueue('e',2);
        pq.enqueue('c',6);
        pq.enqueue('b',2);
        pq.enqueue('d',5);

        string expected = "1 value: a\n2 value: b\n2 value: e\n2 value: b\n3 value: c\n4 value: d\n5 value: d\n6 value: c\n";
        REQUIRE(pq.toString() == expected);
    }
}

TEST_CASE("Test 5: The Dequeue Test") {
        SECTION("Test 5: Ints") {
        prqueue<int> pq;

        pq.enqueue(0,1);
        pq.enqueue(1,2);
        pq.enqueue(2,3);
        pq.enqueue(3,4);

        REQUIRE((pq.size() == 4));
        pq.clear();
        REQUIRE((pq.size() == 0));

    }
    SECTION("Test 5: Strings") {
        prqueue<string> pq;

        pq.enqueue("Dolores", 5);
        pq.enqueue("Benard", 4);
        pq.enqueue("Arnold", 8);
        pq.enqueue("Ford", 2);

        REQUIRE((pq.size() == 4));
        pq.clear();
        REQUIRE((pq.size() == 0));
    }
    SECTION("Test 5: Doubles") {
        prqueue<double> pq;

        pq.enqueue(0.5,1);
        pq.enqueue(1.5,2);
        pq.enqueue(2.5,3);
        pq.enqueue(3.5,4);

        REQUIRE((pq.size() == 4));
        pq.clear();
        REQUIRE((pq.size() == 0));
    }
    SECTION("Test 5: Chars") {
        prqueue<char> pq;

        pq.enqueue('a',1);
        pq.enqueue('b',2);
        pq.enqueue('c',3);
        pq.enqueue('d',4);

        REQUIRE((pq.size() == 4));
        pq.clear();
        REQUIRE((pq.size() == 0));
    }
}

TEST_CASE("Test 6: The Operator= Test") {
        SECTION("Test 6: Ints") {
        prqueue<int> pq;
        prqueue<int> pqNew;

        pq.enqueue(0,1);
        pq.enqueue(1,2);
        pq.enqueue(2,3);
        pq.enqueue(3,4);

        REQUIRE((pq.size() == 4));

        pqNew = pq;

        REQUIRE((pqNew.size() == pq.size()));
        REQUIRE((pqNew.toString() == pq.toString()));

        pq.enqueue(10,5);

        REQUIRE((pq.size() == 5));
        REQUIRE((pq.size() != pqNew.size()));
        REQUIRE((pqNew.toString() != pq.toString()));
    }
    SECTION("Test 6: Strings") {
        prqueue<string> pq;
        prqueue<string> pqNew;

        pq.enqueue("Dolores", 5);
        pq.enqueue("Benard", 4);
        pq.enqueue("Arnold", 8);
        pq.enqueue("Ford", 2);

        REQUIRE((pq.size() == 4));

        pqNew = pq;

        REQUIRE((pqNew.size() == pq.size()));
        REQUIRE((pqNew.toString() == pq.toString()));

        pq.enqueue("Jasmine", 6);

        REQUIRE((pq.size() == 5));
        REQUIRE((pq.size() != pqNew.size()));
        REQUIRE((pqNew.toString() != pq.toString()));
    }
    SECTION("Test 6: Doubles") {
        prqueue<double> pq;
        prqueue<double> pqNew;

        pq.enqueue(0.5,1);
        pq.enqueue(1.5,2);
        pq.enqueue(2.5,3);
        pq.enqueue(3.5,4);

        REQUIRE((pq.size() == 4));

        pqNew = pq;

        REQUIRE((pqNew.size() == pq.size()));
        REQUIRE((pqNew.toString() == pq.toString()));

        pq.enqueue(10.5,5);

        REQUIRE((pq.size() == 5));
        REQUIRE((pq.size() != pqNew.size()));
        REQUIRE((pqNew.toString() != pq.toString()));
    }
    SECTION("Test 6: Chars") {
        prqueue<char> pq;
        prqueue<char> pqNew;

        pq.enqueue('a',1);
        pq.enqueue('b',2);
        pq.enqueue('c',3);
        pq.enqueue('d',4);

        REQUIRE((pq.size() == 4));

        pqNew = pq;

        REQUIRE((pqNew.size() == pq.size()));
        REQUIRE((pqNew.toString() == pq.toString()));

        pq.enqueue('e',2);

        REQUIRE((pq.size() == 5));
        REQUIRE((pq.size() != pqNew.size()));
        REQUIRE((pqNew.toString() != pq.toString()));
    }
}

TEST_CASE("Test 7: The Next Test") {
        SECTION("Test 7: Empty Queue") {
            prqueue<int> pq;
            int value, priority;

            REQUIRE((pq.next(value, priority) == false));
        }
        SECTION("Test 7: Ints") {
        prqueue<int> pq;
        int value, priority;

        pq.enqueue(0,1);
        pq.enqueue(1,2);
        pq.enqueue(2,3);
        pq.enqueue(3,4);

        pq.begin();

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 0);
        REQUIRE(priority == 1);

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 1);
        REQUIRE(priority == 2);

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 2);
        REQUIRE(priority == 3);

        REQUIRE(pq.next(value, priority) == false);
        REQUIRE(value == 3);
        REQUIRE(priority == 4);

    }
    SECTION("Test 7: Strings") {
        prqueue<string> pq;
        string value;
        int priority;

        pq.enqueue("Dolores", 5);
        pq.enqueue("Benard", 4);
        pq.enqueue("Arnold", 8);
        pq.enqueue("Ford", 2);

        pq.begin();

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == "Ford");
        REQUIRE(priority == 2);

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == "Benard");
        REQUIRE(priority == 4);

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == "Dolores");
        REQUIRE(priority == 5);

        REQUIRE(pq.next(value, priority) == false);
        REQUIRE(value == "Arnold");
        REQUIRE(priority == 8);


    }
    SECTION("Test 7: Doubles") {
        prqueue<double> pq;
        double value; 
        int priority;

        pq.enqueue(0.5,1);
        pq.enqueue(1.5,2);
        pq.enqueue(2.5,3);
        pq.enqueue(3.5,4);

        pq.begin();

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 0.5);
        REQUIRE(priority == 1);

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 1.5);
        REQUIRE(priority == 2);

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 2.5);
        REQUIRE(priority == 3);

        REQUIRE(pq.next(value, priority) == false);
        REQUIRE(value == 3.5);
        REQUIRE(priority == 4);


    }
    SECTION("Test 7: Chars") {
        prqueue<char> pq;
        char value; 
        int priority;

        pq.enqueue('a',1);
        pq.enqueue('b',2);
        pq.enqueue('c',3);
        pq.enqueue('d',4);

        pq.begin();

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 'a');
        REQUIRE(priority == 1);

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 'b');
        REQUIRE(priority == 2);

        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 'c');
        REQUIRE(priority == 3);

        REQUIRE(pq.next(value, priority) == false);
        REQUIRE(value == 'd');
        REQUIRE(priority == 4);
    }
}


TEST_CASE("Test 8: The Dequeue Test") {
        SECTION("Test 8: Ints") {
        prqueue<int> pq;
        int value;

        pq.enqueue(0,1);
        pq.enqueue(1,2);
        pq.enqueue(2,3);
        pq.enqueue(3,4);

        REQUIRE(pq.size() == 4);

        value = pq.dequeue();
        REQUIRE(value == 0);
        REQUIRE(pq.size() == 3);

        value = pq.dequeue();
        REQUIRE(value == 1);
        REQUIRE(pq.size() == 2);

        value = pq.dequeue();
        REQUIRE(value == 2);
        REQUIRE(pq.size() == 1);

        value = pq.dequeue();
        REQUIRE(value == 3);
        REQUIRE(pq.size() == 0);

    }
    SECTION("Test 8: Strings") {
        prqueue<string> pq;
        string value;

        pq.enqueue("Dolores", 5);
        pq.enqueue("Benard", 4);
        pq.enqueue("Arnold", 8);
        pq.enqueue("Ford", 2);

        REQUIRE(pq.size() == 4);

        value = pq.dequeue();
        REQUIRE(value == "Ford");
        REQUIRE(pq.size() == 3);

        value = pq.dequeue();
        REQUIRE(value == "Benard");
        REQUIRE(pq.size() == 2);

        value = pq.dequeue();
        REQUIRE(value == "Dolores");
        REQUIRE(pq.size() == 1);

        value = pq.dequeue();
        REQUIRE(value == "Arnold");
        REQUIRE(pq.size() == 0);
    }
    SECTION("Test 8: Doubles") {
        prqueue<double> pq;
        double value; 


        pq.enqueue(0.5,1);
        pq.enqueue(1.5,2);
        pq.enqueue(2.5,3);
        pq.enqueue(3.5,4);


        REQUIRE(pq.size() == 4);

        value = pq.dequeue();
        REQUIRE(value == 0.5);
        REQUIRE(pq.size() == 3);

        value = pq.dequeue();
        REQUIRE(value == 1.5);
        REQUIRE(pq.size() == 2);

        value = pq.dequeue();
        REQUIRE(value == 2.5);
        REQUIRE(pq.size() == 1);

        value = pq.dequeue();
        REQUIRE(value == 3.5);
        REQUIRE(pq.size() == 0);


    }
    SECTION("Test 8: Chars") {
        prqueue<char> pq;
        char value; 


        pq.enqueue('a',1);
        pq.enqueue('b',2);
        pq.enqueue('c',3);
        pq.enqueue('d',4);

        REQUIRE(pq.size() == 4);

        value = pq.dequeue();
        REQUIRE(value == 'a');
        REQUIRE(pq.size() == 3);

        value = pq.dequeue();
        REQUIRE(value == 'b');
        REQUIRE(pq.size() == 2);

        value = pq.dequeue();
        REQUIRE(value == 'c');
        REQUIRE(pq.size() == 1);

        value = pq.dequeue();
        REQUIRE(value == 'd');
        REQUIRE(pq.size() == 0);
    }

}

TEST_CASE("Test 10: The Peek Test") {
        SECTION("Test 9: Ints") {
        prqueue<int> pq;

        pq.enqueue(0,1);
        pq.enqueue(1,2);
        pq.enqueue(2,3);
        pq.enqueue(3,4);

        REQUIRE(pq.size() == 4);
        REQUIRE(pq.peek() == 0);

        pq.dequeue();
        REQUIRE(pq.peek() == 1);
        REQUIRE(pq.size() == 3);

        pq.dequeue();
        REQUIRE(pq.peek() == 2);
        REQUIRE(pq.size() == 2);

        pq.dequeue();
        REQUIRE(pq.peek() == 3);
        REQUIRE(pq.size() == 1);

        pq.dequeue();
        REQUIRE(pq.size() == 0);

    }
    SECTION("Test 9: Strings") {
        prqueue<string> pq;

        pq.enqueue("Dolores", 5);
        pq.enqueue("Benard", 4);
        pq.enqueue("Arnold", 8);
        pq.enqueue("Ford", 2);

        REQUIRE(pq.size() == 4);
        REQUIRE(pq.peek() == "Ford");

        pq.dequeue();
        REQUIRE(pq.peek() == "Benard");
        REQUIRE(pq.size() == 3);

        pq.dequeue();
        REQUIRE(pq.peek() == "Dolores");
        REQUIRE(pq.size() == 2);

        pq.dequeue();
        REQUIRE(pq.peek() == "Arnold");
        REQUIRE(pq.size() == 1);

        pq.dequeue();
        REQUIRE(pq.size() == 0);
    }
    SECTION("Test 9: Doubles") {
        prqueue<double> pq;

        pq.enqueue(0.5,1);
        pq.enqueue(1.5,2);
        pq.enqueue(2.5,3);
        pq.enqueue(3.5,4);


        REQUIRE(pq.size() == 4);
        REQUIRE(pq.peek() == 0.5);

        pq.dequeue();
        REQUIRE(pq.peek() == 1.5);
        REQUIRE(pq.size() == 3);

        pq.dequeue();
        REQUIRE(pq.peek() == 2.5);
        REQUIRE(pq.size() == 2);

        pq.dequeue();
        REQUIRE(pq.peek() == 3.5);
        REQUIRE(pq.size() == 1);

        pq.dequeue();
        REQUIRE(pq.size() == 0);


    }
    SECTION("Test 9: Chars") {
        prqueue<char> pq;

        pq.enqueue('a',1);
        pq.enqueue('b',2);
        pq.enqueue('c',3);
        pq.enqueue('d',4);

        REQUIRE(pq.size() == 4);
        REQUIRE(pq.peek() == 'a');

        pq.dequeue();
        REQUIRE(pq.peek() == 'b');
        REQUIRE(pq.size() == 3);

        pq.dequeue();
        REQUIRE(pq.peek() == 'c');
        REQUIRE(pq.size() == 2);

        pq.dequeue();
        REQUIRE(pq.peek() == 'd');
        REQUIRE(pq.size() == 1);

        pq.dequeue();
        REQUIRE(pq.size() == 0);
    }
}

TEST_CASE("Test 10: The Operator== Test") {
        SECTION("Test 10: Ints") {
        prqueue<int> pq;

        pq.enqueue(0,1);
        pq.enqueue(1,2);
        pq.enqueue(2,3);
        pq.enqueue(3,4);

        prqueue<int> pqNew;

        pqNew.enqueue(0,1);
        pqNew.enqueue(1,2);
        pqNew.enqueue(2,3);
        pqNew.enqueue(3,4);

        REQUIRE((pq == pqNew == true));

        pqNew.dequeue();

        REQUIRE((pq == pqNew == false));



    }
    SECTION("Test 10: Strings") {
        prqueue<string> pq;

        pq.enqueue("Dolores", 5);
        pq.enqueue("Benard", 4);
        pq.enqueue("Arnold", 8);
        pq.enqueue("Ford", 2);

        prqueue<string> pqNew;
        pqNew.enqueue("Dolores", 5);
        pqNew.enqueue("Benard", 4);
        pqNew.enqueue("Arnold", 8);
        pqNew.enqueue("Ford", 2);

        REQUIRE((pq == pqNew == true));

        pqNew.dequeue();

        REQUIRE((pq == pqNew == false));

    }
    SECTION("Test 10: Doubles") {
        prqueue<double> pq;

        pq.enqueue(0.5,1);
        pq.enqueue(1.5,2);
        pq.enqueue(2.5,3);
        pq.enqueue(3.5,4);

        prqueue<double> pqNew;
        pqNew.enqueue(0.5, 1);
        pqNew.enqueue(1.5, 2);
        pqNew.enqueue(2.5, 3);
        pqNew.enqueue(3.5, 4);

        REQUIRE((pq == pqNew == true));

        pqNew.dequeue();

        REQUIRE((pq == pqNew == false));



    }
    SECTION("Test 10: Chars") {
        prqueue<char> pq;

        pq.enqueue('a',1);
        pq.enqueue('b',2);
        pq.enqueue('c',3);
        pq.enqueue('d',4);

        prqueue<char> pqNew;
        pqNew.enqueue('a', 1);
        pqNew.enqueue('b', 2);
        pqNew.enqueue('c', 3);
        pqNew.enqueue('d', 4);

        REQUIRE((pq == pqNew == true));

        pqNew.dequeue();

        REQUIRE((pq == pqNew == false));

    }
}