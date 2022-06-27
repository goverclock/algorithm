#include <iostream>

class Matrix {
   public:
    Matrix(int r, int l) {
        rows = r;
        lines = l;
        data = new int *[r];
        for (int i = 0; i < r; i++) data[i] = new int[l];
    }
    Matrix(const Matrix &other) {
        rows = other.rows;
        lines = other.lines;
        data = new int *[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[lines];
            for (int j = 0; j < lines; j++) data[i][j] = other.data[i][j];
        }
    }
    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }

    int rows;
    int lines;
    int **data;

    void in_matrix() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < lines; j++) std::cin >> data[i][j];
    }
    void out_matrix() {
        for (int i = 0; i < rows; i++, std::cout << std::endl)
            for (int j = 0; j < lines; j++)
                std::cout << data[i][j] << ' ';
        std::cout << std::endl;
    }
    bool is_same_scale(const Matrix &other) {
        if (rows != other.rows) return false;
        if (lines != other.lines) return false;
        return true;
    }
};

void add_matrix(Matrix &A, Matrix &B, Matrix &C) {
    if (!A.is_same_scale(B) || !B.is_same_scale(C)) {
        std::cout << "add_matrix: matrix are not of the same size."
                  << std::endl;
        return;
    }
    int r = A.rows, l = A.lines;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < l; j++) C.data[i][j] = A.data[i][j] + B.data[i][j];
}
void sub_matrix(Matrix &A, Matrix &B, Matrix &C) {
    if (!A.is_same_scale(B) || !B.is_same_scale(C)) {
        std::cout << "sub_matrix: matrix are not of the same size."
                  << std::endl;
        return;
    }
    int r = A.rows, l = A.lines;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < l; j++) C.data[i][j] = A.data[i][j] - B.data[i][j];
}

int main() {
    // freopen("in.txt", "r", stdin);
    Matrix A1(3, 4), A2(3, 4), A3(3, 4);
    A1.in_matrix();
    A2.in_matrix();

    add_matrix(A1, A2, A3);
    A3.out_matrix();
    sub_matrix(A1, A2, A3);
    A3.out_matrix();

    Matrix *pA1 = new Matrix(4, 3);
    Matrix *pA2 = new Matrix(4, 3);
    Matrix *pA3 = new Matrix(4, 3);
    pA1->in_matrix();
    pA2->in_matrix();

    add_matrix(*pA1, *pA2, *pA3);
    pA3->out_matrix();
    sub_matrix(*pA1, *pA2, *pA3);
    pA3->out_matrix();

    delete pA1;
    delete pA2;
    delete pA3;


    return 0;
}

/* 1 2 3 4 
4 3 2 1
2 2 2 2

1 1 1 1
2 2 2 2
3 3 3 3

8 8 2
9 1 6
2 7 8
1 9 5

9 9 9
0 7 5
6 6 2
7 2 5 */
