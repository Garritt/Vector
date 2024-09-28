/* Author: Garritt Baker
   Date: 09/27/2024
   Assignment: Vector
*/



#include "Vector.h"
#include <iostream>

using namespace std;



/**
 * Prints the elements of a vector
 *
 * @param const Vector &vec 
 * @pre 
 * @return void 
 * @post 
 * 
 */
void print_vector(const Vector &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


/**
 * Main file
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
int main() {
  
    Vector vec;

    for (int i = 1; i <= 1000; ++i) {
        vec.push_back(i);
    }

    cout << "First 10 elements of the vector: ";
    for (int i = 0; i < 10; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    vec[0] = 1001;
    vec[1] = 1002;
    
    cout << "After modification, first 10 elements: ";
    for (int i = 0; i < 10; ++i) {
      cout << vec[i] << " ";
    }
    cout << endl;


/**
 * Uses copy constructor
 *
 * @param vec 
 * @pre 
 * @return Vector 
 * @post 
 * 
 */
    Vector vec_copy(vec);
    cout << "First 10 elements of the copied vector: ";
    print_vector(vec_copy);
    
/**
 * Uses assignment constructor
 * 
 * @param vec
 * @pre
 * @return Vector
 * @post
 *
 */
    Vector vec_assigned;
    vec_assigned = vec;
    cout << "First 10 elements of the assigned vector: ";
    print_vector(vec_assigned);
    
    return 0;
}
