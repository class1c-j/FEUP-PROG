 #include <iostream>

/*
 
   Suppose you didn't have class vector from the STL. Define and implement
   a template class, Vector, that emulates the functioning of class vector
   from the STL. Your class Vector, defined below, must only implement a
   limited set of functionalities; the functionality of the methods is the
   same as in vector (from the STL). The memory for the elements of Vector
   must be allocated dinamically.
   Hints: use function malloc() for dynamic memory allocation;
   to implement method push_back() investigate the use of function
   realloc() to increase the space allocated for the buffer
   
*/

template<typename T>
class Vector {
public:
    Vector();
    explicit Vector(unsigned int size);
    Vector(unsigned int size, const T &initial);
    Vector(const Vector<T> &v);
    ~Vector();
    size_t size() const;
    bool empty() const;
    T & front();
    T & back();
    T & at(size_t index);
    void push_back(const T & value);
    void pop_back();
    void clear();

private:
    T * buffer;
    size_t bufferSize;
};


template<typename T>
Vector<T>::Vector() = default;

template<typename T>
Vector<T>::Vector(unsigned int size) {
    buffer = (T *) malloc(size * sizeof(T));
    bufferSize = size;
}

template<typename T>
Vector<T>::Vector(unsigned int size, const T &initial) {
    buffer = (T *) malloc(size * sizeof(T));
    bufferSize = size;
    for (int i = 0; i < size; i ++) {
        buffer[i] = initial;
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T> &v) {
    buffer = (T *) malloc(v.size() * sizeof(T));
    bufferSize = v.size();
    for (int i = 0; i < v.size(); i ++) {
        buffer[i] = v.buffer[i];
    }
}

template<typename T>
Vector<T>::~Vector() {
    free(buffer);
    bufferSize = 0;
}

template<typename T>
size_t Vector<T>::size() const {
    return bufferSize;
}

template<typename T>
bool Vector<T>::empty() const {
    return bufferSize == 0;
}

template<typename T>
T &Vector<T>::front() {
    return buffer[0];
}

template<typename T>
T &Vector<T>::back() {
    return buffer[bufferSize-1];
}

template<typename T>
T &Vector<T>::at(size_t index) {
    return buffer[index];
}

template<typename T>
void Vector<T>::push_back(const T &value) {
    T* temporaryBigger = (T *)  realloc(buffer, (bufferSize + 1) * sizeof(T));
    buffer = temporaryBigger;
    bufferSize ++;
    buffer[bufferSize - 1] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    T* temporarySmaller = (T *) malloc((bufferSize - 1) * sizeof(T));
    for (int i = 0; i < bufferSize - 1; i ++) {
        temporarySmaller[i] = buffer[i];
    }
    free(buffer);
    buffer = temporarySmaller;
    bufferSize --;
}

template<typename T>
void Vector<T>::clear() {
    free(buffer);
    buffer = nullptr;
    bufferSize = 0;
}

/*
  
   In the vector class of the STL, the reallocation of memory is not done
   every time a new element is pushed back;
   instead, it is allocated in new chunks. The capacity of a vector tells
   us how many elements the vector could hold before it must allocate more
   space. Modify the definition and implementation of the class methods
   in order to include a new attribute bufferCapacity and two new methods:
   capacity() that tells the current capacity of the Vector object, and 
   reserve() that requests that the vector capacity be at least enough to
   contain n elements, where n is a parameter of the method.
   Before doing your implementation,try to infer how the capacity of a
   vector is increased in the STL;
   for that, start with an empty STL vector object, make a lot of push backs,
   and determine its capacity after each one of the push backs. 
    
*/

template<typename T>
class Vector {
public:
    Vector();
    explicit Vector(unsigned int size);
    Vector(unsigned int size, const T &initial);
    Vector(const Vector<T> &v);
    ~Vector();
    size_t size() const;
    bool empty() const;
    T & front();
    T & back();
    T & at(size_t index);
    void push_back(const T & value);
    void pop_back();
    void clear();
    void reserve(size_t n);
    size_t capacity();

private:
    T * buffer{};
    size_t bufferSize{};
    size_t bufferCapacity{};
};


template<typename T>
Vector<T>::Vector() {
    buffer = (T *) malloc(0);
    bufferSize = 0;
    bufferCapacity = 0;
}

template<typename T>
Vector<T>::Vector(unsigned int size) {
    buffer = (T *) malloc(size * sizeof(T));
    bufferSize = size;
    bufferCapacity = size;
}

template<typename T>
Vector<T>::Vector(unsigned int size, const T &initial) {
    buffer = (T *) malloc(size * sizeof(T));
    bufferSize = size;
    bufferCapacity = size;
    for (int i = 0; i < size; i ++) {
        buffer[i] = initial;
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T> &v) {
    buffer = (T *) malloc(v.size() * sizeof(T));
    bufferSize = v.size();
    bufferCapacity = v.capacity();
    for (int i = 0; i < v.size(); i ++) {
        buffer[i] = v.buffer[i];
    }
}

template<typename T>
Vector<T>::~Vector() {
    free(buffer);
    bufferSize = 0;
}

template<typename T>
size_t Vector<T>::size() const {
    return bufferSize;
}

template<typename T>
bool Vector<T>::empty() const {
    return bufferSize == 0;
}

template<typename T>
T &Vector<T>::front() {
    return buffer[0];
}

template<typename T>
T &Vector<T>::back() {
    return buffer[bufferSize-1];
}

template<typename T>
T &Vector<T>::at(size_t index) {
    if (index < bufferSize) return buffer[index];
    else throw std::out_of_range("Index out of vector's range");
}

template<typename T>
void Vector<T>::push_back(const T &value) {

    if (bufferCapacity == 0) {  // special case because the capacity doesn't double
        buffer = (T *) malloc(sizeof(T));
        bufferCapacity = 1;
    } else if (bufferSize + 1 > bufferCapacity) {
        buffer = (T *) realloc(buffer, 2 * bufferCapacity * sizeof(T));
        bufferCapacity *= 2;
    }

    bufferSize ++;
    buffer[bufferSize - 1] = value;

}

template<typename T>
void Vector<T>::pop_back() {
    T* temporarySmaller = (T *) malloc((bufferSize - 1) * sizeof(T));
    for (int i = 0; i < bufferSize - 1; i ++) {
        temporarySmaller[i] = buffer[i];
    }
    free(buffer);
    buffer = temporarySmaller;
    bufferSize --;
}

template<typename T>
void Vector<T>::clear() {
    free(buffer);
    buffer = nullptr;
    bufferSize = 0;
    bufferCapacity = 0;
}

template<typename T>
size_t Vector<T>::capacity() {
    return bufferCapacity;
}

template<typename T>
void Vector<T>::reserve(size_t n) {
    bufferCapacity = n;
}


int main() {

    return 0;
}
