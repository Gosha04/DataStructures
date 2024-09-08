#include <iostream>

int** addMatrices (int** A, int** B, int n) {
    int** C = new int*[n];

    for(int i = 0; i < n; i++) {
        C[i] = new int[n];
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

void addMatrices (int** A, int** B, int** C, int n) { // To force memory de-allocation
    for(int i = 0; i < n; i++) {
        C[i] = new int[n];
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
            std::cout << C[i][j] << "\t";
        }
    }
}


int main() {
    int** X = new int*[2];
    for(int i = 0; i < 2; ++i) {
        X[i] = new int[2];
    }
    X[0][0] = 2;
    X[0][1] = 4;
    X[1][0] = 6;
    X[1][1] = 8;

    int** res = addMatrices(X, X, 2);
    for (int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            std::cout << res[i][j] << "\t";
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < 2; ++i) {
        delete[] X[i];
        delete[] res[i];
    }
    delete[] X;
    delete[] res;

    int** res2 = new int* [2];
    res2[0] = new int [2];
    res2[1] = new int [2];
    addMatrices(X, X, res2, 2);

    return 0;
}