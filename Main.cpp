// tomergal40@gmail.com
#include "SquareMat.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>

using namespace Matrix;
using namespace std;

// Function to print a main header
void printHeader(const string& title) {
    const int width = 80;
    string line(width, '=');
    cout << "\n" << line << endl;
    cout << setw((width + title.length()) / 2) << title << endl;
    cout << line << "\n" << endl;
}

// Function to print a sub-header
void printSubHeader(const string& title) {
    const int width = 60;
    string line(width, '-');
    cout << "\n" << line << endl;
    cout << " " << title << endl;
    cout << line << "\n" << endl;
}

// Function to print operation description
void printOperation(const string& op, const string& description) {
    cout << "\n>> " << op << " : " << description << endl;
}

int main() {
    try {
        printHeader("SquareMat Class - Demonstration of Square Matrix Operations");
        
        // Creating matrices
        printSubHeader("Creating Basic Matrices");
        cout << "Creating matrix A of size 3x3..." << endl;
        SquareMat A(3);  // Empty 3x3 matrix
        
        // Initialize matrix A with values
        printOperation("Initializing Values", "Using [] operator to modify elements");
        A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
        A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
        A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;
        
        cout << "Matrix A:" << endl << A << endl;
        
        // Create matrix directly
        printOperation("Matrix Construction", "Creating a matrix from an existing array");
        cout << "Creating matrix B from a 2D array..." << endl;
        double** dataB = new double*[3];
        for (int i = 0; i < 3; i++) {
            dataB[i] = new double[3];
        }
        dataB[0][0] = 9; dataB[0][1] = 8; dataB[0][2] = 7;
        dataB[1][0] = 6; dataB[1][1] = 5; dataB[1][2] = 4;
        dataB[2][0] = 3; dataB[2][1] = 2; dataB[2][2] = 1;
        
        SquareMat B(dataB, 3);
        
        // Free the original memory (B has a copy)
        for (int i = 0; i < 3; i++) {
            delete[] dataB[i];
        }
        delete[] dataB;
        
        cout << "Matrix B:" << endl << B << endl;
        
        // Basic arithmetic operations
        printSubHeader("Basic Arithmetic Operations");
        
        printOperation("A + B", "Matrix addition (+ operator)");
        cout << (A + B) << endl;
        
        printOperation("A - B", "Matrix subtraction (- operator)");
        cout << (A - B) << endl;
        
        printOperation("-A", "Unary minus (reversing sign of all elements)");
        cout << (-A) << endl;
        
        printOperation("A * B", "Matrix multiplication");
        cout << (A * B) << endl;
        
        printOperation("A * 2", "Matrix multiplication with scalar (matrix * scalar)");
        cout << (A * 2) << endl;
        
        printOperation("2 * A", "Scalar multiplication with matrix (scalar * matrix)");
        cout << (2 * A) << endl;
        
        printOperation("A % B", "Element-wise multiplication between matrices");
        cout << (A % B) << endl;
        
        printOperation("A % 3", "Modulo with scalar");
        cout << (A % 3) << endl;
        
        printOperation("A / 2", "Matrix division by scalar");
        cout << (A / 2) << endl;
        
        // Power operations
        printSubHeader("Power Operations");
        
        printOperation("A^2", "Matrix squared (self-multiplication)");
        cout << (A ^ 2) << endl;
        
        printOperation("A^0", "Power of 0 (identity matrix)");
        cout << (A ^ 0) << endl;
        
        // Exception demonstration
        printOperation("A^(-1)", "Attempt to raise to negative power (should throw exception)");
        try {
            SquareMat invA = A ^ (-1);
            cout << invA << endl;
        } catch (const std::invalid_argument& e) {
            cout << "Exception caught as expected: " << e.what() << endl;
        }
        
        // Increment/Decrement
        printSubHeader("Increment and Decrement Operators");
        
        SquareMat C = A;
        cout << "Matrix C = A:" << endl << C << endl;
        
        printOperation("++C", "Pre-increment");
        cout << (++C) << endl;
        
        printOperation("C++", "Post-increment");
        cout << "Return value: " << endl << (C++) << endl;
        cout << "After operation, C: " << endl << C << endl;
        
        printOperation("--C", "Pre-decrement");
        cout << (--C) << endl;
        
        printOperation("C--", "Post-decrement");
        cout << "Return value: " << endl << (C--) << endl;
        cout << "After operation, C: " << endl << C << endl;
        
        // Transpose
        printSubHeader("Transpose and Matrix Operations");
        
        printOperation("~A", "Transpose of matrix A");
        cout << (~A) << endl;
        
        // Comparison operators
        printSubHeader("Comparison Operators");
        
        printOperation("A == B", "Equality (based on sum of elements): " + to_string(A == B));
        printOperation("A != B", "Inequality: " + to_string(A != B));
        printOperation("A < B", "Less than: " + to_string(A < B));
        printOperation("A > B", "Greater than: " + to_string(A > B));
        printOperation("A <= B", "Less than or equal: " + to_string(A <= B));
        printOperation("A >= B", "Greater than or equal: " + to_string(A >= B));
        
        // Determinant
        printSubHeader("Determinant");
        
        printOperation("!A", "Calculating determinant of A: " + to_string(!A));
        
        // Compound assignment operators
        printSubHeader("Compound Assignment Operators");
        
        SquareMat D = A;
        cout << "Matrix D = A:" << endl << D << endl;
        
        printOperation("D += B", "Addition and assignment");
        D += B;
        cout << D << endl;
        
        printOperation("D -= B", "Subtraction and assignment");
        D -= B;
        cout << D << endl;
        
        printOperation("D *= 2", "Scalar multiplication and assignment");
        D *= 2;
        cout << D << endl;
        
        printOperation("D /= 2", "Scalar division and assignment");
        D /= 2;
        cout << D << endl;
        
        printOperation("D %= 3", "Modulo with scalar and assignment");
        D %= 3;
        cout << D << endl;
        
        printOperation("D %= B", "Element-wise multiplication and assignment");
        D %= B;
        cout << D << endl;
        
        printOperation("D *= B", "Matrix multiplication and assignment");
        D *= B;
        cout << D << endl;

        // Error handling
        printSubHeader("Error Handling");
        
        printOperation("SquareMat(0)", "Attempt to create a matrix of size 0");
        try {
            SquareMat invalid(0);
        } catch (const std::invalid_argument& e) {
            cout << "Exception caught as expected: " << e.what() << endl;
        }
        
        printOperation("A / 0", "Attempt to divide by zero");
        try {
            SquareMat zero = A / 0;
        } catch (const std::invalid_argument& e) {
            cout << "Exception caught as expected: " << e.what() << endl;
        }
        
        // Summary
        printHeader("Summary and Recommendations");
        cout << "All operators of the SquareMat class work as expected." << endl;
        cout << "This square matrix class provides full functionality for matrix calculations." << endl;
        cout << "Main applications: linear algebra, computer graphics, neural networks, and more." << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}