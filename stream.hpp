/*
    notes

    selective stream mover

    *key points

    * read the stream character by character and only moves what is allowed by condition
    * useing move semantics, stream data is only moved once cleared, no copying when processed
    * can define conditions, for data they want to get, bad data is never moved
    * can define, so user can recieve feedback
    * must define, where the data is to be moved to

    class condition - base class                                lines (30-38)

    inherited class
    1, range ()                                                 lines (40-58)

    class range_cond                                            lines (61-87)

    constructors
    1, (int, int)           (upper bound, lower bound)          set a upper and lower bound
    2, (char, int)          (upper or lower bound, int)     set the bound to a lower or upper 'u' upper, 'l' lower



 */


#include <iostream>
#include "str.hpp"


namespace strm {


class condition {

public:

    int pass_condition (int i);

    int pass_conditon (int i);

};

class range : public condition {                                                   // class for range condition

    int lower_bound, upper_bound;

public:

    range (int upper, int lower){                               // constructor

        lower_bound = lower;
        upper_bound = upper;
    }

    bool pass_condition (int i){

        if (i > upper_bound && i < lower_bound) return true;
            else return false;
    }

};


class range_cond {

    int lower_bound,upper_bound;
    char lower_upper_choice = 'n';

public:

    range_cond (int upper, int lower){                               // constructor

        lower_bound = lower;
        upper_bound = upper;
    }

    range_cond (char lower_upper, int bound) {                        // constructor

        if (lower_upper == 'u') upper_bound = bound;
        if (lower_upper == 'l') lower_bound = bound;
        lower_upper_choice = lower_upper;
    }

    bool pass_condition (int i){

        if (lower_upper_choice == 'n') {

            if (i > lower_bound && i < upper_bound) return true;
            else return false;
        }

        if (lower_upper_choice == 'l') {

            if (i > lower_bound) return true;
            else return false;
        }

        if (lower_upper_choice == 'u') {

            if (i < upper_bound) return true;
            else return false;
        }
        return false;
    }

};




class conditional {                                             // class for stream return

     condition condition;                                       // store condition for object

public:

    conditional (){};                                                     // constructor generic

    template <class Ccond>                                            // if pass in condition at object instantiation
    conditional (Ccond condition) {

        conditional::condition = condition;
    }

// method to get integars from stream and return using condition passed in constructor
int move (std::istream &universal_stream) {

    int integar;

        universal_stream >> integar;

        integar =(condition.pass_condition(integar));

    return std::move(integar);
}


// method to get integars from stream and return using passed in condition object
template <typename condition>
int moveif (std::istream &by_stream, condition Cotn) {

    int integar;

        by_stream >> integar;

        integar = (Cotn.pass_condition(integar));

    return std::move(integar);
}


// method to get characters from stream and return into object (usually string)
template <typename condition,typename C>
void moveif (std::istream &by_stream,condition Cotn, C object) {

    char character;
    // contianer to store stream data

    while (by_stream.get(character)) {

        // check if stream data meets condition
        // if meets condition than append it to the container
    }
    // return std::move(container)
}


char* getline (std::istream &stream,strstd::string string_container) {

    char character;
    // string container to return

    // while stream is not a null character

        // append string container with character from stream
//  return container
}


};  // end class conditional


int get (std::istream &by_stream, strm::range_cond Condition_obj) {

    int i;

    while (by_stream >> i) {

        if (Condition_obj.pass_condition(i)) return std::move(i);
            else std::cout << "invalid data\n";
    }
}






}   // end of namespace