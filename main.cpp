#include <iostream>
#include "my_string.h"

int main(){
    /*
    CU::string nume = {"State Lucian Vladut de la facultatea de matematica"};
    std:: cout << "nume : " << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity :" << nume.capacity() << std::endl; 

    std::cout <<"------------" << std::endl;

    nume = "ade";
    std:: cout << "nume : " << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity:" << nume.capacity() << std::endl; 

    std::cout <<"------------" << std::endl;

    nume.clear();
    std:: cout << "nume : " << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity:" << nume.capacity() << std::endl; 



    std::cout <<"------------" << std::endl;
    nume += "Ade e bou" ;

    std:: cout << "nume : " << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity:" << nume.capacity() << std::endl;

    std::cout <<"------------" << std::endl;

    nume = "Ade e bou";
    std:: cout << "nume : " << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity:" << nume.capacity() << std::endl; 

    std::cout <<"------------" << std::endl;

    nume.erase(0,4);
     std:: cout << "nume :" << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity:" << nume.capacity() << std::endl; */

   /* CU::string nume = {"State Lucian Vladut de la facultatea de matematica"};
    std:: cout << "nume :" << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity:" << nume.capacity() << std::endl;

    nume.erase(7, 7);
    nume.shrink_to_fit();
    std:: cout << "nume :" << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity:" << nume.capacity() << std::endl*/

    /*
    CU::string ok = {"e bou"};
    
    //ok.insert(0, "Ade ");
   // std:: cout << "ok :" << ok << std::endl;
    //ok.insert(5, ", Ade");
    //std:: cout << "ok :" << ok << std::endl;
    ok.insert(2, "Adeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee ");
    std:: cout << "ok :" << ok << std::endl;
    std::cout << "size :" << ok.size() << std::endl; 
    std::cout << "capacity:" << ok.capacity() << std::endl;
    */
    
   /* CU::string str {"Ade"};

    std::cout << str.compare("Ade") << std::endl; //0
    std::cout << str.compare("ade") << std::endl; //-1
    std::cout << str.compare("Ace") << std::endl; //1
    std::cout << str.compare("Adee") << std::endl; //-1
    std::cout << str.compare("Ad") << std::endl; //1

    */

    //CU::string str {"Ade"};
    //std::cout << (str == "Ade") << std::endl;//1
    //std::cout << (str != "Ade") << std::endl;//0

    /*CU::string nume {"Ade"};
    nume.append('c', 15);
    std:: cout << "nume :" << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity:" << nume.capacity() << std::endl;*/

    CU::string nume;
    std::cout << "Numele este : ";
    std::cin >> nume;
    std:: cout << "nume :" << nume << std::endl;
    std::cout << "size :" << nume.size() << std::endl; 
    std::cout << "capacity:" << nume.capacity() << std::endl;



    return 0;
}