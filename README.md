# GenClass
Generate C++ class .h and .cpp files automatically at current dirctory.
===

Install:
---
    make
    sudo make install

Usage:
---
    genclass <Class Name> [-<STL head file name>]

Example:
---
    genclass Test -string -vector
then Test.h and Test.cpp will be generated at current dirctory.
Following are their content:
    Test.h:
    
    > #ifndef _TEST_H_
    > #define _TEST_H_
    > 
    > #include <string>
    > #include <vector>
    > 
    > class Test
    > {
    >   public:
    >     Test();
    >     ~Test();
    >   private:
    > };
    > 
    > 
    > #endif//_TEST_H_
    > 
    
    Test.cpp:
    
    > #include "Test.h"
    > 
    > using namespace std;
    > 
    > Test::Test()
    > {
    > 
    > }
    > 
    > Test::~Test()
    > {
    > 
    > }
    > 
    
