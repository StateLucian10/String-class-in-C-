#include <iostream>
#include "my_string.h"

int main(){

    CU::string name;
    std::cout << "Your name : ";
    std::cin >> name;
    std:: cout << "name :" << name << std::endl;
    std::cout << "size :" << name.size() << std::endl; 
    std::cout << "capacity:" << name.capacity() << std::endl;



    return 0;
}
