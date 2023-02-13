#include <iostream>

using namespace std;


int times[46];

int check_fib_log_n()
{
    for (int i = 0; i < 47; ++i) {
        clock_t tStart = clock();
        int result = fib_n_log_func(i);
        times[i] = clock() - tStart;
    }

    for (int i = 0; i < 47; i++) {
        if (times[i] >= 5) {
            cout << "Ol(og_n) test FAIL" << endl;
            return 0;
        }
    }
    cout << "O(log_n) test OK" << endl;
    return 0;
}

int check_fib_n()
{
    for (int i = 0; i < 47; ++i) {
        clock_t tStart = clock();
        BigInt result;
        result = getNthFibNum(i);
        times[i] = clock() - tStart;
    }

    for (int i = 0; i < 47; i++) {
        if (times[i+1] - times[i] > 5) {
            cout << "O(n) test FAIL" << endl;
            return 0;
        }
    }
    cout << "O(n) test OK" << endl;
    return 0;
}
