// tomergal40@gmail.com
#include "SquareMat.hpp"
#include <stdexcept>

namespace Matrix {

// Constructor with size - creates an empty matrix filled with zeros
SquareMat::SquareMat(int size) {
        if (size <= 0) {
            throw std::invalid_argument("Matrix size must be positive");
        }
        
    }  


}