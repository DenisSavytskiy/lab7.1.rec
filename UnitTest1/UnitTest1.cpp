#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab№7.1.рек/AP_Lab№7.1.рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRec {
    TEST_CLASS(RecursiveMatrixTests) {
public:
    TEST_METHOD(TestCreateMatrix) {
        const int rows = 2, cols = 2;
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new int[cols];

        Create(matrix, rows, cols, -41, 51);

        // Перевіряємо, чи всі елементи в правильному діапазоні
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                Assert::IsTrue(matrix[i][j] >= -42 && matrix[i][j] <= 51);

        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    TEST_METHOD(TestCalc) {
        const int rows = 2, cols = 2;
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new int[cols];

        matrix[0][0] = 10;  // не повинен оброблятися
        matrix[0][1] = 3;   // повинен оброблятися
        matrix[1][0] = -5;  // повинен оброблятися
        matrix[1][1] = 15;  // не повинен оброблятися

        int sum = 0, count = 0;
        Calc(matrix, rows, cols, sum, count, 0, 0);

        Assert::AreEqual(2, count);
        Assert::AreEqual(-2, sum);

        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
    };
}