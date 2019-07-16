// This class defines an element that is stored
// in the garbage collection information list.
//
template <class T>
class PtrDetails
{
  public:
    unsigned refcount; // current reference count
    T *memPtr;         // pointer to allocated memory
    /* isArray is true if memPtr points
to an allocated array. It is false
otherwise. */
    bool isArray; // true if pointing to array
    /* If memPtr is pointing to an allocated
array, then arraySize contains its size */
    unsigned arraySize; // size of array
    // Here, mPtr points to the allocated memory.
    // If this is an array, then size specifies
    // the size of the array.

    PtrDetails(T* _memPtr, unsigned _arraySize)
    {
        isArray = false;
        if(_arraySize > 0){
            isArray = true;
            arraySize = _arraySize;
        }
        // TODO: Implement PtrDetails
        memPtr = _memPtr;
    }
    
};
// Overloading operator== allows two class objects to be compared.
// This is needed by the STL list class.
template <class T>
bool operator==(const PtrDetails<T> &ob1,
                const PtrDetails<T> &ob2)
{
    // TODO: Implement operator==
     if(ob1.isArray != ob2.isArray){
        return false;
    }
    if(ob1.memPtr != ob2.memPtr){
        return false;
    }
    if(ob1.refcount != ob2.refcount){
        return false;
    }
    if(ob1.arraySize != ob2.arraySize){
        return false;
    }
    return true;
}