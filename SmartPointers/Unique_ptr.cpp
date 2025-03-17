// Implement unique_ptr (Exclusive Ownership)
// 	• Define a template class UniquePtr<T>.
// 	• Use a raw pointer (T* ptr) to store the managed object.
// 	• Implement: 
// 		○ Constructor: Accepts a raw pointer.
// 		○ Destructor: Deletes the managed object.
// 		○ Move semantics: Implement move constructor and move assignment operator.
// 		○ Delete copy constructor and copy assignment to enforce unique ownership.
// Overload operator* and operator-> for object access.

template <typename T>
class myUniquePtr{

private:
    T* ptr;

public:
    myUniquePtr(T* ptr)
    {
        this->ptr = ptr;
    }
    
    ~myUniquePtr()
    {
        delete ptr;
    }

    myUniquePtr(myUniquePtr&& other){
        other.ptr = mull
    }


};
