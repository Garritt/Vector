#include "Vector.h"
#include <iostream>

using namespace std;


void print_vector(const Vector &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

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

    Vector vec_copy(vec);
    cout << "First 10 elements of the copied vector: ";
    print_vector(vec_copy);
    
    Vector vec_assigned;
    vec_assigned = vec;
    cout << "First 10 elements of the assigned vector: ";
    print_vector(vec_assigned);

    return 0;
}
