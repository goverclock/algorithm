#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

double A[11][11], B[11][11], C[11][11];

int main() {
    freopen("in2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) cin >> A[i][j];
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) cin >> B[i][j];

    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
            for(int k = 1; k <= 10; k++)
                C[i][j] += A[i][k] * B[k][j];

    for (int i = 1; i <= 10; i++, puts(""))
        for (int j = 1; j <= 10; j++)
            printf("%.4f\t", C[i][j]);


    return 0;
}