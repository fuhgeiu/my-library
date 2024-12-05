#include <iostream>
#include "str.hpp"
#include "classcustvar_template.hpp"
#include "mem_view.hpp"
#include <cassert>

class temp {
    
    int i;
    
    
public:
    
    temp() = default;
    
    temp (int I) : i(I) {}

    int& ret_i () {return i;}
};


int main () {
    
//test basic functions of the container
    
    auto *dynamic = new cstd::contdynamic<int>;

    assert(dynamic->cd_capacity == 3);                                  // test the default allocation amount 2*1.5
    
    dynamic->append(5);
    dynamic->append(6);
    dynamic->append(9);                                          // after this append, the container is full, will allocate
    
    assert((*dynamic)[0] == 5);
    assert((*dynamic)[1] == 6);
    assert((*dynamic)[2] == 9);

    assert(dynamic->cd_capacity == 3);

    dynamic->append(3);
    dynamic->append(4);
    dynamic->append(9);
    dynamic->append(1);
    dynamic->append(3);
    dynamic->append(4);
    dynamic->append(5);
    
    assert((*dynamic)[3] == 3);
    assert((*dynamic)[4] == 4);
    assert((*dynamic)[5] == 9);
    assert((*dynamic)[6] == 1);
    assert((*dynamic)[7] == 3);
    assert((*dynamic)[8] == 4);
    assert((*dynamic)[9] == 5);
  
    assert(dynamic->cd_capacity == 10);
    
    dynamic->print();
    
    std::cout << std::endl << std::endl;
    
    dynamic->popback();
    dynamic->popback();
    
//    assert((*dynamic)[8] == 4);
//    assert((*dynamic)[9] == 5);
    
    std::cout << std::endl << std::endl;
    
    dynamic->print();
    
    std::cout << std::endl << std::endl;
    
    std::cout << dynamic->cd_size;
    
    std::cout << std::endl << std::endl << std::endl << std::endl;
    
    
    // test user defined data types
    
    auto *class_test = new cstd::contdynamic<temp>;
    
    temp t1(1);
    temp t2(6);
    
    class_test->append(t1);
    class_test->append(t2);
    
    assert((*class_test)[0].ret_i() == 1);
    assert((*class_test)[1].ret_i() == 6);
    
    
    auto *class_testp = new cstd::contdynamic<temp*>;
    
    auto *t3 = new temp(3);
    auto *t4 = new temp(6);
    
    class_testp->append(t3);
    class_testp->append(t4);
    
    assert((*class_testp)[0]->ret_i() == 3);
    assert((*class_testp)[1]->ret_i() == 6);
    
    
//    allocation will only happen in size_t, ie if use 3 for allocation, even tho the allocation is 3*1.5 = 4.5, the capacity will be 4
    
    
    
    
    
}

