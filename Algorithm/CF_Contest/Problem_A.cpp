#include <windows.h>

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string Say[500];

int main() {
    getchar();
    freopen("inANSI.txt", "r", stdin);
    int Index = 0;
    while (cin >> Say[Index++])
        ;

    bool End = false;
    for (int i = 0; i < Index && !End; i++) {
        const string &CurSay = Say[i];
        int Rest = 0;
        switch (CurSay[0]) {
            case 'A':
                Rest = 1000;
                break;
            case 'B':
                Rest = 500;
                break;
            case 'O':
                puts("");
                break;
            case 'X':
                End = true;
                break;
            default:
                for (int j = 0; j < CurSay.length(); j++) {
                    cout << CurSay[j];
                    Sleep(15);
                }
                puts("");
                break;
        }

        Sleep(Rest);
    }

    int Rep = 10;
    while (Rep--) {
        Sleep(2000);
        puts("\n");
    }

    getchar();

    return 0;
}

/*
A - 1000ms
B - 500ms
*/