
// Implement shared_ptr (Reference Counting)
// 	• Define a template class SharedPtr<T>.
// 	• Use: 
// 		○ A raw pointer (T* ptr) for object storage.
// 		○ A reference counter (int* refCount) to track ownership.
// 	• Implement: 
// 		○ Constructor: Accepts a raw pointer and initializes refCount.
// 		○ Copy constructor: Increases refCount when copied.
// 		○ Destructor: Decreases refCount and deletes the object when refCount reaches zero.
// 		○ Move semantics: Move constructor and move assignment to transfer ownership.
// 		○ Overload operator* and operator->.

template <typename T>
class mySharedPtr{
    T* ptr;
    int* refCount {0};

    public:
        mySharedPtr(T* inputPtr) : ptr(inputPtr)
        {
            refCount++;
        }
};


int main()
{
    return 0;
}
