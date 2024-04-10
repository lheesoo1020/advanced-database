#include <iostream>
#include "p0_starter.h"

int main() {
    // Define matrices dimensions
    const int rows = 2;
    const int cols = 2;

    // Define matrix elements
    int arr1[rows * cols] = {1, 2, 3, 4};

    // Create RowMatrix object and import elements
    bustub::RowMatrix<int> mat1(rows, cols);
    mat1.MatImport(arr1);

    // Test GetRows, GetColumns, GetElem, SetElem functions
    std::cout << "Rows: " << mat1.GetRows() << ", Columns: " << mat1.GetColumns() << std::endl;
    std::cout << "Element at (1, 1): " << mat1.GetElem(1, 1) << std::endl;
    std::cout << "Setting element at (1, 1) to 5" << std::endl;
    mat1.SetElem(1, 1, 5);
    std::cout << "Element at (1, 1) after setting: " << mat1.GetElem(1, 1) << std::endl;

    // Test Matrix Import
    std::cout << "Matrix elements after import:" << std::endl;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            std::cout << mat1.GetElem(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

