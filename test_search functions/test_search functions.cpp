#include "search.hpp"
#include <cassert>


/*  notes

    SEARCH FUNCTIONS (linear search only, string and character only)

    1) srcstd::search int (const char* , const char*)

    2) srcstd::search int (const char* , cstd::string object)

    3) srcstd::search int (char , cstd::string object)

    4) srcstd::search int (char , const char* )

    _____________________________________________________________________________________________________________
    1) search a string literal, for a string literal (what to search for, what to search from). only pass pointer
       to r value of char in " " format. return common.
    2) search a string object, for a string literal. (what to search for , object to search from
    3) search character literal from string object ('char' to searchfor , object to search from)
    4) search character literal from a string literal. (search for, look in). return common.
    common) all return signed int. returns index of first occurance or -1 for no occurance. index of 0.
    notes) a single function will pass in both string object and string literal, with implicit conversion
           there are 2 functions, although 4 argument combinations exist. array does not need to be null terminated


    STRING LITERAL LENGTH
    COMPARE STRINGS

    1) strstd::strlength size_t (const char*)

       <size_t S, typename T>
    2) strstd::strcompare int (const char* , T (&array)[S] (size must be r value))

    3) strstd::strcompare int (const char* , char*)

    4) strstd::strcompare int (const char*, strstd::string, int)

    _______________________________________________________________________________________________________________
    1) get size of string literal, does not include null. return type, unsigned int  size_t
    2) compare string literal to array. template pass in unsighned int for size, and array data type. cannot pass in
       cannot pass in a runtime only value for size, must be known at compile time. makes size comparison before
       iterating through, better for comparisons with large data.
    3) compare string literal to array. pass in pointer to array
    4) compare string literal with a string object. (compare to, object to compare with, index where begin search)
       return type int, returns 0, if comparision is true. return -1, if comparision false

 */



int main () {

//  test functions part of the search header file

//  srcstd::search (char , string literal)

    assert(srcstd::search(' ',"foo bar" ) == 3);
    assert(srcstd::search('o',"foo bar" ) == 1);
    assert(srcstd::search('f',"foo bar" ) == 0);
    assert(srcstd::search('z',"foo bar" ) == -1);

    char myarray[8] = "foo bar";

    assert(srcstd::search('z',myarray) == -1);

// srcstd::search (char , string object)

    strstd::string test("foo bar");

    assert(srcstd::search(' ',test) == 3);
    assert(srcstd::search('o',test) == 1);
    assert(srcstd::search('f',test) == 0);
    assert(srcstd::search('i',test) == -1);

// srcstd::search (string literal , string object)

    assert(srcstd::search("foo",test) == 0);
    assert(srcstd::search(" ",test) == 3);
    assert(srcstd::search("ar",test) == 5);
    assert(srcstd::search("oo",test) == 1);
    assert(srcstd::search("aro",test) == -1);

//  srcstd::search (string literal , string literal)

    assert(srcstd::search("foo","foo bar") == 0);
    assert(srcstd::search(" ","foo bar") == 3);
    assert(srcstd::search("arx","foo bar") == -1);
    assert(srcstd::search("ba","foo bar") == 4);

}
