#include <iostream>


// memory viewer
// concept
//  takees pointers than dispalys there value in an orginized way
//
//  example
//      container of block of memory heap allocation
//
//  void display_block (const *(to first spot in memory block),size_t number of elments) {             only use with contiguous memory applictions
//
//      // itterate over block of memory and dispaly each derefernced pointer
//
//
// }
//
//
//
//

namespace memv {

struct memory_view {

    
template <typename T>
void display_block_mem_cont (const T* block_start, size_t elements) const {
    
    if (block_start == nullptr) std::cout << "error in valid memory spot found\n";
        else    for (size_t i = 0; i <elements; i++) std::cout << (block_start[i]);
        
}
    
    
};  // end of class memory_view

}  // end of namespace memv


