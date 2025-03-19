// Implement weak_ptr (Non-Owning Reference)
// 	• Define WeakPtr<T> to hold a weak reference to SharedPtr<T>.
// 	• Store: 
// 		○ A pointer to the object (T* ptr).
// 		○ A pointer to refCount (without increasing it).
// 	• Implement: 
// 		○ Constructor: Accepts a SharedPtr<T>.
// 		○ Method expired(): Checks if the referenced object is still valid.
// Method lock(): Returns a SharedPtr<T> if the object is still alive.

#include <iostream>
#include "Shared_ptr.cpp"

template <typename T>
class myWeak_ptr
{
    T* ptr;
    int* refcount;

public:
    myWeak_ptr() : ptr(nullptr), refcount(nullptr) {}

    myWeak_ptr(const mySharedPtr<T>& isharedPtr){
        ptr = isharedPtr.ptr;
        refcount = isharedPtr.refCount;
    }

    bool expired() const {
        return refcount == nullptr || *refcount == 0;
    }

    mySharedPtr<T> lock() const{
        if(expired()){
            return mySharedPtr<T>();
        }

        return mySharedPtr<T>(ptr, refcount); 
    }
};