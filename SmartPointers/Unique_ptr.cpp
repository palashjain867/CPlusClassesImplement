// Implement unique_ptr (Exclusive Ownership)
// 	• Define a template class UniquePtr<T>.
// 	• Use a raw pointer (T* ptr) to store the managed object.
// 	• Implement: 
// 		○ Constructor: Accepts a raw pointer.
// 		○ Destructor: Deletes the managed object.
// 		○ Move semantics: Implement move constructor and move assignment operator.
// 		○ Delete copy constructor and copy assignment to enforce unique ownership.
// Overload operator* and operator-> for object access.

#include <stdexcept>

template <typename T>
class myUniquePtr{

private:
    T* ptr;

public:
    explicit myUniquePtr(T* ptr)
    {
        this->ptr = ptr;
    }
    
    ~myUniquePtr()
    {
        delete ptr;
    }

    myUniquePtr(myUniquePtr&& other){
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    myUniquePtr& operator=(myUniquePtr&& other){
        if(this != &other){
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    myUniquePtr(const myUniquePtr& other) = delete;

    myUniquePtr& operator=(const myUniquePtr& other) = delete;

    T& operator*(){
        if(!ptr){
            throw std::runtime_error("Pointer is null");
        }
        return *ptr;
    }

    T& operator->(){
        if(!ptr){
            throw std::runtime_error("Pointer is null");
        }
        return ptr;
    }

};

int main(){

    myUniquePtr<int> ptr1(new int(50));
    myUniquePtr<int> ptr2(new int(100));
    // myUniquePtr<int> ptr3(ptr1);
    // ptr1 = ptr2; these 2 lines will not work as we have limited the implementation
    ptr1 = std::move(ptr2);
    return 0;
}