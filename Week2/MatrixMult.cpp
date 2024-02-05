#include <iostream>
#include <vector>
using namespace std;

void addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int row, int col, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[row + i][col + j] += A[row + i][col + j] + B[row + i][col + j];
        }
    }
}

void matrixMultiplyRecursiveAux(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int rowA, int colA, int rowB, int colB, int rowC, int colC, int n) {
    if (n == 1) {
        C[rowC][colC] += A[rowA][colA] * B[rowB][colB];
        return;
    }

    // Divide the matrix size by 2
    int half = n / 2;

    // Perform recursive multiplication and addition for each quadrant
    // Top-left quadrant
    matrixMultiplyRecursiveAux(A, B, C, rowA, colA, rowB, colB, rowC, colC, half);
    matrixMultiplyRecursiveAux(A, B, C, rowA, colA + half, rowB + half, colB, rowC, colC, half);

    // Top-right quadrant
    matrixMultiplyRecursiveAux(A, B, C, rowA, colA, rowB, colB + half, rowC, colC + half, half);
    matrixMultiplyRecursiveAux(A, B, C, rowA, colA + half, rowB + half, colB + half, rowC, colC + half, half);

    // Bottom-left quadrant
    matrixMultiplyRecursiveAux(A, B, C, rowA + half, colA, rowB, colB, rowC + half, colC, half);
    matrixMultiplyRecursiveAux(A, B, C, rowA + half, colA + half, rowB + half, colB, rowC + half, colC, half);

    // Bottom-right quadrant
    matrixMultiplyRecursiveAux(A, B, C, rowA + half, colA, rowB, colB + half, rowC + half, colC + half, half);
    matrixMultiplyRecursiveAux(A, B, C, rowA + half, colA + half, rowB + half, colB + half, rowC + half, colC + half, half);
}

void matrixMultiplyRecursive(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    matrixMultiplyRecursiveAux(A, B, C, 0, 0, 0, 0, 0, 0, n);
}

int main() {
    // Example usage for 4x4 matrices, can be adapted for other sizes
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
    int n = 4; // Size of the matrix
    vector<vector<int>> C(n, vector<int>(n, 0)); // Initialize result matrix C with zeros

    matrixMultiplyRecursive(A, B, C, n);

    // Print the result matrix C
    for (const auto &row : C) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

