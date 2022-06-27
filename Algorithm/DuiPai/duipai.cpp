#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
    for (int T = 1; T <= 1000; T++) {
        system("DuiPai\\bin\\random.exe");
        double stSol = clock();
        system("DuiPai\\bin\\sol.exe");
        double edSol = clock();
        double stBf = edSol;
        system("DuiPai\\bin\\bf.exe");
        double edBf = clock();
        if (system("fc data.ans data.out")) {
            printf("#%d Wrong Answer\n", T);
            break;
        } else
            printf("#%d Accepted\nSol time = %.0lfms\nBf time = %.0fms\n", T,
                   edSol - stSol, edBf - stBf);
    }

    return 0;
}