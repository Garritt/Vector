/**
 * @file Vector.h
 * @author Garritt Baker
 * @date 2024-09-27
 * @brief Implementing a simple version of a Vector class to access the vector's contents and grow as needed.
 * 
 * 
 */



class Vector {
private:
    int *vec_ptr;
    int vec_size;
    int vec_capacity;

public:
    

/**
 * Default Constructor
 *
 * @pre 
 * @post 
 * 
 */
    Vector() : vec_ptr(nullptr), vec_size(0), vec_capacity(0) {}
    

/**
 * Copies Constructor
 *
 * @param const Vector &other 
 * @pre 
 * @post 
 * 
 */
    Vector(const Vector &other) : vec_size(other.vec_size), vec_capacity(other.vec_capacity) {
        vec_ptr = new int[vec_capacity];
        for (int i = 0; i < vec_size; ++i) {
            vec_ptr[i] = other.vec_ptr[i];
        }
    }
    

/**
 * Deconstructor
 *
 * @pre 
 * @post 
 * 
 */
    ~Vector() {
        delete[] vec_ptr;
    }
    

/**
 * Assignment Operator; Initializes a dynamic and copies data to the new array
 *
 * @param const Vector &other 
 * @pre 
 * @return Vector& 
 * @post 
 * 
 */
    Vector& operator=(const Vector &other) {
        if (this != &other) {
            delete[] vec_ptr;
            vec_size = other.vec_size;
            vec_capacity = other.vec_capacity;
            vec_ptr = new int[vec_capacity];
            for (int i = 0; i < vec_size; ++i) {
                vec_ptr[i] = other.vec_ptr[i];
            }
        }
        return *this;
    }
    

/**
 * Returns the number of elements in the vector
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
    int size() const {
        return vec_size;
    }
    

/**
 * Returns the storage capacity allocated to the vector
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
    int capacity() const {
        return vec_capacity;
    }
    

/**
 * Stores element at the end of the vector
 *
 * @param int element 
 * @pre 
 * @return void 
 * @post 
 * 
 */
    void push_back(int element) {
        if (vec_size == vec_capacity) {
            reserve(vec_capacity == 0 ? 1 : 2 * vec_capacity);
        }
        vec_ptr[vec_size++] = element;
    }
    

/**
 * Holds the vector capacity to contain n elements
 *
 * @param int n 
 * @pre 
 * @return void 
 * @post 
 * 
 */
    void reserve(int n) {
        if (n > vec_capacity) {
            int *new_ptr = new int[n];
            for (int i = 0; i < vec_size; ++i) {
                new_ptr[i] = vec_ptr[i];
            }
            delete[] vec_ptr;
            vec_ptr = new_ptr;
            vec_capacity = n;
        }
    }
    

/**
 * Returns a reference to the element at positoin index
 *
 * @param unsigned int index 
 * @pre 
 * @return int& 
 * @post 
 * 
 */
    int& operator[](unsigned int index) {
        return vec_ptr[index];
    }
};
