// tomergal40@gmail.com
#pragma once 
#include <iostream>

namespace Matrix {
    class SquareMat{
    private:
        double** matrix;    // 2D array for storing the matrix
        int size;           // Size of the square matrix (n x n)

    public:
    // Constructors and Destructor
        SquareMat(int size);                   // Create empty matrix of given size
        SquareMat(double** data, int size);    // Create from existing 2D array
        SquareMat(const SquareMat& other);     // Copy constructor
        SquareMat(SquareMat&& other) noexcept; // Move constructor
        ~SquareMat();                          // Destructor
        
    // Assignment operators
        SquareMat& operator=(const SquareMat& other);     // Copy assignment
        SquareMat& operator=(SquareMat&& other) noexcept; // Move assignment
        
    
    // Basic arithmetic operators
        SquareMat operator+(const SquareMat& other) const;
        SquareMat operator-(const SquareMat& other) const;
        SquareMat operator-() const;  // Unary minus
        SquareMat operator*(const SquareMat& other) const;
        SquareMat operator*(double scalar) const;
        friend SquareMat operator*(double scalar, const SquareMat& mat);
   


    // Element-wise operations
        SquareMat operator%(const SquareMat& other) const;  // Element-wise multiplication
        SquareMat operator%(int scalar) const;              // Modulo with scalar
        SquareMat operator/(double scalar) const;           // Division by scalar
        
    // Power operator
        SquareMat operator^(int power) const;
    
    
    // Increment/Decrement
        SquareMat& operator++();    // Pre-increment
        SquareMat operator++(int);  // Post-increment
        SquareMat& operator--();    // Pre-decrement
        SquareMat operator--(int);  // Post-decrement
        
    // Transpose
        SquareMat operator~() const;
    
    // Access operators
        double* operator[](int row);
        const double* operator[](int row) const;
        
    // Comparison operators
        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;
        bool operator<(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;
        
    // Determinant
        double operator!() const;
        
    // Compound assignment operators
        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);
        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator*=(double scalar);
        SquareMat& operator/=(double scalar);
        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator%=(int scalar);
    
    // Output operator
        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
        
    // Helper methods
        int getSize() const;
        double sum() const;  // Sum of all elements

    private:
    // Helper methods for internal use
        void validateSameSize(const SquareMat& other) const;
        double calculateDeterminant(double** matrix, int size) const;


    };
}
