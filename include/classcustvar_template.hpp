#include <iostream>

// notes, this library will contain class and members and templates that are not used in every project
// this is my library i will use and expand in projects to learn

/*
 * contents
 *
 * class template for array like container, container (0)
 *
 *
 *
 * class for project
 *
 *
 * class template to read stream buffer and store into container (0)
 *
 *
 */

// mem adress 7f = in stack on 64bit system


namespace cstd {


// fixed container
template<typename T, int S>                  // <size of container, data type>
class mydataT {

    T m_fixedcont[S];                           // stack array

public:

    mydataT() {};                            // constructor

    int size() const {return S;}             // returns size as an int

    T& operator[](int index) {return m_fixedcont[index];}           // return refernce
    const T& operator[](int index) const {return m_fixedcont[index];}           // for use if array is const

    T* arraypointer () { return m_fixedcont; }                                  // return pointer to array
};

//template<int S, typename T> void mydataT<S,T>::getsay(){}



// dynamic container
template <typename T>
class contdynamic {

    T* cd_data = nullptr;

protected:
    size_t  cd_size = 0;                // used amount of container
    size_t cd_capacity = 0;             // capacity of container

private:

    void Calloc (size_t newCapacity){                // allocates memory, called everytime need or want more memory

        T* newBlock = (T*)::operator new (newCapacity* sizeof(T));      // --allocate a array, to store moved data

        if (newCapacity < cd_size) cd_size = newCapacity;       // for reducing container size to a new capacity

        for (size_t i = 0; i < cd_size; i++) {                  // to allocate more memory to increase container size

            newBlock[i] = std::move(cd_data[i]);            // move data from
        }

        for (size_t i = 0; i < cd_size; i++) {                  // for deallocating memory (shrink container)

            cd_data[i].~T();                                // clear data without changing container size
        }

        T::operator delete(cd_data, cd_capacity * sizeof(T));        // delete operator on object type T
        delete[] cd_data;                                 // delete from where we moved data from
        cd_data = newBlock;                               // assign pointer to block of meory where data was moved to
        cd_capacity = newCapacity;                        // assign a capacity based on block of memory we moved data to
    }

public:

    contdynamic() {Calloc(1);}                   // default constructor allocate for 2 slots

    virtual ~contdynamic() {                                        // destructor

        clear();                                                // clear the memory block
        T::operator delete(cd_data, cd_capacity * sizeof(T));    // instead of array delete, delete object type T
    }

    void append(const T& element) {

        if (cd_size >= cd_capacity){                         // to increase available container space

            Calloc(cd_capacity + cd_size / 2);   // allocate 1.5 times memory size
        }

        cd_data[cd_size] = element;                         // copy data to apped onto container and assign
        cd_size++;                                          // increment size
    }

    void append(const T&& element) {                         // to mvoe data must be rvalue to use move()

        if (cd_size >= cd_capacity){                         // to increase available container space

            Calloc(cd_capacity + cd_size / 2);   // allocate 1.5 times memory size
        }

        cd_data[cd_size] = std::move(element);              // move data to apped onto container and assign
        cd_size++;                                          // increment size
    }

    void popback() {                                      // to destruct and deallocate last element
        if (cd_size > 0) {                                  // only when container is bigger than zero
                                                            // to prevent segmentation error
            cd_size--;
            cd_data[cd_size].~T();                          // destruct array over size of array and not the capacity
        }                                                    // of the array, as some may not have data stored
    }

    void clear() {                                                    // to clear each element

        for (size_t i = 0; i < cd_size; i++) { cd_data[i].~T(); }     // itterate over container, destruct each element
        cd_size = 0;
    }

    size_t Size() const {return cd_size;}                         // return size of container

    const T& operator[](size_t index) const { return cd_data; }   // return data at index of container ,const version

    T& operator[](size_t index)  { return cd_data; }   // return data at index of container

};


// inherited class for use with fixed data type container
template <typename T>
class contblockfixed : contdynamic<T> {

public:

    void print (contblockfixed<T> object) {                 // to print contianer contents

        for (int i = 0; i < object.Size(); i++){

            std::cout << object[i];
        }
    }

    void storeblock (contblockfixed<T> mycont,std::string tempstring) {  // pass in the object and data we want to store

        for (char c:tempstring) {                           // itterate over string and copy over char to append method

            mycont.append(c);                               // should be using rvalue
        }
    }

    ~contblockfixed () {};                                      // destructor

}; // end of class



// inherited class to use with a variable data type container
// inherited class to pass into template arguemnt to define data type and move data from another container
class variable  : public contdynamic<variable*>{              // inherited class, to pass in as template arguemnt

public:

    void storeblock(variable,std::string);                 // store string into container using class as data type
    ~ variable() {};                                         // destructor
    void print () {

        std::cout << "test";
    }

}; // end of class


// inherited class for data to pass in to append if user defined data type container
template <typename T>                                       // generic allows, reuse class for multiple data types
class datapass  :   public variable {                      // if container requires a template as element

public:

    datapass(T) {}                                           // constructor using typename to pass in any data type
    ~ datapass() {};                                         // destructor

}; // end of class







//
//}
//
//
//namespace mystd{


//class contblock {
//
//    cstd::contdynamic<contblock*> my_data;                // contianer from our dynamic container class template
//
//public:
//
//    contblock() { };                                                  // constructor
//
//    void storeblock(std::string,contblock);                     // method decleration for storing
//
//    template <typename T,class C> int locate();                 // for locating in container
//
//    virtual ~contblock () {};
//};
//
//template <typename T>
//class custchar : public contblock {                             // for storing char
//
//    T character;
//
//    void custcharmehtod (T) {};
//
//};      // end of class


}   // end of name space




// add asserts for out of range indexing

// variatic templates (emplaceback)
// destructor


//try {
//    new allocation
//}   catch (std::bad_alloc& exc){
//
//
//}


// things to aks

// does a virtual destructor in an inherited class also destroy the child classes of it
// when that happens does
