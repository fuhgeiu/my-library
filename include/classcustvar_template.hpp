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
    size_t m_length = S;
    
public:
    
    mydataT() {};                            // constructor
    
    int size() const {return S;}             // returns size as an int
    
    T& operator[](int index) {return m_fixedcont[index % S ];}           // return refernce
    const T& operator[](int index) const {return m_fixedcont[index % S];}           // for use if array is const
    
    T* arraypointer () { return m_fixedcont; }                                  // return pointer to array
};



// dynamic container
template <typename T>
struct contdynamic {
    
    T* cd_data = nullptr;
    
    size_t  cd_size = 0;
    size_t cd_capacity = 0;
    
private:
    
    void allocate (size_t newCapacity, size_t multiplier) {             // (to be allocated, multiplier) multiplier adjustable

        T* newblock = static_cast<T*>(::operator new ((newCapacity+cd_capacity) * sizeof(T) * multiplier));

        for (size_t i = 0; i < cd_size; i++) {newblock[i] = std::move(cd_data[i]);}         // move stuff to newblock

        for (size_t i = 0; i < cd_capacity; i++) {cd_data[i].~T();}                       // only when T is not an pointer

        operator delete(cd_data);                                               // deallocate the current block of data stored in container

        cd_data = newblock;                                                              // asign container to newly allcoated block
        cd_capacity = ((newCapacity+cd_capacity)*1.5);                                   // assign new lenght of newly allocated block
    }
    
    void allocate (size_t newCapacity) {                                    // (to be allocated)  multiplier is 1.5

        T* newblock = static_cast<T*>(::operator new ((newCapacity+cd_capacity) * sizeof(T) * 1.5));

        for (size_t i = 0; i < cd_size; i++) {(newblock[i]) = std::move(cd_data[i]);}

        for (size_t i = 0; i < cd_capacity; i++) {cd_data[i].~T();}                        // only when T is not an pointer

        operator delete(cd_data);                                              // deallocate the current block of data stored in container
        
        cd_data = newblock;                                             // asign container to newly allcoated block
        cd_capacity = ((newCapacity+cd_capacity)*1.5);                  // assign new lenght of newly allocated block
    }
    
    void allocate () {

        size_t newCapacity = 5;

        T* newblock = static_cast<T*>(::operator new ((newCapacity+cd_capacity) * sizeof(T) * 1.5));

        for (size_t i = 0; i < cd_size; i++) {(newblock[i]) = std::move(cd_data[i]);}

        for (size_t i = 0; i < cd_capacity; i++) {cd_data[i].~T();}                        // destruct current block of obejcts

        operator delete(cd_data);
        
        cd_data = newblock;
        cd_capacity = (newCapacity*1.5);
    }
    
    
public:
    
    contdynamic() {allocate(2);}                   // default constructor allocate 2*1.5
    
    ~contdynamic() {                                        // destructor

        for (size_t i = 0; i < cd_capacity; i++) {cd_data[i].~T();}                        // destruct current block of obejcts

        operator delete(cd_data);
    }
    
    void append(const T& element) {
        
        if (cd_size >= cd_capacity){                         // to increase available container space
            
            allocate(cd_size*3/2);
        }
        
        cd_data[cd_size] = element;                         // copy data to apped onto container and assign
        cd_size++;                                          // increment size
    }
    
    void append(const T&& element) {                         // to mvoe data must be rvalue to use move()
        
        if (cd_size >= cd_capacity){                         // to increase available container space
            
            allocate(cd_size*3/2);
        }
        
        cd_data[cd_size] = element;                         // copy data to apped onto container and assign
        cd_size++;                                          // increment size
    }
    
    void popback() { cd_data[cd_size-1].~T(); cd_size -= 1;}
    
    void print () {for (size_t i = 0; i < cd_size; i++) std::cout << cd_data[i];}
    
    const size_t length() const {return cd_size;}                                   // return size of container
    
    const size_t size() const {return cd_size * sizeof(T);}
    
    const T& operator[](size_t index) const {return cd_data[index % cd_size];}   // return const ref to index
    
    T& operator[] (size_t index)  {return cd_data[index % cd_size];}   // return refrence to data at index
    
};

}

/*  things to add
 
 add a stream operator overload
 
 add exception handling
 
 add peek
 
 change allocate funciton, it dosnt shrink currently
 
 
 
 
 
 add documentation
 
 */


