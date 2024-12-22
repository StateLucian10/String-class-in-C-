#include "my_string.h"

namespace CU
{
    string::string()
    {
        m_data = new char[m_capacity]{'\0'};
    }

    string::string(const char *data)
    {
        int size = std::strlen(data);
        m_size = size;
        m_capacity = (m_size + 1 > m_capacity) ? m_size + 1 : m_capacity; // if the string has less characters than 15 we initialize the capacity with the length of the cstring
        m_data = new char[m_capacity];
        std::strcpy(m_data, data);
    }

    string::string(const string &source)
    {
        m_size = source.m_size;
        m_capacity = source.m_capacity;
        m_data = new char[m_capacity]; // We want to do deep copy here.
        std::strcpy(m_data, source.m_data);
    }

    string::~string()
    {
        delete[] m_data;
        m_data = nullptr;
    }

    const char *string::c_str() const
    {
        return m_data;
    }

    void string::shrink_to_fit()
    {
        char *tmp = new char[m_size + 1];
        std::strcpy(tmp, m_data);
        delete[] m_data;
        m_data = tmp;
        m_capacity = m_size + 1;
    }

    unsigned int string::size() const
    {
        return m_size;
    }
    unsigned int string::capacity() const
    {
        return m_capacity;
    }

    bool string::empty()
    {
        return (m_size == 0) ? true : false;
    }

    void string::clear()
    {
        m_size = 0;
        delete[] m_data;
        m_data = new char[m_capacity]{'\0'}; // the capacity remains the same
    }

    string &string::erase(unsigned int index, unsigned int npos)
    {
        assert(index + npos <= m_size);
        unsigned int i{};

        while (i < npos)
        {
            for (unsigned j{index}; j < m_size; j++)
            {
                m_data[j] = m_data[j + 1];
            }
            i++;
            m_size--;
        }

        return (*this);
    }

    void string::append(const string &str)
    {
        (*this) += str;
    }

    void string::push_back(char c)
    {
        ++m_size;
        if (m_size + 1 > m_capacity)
        {
            m_capacity = m_size + 1;
            char *tmp = new char[m_capacity];
            if (m_data)
            {
                std::memcpy(tmp, m_data, m_size);
                delete[] m_data;
            }
            m_data = tmp;
        }

        m_data[m_size-1] = c;
        m_data[m_size] = '\0';
    }

    void string::append(char c, unsigned int count)
    {
        unsigned int aux = m_size;
        m_size += count;

        if (m_size + 1 >= m_capacity)
        {
            m_capacity = m_size + 1;
            char *tmp = new char[m_capacity];
            std::strcpy(tmp, m_data);
            delete[] m_data;
            m_data = tmp;
        }

        for (unsigned int i{aux}; i < m_size; i++)
        {
            m_data[i] = c;
        }

        m_data[m_size] = '\0';
    }

    string &string::insert(unsigned int index, const string &str)
    {
        assert(index >= 0 && index <= m_size);
        m_size += str.m_size;

        if (m_capacity <= m_size + 1)
        {
            m_capacity = m_size + 1;
            char *tmp = new char[m_capacity];
            std::strcpy(tmp, m_data);
            delete[] m_data;
            m_data = tmp;
        }

        unsigned int i{};

        while (i != str.m_size)
        {
            for (size_t j{m_size + 1}; j > index; j--)
            {
                m_data[j] = m_data[j - 1];
            }
            i++;
        }

        for (size_t j{}; j < str.m_size; j++)
        {
            m_data[index + j] = str.m_data[j];
        }
        return (*this);
    }

    int string::compare(const string &str) const
    {
        int flag = 0;
        unsigned int i{};
        unsigned int stop = (m_size < str.m_size) ? m_size : str.m_size;

        while (flag == 0 && i < stop)
        {
            if (m_data[i] < str.m_data[i])
            {
                flag = -1;
            }
            if (m_data[i] > str.m_data[i])
            {
                flag = 1;
            }
            i++;
        }

        if (flag == 0 && m_size != str.m_size)
        {
            flag = (m_size < str.m_size) ? -1 : 1;
        }

        return flag;
    }

    string &string::operator=(const string &right_operand)
    {
        if (this != &right_operand)
        {
            m_size = right_operand.m_size;
            m_capacity = right_operand.m_capacity;
            delete[] m_data;
            m_data = new char[m_capacity];
            std::strcpy(m_data, right_operand.m_data);
        }
        return *this;
    }

    char &string::operator[](unsigned int index)
    {
        assert(index >= 0 && index <= m_size);
        return m_data[index];
    }

    std::ostream &operator<<(std::ostream &out, const string &s)
    {
        out << s.m_data;
        return out;
    }

    std::istream &operator>>(std::istream &is, string &s)
    {
        s.clear();
        char c;
        while (is.get(c))
        {
            if(c == '\n')   break;
            s.push_back(c);
        }
        return is;
    }

    string operator+(const string &left, const string &right)
    {
        string tmp(left);
        tmp += right;
        return tmp;
    }

    string &operator+=(string &left, const string &right)
    {
        left.m_size += right.m_size;

        if (left.m_size + 1 >= left.m_capacity)
        {
            left.m_capacity = left.m_size + 1;
            delete[] left.m_data;
            left.m_data = new char[left.m_capacity]; // Alocate new space only if the capacity of the left string is not enough
        }

        std::strcat(left.m_data, right.m_data);
        return left;
    }

    bool operator==(const string &left, const string &right)
    {
        int tmp = left.compare(right);
        return (tmp == 0) ? true : false;
    }

    bool operator!=(const string &left, const string &right)
    {
        int tmp = left.compare(right);
        return (tmp == 0) ? false : true;
    }
}