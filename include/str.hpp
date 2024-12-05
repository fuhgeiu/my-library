#include <iostream>

/*

    STRING CLASS

    strstd::string          non template class to store char in a dynamically allocated container        line 40
 
    CONSTRUCTORS
 
    1) string ()
    
    ____________________________________________________________________________________________________________
 
 

    PUBLIC MEMBERS
 
    1) setstring ()
 
    2) void print ()
 
    3) char* sequence ()
 
    4) void append ()
 
    _____________________________________________________________________________________________________________
    
    



    STRING LITERAL LENGTH       (lines 88-95)
    COMPARE STRINGS             (lines 98-139)

    1) strstd::strlength size_t (const char*)                                           lines 90-96

       <size_t S, typename T>
    2) strstd::strcompare int (const char* , T (&array)[S] (size must be r value))      lines 99-111

    3) strstd::strcompare int (const char* , char*)                                     lines 114-124

    4) strstd::strcompare int (const char*, strstd::string, int)                        lines 127-137

    _______________________________________________________________________________________________________________
    1) get size of string literal, does not include null. return type, unsigned int  size_t
    2) compare string literal to array. template pass in unsighned int for size, and array data type. cannot pass in
       cannot pass in a runtime only value for size, must be known at compile time
    3) compare string literal to array. pass in pointer to array
    4) compare string literal with a string object. (compare to, object to compare with, index where begin search)
       return type int, returns 0, if comparision is true. return -1, if comparision false
*/

namespace strstd{

size_t strlength (const char*);                            // declare to use in class and other members

// very redumentary string class, class container will only allocate the space needed to append with or construct with
class string {

    char* m_data = nullptr;                                   // char pointer for object/container
    size_t m_length;                                          //  size without null char
    size_t m_length_null;                                     //  size with null char
    
// cd_length is number of char to store
// note, although the sizeof char is 1, still included sizeof() for good practice
    
    void alloc (size_t cd_length) {                                 // alocate more memory, by number of char, not in terms of bytes
        
        char* mem_block = static_cast<char*>(::operator new (sizeof(char) * (cd_length + m_length)));  // cd_length = number of char to alloc
        auto mem_block2 = (char*) ::operator new (m_length * sizeof(char*));
        
        
        for (size_t i = 0; i < m_length; i++) {mem_block[i] = std::move(m_data[i]);}          // copy over current char to new_block
        
        if (m_data != nullptr) {operator delete (m_data, sizeof(char) * m_length);}                  // deallocate old allocation

        m_data = mem_block;                                        // assign block of memory with space allocated by amount of char, to m_data
        m_length = (cd_length + m_length);                         // change length of m_data to the length of new allocation mem_block
    }
    
    void alloc_null (size_t cd_length) {                     // allocate more memory, also include a null char
        
        char* mem_block = static_cast<char*>(::operator new ((cd_length + m_length + 1) * sizeof(char)));
        
        for (size_t i = 0; i < m_length; i++) { if (m_data[i] != '\n') {mem_block[i] = std::move(m_data[i]);}} // !warning does not copy \n
        
        if (m_data != nullptr) {operator delete (m_data, sizeof(char) * m_length);}                  // deallcate old allocation
        
        m_data = mem_block;
        m_length = (cd_length + m_length);                                          // update length without null char
        m_length_null = (cd_length + m_length +1);                                  // update length including null char
    }
    
    void realloc (size_t cd_length) {                       // shrink container
        
//        operator delete ();                                          // deallocate segment of container
        
        m_length = m_length - cd_length;                    // update the length of the container
    }
    

public:
    
    string () = default;

    string (const char* string) {
        
        strlength(string);                          // returns length of string in terms of numbers of char, not including the null character
        // alloc new memory
        // assign the string literal chars to each memory spot, take r value and assign to l value
        // add a null char to the string
        
        
        
    }                           // constructor for instantiation of a string literal

    const char& operator[] (size_t index) const { return *(m_data + index);}             // index return as const

    size_t length () const { return (m_length);}                          // return number of elments, no null char
    size_t abslength () const { return (m_length+1);}                     // return number of elements, including null
    
    char& operator[] (size_t index) {return *(m_data + index);}           // warning! can be used to change m_data
    
    // index operator to return a const char
    // const index operator to return a const char

    void setstring (const char* string){

        m_length = strlength(string);                        // get the size of passed string w/o null char
        m_data = new char[m_length];                         // allocate new memory by passing in size of space needed

        memcpy(m_data, string, m_length);         // copy (destination, source, size (number of bytes))

        // move semantics

    }
    
    void append (const char* append_data) {
        
// alloc more memory
        
        size_t cd_length = strlength(append_data);                               // length of data we append, no null character included
        alloc(cd_length+1);                                                      // +1 to include null char
        
// move/copy append_data into container
        
        
        
    }

    void print () {

        for (size_t i = 0; i < m_length; i++) { std::cout << m_data[i]; }     // does not print null char
        std::cout << m_data[0] << m_data[1];
    }

    char* sequence (int i, size_t length) {             // to get a section of string and return new array ptr

        char *m_store = new char[length];

        memcpy(m_store,m_data,(length * sizeof(char)));

        return m_store;                      // move char* to array
    }
    
    // append member
    
    // alloc for string literal to apppend 
    

}; // end of class


size_t strlength (const char* string) {                         // get size of a string literal, exclude null char

    size_t m_length = 0;

    while (*string != '\0')  { ++ m_length; ++ string; }
    return m_length;
}


template <size_t S,typename T>
int strcompare (const char* string, T (&array)[S]) {             // compare string literal to array

    size_t length_literal = strlength(string);
    if (length_literal != (S-1)) return -1;                     // if sizes do not match
    strstd::string literal_cont(string);                        // store in object

    for (size_t i = 0; i < length_literal; i++) {                       // itterate over string literal

        if (literal_cont[i] == array[i]) {} else return -1;
    }
    return 0;
}


int strcompare (const char* string, const char* string1) {          // compare string literal to literal

    size_t length_literal = strlength(string);
    strstd::string literal_cont(string);                        // store in object
    strstd::string literal1_cont (string1);               // store in object

    for (size_t i = 0; i < length_literal; i++) {                       // itterate over string literal

        if (literal_cont[i] == literal1_cont[i]) {} else return -1;
    }
    return 0;
}


int strcompare (const char* string, strstd::string look, size_t begin) {   // string literal to string object

    size_t length_literal = strlength(string);
    strstd::string literal_cont(string);                                // store literal in object

    for (size_t i = 0; i < length_literal; i++) {                       // itterate over string literal

        if (literal_cont[i] == look[begin+i]) {} else return -1;
    }
    return 0;
}








}   // end of namespace




// list to improve on

// use move sematics when passing in string literal, and for locating member(passing in literal)
// update destructor
// add append to string
// add emplace back 
// update constructor to a , copy and assignment constructor and move constructor
// add more useful methods
// need to be able to use refernces for constructing
