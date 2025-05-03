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
        printHeader("SquareMat Class - Comprehensive Demonstration");
        
        // 1. Creating matrices
        printSubHeader("1. Creating and Initializing Matrices");
        
        // Create empty matrix
        printOperation("SquareMat A(3)", "Creating a 3x3 empty matrix");
        SquareMat A(3);
        cout << "Empty matrix A:" << endl << A << endl;
        
        // Initialize with values
        printOperation("Setting values", "Using [] operator to modify elements");
        A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
        A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
        A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;
        cout << "Modified matrix A:" << endl << A << endl;
        
        // Create from 2D array
        printOperation("Matrix from array", "Creating matrix from existing 2D array");
        double** dataB = new double*[3];
        for (int i = 0; i < 3; i++) {
            dataB[i] = new double[3];
        }
        dataB[0][0] = 9; dataB[0][1] = 8; dataB[0][2] = 7;
        dataB[1][0] = 6; dataB[1][1] = 5; dataB[1][2] = 4;
        dataB[2][0] = 3; dataB[2][1] = 2; dataB[2][2] = 1;
        
        SquareMat B(dataB, 3);
        cout << "Matrix B:" << endl << B << endl;
        
        // Free original memory
        for (int i = 0; i < 3; i++) {
            delete[] dataB[i];
        }
        delete[] dataB;
        
        // Copy constructor demonstration
        printOperation("Copy constructor", "SquareMat C(A)");
        SquareMat C(A);
        cout << "Matrix C (copy of A):" << endl << C << endl;
        
        // Assignment operator demonstration
        printOperation("Assignment operator", "SquareMat D = B");
        SquareMat D = B;
        cout << "Matrix D (assigned from B):" << endl << D << endl;
        
        // 2. Basic arithmetic operations
        printSubHeader("2. Basic Arithmetic Operations");
        
        // Addition
        printOperation("A + B", "Matrix addition");
        SquareMat sum = A + B;
        cout << sum << endl;
        cout << "Sum of all elements: " << sum.sum() << endl;
        
        // Subtraction
        printOperation("A - B", "Matrix subtraction");
        SquareMat diff = A - B;
        cout << diff << endl;
        cout << "Sum of all elements: " << diff.sum() << endl;
        
        // Unary minus
        printOperation("-A", "Unary minus");
        SquareMat negA = -A;
        cout << negA << endl;
        cout << "Sum of all elements: " << negA.sum() << endl;
        
        // 3. Matrix multiplication operations
        printSubHeader("3. Matrix Multiplication Operations");
        
        // Matrix multiplication
        printOperation("A * B", "Matrix multiplication");
        SquareMat product = A * B;
        cout << product << endl;
        
        // Scalar multiplication (both ways)
        printOperation("A * 3", "Matrix times scalar");
        SquareMat scaled1 = A * 3;
        cout << scaled1 << endl;
        
        printOperation("3 * A", "Scalar times matrix");
        SquareMat scaled2 = 3 * A;
        cout << scaled2 << endl;
        
        // Verify both results are the same
        cout << "\nVerifying scalar multiplication equivalence:" << endl;
        cout << "A*3 == 3*A: " << (scaled1 == scaled2) << endl;
        
        // 4. Element-wise operations
        printSubHeader("4. Element-wise Operations");
        
        // Element-wise multiplication
        printOperation("A % B", "Element-wise multiplication");
        SquareMat elemProduct = A % B;
        cout << elemProduct << endl;
        
        // Modulo with scalar
        printOperation("A % 3", "Modulo with scalar");
        SquareMat modResult = A % 3;
        cout << modResult << endl;
        
        // Division by scalar
        printOperation("A / 2", "Division by scalar");
        SquareMat divResult = A / 2;
        cout << divResult << endl;
        
        // 5. Power operations
        printSubHeader("5. Power Operations");
        
        // Various powers
        printOperation("A^0", "Identity matrix");
        SquareMat power0 = A ^ 0;
        cout << power0 << endl;
        
        printOperation("A^1", "Matrix to power 1");
        SquareMat power1 = A ^ 1;
        cout << power1 << endl;
        
        printOperation("A^2", "Matrix squared");
        SquareMat power2 = A ^ 2;
        cout << power2 << endl;
        
        printOperation("A^3", "Matrix cubed");
        SquareMat power3 = A ^ 3;
        cout << power3 << endl;
        
        // 6. Increment/Decrement operators
        printSubHeader("6. Increment and Decrement Operators");
        
        SquareMat E = A;
        
        // Pre-increment
        printOperation("++E", "Pre-increment");
        cout << "Before: " << E.sum() << endl;
        SquareMat result1 = ++E;
        cout << "Result: " << endl << result1 << endl;
        cout << "E after: " << endl << E << endl;
        cout << "Sum after: " << E.sum() << endl;
        
        // Post-increment
        printOperation("E++", "Post-increment");
        cout << "Before: " << E.sum() << endl;
        SquareMat result2 = E++;
        cout << "Result: " << endl << result2 << endl;
        cout << "E after: " << endl << E << endl;
        cout << "Sum after: " << E.sum() << endl;
        
        // Pre-decrement
        printOperation("--E", "Pre-decrement");
        cout << "Before: " << E.sum() << endl;
        SquareMat result3 = --E;
        cout << "Result: " << endl << result3 << endl;
        cout << "E after: " << endl << E << endl;
        cout << "Sum after: " << E.sum() << endl;
        
        // Post-decrement
        printOperation("E--", "Post-decrement");
        cout << "Before: " << E.sum() << endl;
        SquareMat result4 = E--;
        cout << "Result: " << endl << result4 << endl;
        cout << "E after: " << endl << E << endl;
        cout << "Sum after: " << E.sum() << endl;
        
        // 7. Matrix transformations
        printSubHeader("7. Matrix Transformations");
        
        // Transpose
        printOperation("~A", "Transpose");
        SquareMat transposeA = ~A;
        cout << "A:" << endl << A << endl;
        cout << "~A:" << endl << transposeA << endl;
        
        // Double transpose verification
        printOperation("~(~A)", "Double transpose (should equal A)");
        SquareMat doubleTranspose = ~transposeA;
        cout << "~(~A):" << endl << doubleTranspose << endl;
        cout << "A == ~(~A): " << (A == doubleTranspose) << endl;
        
        // 8. Comparison operators
        printSubHeader("8. Comparison Operators");
        
        // Create matrices with specific sums
        SquareMat F(2);
        F[0][0] = 1; F[0][1] = 2;
        F[1][0] = 3; F[1][1] = 4;  // Sum = 10
        
        SquareMat G(2);
        G[0][0] = 2; G[0][1] = 3;
        G[1][0] = 4; G[1][1] = 5;  // Sum = 14
        
        cout << "F:" << endl << F << endl;
        cout << "G:" << endl << G << endl;
        cout << "F sum: " << F.sum() << endl;
        cout << "G sum: " << G.sum() << endl;
        
        printOperation("All comparisons", "Testing all comparison operators");
        cout << "F == G: " << (F == G) << endl;
        cout << "F != G: " << (F != G) << endl;
        cout << "F < G:  " << (F < G) << endl;
        cout << "F > G:  " << (F > G) << endl;
        cout << "F <= G: " << (F <= G) << endl;
        cout << "F >= G: " << (F >= G) << endl;
        
        // 9. Determinant calculations
        printSubHeader("9. Determinant Calculations");
        
        // Determinant examples
        printOperation("!A", "Determinant of A");
        cout << "A:" << endl << A << endl;
        cout << "Determinant: " << !A << endl;
        
        // Create invertible matrix
        SquareMat H(2);
        H[0][0] = 1; H[0][1] = 2;
        H[1][0] = 3; H[1][1] = 5;  // Determinant = 1*5 - 2*3 = -1
        cout << "\nH:" << endl << H << endl;
        cout << "Determinant: " << !H << endl;
        
        // Singular matrix
        SquareMat I(2);
        I[0][0] = 1; I[0][1] = 2;
        I[1][0] = 2; I[1][1] = 4;  // Determinant = 0 (singular)
        cout << "\nI:" << endl << I << endl;
        cout << "Determinant: " << !I << endl;
        
        // 10. Compound assignment operators
        printSubHeader("10. Compound Assignment Operators");
        
        SquareMat J = A;
        
        printOperation("J = A", "Initial state");
        cout << J << endl;
        cout << "Sum: " << J.sum() << endl;
        
        printOperation("J += B", "Add B to J");
        J += B;
        cout << J << endl;
        cout << "Sum: " << J.sum() << endl;
        
        printOperation("J -= B", "Subtract B from J");
        J -= B;
        cout << J << endl;
        cout << "Sum: " << J.sum() << endl;
        
        printOperation("J *= 2", "Multiply J by 2");
        J *= 2;
        cout << J << endl;
        cout << "Sum: " << J.sum() << endl;
        
        printOperation("J /= 2", "Divide J by 2");
        J /= 2;
        cout << J << endl;
        cout << "Sum: " << J.sum() << endl;
        
        printOperation("J %= 3", "J modulo 3");
        J %= 3;
        cout << J << endl;
        cout << "Sum: " << J.sum() << endl;
        
        printOperation("J %= B", "Element-wise product with B");
        J %= B;
        cout << J << endl;
        cout << "Sum: " << J.sum() << endl;
        
        printOperation("J *= A", "Matrix multiply by A");
        J *= A;
        cout << J << endl;
        cout << "Sum: " << J.sum() << endl;
        
        // 11. Error handling
        printSubHeader("11. Error Handling");
        
        // Invalid size
        printOperation("SquareMat(0)", "Invalid size 0");
        try {
            SquareMat invalid(0);
        } catch (const std::invalid_argument& e) {
            cout << "Exception: " << e.what() << endl;
        }
        
        printOperation("SquareMat(-5)", "Invalid size -5");
        try {
            SquareMat invalid(-5);
        } catch (const std::invalid_argument& e) {
            cout << "Exception: " << e.what() << endl;
        }
        
        // Division by zero
        printOperation("A / 0", "Division by zero");
        try {
            SquareMat zero = A / 0;
        } catch (const std::invalid_argument& e) {
            cout << "Exception: " << e.what() << endl;
        }
        
        // Modulo by zero
        printOperation("A % 0", "Modulo by zero");
        try {
            SquareMat zero = A % 0;
        } catch (const std::invalid_argument& e) {
            cout << "Exception: " << e.what() << endl;
        }
        
        // Compound assignment with incompatible sizes
        printOperation("Size mismatch", "3x3 += 2x2");
        try {
            A += F;  // F is 2x2, A is 3x3
        } catch (const std::invalid_argument& e) {
            cout << "Exception: " << e.what() << endl;
        }
        
        // Invalid array index
        printOperation("A[10][0]", "Out of bounds access");
        try {
            double value = A[10][0];
            cout << value << endl;  // Won't be reached
        } catch (const std::out_of_range& e) {
            cout << "Exception: " << e.what() << endl;
        }
        
        // 12. Large matrix operations
        printSubHeader("12. Large Matrix Operations");
        
        cout << "Testing with larger matrices..." << endl;
        
        // Create larger matrices
        SquareMat large1(5);
        SquareMat large2(5);
        
        // Fill with test data
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                large1[i][j] = i + j + 1;
                large2[i][j] = (i + 1) * (j + 1);
            }
        }
        
        // Test operations with large matrices
        SquareMat largeProduct = large1 * large2;
        cout << "5x5 matrix multiplication completed" << endl;
        cout << "Result determinant: " << !largeProduct << endl;
        
        // 13. Practical examples
        printSubHeader("13. Practical Application Examples");
        
        // Example: Transformation matrix
        printOperation("2D Rotation", "Creating a 90-degree rotation matrix");
        SquareMat rotation(2);
        rotation[0][0] = 0;  rotation[0][1] = -1;
        rotation[1][0] = 1;  rotation[1][1] = 0;
        cout << "Rotation matrix:" << endl << rotation << endl;
        
        // Example: Vector transformation
        SquareMat point(2);
        point[0][0] = 1; point[0][1] = 0;
        point[1][0] = 0; point[1][1] = 1;
        cout << "Original point matrix:" << endl << point << endl;
        
        SquareMat rotated = rotation * point;
        cout << "Rotated point:" << endl << rotated << endl;
        
        // Example: Scaling matrix
        printOperation("Scaling", "Creating a scaling matrix");
        SquareMat scaling(2);
        scaling[0][0] = 2; scaling[0][1] = 0;
        scaling[1][0] = 0; scaling[1][1] = 2;
        cout << "Scaling matrix:" << endl << scaling << endl;
        
        SquareMat scaled = scaling * point;
        cout << "Scaled point:" << endl << scaled << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}