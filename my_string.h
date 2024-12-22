#pragma once
#include <iostream>
#include <cstring>
#include <cassert>

namespace CU{

class string{

	friend std::ostream& operator<< (std::ostream& out , const string& s);
        friend std::istream& operator>> (std::istream& is , string& s);
	friend string operator+(const string& left, const string& right);
	friend string& operator+=(string& left, const string& right);
    

	public : 
        //No arguments constructor
        string();
        //Constructor
        string(const char* data);

        //Copy constructor
        string(const string& source);
        
        //Destructor
        ~string();

        const char* c_str() const;

        void shrink_to_fit();

        unsigned int size() const;

        unsigned int capacity() const;

        bool empty();

        void clear();

        string& erase(unsigned int index, unsigned int npos);

        void append(const string& str);
        
        void append(char c, unsigned int count = 1);

        void push_back(char c);

        string& insert(unsigned int index, const string& str);

        int compare(const string& str) const;

        //Copy assignment operator
        string& operator=(const string& right_operand);

        //Index operator
        char& operator[](unsigned int index);

	private : 
                unsigned int m_size{0};
                unsigned int m_capacity {15};
                char * m_data{nullptr};
};
        
        bool operator==(const string& left , const string& right);
        bool operator!=(const string& left, const string& right);
}