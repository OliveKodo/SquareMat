// your_email@example.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <stdexcept>
#include <cmath>

using namespace Matrix;

// Helper function to compare doubles with tolerance
bool doubleEqual(double a, double b, double epsilon = 1e-9) {
    return std::fabs(a - b) < epsilon;
}

TEST_CASE("Constructors and basic operations") {
    SUBCASE("Size constructor and zero initialization") {
        SquareMat m1(3);
        CHECK(m1.getSize() == 3);
        CHECK(m1[0][0] == 0);
        CHECK(m1[1][1] == 0);
        CHECK(m1[2][2] == 0);
    }
    
    SUBCASE("Array constructor") {
        double** data = new double*[2];
        for (int i = 0; i < 2; i++) {
            data[i] = new double[2];
        }
        data[0][0] = 1; data[0][1] = 2;
        data[1][0] = 3; data[1][1] = 4;
        
        SquareMat m2(data, 2);
        
        // Free the original data
        for (int i = 0; i < 2; i++) {
            delete[] data[i];
        }
        delete[] data;
        
        CHECK(m2[0][0] == 1);
        CHECK(m2[0][1] == 2);
        CHECK(m2[1][0] == 3);
        CHECK(m2[1][1] == 4);
    }
    
    SUBCASE("Copy constructor") {
        SquareMat original(2);
        original[0][0] = 1; original[0][1] = 2;
        original[1][0] = 3; original[1][1] = 4;
        
        SquareMat copy(original);
        
        CHECK(copy[0][0] == 1);
        CHECK(copy[0][1] == 2);
        CHECK(copy[1][0] == 3);
        CHECK(copy[1][1] == 4);
    }
    
    SUBCASE("Assignment operator") {
        SquareMat original(2);
        original[0][0] = 1; original[0][1] = 2;
        original[1][0] = 3; original[1][1] = 4;
        
        SquareMat assigned(1); // Different size
        assigned = original;
        
        CHECK(assigned[0][0] == 1);
        CHECK(assigned[0][1] == 2);
        CHECK(assigned[1][0] == 3);
        CHECK(assigned[1][1] == 4);
    }
    
    SUBCASE("Invalid size exception") {
        CHECK_THROWS_AS(SquareMat(0), std::invalid_argument);
        CHECK_THROWS_AS(SquareMat(-1), std::invalid_argument);
    }
}

TEST_CASE("Arithmetic operations") {
    // Create test matrices
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    
    SquareMat B(2);
    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;
    
    SUBCASE("Addition") {
        SquareMat C = A + B;
        CHECK(C[0][0] == 6);
        CHECK(C[0][1] == 8);
        CHECK(C[1][0] == 10);
        CHECK(C[1][1] == 12);
    }
    
    SUBCASE("Subtraction") {
        SquareMat D = A - B;
        CHECK(D[0][0] == -4);
        CHECK(D[0][1] == -4);
        CHECK(D[1][0] == -4);
        CHECK(D[1][1] == -4);
    }
    
    SUBCASE("Unary minus") {
        SquareMat E = -A;
        CHECK(E[0][0] == -1);
        CHECK(E[0][1] == -2);
        CHECK(E[1][0] == -3);
        CHECK(E[1][1] == -4);
    }
    
    SUBCASE("Matrix multiplication") {
        SquareMat F = A * B;
        CHECK(F[0][0] == 19);
        CHECK(F[0][1] == 22);
        CHECK(F[1][0] == 43);
        CHECK(F[1][1] == 50);
    }
    
    SUBCASE("Scalar multiplication") {
        SquareMat G = A * 2;
        CHECK(G[0][0] == 2);
        CHECK(G[0][1] == 4);
        CHECK(G[1][0] == 6);
        CHECK(G[1][1] == 8);
        
        SquareMat H = 3 * A;
        CHECK(H[0][0] == 3);
        CHECK(H[0][1] == 6);
        CHECK(H[1][0] == 9);
        CHECK(H[1][1] == 12);
    }
    
    SUBCASE("Element-wise multiplication") {
        SquareMat I = A % B;
        CHECK(I[0][0] == 5);
        CHECK(I[0][1] == 12);
        CHECK(I[1][0] == 21);
        CHECK(I[1][1] == 32);
    }
    
    SUBCASE("Scalar modulo") {
        SquareMat J = A % 3;
        CHECK(J[0][0] == 1);
        CHECK(J[0][1] == 2);
        CHECK(J[1][0] == 0);
        CHECK(J[1][1] == 1);
    }
    
    SUBCASE("Scalar division") {
        SquareMat K = A / 2;
        CHECK(doubleEqual(K[0][0], 0.5));
        CHECK(doubleEqual(K[0][1], 1.0));
        CHECK(doubleEqual(K[1][0], 1.5));
        CHECK(doubleEqual(K[1][1], 2.0));
    }
    
    SUBCASE("Division by zero exception") {
        CHECK_THROWS_AS(A / 0, std::invalid_argument);
    }
}

