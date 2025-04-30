// tomergal40@gmail.com
#include "SquareMat.hpp"
#include <stdexcept>

namespace Matrix {

// Constructor with size - creates an empty matrix filled with zeros
SquareMat::SquareMat(int size) {
        if (size <= 0) {
            throw std::invalid_argument("Matrix size must be positive");
        }
        this -> size = size;
    // Allocate memory for the matrix
        matrix = new double*[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new double[size];
            
        // Initialize all elements to 0
            for (int j = 0; j < size; j++) {
                matrix[i][j] = 0.0;
            }
        }
    }   
    // Constructor from existing 2D array
         SquareMat::SquareMat(double** data, int size) { 
        if (size <= 0) {
            throw std::invalid_argument("Matrix size must be positive");
        }
        if (data == nullptr) {
            throw std::invalid_argument("Input data cannot be null");
        } 
        this -> size = size;          
    // Allocate memory and copy data
        matrix = new double*[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; j++) {
                matrix[i][j] = data[i][j];
            }
        }
    }
    // Copy constructor
    SquareMat::SquareMat(const SquareMat& other) : size(other.size) {  
     // Allocate memory for the new matrix
        matrix = new double*[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new double[size];
            
            // Copy values from the source matrix
            for (int j = 0; j < size; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    // Move constructor
SquareMat::SquareMat(SquareMat&& other) noexcept : matrix(other.matrix), size(other.size) {
    // Take ownership of resources from other
    other.matrix = nullptr;
    other.size = 0;
    }

    SquareMat:: ~SquareMat(){
        // Free allocated memory
        if (matrix != nullptr) {
            for (int i = 0; i < size; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }    

    }
    // Copy assignment operator
    SquareMat& SquareMat:: operator=(const SquareMat& other){
        if(this != &other){ // Self-assignment check
        // Free existing memory
        for(int i=0; i < size ; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
        
        // Copy new data 
        size = other.size;
         matrix = new double*[size];
            for (int i = 0; i < size; i++) {
                matrix[i] = new double[size];
                for (int j = 0; j < size; j++) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }   
        return *this;
    }
        
    // Move assignment operator
    SquareMat& SquareMat::operator=(SquareMat&& other) noexcept {
   if (this != &other) {  // Self-assignment check
        // Free existing memory
        for (int i = 0; i < size; i++) {
            delete[] matrix[i];
            }
        delete[] matrix;

        // Move resources
        size = other.size;
        matrix = other.matrix;

        // Rest resources
        other.matrix = nullptr;
        other.size = 0;
        }
        return *this;
    }
    // Helper method to get matrix size
    int SquareMat:: getSize() const{
        return size;
    }

    // Helper method to calculate sum of all elements

    double SquareMat:: sum() const{
        double total = 0.0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                total += matrix[i][j];
            }
        }
        return total;
    }

    // Validation helper method
    void SquareMat::validateSameSize(const SquareMat& other) const{
        if (size != other.size){
            throw std::invalid_argument("Matrix sizes do not match");
        }
    }
    // Access operators
    double* SquareMat:: operator[](int row){
        if(row < 0 || row >= size){
            throw std::out_of_range("Row index out of bounds");
        }
        return matrix[row];
    }
    const double* SquareMat:: operator[](int row) const{
        if (row < 0 || row >= size) {
            throw std::out_of_range("Row index out of bounds");
        }
        return matrix[row];
    
    }


}