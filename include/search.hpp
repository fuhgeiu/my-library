#include "str.hpp"

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
 */

namespace srcstd {


int search(const char* tolocate, strstd::string lookin) {       // (string literal, string object)

    size_t seqlen = strstd::strlength(tolocate);
    size_t index = 0;

    while (index <= (lookin.length() - seqlen)) {

        if (strstd::strcompare(tolocate, lookin , index) == 0) return index;
        index++;
    }
    return -1;
}


int search (char locate, strstd::string lookin) {                  // (char , string object)

    size_t index = 0;

    while (index <= lookin.length()) {

        if (lookin[index] == locate) return index;
        index++;
    }
    return -1;
}



// might need later for testign r value refernces
//int search(const char* tolocate, const char* look) {            // (string literal, string literal
//
//    strstd::string lookin(look);
//
//    return search(tolocate,lookin);
//}


// might need later for testing r value refernces
//int search (char c, const char* look){                             // (char , string literal)
//
//    strstd::string tolocate(look);                            // string literal not mutible, store in object
//
//    return search(c,tolocate);
//}


}   // end of namespace


