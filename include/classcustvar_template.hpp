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

//template<int S, typename T> void mydataT<S,T>::getsay(){}



// dynamic container
template <typename T>
class contdynamic {
    
    T* cd_data = nullptr;               // pointer to contiguous memory block
    
    size_t  cd_size = 0;                // used amount of container
    size_t cd_capacity = 0;             // capacity of container
    
private:
            
    void Calloc (size_t newCapacity){                                                    // allocating and reallocating memeory
        
        T* newBlock = (T*)::operator new (newCapacity* sizeof(T));                      // allocate a block of memory
        
        if (newCapacity < cd_size) cd_size = newCapacity;                              // for reducing container size to a new capacity
        
        for (size_t i = 0; i < cd_size; i++) {newBlock[i] = std::move(cd_data[i]);}                 //move cd_data elements to newblock
        
        for (size_t i = 0; i < cd_size; i++) {cd_data[i].~T();}                         // call destructors for each element
        
        operator delete(cd_data, cd_capacity * sizeof(T));        // delete operator on object type T
        
//        delete[] cd_data;                                 // delete from where we moved data from
        cd_data = newBlock;                               // assign pointer to block of meory where data was moved to
        cd_capacity = newCapacity;                        // assign a capacity based on block of memory we moved data to
    }
    
public:
    
    contdynamic() {Calloc(0);}                   // default constructor allocate for 2 slots
    
    ~contdynamic() {                                        // destructor
        
        clear();                                                 // call destructer for typ T each elment
        operator delete(cd_data, cd_capacity * sizeof(T));    // deallocate each spot in memory
    }
    
    void append(const T& element) {
        
        if (cd_size >= cd_capacity){                         // to increase available container space
            
            Calloc(cd_capacity + cd_size / 2);                  // allocate 1.5 times memory size
        }
        std::cout << "appned T& called";
        
        cd_data[cd_size] = element;                         // copy data to apped onto container and assign
        cd_size++;                                          // increment size
    }
    
    void append(const T&& element) {                         // to mvoe data must be rvalue to use move()
        
        if (cd_size >= cd_capacity){                         // to increase available container space
            
            Calloc(cd_capacity + cd_size / 2);   // allocate 1.5 times memory size
        }
        std::cout << "append T&& called" << " element->" << element;
        
        cd_data[cd_size] = std::move(element);              // move data to apped onto container and assign
        cd_size++;                                          // increment size
    }
    
    void popback() {                                      // to destruct and deallocate last element
        if (cd_size > 0) {                                  // only when container is bigger than zero

            cd_size--;
            cd_data[cd_size].~T();                          // destruct array over size of array and not the capacity
        }                                                    // of the array, as some may not have data stored
        else std::cout << "WARNING ATTEMPT TO POP BACK A CONTAINER OF NO DATA FAILED\n";
    }
    
    void clear() {                                                    // to clear each element
        
        for (size_t i = 0; i < cd_size; i++) { cd_data[i].~T(); }     // itterate over container, destruct each element
        cd_size = 0;
    }
    
    void print () {
        
        for (size_t i = 0; i < cd_size; i++) std::cout << cd_data[i];
        
    }
    
    size_t length() const {return cd_size;}                                   // return size of container
    
    const size_t length() {return cd_size;}
    
    const size_t size() {return cd_size * sizeof(T);}
    
    const T& operator[](size_t index) const  { return cd_data[index % cd_size]; }   // return refernce to data at index, const function
    
    T& operator[] (size_t index)  { return cd_data[index % cd_size]; }   // return refrence to data at index
    
};

}
