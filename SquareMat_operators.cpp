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
// Power operator
SquareMat SquareMat::operator^(int power) const{
    if (power < 0) {
            throw std::invalid_argument("Negative power not supported");
        }
     if (power == 0) {
            // Return identity matrix
        SquareMat result(size);
    for (int i = 0; i < size; i++) {
            result.matrix[i][i] = 1.0;
        }
        return result;
    }
    if (power == 1){
        return *this;
    }
    // For higher powers, use repeated multiplication
    SquareMat result = *this;
      for (int i = 1; i < power; i++) {
            result = result * (*this);
        }
        return result;
    }
// Pre-increment operator
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] += 1.0;
        }
    }
        return *this;
    }
// Post-increment operator
SquareMat SquareMat::operator++(int) {
    SquareMat temp(*this);  // Create a copy
    ++(*this);              // Use pre-increment
    return temp;            // Return the copy (original value)
    }

// Pre-decrement operator
SquareMat& SquareMat:: operator--(){
for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] -= 1.0;
        }
    }
        return *this;
    }
// Post-decrement operator
SquareMat SquareMat::operator--(int) {
    SquareMat temp(*this);  // Create a copy
    --(*this);              // Use pre-decrement
    return temp;            // Return the copy (original value)
    }
// Transpose operator
SquareMat SquareMat::operator~() const {
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[j][i];
            }
        }
        return result;
    }

    // Equality operator
    bool SquareMat::operator==(const SquareMat& other) const {
        return this->sum() == other.sum();
    }

    // Inequality operator
    bool SquareMat::operator!=(const SquareMat& other) const {
        return !(*this == other);
    }

    // Less than operator
    bool SquareMat::operator<(const SquareMat& other) const {
        return this->sum() < other.sum();
    }

    // Greater than operator
    bool SquareMat::operator>(const SquareMat& other) const {
        return this->sum() > other.sum();
    }

    // Less than or equal operator
    bool SquareMat::operator<=(const SquareMat& other) const {
        return this->sum() <= other.sum();
    }
    
    // Greater than or equal operator
    bool SquareMat::operator>=(const SquareMat& other) const {
        return this->sum() >= other.sum();
    }
    
    // Determinant operator
    double SquareMat::operator!() const{
        return calculateDeterminant(matrix,size);


    }

    // Helper method to calculate determinant recursively
    double SquareMat:: calculateDeterminant(double** matrix, int size) const{
    // Base case for 1x1 matrix
    if (size == 1){
        return matrix[0][0];
        }
    
    // Base case for 2x2 matrix
    if (size == 2){
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
    double det = 0;
    double sign = 1;
    
    // Create a submatrix for cofactor calculation
    double** subMatrix = new double*[size-1];
    for (int i = 0; i < size-1; i++) {
            subMatrix[i] = new double[size-1];
        }
     // Iterate through the first row to calculate cofactors
        for (int col = 0; col < size; col++) {
            // Fill the submatrix
            for (int i = 1; i < size; i++) {
                int subCol = 0;
                for (int j = 0; j < size; j++) {
                    if (j == col) continue;
                    subMatrix[i-1][subCol++] = matrix[i][j];
                }
            }
            
            // Add or subtract the cofactor
            det += sign * matrix[0][col] * calculateDeterminant(subMatrix, size-1);
            sign = -sign;
        }
    // Free memory
        for (int i = 0; i < size-1; i++) {
            delete[] subMatrix[i];
        }
        delete[] subMatrix;
        
        return det;
    }
    // Compound addition
    SquareMat& SquareMat:: operator+=(const SquareMat& other){
        validateSameSize(other);
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }
    // Compound subtraction
    SquareMat& SquareMat:: operator-=(const SquareMat& other){
        validateSameSize(other);
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                matrix[i][j] -= other.matrix[i][j];
            }
        }
        return *this;
    }
    // Compound matrix multiplication
    SquareMat& SquareMat:: operator*=(const SquareMat& other){

    *this = *this * other;
    return *this;

    }
    // Compound scalar multiplication
    SquareMat& SquareMat:: operator*=(double scalar){
        
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                matrix[i][j] *= scalar;
            }
        }
        return *this;

    }
    // Compound division by scalar
    SquareMat& SquareMat:: operator/=(double scalar){
    if (scalar == 0 ){
        throw std::invalid_argument("Division by zero");
        }
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                matrix[i][j] /= scalar;
            }
        }
        return *this; 
    }

    // Compound element-wise multiplication
    SquareMat& SquareMat:: operator%=(const SquareMat& other){
     validateSameSize(other);
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                matrix[i][j] *= other.matrix[i][j];
            }
        }
        return *this;
    }

    // Compound modulo with scalar
    SquareMat& SquareMat::operator%=(int scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Modulo zero");
        }
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = std::fmod(matrix[i][j], scalar);
            }
        }
        return *this;
    }
    // Output stream operator
    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.size; i++) {
            for (int j = 0; j < mat.size; j++) {
                os << std::setw(10) << std::fixed << std::setprecision(2) << mat.matrix[i][j];
                if (j < mat.size - 1) {
                    os << " ";
                }
            }
            if (i < mat.size - 1) {
                os << std::endl;
            }
        }
        return os;
    }

        

}

       


