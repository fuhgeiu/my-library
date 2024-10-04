#include <iostream>
#include <cassert>
#include "stream.hpp"

/*  notes

    * key points

    * The use of an object, allows for conditons to be set on a object basis and getting data can be done
      wihtout the need for defining conditions again.
    * allows to tie conditions on a object basis, can create many objects each with differnt conditions


    STREAM PROCESSOR

    A)  1, strm::conditional
        2, strm::conditional (strm::condition)

    A.1) strm.moveif(stream object, condition, return type)

    A.1) strm.moveif (std::cin, strm::range, int)

    _______________________________________________________________________________________________________
    A, 1,class conditional, which moves data from stream to what it is assigned to with std::move.
       2, constructor (condiiton object) pass in object to set the stream processor with a condition


    RANGE

    1) strm::range (int, int)
    2) strm::range (char, int)

    _________________________________________________________________________________________________________
    1, to create condition object, constructor (upper bound, lower bound)
    2, constructor for condiiton object, (upper or lower, bound)
       pass in 'u ' to set passed bound int as a upper bound, and 'l' for lower bound
    all) bound is not included in the valid data, if bound = 4, than 4 is not valid, 3 is valid


    FUNCTION

    strm::get(stream object, condition object)

    1) strm:: get (&stream , strm::range_condition)

    ______________________________________________________________________________________________________
    1, returns std::move to move data from stream, that pass condiiton, will display message for non valid data
       found in stream.

 */


int main () {

// testing stream processor , is not part of lab acceptance criteria
    strm::conditional stream;                                           // object without condition

    strm::range condition1 (0,10);                                             // condition

    int myint;

    strm::conditional stream1(condition1);                     // object with condiiton atribute

    


// testing input validation function
    strm::range_cond condition2 (10,0);                // condiiton, upper and lower

    std::cout << "enter a number\n";                                // prompt

    myint = strm::get(std::cin,condition2);          // varify and return data

    std::cout << myint;                                             // prints data

// upper bound only
    strm::range_cond condition3 ('u',5);          // condiiton, only upper bound

    std::cout << "enter a number\n";                                // prompt

    myint = strm::get(std::cin, condition3);         // get data

    std::cout << myint;                                             // print data

// lower bound only
    strm::range_cond condition4 ('l',8);          // condiiton, only upper bound

    std::cout << "enter a number\n";                                // prompt

    myint = strm::get(std::cin, condition4);         // get data

    std::cout << myint;                                             // print data

}


