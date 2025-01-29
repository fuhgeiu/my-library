//
//  main.cpp
//  test_linked_container
//
//  Created by Alex Carnes on 1/29/25.
//

#include <iostream>
#include "singlelink.hpp"

class test {
    
    int x,y,z;
    
public:
    
    test (int x, int y, int z) : x(x) , y(y) , z(z) {}
    
    int ret_copy_x () {return x;}
    int ret_copy_y () {return y;}
    int ret_copy_z () {return z;}
    
    void print_values () const {std::cout << x << "," << y << "," << z << std::endl;}
    
};


typedef node_container::single::slist<const test*> const_container;

int main() {

    const_container container1;
    
    size_t length = 10;
    
    for (size_t i = 0; i < length; i++) {
        
        auto *Test = new const test(i, i+1, i+2);
        
        container1.add(Test);
    }
    
    for (size_t i; i < length; i++) {
        
        container1.ret_value_index(i)->print_values();
    }
    
    
    
    
    
    
    
    
}
