#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    srand(time(nullptr));
    int ans = (rand() % 1000) + 1;
    int guess = -1;

    while (guess != ans) {
        std::cout << "Enter your guess:";
        std::cin >> guess;
        
        if (!std::cin.good() || guess > 1000 || guess < 1) {
            std::cout << "Invalid.\n";
            std::cin.clear();
            std::cin.sync();
            continue;
        }
        if (guess == ans) {
            std::cout << "Correct\n";
            break;
        }
        if (guess < ans)
            std::cout << "Too small.\n";
        else
            std::cout << "Too big.\n";

        guess = -1;
    }

    return 0;
}

/* Enter your guess:500
Too small.
Enter your guess:1000
Too big.
Enter your guess:1001
Invalid.
Enter your guess:1
Too small.
Enter your guess:0
Invalid.
Enter your guess:750
Too small.
Enter your guess:875
Too small.
Enter your guess:937
Too small.
Enter your guess:968
Too big.
Enter your guess:952
Too small.
Enter your guess:960
Too small.
Enter your guess:964
Too big.
Enter your guess:962
Too big.
Enter your guess:961
Correct */