TEST_CASE("Power and other operations") {
    // Create test matrix
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    
    SUBCASE("Power 0 (Identity matrix)") {
        SquareMat B = A ^ 0;
        CHECK(B[0][0] == 1);
        CHECK(B[0][1] == 0);
        CHECK(B[1][0] == 0);
        CHECK(B[1][1] == 1);
    }
    
    SUBCASE("Power 1") {
        SquareMat C = A ^ 1;
        CHECK(C[0][0] == 1);
        CHECK(C[0][1] == 2);
        CHECK(C[1][0] == 3);
        CHECK(C[1][1] == 4);
    }
    
    SUBCASE("Power 2") {
        SquareMat D = A ^ 2;
        CHECK(D[0][0] == 7);
        CHECK(D[0][1] == 10);
        CHECK(D[1][0] == 15);
        CHECK(D[1][1] == 22);
    }
    
    SUBCASE("Negative power exception") {
        CHECK_THROWS_AS(A ^ (-1), std::invalid_argument);
    }
    
    SUBCASE("Pre-increment") {
        SquareMat F = A;
        SquareMat G = ++F;
        
        CHECK(F[0][0] == 2);
        CHECK(F[0][1] == 3);
        CHECK(F[1][0] == 4);
        CHECK(F[1][1] == 5);
        
        CHECK(G[0][0] == 2);
        CHECK(G[0][1] == 3);
        CHECK(G[1][0] == 4);
        CHECK(G[1][1] == 5);
    }
    
    SUBCASE("Post-increment") {
        SquareMat F = A;
        SquareMat H = F++;
        
        CHECK(F[0][0] == 2);
        CHECK(F[0][1] == 3);
        CHECK(F[1][0] == 4);
        CHECK(F[1][1] == 5);
        
        CHECK(H[0][0] == 1);
        CHECK(H[0][1] == 2);
        CHECK(H[1][0] == 3);
        CHECK(H[1][1] == 4);
    }
    
    SUBCASE("Pre-decrement") {
        SquareMat I = A;
        SquareMat J = --I;
        
        CHECK(I[0][0] == 0);
        CHECK(I[0][1] == 1);
        CHECK(I[1][0] == 2);
        CHECK(I[1][1] == 3);
        
        CHECK(J[0][0] == 0);
        CHECK(J[0][1] == 1);
        CHECK(J[1][0] == 2);
        CHECK(J[1][1] == 3);
    }
    
    SUBCASE("Post-decrement") {
        SquareMat I = A;
        SquareMat K = I--;
        
        CHECK(I[0][0] == 0);
        CHECK(I[0][1] == 1);
        CHECK(I[1][0] == 2);
        CHECK(I[1][1] == 3);
        
        CHECK(K[0][0] == 1);
        CHECK(K[0][1] == 2);
        CHECK(K[1][0] == 3);
        CHECK(K[1][1] == 4);
    }
    
    SUBCASE("Transpose") {
        SquareMat L = ~A;
        CHECK(L[0][0] == 1);
        CHECK(L[0][1] == 3);
        CHECK(L[1][0] == 2);
        CHECK(L[1][1] == 4);
    }
    
    SUBCASE("Determinant") {
        double det = !A;
        CHECK(doubleEqual(det, -2.0));
    }
}

