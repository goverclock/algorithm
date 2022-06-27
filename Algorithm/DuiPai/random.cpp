// freopen("data.in", "w", stdout);
// srand(unsigned(time(0)));

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int random(int n) { return (long long)rand() * rand() % n; }
    #define M 2000000
    int X[M];
int main() {
    freopen("data.in", "w", stdout);
    srand(unsigned(time(0)));
    /************************************************************************************/

    for(int i = 0; i < M; i++) X[i] = i + 1;
    // for(int i = 0; i < M * 10; i++)
        // swap(X[i / 10], X[random(M)]);
    for(int i = 0; i < M; i++)
        printf("%d\n", X[i]);
    /************************************************************************************/
    return 0;
}
