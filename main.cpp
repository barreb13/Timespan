// Brent Barrese - Program Driver
// TODO Created by XXX on YYY.
//

#include "timespan.h"
#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

// testing constructor
void test1() 
{
    //Display "Starting Test 1" for debugging purposes
    //cout << "STARTING TEST 1\n";
    TimeSpan ts(1, 20, 30);
    stringstream ss;
    ss << ts;
     assert(ss.str() == "1:20:30");

    TimeSpan ts2(4, -20, -90);
    ss.str("");
    ss << ts2;
    assert(ss.str() == "3:38:30");

    TimeSpan ts3(1.5, 30.5, -90);
    ss.str("");
    ss << ts3;
    assert(ss.str() == "1:59:00");

    TimeSpan ts4(0, 0.07, 0);
    ss.str("");
    ss << ts4;
    assert(ss.str() == "0:00:04");
}

// testing equality, addition, subtraction, multiplication
void test2() 
{
    //Display "Starting Test 2" for debugging purposes
    //cout << "STARTING TEST 2\n";
    TimeSpan ts(1, 20, 30);
    TimeSpan ts2(1, 20, 30);
    TimeSpan ts3(0, 0, 0);
    //TimeSpan ts4 = ts += ts2;

    assert(ts == ts2);
    assert(!(ts != ts2));
    assert(ts != ts3);
    assert((ts + ts + ts) == (ts2 * 3));
    assert((ts * 5) == (ts2 * 4) + ts2);
    assert((ts * 5) == (ts2 * 6) - ts2);
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    assert((ts - ts2) == ts3);
    assert((ts3 * 5) == ts3);
}

void test3() 
{
    //Display "Starting Test 3" for debugging purposes
    //cout << "STARTING TEST 3\n";
    TimeSpan ts0(0, 0, 0);
    TimeSpan ts1(0, 0, 1);
    TimeSpan ts2 = ts0 - ts1;
    stringstream ss;
    ss << ts2;
    assert(ss.str() == "-0:00:01");
}

void testAll() 
{
    test1();
    test2();
    test3();
}

int main() 
{
    testAll();
    cout << "Passed all tests. Done." << std::endl;
    return 0;
}