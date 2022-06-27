#include <iostream>

void matrix_init(int **);
void matrix_out(int **);
void matrix_add(int **, int **, int **);
void matrix_sub(int **, int **, int **);
void matrix_free(int **);

int main() {
    int **A1 = new int *[4];
    int **A2 = new int *[4];
    int **A3 = new int *[4];

    for (int i = 0; i < 4; i++) {
        A1[i] = new int[5];
        A2[i] = new int[5];
        A3[i] = new int[5];
    }

    matrix_init(A1);
    matrix_init(A2);
    puts("");

    matrix_add(A1, A2, A3);
    matrix_out(A3);
    puts("");
    matrix_sub(A1, A2, A3);
    matrix_out(A3);
    puts("");

    matrix_free(A1);
    matrix_free(A2);
    matrix_free(A3);

    return 0;
}

void matrix_init(int **m) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++) std::cin >> m[i][j];
}

void matrix_out(int **m) {
    for (int i = 0; i < 4; i++, std::cout << std::endl)
        for (int j = 0; j < 5; j++) std::cout << m[i][j] << ' ';
}

void matrix_add(int **a, int **b, int **c) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++) c[i][j] = a[i][j] + b[i][j];
}
void matrix_sub(int **a, int **b, int **c) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++) c[i][j] = a[i][j] - b[i][j];
}

void matrix_free(int **m) {
    for (int i = 0; i < 4; i++) delete[] m[i];
    delete[] m;
}

/* 
1 1 1 1 1
1 1 1 1 1
1 1 4 1 1
1 1 1 1 1

2 2 2 2 2
2 2 2 2 2
2 9 2 2 2
2 2 2 2 2
 */
