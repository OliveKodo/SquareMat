//tomergal40@gmail.com
#include "SquareMat.hpp"
#include <stdexcept>
#include <iomanip>
#include <cmath>

namespace Matrix{
// Addition operator
SquareMat SquareMat::operator+(const SquareMat& other) const{
        validateSameSize(other);
        
    SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }
// Subtraction operator
SquareMat SquareMat:: operator-(const SquareMat& other) const {
    validateSameSize(other);

    SquareMat result(size);
    for(int i = 0; i < size; i++){
        for (int j = 0 ; j < size ; j++){
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];

            } 
        }
    return result;
    }

// Unary minus operator
SquareMat SquareMat:: operator-() const{
     SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = -matrix[i][j];
            }
        }
        return result;
    }   
// Matrix multiplication
SquareMat SquareMat:: operator*(const SquareMat& other) const{
    validateSameSize(other);

    SquareMat result(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.matrix[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;

    }
 // Scalar multiplication (matrix * scalar)
SquareMat SquareMat:: operator*(double scalar)const{
    SquareMat result(size);
     for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] * scalar;
            }
        }
        return result;
    }
 // Scalar multiplication (scalar * matrix)
SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;  // Reuse the matrix * scalar operator
    }

// Element-wise multiplication
SquareMat SquareMat::operator%(const SquareMat& other) const{
    validateSameSize(other);
    SquareMat result(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.matrix[i][j] = matrix[i][j] * other.matrix[i][j];
            }
        }
        return result;

    }
// Modulo with scalar
SquareMat SquareMat:: operator%(int scalar) const{
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero");
        }
    SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = std::fmod(matrix[i][j],scalar);
            }
        }
    return result;
    } 
// Division by scalar  
SquareMat SquareMat:: operator/(double scalar)const{
    if (scalar == 0 ){
        throw std::invalid_argument("Division by zero");
        }
     SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] / scalar;
            }
        }
    return result;
    }

}    


