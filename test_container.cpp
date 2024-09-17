#include <iostream>
#include <sstream>
#include "classcustvar_template.hpp"


template <typename C>
void getstring(C object) {

    std::string tempstring;                               // temp variable, destroy after function

    std::cout << "enter a sentence\n";                    // prompt

    std::getline(std::cin,tempstring);              // stream into temporary string

    object.storeblock(object,tempstring);                 // to store data into container
}

void storestring (cstd::string mystring) {

    std::cout << "enter a sentence\n";                    // prompt

    std::string tempstring;

    std::getline(std::cin,tempstring);              // stream into temporary string

    mystring.setstring("the quik brown fox");
}

int main () {

// for object not using template class
using namespace cstd;
{

// using dynamic container with inherited class for fixed and variable data type

    std::cout << "enter a sentence\n";                      // prompt user

    variable *userinput = new variable;                   // create object for container heap

    contblockfixed<char> *userinputfixed = new contblockfixed<char>;     // create heap obejct for fixed data container

    getstring (*userinputfixed);                                 // get string and store into custom container

    getstring (*userinput);                                      // get string and store into custom container

// using string class

    cstd::string mystring;                                        // if using a string class

    storestring(mystring);                                // store into object container using constructor

    mystring.locate('f');                            // to locate

// using variatic tempalte

    contdynamic<variable*> *variatic =  new contdynamic<variable*>;      // variatic container

    variable *variatoc = new variable;

    variatoc->print();

// fixed array

    cstd::mydataT<char,2> myarray;

}

}