TEST_CASE("Comparison operators") {
    // Create test matrices with different sums
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    // Sum = 10
    
    SquareMat B(2);
    B[0][0] = 2; B[0][1] = 3;
    B[1][0] = 4; B[1][1] = 5;
    // Sum = 14
    
    SquareMat C(2);
    C[0][0] = 1; C[0][1] = 2;
    C[1][0] = 3; C[1][1] = 4;
    // Sum = 10 (same as A)
    
    SUBCASE("Equality and inequality") {
        CHECK(A == C);
        CHECK(A != B);
        CHECK_FALSE(A == B);
        CHECK_FALSE(A != C);
    }
    
    SUBCASE("Less than and greater than") {
        CHECK(A < B);
        CHECK(B > A);
        CHECK_FALSE(B < A);
        CHECK_FALSE(A > B);
    }
    
    SUBCASE("Less than or equal and greater than or equal") {
        CHECK(A <= B);
        CHECK(A <= C);
        CHECK(B >= A);
        CHECK(A >= C);
        CHECK_FALSE(B <= A);
        CHECK_FALSE(A >= B);
    }
}

TEST_CASE("Compound assignment operators") {
    // Create test matrices
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    
    SquareMat B(2);
    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;
    
    SUBCASE("Compound addition (+=)") {
        SquareMat C = A;
        C += B;
        CHECK(C[0][0] == 6);
        CHECK(C[0][1] == 8);
        CHECK(C[1][0] == 10);
        CHECK(C[1][1] == 12);
    }
    
    SUBCASE("Compound subtraction (-=)") {
        SquareMat D = A;
        D -= B;
        CHECK(D[0][0] == -4);
        CHECK(D[0][1] == -4);
        CHECK(D[1][0] == -4);
        CHECK(D[1][1] == -4);
    }
    
    SUBCASE("Compound matrix multiplication (*=)") {
        SquareMat E = A;
        E *= B;
        CHECK(E[0][0] == 19);
        CHECK(E[0][1] == 22);
        CHECK(E[1][0] == 43);
        CHECK(E[1][1] == 50);
    }
    
    SUBCASE("Compound scalar multiplication (*=)") {
        SquareMat F = A;
        F *= 2;
        CHECK(F[0][0] == 2);
        CHECK(F[0][1] == 4);
        CHECK(F[1][0] == 6);
        CHECK(F[1][1] == 8);
    }
    
    SUBCASE("Compound division (/=)") {
        SquareMat G = A;
        G /= 2;
        CHECK(doubleEqual(G[0][0], 0.5));
        CHECK(doubleEqual(G[0][1], 1.0));
        CHECK(doubleEqual(G[1][0], 1.5));
        CHECK(doubleEqual(G[1][1], 2.0));
    }
    
    SUBCASE("Compound element-wise multiplication (%=)") {
        SquareMat H = A;
        H %= B;
        CHECK(H[0][0] == 5);
        CHECK(H[0][1] == 12);
        CHECK(H[1][0] == 21);
        CHECK(H[1][1] == 32);
    }
    
    SUBCASE("Compound modulo (%=)") {
        SquareMat I = A;
        I %= 3;
        CHECK(I[0][0] == 1);
        CHECK(I[0][1] == 2);
        CHECK(I[1][0] == 0);
        CHECK(I[1][1] == 1);
    }
}

TEST_CASE("Access operators and exceptions") {
    SquareMat A(3);
    
    SUBCASE("Valid access") {
        A[0][0] = 42;
        CHECK(A[0][0] == 42);
        
        A[2][2] = 100;
        CHECK(A[2][2] == 100);
    }
    
    SUBCASE("Out of bounds access") {
        CHECK_THROWS_AS(A[3][0], std::out_of_range);
        CHECK_THROWS_AS(A[-1][0], std::out_of_range);
    }
}

TEST_CASE("Matrix size mismatch") {
    SquareMat A(2);
    SquareMat B(3);
    
    SUBCASE("Addition with size mismatch") {
        CHECK_THROWS_AS(A + B, std::invalid_argument);
    }
    
    SUBCASE("Subtraction with size mismatch") {
        CHECK_THROWS_AS(A - B, std::invalid_argument);
    }
    
    SUBCASE("Multiplication with size mismatch") {
        CHECK_THROWS_AS(A * B, std::invalid_argument);
    }
    
    SUBCASE("Element-wise multiplication with size mismatch") {
        CHECK_THROWS_AS(A % B, std::invalid_argument);
    }
    
    SUBCASE("Compound addition with size mismatch") {
        CHECK_THROWS_AS(A += B, std::invalid_argument);
    }
}