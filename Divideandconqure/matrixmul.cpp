#include <iostream>
#include <vector>
using namespace std;

// Function to add two matrices element-wise
vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices recursively
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    if (n == 1) {
        result[0][0] = A[0][0] * B[0][0];
    } else {
        vector<vector<int>> A11(n / 2, vector<int>(n / 2));
        vector<vector<int>> A12(n / 2, vector<int>(n / 2));
        vector<vector<int>> A21(n / 2, vector<int>(n / 2));
        vector<vector<int>> A22(n / 2, vector<int>(n / 2));
        vector<vector<int>> B11(n / 2, vector<int>(n / 2));
        vector<vector<int>> B12(n / 2, vector<int>(n / 2));
        vector<vector<int>> B21(n / 2, vector<int>(n / 2));
        vector<vector<int>> B22(n / 2, vector<int>(n / 2));

        // Splitting matrices into submatrices
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A22[i][j] = A[i + n / 2][j + n / 2];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n / 2][j];
                B22[i][j] = B[i + n / 2][j + n / 2];
            }
        }

        // Recursive calls to multiply submatrices
        vector<vector<int>> C11 = matrixAddition(matrixMultiply(A11, B11), matrixMultiply(A12, B21));
        vector<vector<int>> C12 = matrixAddition(matrixMultiply(A11, B12), matrixMultiply(A12, B22));
        vector<vector<int>> C21 = matrixAddition(matrixMultiply(A21, B11), matrixMultiply(A22, B21));
        vector<vector<int>> C22 = matrixAddition(matrixMultiply(A21, B12), matrixMultiply(A22, B22));

        // Combining submatrices to form result matrix
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                result[i][j] = C11[i][j];
                result[i][j + n / 2] = C12[i][j];
                result[i + n / 2][j] = C21[i][j];
                result[i + n / 2][j + n / 2] = C22[i][j];
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    // Ensure both matrices are square and have dimensions as powers of 2
    int n = A.size();
    if (n != B.size() || (n & (n - 1)) != 0) {
        cout << "Matrices must be square and have dimensions as powers of 2" << endl;
        return 1;
    }

    vector<vector<int>> C = matrixMultiply(A, B);

    // Displaying the result matrix
    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
