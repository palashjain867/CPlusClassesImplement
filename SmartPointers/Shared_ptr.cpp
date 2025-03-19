
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
    int* refCount;

    void decrementRefCount(){
        if(refCount){
            (*refCount)--;
            if(*refCount == 0){
                delete ptr;
                delete refCount;

                ptr = nullptr;
                refCount = nullptr;
            }
        }
    }

    public:
        mySharedPtr(T* inputPtr = nullptr)
        {
            if(inputPtr)
            {
                ptr = inputPtr;
                refCount = new int(1);
            }
        }

        ~mySharedPtr()
        {
            decrementRefCount();
             
        }
        mySharedPtr(const mySharedPtr& other){
            ptr = other.ptr;
            refCount = other.refCount;

            if(refCount){
                (*refCount)++;
            }
        }

        mySharedPtr& operator=(const mySharedPtr& other){
            if(this != other){
                decrementRefCount();
                ptr = other.ptr;
                refCount = other.refCount;

                if(refCount){
                    (*refCount)++;
                }
            }
            return *this;
        }

        mySharedPtr(const mySharedPtr && other) : ptr(other.ptr),
                                                refCount(other.refCount)
        {
            other.ptr = nullptr;
            other.refCount = nullptr;
        }

        //why using noexcept
        mySharedPtr& operator=(mySharedPtr&& other){
            if(this != other){
                decrementRefCount(); //why we have not used in move constructor
                ptr = other.ptr;
                refCount = other.refCount;

                other.ptr = nullptr;
                other.refCount = nullptr;
            }
            return *this;
        }

        //Deference operator
        T& operator*() const{
            if(!ptr){
                throw std::runtime_error("Deferencing a null pointer");
            }
            return *ptr;
        }

        T* operator->() const{
            if(!ptr){
                throw std::runtime_error("Deferencing a null pointer");
            }
            return ptr;
        }
};


int main()
{
    return 0;
}
