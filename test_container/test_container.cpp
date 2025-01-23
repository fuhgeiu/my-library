#include <iostream>
#include "str.hpp"
#include "classcustvar_template.hpp"
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
    
    dynamic->print();
    
    
    // test heap allocated objects
    // t0-t9
    
    auto *class_test = new cstd::contdynamic<temp>;
    
    temp t1(1);
    temp t2(6);
    temp t3(9);
    temp t4(400);
    
    class_test->append(t1);
    class_test->append(t2);
    class_test->append(t3);
    class_test->append(t4);
    
    assert((*class_test)[0].ret_i() == 1);
    assert((*class_test)[1].ret_i() == 6);
    assert((*class_test)[2].ret_i() == 9);
    assert((*class_test)[3].ret_i() == 400);
    
    
    // test heap allocated object pointers
    // t_0 - t_1
    auto *class_testp = new cstd::contdynamic<temp*>;
    
    auto *t_0 = new temp(3);
    auto *t_1 = new temp(6);
    auto *t_2 = new temp(500);
    auto *t_3 = new temp(9);
    
    class_testp->append(t_0);
    class_testp->append(t_1);
    class_testp->append(t_2);
    class_testp->append(t_3);
    
    assert((*class_testp)[0]->ret_i() == 3);
    assert((*class_testp)[1]->ret_i() == 6);
    assert((*class_testp)[2]->ret_i() == 500);
    assert((*class_testp)[3]->ret_i() == 9);
    
    
    // stack allocated objects
    // t1_0 - t1_9
    cstd::contdynamic<temp> test5;
    
    temp t1_0(99);
    temp t1_1(30);
    temp t1_2(44);
    temp t1_3(33);
    
    test5.append(t1_0);
    test5.append(t1_1);
    test5.append(t1_2);
    test5.append(t1_3);
    
    assert(test5[0].ret_i() == 99);
    assert(test5[1].ret_i() == 30);
    assert(test5[2].ret_i() == 44);
    assert(test5[3].ret_i() == 33);
    
    
    // stack alocated object pointers
    // t2_0 - t2_9
    
    cstd::contdynamic<temp*> test6;
    
    auto *t2_0 = new temp(33);
    auto *t2_1 = new temp(34);
    auto *t2_2 = new temp(89);
    auto *t2_3 = new temp(29);
    
    test6.append(t2_0);
    test6.append(t2_1);
    test6.append(t2_2);
    test6.append(t2_3);
    
    assert(test6[0]->ret_i() == 33);
    assert(test6[1]->ret_i() == 34);
    assert(test6[2]->ret_i() == 89);
    assert(test6[3]->ret_i() == 29);
    
    
    
    
//    allocation will only happen in size_t, ie if use 3 for allocation, even tho the allocation is 3*1.5 = 4.5, the capacity will be 4
    
    
    
    
    
}

