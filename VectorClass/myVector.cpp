#include "vector"

template <typename T>
class myVector{

    T* m_data;
    size_t m_size;
    size_t m_capacity;

public:
    myVector() : m_data(nullptr), m_size(0), m_capacity(0){}

    myVector(int p_size){
        m_data = new T[p_size];

        for(size_t i = 0; i < p_size; ++i){
            m_data[i] = T(); //Default value of T
        }
        m_size = p_size;
        m_capacity = p_size;
    }

    ~myVector()
    {
        delete[] m_data;
        m_size = m_capacity = 0;
    }
    //copy constructor
    myVector(const myVector<T>& obj) : m_size(obj.m_size), m_capacity(obj.m_capacity)
    {
        m_data = new T[m_capacity];

        for(size_t idx = 0 ; idx< m_size; idx++)
        {
            m_data[idx] = obj.m_data[idx];
        }
    }
    //move constructor
    myVector(myVector<T>&& obj) : m_data(obj.m_data), m_size(obj.m_size), m_capacity(obj.m_capacity)
    {
        obj.m_data = nullptr;
        obj.m_size = obj.m_capacity = 0;
    }

    //copy assignment 
    myVector<T>& operator=(const myVector<T>& obj)
    {
        if(this == &obj)
        {
            return *this;
        }

        delete[] m_data;

        m_size = obj.m_size;
        m_capacity = obj.m_capacity;

        m_data = new T[m_capacity];

        for(size_t idx = 0 ; idx< m_size; idx++)
        {
            m_data[idx] = obj.m_data[idx];
        }
        return *this;
    }

    //move assignment
    myVector<T>& operator=(myVector<T>&& obj) : m_data(obj.m_data), m_size(obj.m_size), m_capacity(obj.m_capacity)
    {
        if(this == &obj)
        {
            return *this;
        }

        delete[] m_data;

        obj.m_data = nullptr;
        obj.m_capacity = obj.m_size = 0;

        return *this;
    }

};

int main()
{
    myVector<int> vec;
    int x;
}